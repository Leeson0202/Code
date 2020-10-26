from requests import *
from bs4 import BeautifulSoup
import re
import bs4

url = 'http://www.zuihaodaxue.com/zuihaodaxuepaiming2020.html'
kv = {"user-agent": 'Mozilla/5.0'}           # 创建一个字段 浏览器5.0


def get_response():
    try:
        r = get(url, params=kv, timeout = 30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r
    except:
        print("爬取失败")


def get_list(r):
    rank_list = []
    soup = BeautifulSoup(r.text, "html.parser")
    for tr in soup.find('tbody').children:
        if isinstance(tr, bs4.element.Tag):
            tds = tr('td')
            rank_list.append([tds[0].string, tds[1].string, tds[3].string, tds[4].string])
    return rank_list

    # try:
    #     soup = BeautifulSoup(r.text,'html.parser')
    #     temp = soup.find_all('tr')
    #     for i,data in enumerate(temp):
    #         if i == 0:
    #             continue
    #         rank_list.append(data.find_all("td")[:5])
    #     return rank_list
    # except:
    #     print("获取排名失败")


def print_list(rank_list, num):
    tple = "{0:^3}{1:{4}^12}{2:^3}{3:^12}"
    print("{0:^3}{1:{4}^10}{2:^7}{3:^5}".format('排名', '学校', '类型', '综合得分', chr(12288)))  # 中文字符填充chr(12288)
    for i, list1 in enumerate(rank_list[:num]):
        temp_list = []
        for j,data in enumerate(list1):
            temp_list.append(data.string)
        print(tple.format(temp_list[0], temp_list[1], temp_list[2], temp_list[3], chr(12288)))
        

def main():
    r = get_response()
    rank_list = get_list(r)
    print_list(rank_list,20)


if __name__ == '__main__':
    main()
