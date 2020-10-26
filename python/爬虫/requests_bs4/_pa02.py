from urllib.request import *
# from urllib import *

url_muke = "https://www.icourse163.org/"

file = urlopen(url_muke)  #方式一爬取
# data = file.read()
print(file.info())                                # 文件信息
print(file.getcode())                             # 爬取网站状态码 正确值为：200
print(file.geturl())                              # 获取URL
# with open("慕课.html", "wb") as f:                # 保存到本地文件
#     f.write(data)

# f = urlretrieve("https://tse1-mm.cn.bing.net/th/id/OIP.7olKPTchQLdCMmfFaGFT3wHaEL?pid=Api&rs=1", "1.jpg")     #方式二爬取 直接保存到本地文件 但是会产生缓存
# urlcleanup()                #清楚缓存
