

stream = open('./text.py','rB')
print(stream.read())
stream.close()




# # ===================================================数码管  打印时间

# import turtle as t
# import time

# def drawline(draw):
#     t.pendown() if draw else t.penup()
#     t.fd(40)
#     t.right(90)

# def drawdigit(digit):
#     drawline(True) if digit in [2,3,4,5,6,8,9] else drawline(False)
#     drawline(True) if digit in [0,1,3,4,5,6,7,8,9] else drawline(False)
#     drawline(True) if digit in [0,2,3,5,6,8,9] else drawline(False)
#     drawline(True) if digit in [0,2,6,8] else drawline(False)
#     t.left(90)
#     drawline(True) if digit in [0,4,5,6,8,9] else drawline(False)
#     drawline(True) if digit in [0,2,3,5,6,7,8,9] else drawline(False)
#     drawline(True) if digit in [0,1,2,3,4,7,8,9] else drawline(False)
#     t.right(180)

# def getdigit():
#     timelist = time.localtime()
#     nowtime = time.strftime('%Y%m%d%H%M%S',timelist)
#     start = -400
#     for i,digit in enumerate(nowtime):
#         t.penup()
#         t.goto(start+i*60,0)
#         drawdigit(eval(digit))

# t.speed(20)
# t.setup(1000,600,400,0)
# t.pensize(5)
# t.pencolor('#000000')
# getdigit()
# t.done()


# #==============================================数

# def f(n):
#     if(n == 1 or n == 2):
#         return 1
#     else:
#         return f(n-1) + f(n-2)

# def fun(m,n):
#     for i in range(m,0,-1):
#         if(m%i == 0 and n%i == 0):
#             return i

# s = input('输入两个数用逗号隔开：')
# m = s.split(',')
# for i in m:
#     if eval(i) == 0:
#         print('输入错误！')
#         exit(0)
# j = f(eval(m[0]))
# k = f(eval(m[1]))

# print(j,'\t',k)
# print('最大公因数为',fun(j,k))



#================================================输入一段数组2,3,4 计数他们的乘积
# def cmul(s):
#     m = s.split(',')
#     result = 1
#     for i in m:
#         result *= eval(i)
#     return result

# print(eval("cmul('{}')".format(input())))


# def cmul(*s):
#     result =1
#     for i in s:
#         result *= i
#     return result

# print(eval("cmul({})".format(input())))


# #===============================================海归库-画-表情
# import  turtle

# def hs(pen,x,y,r,cir = 360):
#     pen.up()
#     pen.goto(x,y)
#     pen.down()
#     pen.begin_fill()
#     pen.circle(r,cir)
#     pen.end_fill()

# def cir(pen,x,y,r,cir = 360):
#     pen.up()
#     pen.goto(x,y)
#     pen.down()
#     pen.circle(r,cir)

# pen = turtle
# pen.setup(1200,700,200,20)
# pen.pencolor("#E49E2D")
# pen.pensize(15)
# pen.speed(100)

# #----------------------------画边框
# pen.right(60)             # 下半部分
# pen.fillcolor("#FFD83F")
# hs(pen,-216,-125,250,cir = 120)

# pen.fillcolor("#FFD950")   # 中间部分1
# pen.begin_fill()
# pen.circle(250,30)
# pen.left(180)
# cir(pen,-250,0,250,30)
# pen.end_fill()

# pen.fillcolor("#FFD950")   # 中间部分2
# pen.left(150)
# pen.up()
# pen.goto(250,0)
# pen.down()
# pen.begin_fill()
# pen.circle(250,30)
# pen.left(120)
# cir(pen,-216,125,250,30)
# pen.end_fill()

# pen.fillcolor("#FAD664")    # 上半部分
# pen.right(150)
# hs(pen,216,125,250,120)

# #-------------------------------------画嘴巴
# pen.left(120)
# pen.pensize(15)
# pen.pencolor("#D0530C")
# cir(pen,0,-207,207,80)
# pen.right(80)
# cir(pen,0,-207,207,-80)

# #------------------------------小红腮
# pen.pensize(1)
# pen.pencolor("#FFDC5C")
# pen.fillcolor("#FECE60")
# hs(pen,-230,45,70)
# hs(pen,85,45,70)

# pen.pencolor("#FECE60")
# pen.fillcolor("#FDC663")
# hs(pen,-215,45,55)
# hs(pen,102,45,55)

# pen.pencolor("#FDC663")
# pen.fillcolor("#FBBC67")
# hs(pen,-202,45,42)
# hs(pen,115,45,42)

# #--------------------------左眼眶部分
# pen.fillcolor("#FDFBFA")
# pen.pencolor("#D2975C")
# pen.pensize(10)
# pen.left(50)
# pen.up()                # 左眼眶右
# pen.goto(-70,60)
# pen.down()
# pen.begin_fill()
# pen.circle(33,170)
# pen.fd(5)

# pen.left(4)             # 左眼眶上
# pen.fd(5)
# pen.circle(135,70)
# pen.fd(10)

# pen.circle(35,155)      # 左眼眶左
# pen.circle(100,6)
# pen.fd(5)

# pen.left(12)            # 左眼眶下
# pen.circle(-110,45)
# pen.fd(15)
# pen.circle(33,5)
# pen.end_fill()

# #--------------------------右眼眶部分
# pen.right(20)
# pen.up()                  # 右眼眶右
# pen.goto(160,60)
# pen.down()
# pen.begin_fill()
# pen.circle(33,170)
# pen.fd(10)

# pen.left(4)               # 右眼眶上
# pen.circle(135,70)
# pen.fd(10)

# pen.circle(35,155)        # 右眼眶左
# pen.circle(100,6)
# pen.fd(5)

# pen.left(12)              # 右眼眶下
# pen.circle(-110,45)
# pen.fd(15)
# pen.circle(33,5)
# pen.end_fill()

# #-------------------------------眼珠
# pen.pencolor("#6E411E")
# pen.fillcolor("#6E411E")
# hs(pen,-186,70,20)
# hs(pen,45,75,20)

# pen.done()


# #-------------------------------------------turtle 海归库
# import  turtle
# import  math
# import time

# def five(pen,a,b):
#     pen.up()
#     pen.goto(a,b)
#     pen.down()
#     pen.forward(169)
#     for i in range(5):
#         pen.right(144)
#         pen.fd(338)

# def circle(pen,a,b,k):
#     list=["#1823cd","#000000","#cd1840","#eef033","#37f033"]
#     pen.pensize(8)
#     pen.pencolor(list[k])
#     pen.up()
#     pen.goto(a,b)
#     pen.down()
#     pen.circle(37,360)

# pen =  turtle
# pen.setup(1200,700,200,20)
# pen.bgcolor("#B0E2FF")
# pen.pencolor("#CD5C5C")
# pen.fillcolor("#CD5C5C")
# pen.speed(5)
# pen.begin_fill()
# five(pen,0,55)
# time.sleep(1)
# pen.right(90)
# five(pen,55,0)
# pen.right(180)
# five(pen,-55,0)
# pen.left(90)
# five(pen,0,-55)
# pen.end_fill()

# circle(pen,200,200,0)
# circle(pen,285,200,1)
# circle(pen,370,200,2)
# circle(pen,242,160,3)
# circle(pen,327,160,4)

# pen.done()


#------------------------------------------------enumerate() 函数
# s = [2,4,5,6,3]
# for index ,i in enumerate(s):
#     print(i,index)

##---------------------------------------------------文件操作
# file_path = 'my_file.txt'
# try:
#     file = open(file_path,'w')
#     for i in range(4):
#         rr =input("请输入：")
#         file.write(rr)
#     file.close()
# finally:
#     file = open(file_path,'r')
#     print(file.readlines())
#     file.close()



# #-------------------------------------------------------jieba库
# import  jieba
# print(jieba.lcut(input('请输入一句话：'),all_cut = True))



# #--------------------------------------------------列表元组的 数学应用
# import math

# in_num = []
# in_sum = 0      #总数
# au = 0;         #方差的上部分和
# try:
#     while 1:
#         a = eval(input("请输入："))
#         in_num.append(a)
#         len = in_num.__len__()
#         in_sum += a
#         ave = in_sum/len
#         in_num.sort()
#     for a in in_num:
#         au += (a-ave)**2
#     if(len%2):
#         zhong = in_num[int(len/2)]
#     else:
#         zhong = ( in_num[math.floor(len/2)] + in_num[math.ceil(len/2)])/2
# except:
#     pass
# finally:
#     print("{:^6}{:^6}{:^6}{:^8}{:^8}{:^20}".format('个数','总和','平均值','方差','中位数','排列后'))
#     print("{:^8d}{:^8d}{:^10.3f}{:^10.3f}{:^10.3f}".format(len,in_sum,ave,au/len,zhong),in_num)




# #----------------------------------------------------类的使用

# class dog:
#     def __init__(self, name):
#         self.__name = name
#     def play(self):
#         print(self.__name)

# Dog = dog('旺旺')
# Dog.play()
# Dog.__name = '百度'
# print(Dog.__name)




# #-----------------------------------------------------猜数游戏
# import  random
# num = random.randrange(1,10,1)
# for i in range(5):
#     g_num = eval(input('输入你猜的数字：'))
#     if(g_num<num):
#         print('猜小了')
#     elif(g_num>num):
#         print('猜大了')
#     else:
#         print('你好棒')
#         break;
# else:
#     print('你好笨')





# #--------------------------------------------------- 产生随机数
# import random
# for i in range(4):
#     t = random.randrange(0,62,1)
#     if(t<10):
#         print(t, end = '')
#     elif(t<36):             #10-35
#         print(chr(t+55),end = '')
#     else:                   #36-61
#         print(chr(t+61),end = '')



# #--------------------------------------------------九九乘法表
# for i in range(1,10):
#     for j in range(1,i+1):
#         print("{}*{}={:<2d}".format(j,i,i*j),end =' ')
#     print('')



# #-------------------------------------------------身体质量指数
# bb = ['偏瘦','正常','偏胖','肥胖']
# height = input("请输入身高(m): ")
# weight = input("请输入体重(kg): ")
# try:
#     h = eval(height)
#     w = eval(weight)
# except:
#     print("输入错误")
#     exit()

# BMI = w/(h**2)
# print("BMI = {:.4f}".format(BMI),"\n国际标准：",end = '')
# if(BMI>=30):
#     print(bb[3])
# elif(BMI>=25):
#     print(bb[2])
# elif(BMI>=18.5):
#     print(bb[1])
# else:
#     print(bb[0])

# print("国内标准：",end = '')
# if(BMI>=28):
#     print(bb[3])
# elif(BMI>=24):
#     print(bb[2])
# elif(BMI>=18.5):
#     print(bb[1])
# else:
#     print(bb[0])



# #------------------------------------------------进度条——时间问题
# #-- 100% ■■■■■■■■■■■■■■■■■■■■    2.01s

# import time

# long = 20
# time_start = time.time()
# for i in range(long+1):
#     did = '■'*i
#     no = '□'*(long-i)
#     percent = (i/long)*100
#     time_end = time.time()
#     print('\r   {:<3.0f}% {}{}   {:5.2f}s'.format(percent,did,no,time_end-time_start),end= ' ')
#     time.sleep(0.1)


#-----------------------------------------------------货币转换

# in_number = input("请输入你接收的货币(例RMB123):")
# if in_number[0:3] in ['RMB']:
#     out = (eval(in_number[3:])/6.78)
#     print("USD{:.2f}".format(out))

# else:
#     out = (eval(in_number[3:])*6.78)
#     print("RMB{:.2f}".format(out))





#------------------------------------------------------输出
#                ----------
#                ----**----
#                ---****---
#                --******--
#                -********-
# ii = '*'
# for i in range(5):
#     kk = ii*2*i
#     print(kk.center(10,'-'))





#-----------------------------------------------------五子棋棋盘

# arange = []
# for i in range(19):
#     arange.append([])
#     for j in range(19):
#         if (i == 0 and j== 0):
#             arange[i].append("┌")
#         elif (i == 0 and j== 18):
#             arange[i].append("┐")
#         elif (i == 18 and j== 18):
#             arange[i].append("┘")
#         elif (i == 18 and j== 0):
#             arange[i].append("└")
#         elif (i == 0 or i== 18):
#             arange[i].append("─")
#         elif (j == 18 or j== 0):
#             arange[i].append("│")
#         else:
#             arange[i].append("╋")


#-------------------------------------输入数字对应输出 星期几

# for i in range(19):
#     print('\n\t')
#     # arange.append([])
#     for j in range(19):
#         print(arange[i][j],end = '    ')


#      星期几判断
# xinqi = '星期一星期二星期三星期四星期五星期六星期日'
# day = eval(input('请输入数字（1-7):'))
# print('{}'.format(xinqi[(day-1)*3:(day-1)*3+3]))



#-----------------------------------------------工作效率 365
# k = 1
# for i in range(1,365,1):
#     if(i%7<6 and i%7 != 0 ):
#         k*=1.01
#         print('{:.2f}'.format(k),end = ' ')
#     else:
#         k*=0.99
#         print('{:.2f}'.format(k),end = ' ')
#     if(i%7 == 0):
#         print('\n')

