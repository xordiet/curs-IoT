#!/bin/sh

URL="rtmp://a.rtmp.youtube.com/live2/2wj6-5zar-93e1-bjqv-9bh9"

raspivid -o - -t 0 -vf -hf -fps 30 -b 6000000 | ffmpeg -ac 1 -f alsa -i hw:1 -f video4linux2 -framerate 30 -i /dev/video0 -fflags nobuffer -vcodec h264_omx -g 5 -b:v 1000k -tune zerolatency -acodec aac -ab 128k -f flv URL
