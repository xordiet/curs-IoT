import requests

bot_token = 'xxxxx'
bot_chatId = '-xxxx'
bot_missatge = "Hola mon!"

url_final = 'https://api.telegram.org/bot' + bot_token + '/sendMessage?chat_id=' + bot_chatId + '&parse_mode=Markdown&text=' + bot_missatge

response = requests.get(url_final)

print(response.json())
