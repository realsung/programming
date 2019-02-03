from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import time


ID = ''
PW = ''
driver = webdriver.Chrome('/Users/realsung/Desktop/chromedriver')
driver.get('https://fb.com')
time.sleep(3)
elem = driver.find_element_by_id("email")
elem.send_keys(ID)
elem = driver.find_element_by_id("pass")
elem.send_keys(PW)
time.sleep(0.5)
elem.send_keys(Keys.RETURN) # enter
time.sleep(3)
profile = driver.find_element_by_xpath('//*[@id="u_0_a"]/div[1]/div[1]/div/a')
profile.click()
time.sleep(4)
req = driver.page_source
soup = BeautifulSoup(req,'html.parser')
infomation_list = soup.select('#u_ps_fetchstream_2_1_4')
for i in infomation_list:
	print i.text