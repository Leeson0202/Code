from requests import *
from bs4 import BeautifulSoup
import re

url = 'http://42.56.69.142/videos/v0/20200807/a0/76/6e5423e07468d4c078ba45c36ab757b0.mp4?key=01a2bb0d9a38970b5dd833d64baf4d32&dis_k=2345721fbed3d9c01449c17b95b4cd4cd&dis_t=1598325806&dis_dz=OTHER-None&dis_st=44&src=iqiyi.com&dis_hit=0&uuid=b65cc62e-5f44842e-115&qd_uri=dash&qd_ip=b65cc62e&qd_tm=1598313013187&qd_tvid=4376316052998100&qd_uid=992858274269030&qd_k=c3730869363946875217545086b380d0&ve=0808f4a9bb5ee572ca2bd52b07270edf&m=v&qd_p=b65cc62e&qd_vip=2&ssl=0&qd_src=02020031010000000000&dis_src=vrs&pv=0.2'
kv = {"user-agent": 'Mozilla/5.0'}           # 创建一个字段 浏览器5.0


def gethtml():
	try:
		res = get(url,headers = kv, timeout = 30)
		res.raise_for_status()
		r.encoding = 'utf-8'
		print('爬取成功')
		return res
	except:
		print('爬取失败')


def save(res):
	try:
		with open('E:/python/videos/电影.rm') as f:
			f.write(res.content())
		print('保存成功')
	except:
		print('保存失败')


def main():
	res = gethtml()
	save(res)


if __name__ == '__main__':
	main()
