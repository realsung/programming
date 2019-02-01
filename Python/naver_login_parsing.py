from selenium import webdriver
import time
driver = webdriver.Chrome()

ID = '' # input naver id
PW = '' # input naver pw
driver.get('https://www.naver.com/')
time.sleep(5.5)
set_login = driver.find_element_by_class_name('lg_local_btn')
set_login.click()
time.sleep(3)
id_input = driver.find_element_by_id('id')
id_input.send_keys(ID)
time.sleep(1)
pw_input = driver.find_element_by_id('pw')
pw_input.send_keys(PW)
time.sleep(2)
login_button_click = driver.find_element_by_class_name('btn_global')
login_button_click.click()