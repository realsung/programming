#-*-encoding:utf-8-*-
from selenium import webdriver
import bs4
import time
driver = webdriver.Chrome()
driver.get('https://www.istarbucks.co.kr/store/store_map.do')
time.sleep(6)
loca = driver.find_element_by_class_name('loca_search')
loca.click()
time.sleep(1.5)
do_list = driver.find_element_by_class_name('sido_arae_box')
seoul = do_list.find_elements_by_tag_name('li')
seoul[0].click()
time.sleep(.15)
all_area = driver.find_element_by_class_name('gugun_arae_box')
area_click = all_area.find_elements_by_tag_name('li')
area_click[0].click()
time.sleep(5)
source = driver.page_source
bs = bs4.BeautifulSoup(source)
bs_find = bs.find('ul',class_='quickSearchResultBoxSidoGugun')
li_list = bs_find.find_all('li')
for i in li_list:
	print(i.find('p').text)