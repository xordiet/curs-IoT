#!/bin/sh

TOKEN="xxxx"
ID='-xxx'
MENSAJE="Captura de camera"
URL="https://api.telegram.org/bot$TOKEN/sendPhoto"

raspistill -vf -hf -o "./cam.jpg"

curl -s -X POST $URL -F chat_id=$ID -F photo="@./cam.jpg" -F caption="$MENSAJE"
