#!/bin/sh

TOKEN="xxxx"
ID='-xxxx'
MENSAJE="Captura de camera"
URL="https://api.telegram.org/bot$TOKEN/sendVideo"

raspivid -vf -hf -o "./vid.h264" -t 4000
MP4Box -add "./vid.h264" "./vid.mp4"

curl -s -X POST $URL -F chat_id=$ID -F video="@./vid.mp4" -F caption="$MENSAJE"
