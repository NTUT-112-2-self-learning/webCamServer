#include <gst/gst.h>

int main(int argc, char *argv[])
{
    GstElement *pipeline, *source, *depay, *decode, *convert, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    pipeline = gst_pipeline_new("video-pipeline");
    source = gst_element_factory_make("rtspsrc", "video-source");
    depay = gst_element_factory_make("rtph264depay", "depay");
    decode = gst_element_factory_make("avdec_h264", "decode");
    convert = gst_element_factory_make("videoconvert", "convert");
    sink = gst_element_factory_make("filesink", "video-output");

    if (!pipeline || !source || !depay || !decode || !convert || !sink)
    {
        g_printerr("Failed to create elements.\n");
        return -1;
    }

    // Set RTSP location and output file location
    g_object_set(G_OBJECT(source), "location", "rtsp://your_camera_ip:port/stream", NULL);
    g_object_set(G_OBJECT(sink), "location", "output.mp4", NULL);

    gst_bin_add_many(GST_BIN(pipeline), source, depay, decode, convert, sink, NULL);

    // Link the elements together
    if (!gst_element_link_many(depay, decode, convert, sink, NULL))
    {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    // Connect the pad-added signal to handle dynamic pad creation
    g_signal_connect(source, "pad-added", G_CALLBACK(on_pad_added), depay);

    ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE)
    {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                     GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    if (msg != NULL)
    {
        GError *err;
        gchar *debug_info;

        switch (GST_MESSAGE_TYPE(msg))
        {
        case GST_MESSAGE_ERROR:
            gst_message_parse_error(msg, &err, &debug_info);
            g_printerr("Error received from element %s: %s\n",
                       GST_OBJECT_NAME(msg->src), err->message);
            g_printerr("Debugging information: %s\n",
                       debug_info ? debug_info : "none");
            g_clear_error(&err);
            g_free(debug_info);
            break;
        case GST_MESSAGE_EOS:
            g_print("End-Of-Stream reached.\n");
            break;
        default:
            g_printerr("Unexpected message received.\n");
            break;
        }
        gst_message_unref(msg);
    }

    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;
}

static void on_pad_added(GstElement *element, GstPad *pad, gpointer data)
{
    GstPad *sink_pad = gst_element_get_static_pad(data, "sink");
    GstPadLinkReturn ret;

    if (gst_pad_is_linked(sink_pad))
    {
        g_object_unref(sink_pad);
        return;
    }

    ret = gst_pad_link(pad, sink_pad);
    if (GST_PAD_LINK_FAILED(ret))
    {
        g_printerr("Type is '%s' but link failed.\n", GST_PAD_LINK_RETURN_NAME(ret));
    }
    else
    {
        g_print("Link succeeded (type '%s').\n", GST_PAD_LINK_RETURN_NAME(ret));
    }

    g_object_unref(sink_pad);
}