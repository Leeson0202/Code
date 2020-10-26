# 层级 ：/ 直接子级   // 跳级
# 属性 ：@ 属性访问
# 函数 ： contains() 包含得属性 ，text() 文本 ，
#         extract() 提取文本 ，extract_first() 提取第一段文字

from requests import *
from lxml import etree


response = get('https://cn.bing.com/search?q=windows%E5%88%86%E5%B1%8F%E7%94%A8%E4%B8%8D%E4%BA%86&qs=n&form=QBRE&sp=-1&pq=windows%E5%88%86%E5%B1%8F%E7%94%A8%E4%B8%8D%E4%BA%86&sc=0-12&sk=&cvid=5C16953F41BC4CA2AD4E6FCE5B7F6CF2')
response.encoding = 'utf-8'

tree = etree.HTML(response.text)
data = tree.xpath(
    "//a[contains(@target,'_blank')]")

for i in data:
    print(i.text)
