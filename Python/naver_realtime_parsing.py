#-*-encoding:utf-8-*-
import requests
from bs4 import BeautifulSoup
print '실시간 검색어'
URL = "https://www.naver.com/"
req = requests.get(URL)
source = req.text
soup = BeautifulSoup(source,'html.parser')
select_list =  soup.select('#PM_ID_ct > div.header > div.section_navbar > div.area_hotkeyword.PM_CL_realtimeKeyword_base > div.ah_roll.PM_CL_realtimeKeyword_rolling_base > div > ul > li > a > span.ah_k')
ran = 1
for i in select_list:
	print '%d등 :' %ran, i.text
	ran+=1