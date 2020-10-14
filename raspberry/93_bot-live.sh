#!/bin/sh

URL="rtmp://a.rtmp.youtube.com/live2/2wj6-5zar-93e1-bjqv-9bh9"

ffmpeg -ac 1 -f alsa -i hw:1 -f h264 -framerate 30 -i /dev/video0 -vcodec copy -acodec aac -ab 128k -f flv URL
