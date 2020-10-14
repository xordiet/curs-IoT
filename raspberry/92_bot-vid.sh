#!/bin/sh

TOKEN="1286093258:AAFzERZvXst-jlWpZkNYVJ-1l-ZJKMzY6Gw"
ID='-1001499525520'
MENSAJE="Captura de camera"
URL="https://api.telegram.org/bot$TOKEN/sendVideo"

ffmpeg -y -ac 1 -f alsa -i hw:1 -f h264 -framerate 30 -i /dev/video0 -vcodec copy -acodec aac -ab 128k out.mp4

curl -s -X POST $URL -F chat_id=$ID -F video="@./out.mp4" -F caption="$MENSAJE"
