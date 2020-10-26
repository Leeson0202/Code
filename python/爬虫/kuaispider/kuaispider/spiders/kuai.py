import scrapy
from bs4 import BeautifulSoup


class KuaiSpider(scrapy.Spider):
    name = 'kuai'
    allowed_domains = ['kuaidaili.com']
    start_urls = ['https://www.kuaidaili.com/free/']

    def parse(self, response):
        soup = BeautifulSoup(response.text, "html.parser")
        tittle_list = soup.find_all('th')
        for i in tittle_list[:-2]:
            print('{:^16}'.format(i.string), end=' ')
        print()
        t_body = soup.tbody
        tr_list = t_body.find_all('tr')
        for i in tr_list:
            for j in i.find_all('td')[:-2]:
                print('{:^16}'.format(j.string), end=' ')
            print()
