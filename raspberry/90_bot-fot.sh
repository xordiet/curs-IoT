#!/bin/sh

TOKEN="1286093258:AAFzERZvXst-jlWpZkNYVJ-1l-ZJKMzY6Gw"
ID='-1001499525520'
MENSAJE="Captura de camera"
URL="https://api.telegram.org/bot$TOKEN/sendPhoto"

raspistill -vf -hf -o "./cam.jpg"

curl -s -X POST $URL -F chat_id=$ID -F photo="@./cam.jpg" -F caption="$MENSAJE"
