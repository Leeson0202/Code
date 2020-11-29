


# ---------------------------------------------进度条库
# import tqdm
# import time
# bar = tqdm.tqdm(range(10))
# for i in bar:
#     time.sleep(0.2)
#     bar.set_description(f'第{i}轮')
# ------------方法三
# for i in tqdm.trange(10):
#     time.sleep(0.2)
# ------------方法二
# temp = [time.sleep(0.2) for i in tqdm.tqdm(range(10))]
# ------------方法一
# for i in tqdm.tqdm(range(10), desc = '这是一个进度条'):
#     time.sleep(0.2)


# # ----------------------------------两个数列的笛卡尔积
# # ---------------方法一
# list1 = ['black', 'witte']
# list2 = ['S', 'M', 'L']
# for kk in ('%s %s' % (c1, c2) for c1 in list1 for c2 in list2):
#     print(kk)
# # -----------------方法二
# import itertools
# print(list(itertools.product(list1,list2)))


# # ----------------------------------写文件
# with open('document.txt', 'w') as a:
#     a.write(input())

# -------------------------------------------占位符 pass


# # ---------------------------------------快速启动浏览器打开网址
# import webbrowser
# webbrowser.open('http://www.baidu.com')


# # ------------------------------------查看文本的帮助文本 __doc__
# import time
# print(time.__doc__)


# # -------------------------------------查找模块包含的属性 dir(time)
# import time
# print(dir(time))


# # -----------------------------------计算所有整数之和
# s = sum(range(1, 101))
# print(s)


# #------------------------------------给字典中不存在的key设置默认值
# d = {'age':12, 'name':'gogo'}
# print(d.get('aa','nofind'))


# #----------------------------------ll = l.strip()-----出去字符串首尾的空格
# l = '       wdwd dsd d'
# print(l)
# ll = l.strip()
# print(ll)


# # ---------------------------------ll = l.split(' ')--------拆分字符串
# l = ['python', 'has', 'a', 'good', 'learning']
# l = ' '.join(l)
# print(l)
# ll = l.split(' ')
# print(ll)


# # --------------------------------l.replace('good', 'excending')---批量替代字符串中的元素
# l = ['python', 'has', 'a', 'good', 'learning']
# l = ' '.join(l)
# print(l)
# m = l.replace('good', 'excending')
# print(l)
# print(m)


# #-------------------------------------表示只包含一个元素的元组
# t = (1,)
# print(type(t))
# k = (1)
# print(type(k))


# # ----------------l.reverse() 或切片的方法 l[::-1]返回一个新列表----让列表按相反顺序排列
# l = ['python', 'has', 'a', 'good', 'learning']
# print(l)
# l.reverse()
# print(l)
# ll = l[::-1]
# print(ll)


# # --------------------------------------------- pop(1),del l[1]------删除列表中的元素
# l = ['python', 'has', 'a', 'good', 'learning']
# print(l)
# l.pop(1)
# print(l)
# del l[1]
# print(l)


# # ------------------------------insert('a') 或切片的方式--------插入到列表
# l = ['python', 'has', 'a', 'good', 'learning']
# n = [2, 3]
# l.insert(2, n)  # 将n 看做一个元素
# print(l)
# l[2:2] = n      # n里的元素插入l
# print(l)


# # # ----------------------------extend(), append()---------列表末尾加入其它元素
# l = ['python', 'has', 'a', 'good', 'learning']
# l.extend('kk')  # 加入单个字符
# n = [2, 3, 4]
# l.extend(n)     # 列表加入到列表中
# l.append('MM')  # 加入字符串
# l.append(n)     # 列表作为元素
# print(l)


# # --------------------------- count('a)--------计算字符串在列表中出现的次数
# l = ['python', 'has', 'a', 'good', 'learning', 'a']
# print(l.count('a'))


# # ----------------------------------- clearn()-----------清空列表
# l = ['python', 'has', 'a', 'good', 'learning']
# l.clear()
# print(l)

# # -----------------------------------l.strip()-----去除字符串首的空格
# l = '      nihao wo zai'

# print(l.strip())


# # -------------------  title()--------------字符串首字母大写
# k = 'hduh id display'
# print(k.title())       #title()


# # ---------------------------------------在字符串中找到子串  find('i')
# k = 'python is a strong language'
# print(k.find('i'))
# print(k.find('python'))  # 返回首个字符的索引


# # -----------------------------------字符串居中 center(50)
# k = '这是一句要居中的文字'
# print(k.center(50))
# print(k.center(50, '*'))


# # ---------------------------------快速打印英文字母 string.ascii_letters
# import string
# print(string.ascii_letters)


# # -----------------------------将列表转化为字符串 ' '.join(l)
# l = ['python','has','a','good','learning']
# print(l)
# print(' '.join(l))


# print(2**3)
# print(pow(2, 3))
# l = (1,2,4,2,5,1)
# print(max(l),min(l))
