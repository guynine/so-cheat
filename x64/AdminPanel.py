import requests

url = "http://keyauth.win/api/1.2/?type=init&ver=1.1&name=AYUS%20CHEAT&ownerid=hzWzcmKeZS"

headers = {
    "accept": "application/json",
    "Host": "keyauth.win",
    "Content-Type": "application/x-www-form-urlencoded",
    "Content-Length": "46"
}

response = requests.get(url, headers=headers)

print(response.json()["success"])


url = "http://keyauth.win/api/1.2/?type=fetchOnline&sessionid=jYElE4AZt0&name=AYUS%20CHEAT&ownerid=hzWzcmKeZS"

headers = {
    "accept": "application/json",
    "Host": "keyauth.win",
    "Content-Type": "application/x-www-form-urlencoded",
    "Content-Length": "46"
}

response = requests.post(url, headers=headers)

print("Users in online: "+str(len(response.json()["users"])))