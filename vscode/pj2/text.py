import sys
print(sys.path)



# # --------------------------------------------------------------------线程的传参
# import threading
# import time


# def count(a, b):          # 随便写参数
#     for i in range(5):
#         print('----1', a)
#         a += b
#         time.sleep(1)


# def sum():
#     for i in range(5):
#         print('--2', i)
#         time.sleep(3)


# def main():
#     t1 = threading.Thread(target=count, args=(3, 1))  # args = (参数)
#     t2 = threading.Thread(target=sum)
#     t1.start()
#     t2.start()
#     # print(len(threading.enumerate()))     #显示进程


# if __name__ == '__main__':
#     main()
#     print(time.localtime())

# # ---------------------------------------------------------------------线程
# import time
# import datetime
# import _thread

# date_time_format = '%H:%M:%S'

# def get_time_str():       # 获取时间字符串
#     now = datetime.datetime.now()
#     return datetime.datetime.strftime(now,date_time_format)

# def thread_func(thread_id):  #子进程
#     print('Thread %d\t start at %s'%(thread_id,get_time_str()))
#     print("Thread %d\t sleeping"%thread_id)
#     time.sleep(4)
#     print("Thread %d\t finish at %s"%(thread_id,get_time_str()))

# def main():          #进入主函数
#     print("Main thread start at %s"%get_time_str())
#     for i in range(8):
#         _thread.start_new_thread(thread_func,(i,))
#         time.sleep(1)
#     time.sleep(12)
#     print("Main thread finish at %s"%get_time_str())

# if __name__ == '__main__':
#     main()


# # ---------------------------------------------------------------类的初始化
# class Phone:
#     def __init__(self,Name):
#         print('初始化')
#         self.name = Name
#     def getname(self):
#         print("手机的牌子是",self.name)
#     def getprice(self,price):
#         self.price = price
#         if price >5000:
#             print('是高端机')
#         else:
#             print('是低端机')

# huawei = Phone('huawei')  #直接执行__init__()
# huawei.getname()

# huawei.getprice(300)
# print(huawei.price)

# huawei.getprice(5300)
# print(huawei.price)


# ---------------------------------------------------------斐波纳契数列 生成器

# def fbn(length):   #------当函数有 yield 时就不是函数，相当于一个生成器
#     a,b = 0,1
#     n = 0
#     while(n<length):
#         yield b  #相当于return b 加 暂停 功能
#         a,b = b,a+b
#         n+=1

# def get(length):
#     g = fbn(length)
#     for i in range(length-1):
#         next(g)
#     return next(g)

# print(get(eval(input('请输入你需要的地第几个数：'))))


# # ----------------------------------------------------------迭代器
# list = [1,3,4,5,6,74,3,2,2]

# g = iter(list)
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))


# # ----------------------------------------------------------列表表达式
# list1 = [2,3,5,6,2,75,1,34,65,2,23]
# print([k+1 for k in list1])
# print([k for k in list1 if k> 10])
# print([k + 10 if k>=10 else k+20 for k in list1])


# #----------------------------------------------------------map  函数
# list1 = [2, 34, 53, 1]
# res = map(lambda x: x+1, list1)
# print(list(res))


# # #======================================================复制文件及文件夹

# import os

# def copy(scr,target):
#     if os.path.isdir(scr):                          #判断地址是否为文件夹
#         dirname,file = os.path.split(scr)           #拆分文件目录及文件名
#         new_path2 = os.path.join(target,file)       #在目标文件夹也创建新文件夹
#         if not os.path.exists(new_path2):
#             os.mkdir(new_path2)
#         file_list = os.listdir(scr)                 #获取文件夹下的文件列表
#         for file in file_list:                      #依次复制文件
#             new_path1 = os.path.join(scr,file)      #获取当前文件的地址
#             copy(new_path1,new_path2)               #将当前文件复制给目标地址
#     else:
#         with open(scr,'rb') as stream:          #打开当前文件
#             container = stream.read()           #获取当前文件的内容
#             dirname,file = os.path.split(scr)   #拆分文件目录及文件名
#             path1 = os.path.join(target,file)   #获取目标表地址
#             with open(path1,'wb') as nstream:   #创建新文件
#                 nstream.write(container)        #将原文件内容复制到新文件中
#     return True

# scr_path = 'e:\p1\\aa.txt'
# target_path = 'e:\p2'

# if(copy(scr_path,target_path)): print('复制成功')


# ====================================================文件操作
# import os

# container = open('word.txt', 'r')  # 返回值为一个流对象 stream
# # print(container.read())
# print(container.readlines())
# container.close()

# # stream = open('word.txt','w')
# # stream.write('njncj\n')
# # stream.write('njncj\n')
# # stream.close()


# #----------------------------------------------------装饰器

# def decorate1(func): # func 为传进来的原函数
#     print('-------> 1 装饰器开始')
#     def waspper(*a,**b):
#         print('------ 1 装饰器内部------')
#         func(*a,**b)      #调用原函数
#     print('----------> 1 装饰器结束')
#     return waspper  # 返回内部装饰器

# def decorate2(func): # func 为传进来的原函数
#     print('-------> 2 装饰器开始')
#     def waspper(*a,**b):
#         print('------ 2 装饰器内部------')
#         func(*a,**b)      #调用原函数
#     print('----------> 2 装饰器结束')
#     return waspper  # 返回内部装饰器

# @decorate2   #装饰器定义
# @decorate1   # 谁近先装谁
# def f1(a,b):  #此时 f1 相当于 waspper
#     print('------外部函数------')
#     print('--{}--{}--'.format(a,b))

# f1(1,3)
# list = [1,2,4]
# list.sort()


# -----------------------------------------------------函数的应用
# import random

# def ff(k):
#     list = []
#     for i in range(k):
#         temp = random.randint(1,20)
#         list.append(temp)
#     return list

# def showlist(list):
#     if list:
#         index = 0
#         for i in list:
#             print(i,end = '\t')
#             index +=1
#             if not index%10  :
#                 print()

# def sort(list):
#     list.sort()
#     return list

# # def quick_sort(s,l, r ):   #                        快速排序
# #     if (l < r):
# #         i = l; j = r; x = s[l];
# #         while (i < j):
# #             while(i < j and s[j] <= x): # 从右向左找第一个小于x的数
# #                 j -= 1
# #             if(s[j] > x):
# #                 temp = s[i]
# #                 s[i] = s[j]
# #                 s[j] = temp

# #             while(i < j and s[i] >= x): # 从左向右找第一个大于等于x的数
# #                 i +=1
# #             if(s[i] < x):
# #                 temp = s[i]
# #                 s[i] = s[j]
# #                 s[j] = temp
# #         quick_sort(s, l, i - 1) # 递归调用
# #         quick_sort(s, i + 1, r)
# #     return s

# n = eval(input('请输入个数：'))
# list = ff(n)
# showlist(list)
# list = sort(list)
# showlist(list)
# # list = quick_sort(list,0,len(list)-1)
# list = qu(list,0,len(list)-1)
# showlist(list)


# ------------------------------------------文件操作
# f = open(tt,'w')
# lines = []
# try:
#     if 1:
#         for i in range(5):
#             lines.append(input('请输入第 {} 行的语句：'.format(i+1)))
#             f.write(str(lines[i]))
# # except:
# #     pass
# f = open('01_note_python.py' ,'r')
# for i in range(5):
#     print(f.readline())
# f.close()


# class Animal:
#     def __init__(self):
#         self.age = 3
#     def say(self):
#         print("Animal")

# class Dog(Animal):
#     def say(self):
#         print('Dog')

# class Cat(Animal):
#     def say(self):
#         print('Cat')

# dog = Dog()
# cat = Cat()

# print(dog.age)
# print(cat.age)

# dog.age = 4
# print(dog.age)
# print(cat.age)

# Animal.age = 10
# print(dog.age)
# print(cat.age)


# import  time
# for i in range(300):
#     tt = time.localtime()
#     t = time.strftime("%Y-%m-%d %H:%M:%S",tt)
#     print('\r',t,end = '')
#     time.sleep(0.2)
