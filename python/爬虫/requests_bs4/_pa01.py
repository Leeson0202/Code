from requests import *
from bs4 import BeautifulSoup
import re
import os
import time


url = "https://vdept.bdstatic.com/366d38794865507948686e5964573551/6a76646a4d445836/ef016131f2819ce4fc954eb1fb9a6e0c5c1aaf43d1ff3205234b4c3fac3050776b8de1e9c3dc42a4c7a26891a972402b5d56d76531e53ad5bd5a1e39e1f9a2d3.mp4?auth_key=1597319850-0-0-ef854278d9a2035139648bb3d6515f2a"

path_root = 'E://python/'
kv = {"user-agent": 'Mozilla/5.0'}           # 创建一个字段 浏览器5.0


def get_params():                           # ----------获取params

    params = dict()
    try:
        temp = input("请输入关键字对:")
        if temp == '':
            return params
        templist = temp.split(' ')          # re.findall(r"(.+:.+)", temp)
        print(templist)
        for kk in templist:
            tempdict = kk.split(':')
            tempkey, tempvalue = tempdict[0], tempdict[1]
            params[tempkey] = tempvalue
        print(params)
    finally:
        return params


def get_Http_response(url=None, params=None):    # ----------获取response

    if url is None:
        url = input("请输入url：")
    try:
        r = get(url, headers=kv, params=params, timeout=30)  # 伪装浏览器进行爬取
        r.raise_for_status()                     # 自动检测爬虫状态=200
        r.encoding = r.apparent_encoding         # 转换格式
        return r  # 返回response
    except:
        print("爬取错误")


def download_pictures(url=None, path_root=path_root):                # -------------下载图片

    if url is None:
        url = input("请输入url：")
    if url[-4:] == '.jpg' or url[-4:] == '.png':
        path = path_root + 'picture/' + url.split('/')[-15:]  # 创建文件目录名字
    else:
        path = path_root + 'picture/' + url.split('/')[-15:] + '.jpg'
    print(path)
    try:
        if not os.path.exists(path_root):
            os.mkdir(path_root)
        if not os.path.exists(path):
            r = get(url, headers=kv, timeout=30)              # 自动检测爬虫状态=200
            r.raise_for_status()
            with open(path, 'wb') as f:
                f.write(r.content)
                print("图片保存成功")
        else:
            print('图片已存在')
    except:
        print('图片保存失败')


def download_mp4(url=None, path_root=path_root):                        # -------------下载视频

    if url is None:
        url = input("请输入url：")
    video_form = ['rm', 'rmvb', 'mov', 'mtv',
                  'avi', '3gp', 'amv', 'dmv', 'flv']

    if url[-3:] in video_form or url[-4:] in video_form or url[-2] in video_form:
        path = path_root + 'video/' + url[-15:]  # 创建文件目录名字
    else:
        path = path_root + 'video/' + url[-15:] + '.rm'
    print(path)
    try:
        if not os.path.exists(path_root):
            os.mkdir(path_root)
        if not os.path.exists(path):
            r = get(url, headers=kv, timeout=30)
            r.raise_for_status()                    # 自动检测爬虫状态=200
            with open(path, 'wb') as f:
                f.write(r.content)
                print("视频保存成功")
        else:
            print('视频已存在')
    except:
        print('视频保存失败')


def search_ip(ip=None):  # ---------------查询ip地址

    if ip is None:
        ip = input("请输入ip地址：")
    url = "https://ipchaxun.com/" + ip + '/'  # 拼接地址
    try:
        r = get(url, headers=kv, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding

        relist = re.findall(
            r"[<label>\n|<label>]<span class=\"name\">(.+)</span><span class=\"value\">(.+)</span>[\n</label>|</label>]", r.text)  # 正则表达式选择文本
        for i, k in enumerate(relist):
            print(k[0], k[1])
    except:
        print("查询失败")


def main():
    pass
    # search_ip(ip=None)        # 获取ip地址
    # download_pictures(url)    # 下载一张图片
    # download_mp4(url)         # 下载一个视频

    # params = get_params()           # 获取params
    # r = get_Http_response(params)       # 返回response
    # print(r.request.url)            # 获取被改的网站的网址
    # print(r.text)                   # 获取网站的html信息


if __name__ == '__main__':
    main()
