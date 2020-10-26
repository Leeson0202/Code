
from requests import *
from bs4 import BeautifulSoup
import re

header = {'User-Agent':
          'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Mobile Safari/537.36'}
pages = set()


def getlinks(pageurl):
    global pages
    html = get('http://stock.eastmoney.com/{}'.format(pageurl),
               headers=header, timeout=20)
    bs = BeautifulSoup(html.content, 'lxml')
    k = bs.thead
    kk = k.find_all('div',class_='tabs_body')
    for i in kk:
        print(i.string)
    # if 'herf' in link.attrs:
    #     if link.attrs['href'] not in pages:
    #         newpage = link.attrs['href']
    #         print(newpage)
    #         pages.add(newpage)
    #         getlinks(newpage)


getlinks('')
