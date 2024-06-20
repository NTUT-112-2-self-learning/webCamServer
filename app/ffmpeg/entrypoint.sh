#!/bin/bash

echo "Starting ffmpeg"
ffmpeg -i rtsp://root:0000@192.168.1.247/stream=0 \
 -c:v copy \
 -c:a copy \
 -f hls \
 -hls_time 2 \
 -hls_list_size 5 \
 -hls_flags delete_segments \
 -hls_segment_filename "/mnt/hls/stream_%03d.ts" \
 /mnt/hls/stream.m3u8