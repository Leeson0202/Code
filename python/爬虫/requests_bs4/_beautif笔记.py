from requests import *
from bs4 import *
from _pa01 import *
import re

url = 'https://python123.io/ws/demo.html'


def beautiful():
    pass


r = get_Http_response(url)
# print(r.text)
soup = BeautifulSoup(r.text, 'html.parser')  # 将html代码美化，并加解析参数html.parser
next = soup.find_all(name='a',attrs={"class":"next"})  #找到含有class = "next" 的a 标签
# print(soup.prettify())                 # 格式化打印html文档
# print(soup.a.prettify())

# ---------------------------------------beautify基本属性
# print(soup.title)                      # 获取标题
# print(soup.a)                          # 返回a表签的信息
# print(soup.a.string)                   # 返回a标签的字符串内容
# print(soup.a.get('href'))              # 返回a标签 href属性的内容

# print(soup.a.parent.name)              # a标签的父标签
# print(soup.a.parent.parent.name)       # a标签的父标签的父标签
# print(soup.a.attrs)                    #返回a标签的属性的字典

# ------------------------------------------------------上下遍历
# print(soup.html.contents)              # 获取html标签的儿子标签
# for i in soup.html.children:           # 获取html标签的子孙标签列表
#     print(i)
# print(soup.a.parent)                   # a的父标签

# ------------------------------------------------------平行遍历
# print(soup.a.next_sibling)                       # a的下一个节点（标签|字符串）
# print(soup.a.next_sibling.next_sibling)      # a标签的下下个节点
# print(soup.a.previous_sibling)               # a的前一个标签
# print(soup.a.previous_sibling.previous_sibling)  # a的前前一个标签

# -------------------------------------------------查找标签对应属性内容方式
# a_list = soup.find_all('a')                 #返回一个a标签列表
# b_a_list = soup.find_all(['a', 'b'])        # 返回关于a,b标签的列表
# p_course_list = soup.find_all('p', 'course')  # 返回一个带有course属性的p标签列表
# for i in a_list:
#     print(i, end='    ')
#     print(i.name)                  # a标签对应得名字
#     print(i.attrs)                 # a表对于的属性
#     print(i.get('href'))           # 一次打印a标签的href属性对于的值
# id_link1_list = soup.find_all(id='link1')  # 返回一个带有id='link1' 属性的标签列表
# string_list = soup.find_all(string = "Basic Python") # 返回一个带有特定字符串列表
# print(string_list)
# string_list = soup.find_all(string=re.compile("python")) # 利用正则表达式 返回一个带有python的字符串列表
# print(string_list)


# ----------------------------------------等价形式
#       <tag>(...) = <tag>.find_all(...)
#        soup(...) = soup.find_all(...)
