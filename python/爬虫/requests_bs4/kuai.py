from requests import *
from bs4 import BeautifulSoup
from _pa01 import *


response = get_Http_response(url="https://www.kuaidaili.com/free/")
soup = BeautifulSoup(response.content, "html.parser")
tittle_list = soup.find_all('th')
for i in tittle_list[:-2]:
    print(i.string, end='\t\t')
print()
t_body = soup.tbody
tr_list = t_body.find_all('tr')
for i in tr_list:
    for j in i.find_all('td')[:-2]:
        print(j.string, end='    ')
    print()
