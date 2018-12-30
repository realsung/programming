#-*- coding: utf-8 -*-
# import sys
# 변수,함수들을 직접 제어할 수 있는 모듈
# print(sys.argv) # 이 py파일의 디렉토리 경로
# print(sys.path) # 모듈 저장된 위치들
# sys.exit() # 스크립트 강제 종료

# import os
# 환경 변수나 디렉토리, 파일 등 os 자원 제어 모듈
# print os.environ # 시스템의 환경 변수 값
# print os.getcwd() # 현재 자신의 디렉토리 위치를 리턴
# print os.system("ls") # 시스템 명령어 호출

# f = os.popen("ls") # 읽기 모드 형태의 파일 객체로 리턴
# print(f.read()) # 읽어들인 파일 객체의 내용 보기

# import shutil
# 파일을 복사하는 모듈
# shutil.copy("untitled.py", "ex.py") # untitled.py 라는 파일을 복사

#import time
#print time.localtime() # time.time()에 반환된 실수 값을 이용해 연도,월,일,시,분,초 형태로 바꿔줌
#print time.asctime(time.localtime(time.time())) ## time.localtime()에 반환된 튜블 형태의 값을 인수로 받아 쉬운 형태로 리턴하는 함수 / 더 알아보기 편함
#print time.ctime() # asctime과 다른 점은 현재 시간만을 리턴

#for i in range(10): # 1초 단위로 ctime() 출력
#	print time.ctime()
#	time.sleep(1)

# import random
# print random.random() # 0.0 ~ 1.0 사이 실수 중 난수 값을 리턴
# print random.randint(1,10) # 1~10 사이의 정수 중에서 난수 값을 리턴

# data = [1,2,3,4,5] # 리스트 항목 섞기
# random.shuffle(data)
# print data

# import webbrowser
# webbrowser.open("http://google.com") # 웹 브라우저 실행하고 url로 간다
# webbrowser.open_new("http://google.com") # 웹 브라우저가 실행된 상태더라도 새로운 창으로 해당 주소가 열리도록 함

# defaultdict 문자의 개수 
"""
from collections import defaultdict
a = "I I I I I I I A A A A A B C C"
b = defaultdict(int)
for i in a:
	b[i] += 1

print b.items()
"""