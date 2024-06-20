FROM ubuntu:latest

WORKDIR /app

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libmp3lame-dev \
    libopus-dev \
    libvpx-dev \
    libx264-dev \
    wget \
    && echo "Build dependencies installed."

RUN apt-get update && apt-get install -y ffmpeg

COPY ./entrypoint.sh /
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]