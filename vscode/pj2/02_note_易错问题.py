






# print('======================================random 随机数函数')
# random()           生成一个[0.0, 1.0] 的随机小数
# randint(a,b)       生成一个[a,b] 的整数
# rangrange(a,b,c)   生成一个[a,b) 之间以c为步长的随机整数
# uniform(a,b)       生成一个[a,b] 之间的小数
# choice([1,2,4,5,6,3,8,10])  从seq在随机选择一个元素
# shuffle([2,3,1,6]) 打乱seq中的元素并返回
# import random
# print(random.random())




# print('========================================lambda 匿名函数')
# # lambda函数看起来只能写一行
# sum = lambda arg1, arg2: arg1 + arg2
# # 调用sum函数
# print ("相加后的值为 : ", sum( 10, 20 ))  #相加后的值为 :  30
# print ("相加后的值为 : ", sum( 20, 20 ))  #相加后的值为 :  40



# print('========================================函数参数的传递')
# # 加了星号 * 的参数会以  元组(tuple)的形式导入，存放所有未命名的变量参数。
# def printinfo( arg1, *vartuple ):
# #    "打印任何传入的参数"
#    print ("输出: ")
#    print (arg1)
#    for var in vartuple:
#       print (var)
#    return

# # 调用printinfo 函数
# printinfo( 10 )
# printinfo( 70, 60, 50 )

# # 加了两个星号 ** 的参数会以  字典的形式导入
# def printinfo( arg1, **vardict ):
# #    "打印任何传入的参数"
#    print ("输出: ")
#    print (arg1)
#    print (vardict)

# # 调用printinfo 函数
# printinfo(1, a=2,b=3)


# print('=======================================迭代器和生成器')
# # 迭代器  对象从集合的第一个元素开始访问，直到所有的元素被访问完结束
# # 迭代器的  iter()   和   next()
# list = [1,2,3,4]
# it = iter(list)
# for i in it:
#     print(i,end = ' ')

# # 生成器  是一个返回迭代器的函数，只能用于迭代操作，更简单点理解生成器就是一个迭代器
# import sys
# def fibonacci(n): # 生成器函数 - 斐波那契
#     a, b, counter = 0, 1, 0
#     while True:
#         if (counter > n):
#             return
#         yield a
#         a, b = b, a + b
#         counter += 1
# f = fibonacci(10) # f 是一个迭代器，由生成器返回生成

# while True:
#     try:
#         print (next(f), end=" ")
#     except StopIteration:
#         sys.exit()



# print('===========================================time 模块')

# import time

# y = True
# while(y):  #实时演示时间
#     t = time.localtime()  #获取当地时间
#     tt = time.strftime("%Y-%m-%d %H:%M:%S",t)   #格式化日期
#     print('\r',tt,end = '')
#     time.sleep(0.1)      # 推迟 0.1秒


# %Y 年份    %m 月份    %B 月份名称    %b 月份名称缩写   %d 日期
# %A 星期    %a 星期缩写
# %H 24小时制   %h 12小时制    %p 上/下午   %M 分钟    %S 秒



# --------------------------------format()方法格式化
# {1:*^2.3f}.format(float)
#  1  表示 后面format的下标
#  *  表示 填充物
#  ^  表示 居中
#  2  表示 站位
#  .3 表示 保留三位小时
#  f  表示 float 类型
