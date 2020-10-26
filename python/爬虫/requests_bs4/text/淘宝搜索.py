from requests import *
from bs4 import BeautifulSoup
import re

url = 'https://list.tmall.com/search_product.htm?q=%CA%E9%B0%FC&type=p&vmarket=&spm=875.7931836%2FB.a2227oh.d100&from=mallfp..pc_'
url_str = '_searchbutton'

kv = {"user-agent": 'Mozilla/5.0'}           # 创建一个字段 浏览器5.0


def get_Http_text(url_page):
    try:
        r = get(url_page, headers=kv, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        # print(r.text)
        print('爬取成功')
        return r.text
    except:
        print("爬取失败")


def get_par_list(r_text):
    soup = BeautifulSoup(r_text, 'html.parser')
    good_parten = r'<em title=\"(.+)\">.+<a href=.+\stitle=\"(.+)\"\s'
    goods_list = []
    try:
        pit = re.findall(r'<em title=\"(.+)\">', r_text)
        nit = re.findall(
            r'target=\"_blank"\stitle=\"(.+)\".+data', r_text)
        for i, data in enumerate(pit):
            goods_list.append([data,nit[i]])
        print("商品信息获取成功")
        return goods_list
    except:
        print("商品信息获取失败")


def show_list(goods_list):
    print("{0:{2}<5}{1:<}".format('价格','商品',chr(12288)))
    for data in goods_list:
        print("{0:<10}{1:<}".format(data[0],data[1][:35]))


def main():
    k = 0
    mm = True
    while mm:
        k += 1
        url_page = url + str(k) + url_str
        r_text = get_Http_text(url_page)
        goods_list = get_par_list(r_text)
        # print(goods_list)
        show_list(goods_list)
        mm = False
        mm = input("下一页({})：".format(k+1))


if __name__ == '__main__':
    main()
