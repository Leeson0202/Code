from requests import *
from bs4 import BeautifulSoup
import re
import time
import traceback

stock_list_bassurl = 'http://quote.cfi.cn/stockList.aspx?t='
stock_info_headurl = 'http://quote.cfi.cn/'
stock_info_endurl = '.html'
kv = {"user-agent": 'Mozilla/5.0'}           # 创建一个字段 浏览器5.0


def get_stocks_list():
    stock_nums_list = []
    try:
        for i in range(11,12):
            r = get(stock_list_bassurl + str(i), headers=kv, timeout=30)
            r.raise_for_status()
            r.encoding = 'utf-8'
            temp = re.findall(
                r"d><a href=\"(.{6})\.html\">(.{3,8})\(\d{6}\)</a><", r.text)
            stock_nums_list.extend(temp)
        print("获取列表成功")
        return stock_nums_list
        # soup = BeautifuleSoup(r.text,"heml.parser")
    except:
        print("获取列表失败")


def get_stock_text():
    stock_nums_list = get_stocks_list()
    for i, info in enumerate(stock_nums_list):
        print("\r当前进度{:>5.2f}%".format(i/len(stock_nums_list)),end ="")
        try:
            url = stock_info_headurl + info[0] + stock_info_endurl
            r = get(url, headers=kv, timeout=30)
            if r == '':
                continue
            r.raise_for_status()
            r.encoding = 'utf-8'
            temp = re.findall(r"<span id='last'>(.+)[↓|↑]", r.text)
            if temp:
                with open('text/gupiao.txt', 'a', encoding='utf-8') as ff:
                    ff.write(info[0] + ' ' + info[1] + ' ' + temp[0] + '\n')
        except:
            traceback.print_exc()
            continue
        
    print('信息保存成功')


def main():
    # stock_nums_list = get_stocks_list()
    # print(stock_nums_list)
    get_stock_text()


if __name__ == '__main__':
    main()
