# requests_parsing.py
#-*- coding: utf-8 -*-
import requests

request = requests.get('https://realsung.github.io')

# HTML 소스 가져오기
html_parsing = request.text
print(html_parsing)
print("---"*30)

# HTTP Header 가져오기
header_parsing = request.headers
print(header_parsing)
print("---"*30)

# HTTP Status 가져오기 (출력이 200이면 정상)
http_status = request.status_code
print(http_status)
print("---"*30)

# HTTP가 정상적인지 확인
http_ok = request.ok
print(http_ok)
print("---"*30)