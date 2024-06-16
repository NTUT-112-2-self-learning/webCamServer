FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    libgstreamer1.0-dev \
    gstreamer1.0-tools \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN gcc -o main main.c $(pkg-config --cflags --libs gstreamer-1.0)

CMD ["./main"]