from requests import *
from bs4 import BeautifulSoup
import json
import re
import webbrowser

header = {
    'User-Agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Mobile Safari/537.36'}

search_url = 'http://api.skyrj.com/api/movies?searchKey='
movie_detail_url = 'http://api.skyrj.com/api/movies?id='
play_url = 'https://www.8090g.cn/?url='
page_url = 'http://api.skyrj.com/Home/MovieList?orderBy=&pageIndex='
page_end = '&type=&CategoryType=&CategoryArea=&Year=&searchKey='


def getmovielist(searchkey):
    f = False
    page = 0
    num = 0
    movielist = []
    while(not f):
        page += 1
        url = page_url + str(page) + page_end + searchkey
        try:
            response = get(url, timeout=30)
            response.raise_for_status()                     # 自动检测爬虫状态=200
            response.encoding = 'utf-8'  # 转换格式
            # print(response.text)
        except:
            print("爬取失败")
        try:
            list0 = re.findall(
                r"\<a href=\"/Home/Detail\?ID=(\d{6})\"\>", response.text)
            list1 = re.findall(
                r"\<p class=\"font-14 grey\"\>(.{1,15})\</p\>", response.text)
            list2 = re.findall(r"\"\>(.{4})\</span\>", response.text)
            # if list0:
            #     list1 = re.findall(r"\<Name\>(.{1,15})\</Name\>", response.text) 
            #     list2 = re.findall(r"\<Year\>(.{1,15})\</Year\>", response.text)
            #     list3 = re.findall(r"\<Type\>(.{1,15})\</Type\>", response.text)
            #     list4 = re.findall(r"\<Tags\>(.{1,15})\</Tags\>", response.text)
            #     list5 = re.findall(r"\<MovieTitle\>(.{1,5})\</MovieTitle\>", response.text)
            # else:
            #     list0 = re.findall(r"\"ID\":(\d{6}),", response.text)
            #     list1 = re.findall(r"\"Name\":\"(.{1,19})\",", response.text)
            #     list2 = re.findall(r"\"Year\":(\d{4}),", response.text)
            #     list3 = re.findall(r"\"Type\":\"(.{1,15})\",", response.text)
            #     list4 = re.findall(r"\"Tags\":\"(.{1,19})\",", response.text)
            #     list5 = re.findall(r"\"MovieTitle\":\"(.{1,5})\",", response.text)
            # list1 = [x.strip() for x in list1]
            movies = [list(x) for x in zip(list0, list1, list2)]
            if movies:
                for i, movie in enumerate(movies):
                    num += 1
                    print(r"{0:^4}{1:{3}^15}{2:^6}".format(
                        num, movie[1], movie[2], chr(12288)))
                movielist.extend(movies)
            else:
                print("无更多内容")
        except:
            print("解析失败")
        f = input("请选择电影前数字（下一页请回车）：")
    # print(movielist)
    # input()
    return movielist, eval(f)


def selectmovie(movielist):

    selectnum = eval(input("请输入你要选择的视频(数字)："))
    return selectnum, movielist[selectnum-1][0]


def selectname(moviedetail, ID):
    url = movie_detail_url + str(ID)
    try:
        response = get(url, headers=header, timeout=30)

        moviedetail.append(re.findall(
            r"\"Type\":\"(.{1,15})\",", response.text)[-1])
        # introduction = re.findall(r"\"Introduction\": \"{.+}\",", response.text)
        movietitle = re.findall(r"\"MovieTitle\":\"(.{1,9})\",", response.text)
        moviedetail.extend(movietitle)
        playurl = re.findall(
            r"\"PlayUrl\":\"(http.{1,80}m3u8)\"", response.text)
        # print(playurl)
        print("\n{0:{3}^} {1:^15}{2:^12}".format(
            moviedetail[1], str(moviedetail[2])+moviedetail[3], moviedetail[4], chr(12288)), end='  ')
    except:
        if playurl:
            pass
        else:
            print("获取详情页失败")
    showmovie(moviedetail, playurl)


def showmovie(moviedetail, playurl):
    if moviedetail[3] == 'movie':
        input("请回车观看")
        playurl = play_url + playurl[0]
        webbrowser.open(playurl)
    else:
        index = eval(input("你要看的第几集："))
        while(index):
            playurl = play_url + playurl[index-1]
            webbrowser.open(playurl)
            index = 0


def main():
    try:
        searchkey = input("请输入视频名称：")
        # searchkey = '功夫'
        movielist, selectnum = getmovielist(searchkey)
        while selectnum:
            ID = movielist[selectnum-1][0]
            selectname(movielist[selectnum - 1], ID)
            selectnum = input("\n请选择电影前数字（重新搜索请回车）：")
            if not selectnum:
                searchkey = input("请输入视频名称：")
                # searchkey = '功夫'
                movielist, selectnum = getmovielist(searchkey)
            else:
                selectnum = eval(selectnum)
    except:
        print("已退出")


if __name__ == '__main__':
    main()
