# server.py
import subprocess
import time

def capture_udp_stream():
    # Replace udp://localhost:1234 with your UDP stream
    command = ['ffmpeg', '-i', 'udp://localhost:1234', '-vcodec', 'copy', '-an', 'output.mp4']
    subprocess.Popen(command)

if __name__ == '__main__':
    capture_udp_stream()
    while True:
        # Keep the script running
        time.sleep(1)