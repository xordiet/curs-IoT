import requests

bot_token = '1286093258:AAFzERZvXst-jlWpZkNYVJ-1l-ZJKMzY6Gw'
bot_chatId = '-1001499525520'
bot_missatge = "Hola mon!"

url_final = 'https://api.telegram.org/bot' + bot_token + '/sendMessage?chat_id=' + bot_chatId + '&parse_mode=Markdown&text=' + bot_missatge

response = requests.get(url_final)

print(response.json())
