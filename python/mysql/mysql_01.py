
from pymysql import *

# 打开数据库链接，不加端口号链接 创建一个connection类
conn = connect(host="192.168.43.251", port=3306, user="root",
               password="Zhw626938",  charset='utf8') # database="dictionary",
# 使用数据库连接对象的cursor()方法创建一个游标对象 cursor
cursor = conn.cursor()
# ---------------------------------开始


# 使用游标对象的execute()方法执行SQL语句
cursor.execute("show databases;")
# cursor.execute("select * from word_a;")

# 使用游标对象的fetchone()方法获取单条数据（元组）
# print(cursor.fetchone())
# print(cursor.fetchone())
# print(cursor.fetchone())

# 使用游标对象的fetchmany()方法获取n条数据（元组）
# print(cursor.fetchmany(3))

# 使用游标对象的fetchall()方法获取所有数据（元组）
count = cursor.fetchall()
for i in count:
    # print("{:^3}{:^3}{:^10}{:^10}{:^10}".format(i[0], i[1], i[2], i[3], i[4]))
    print(i)
# print(f"Database version:{data}")


# ------------------------------------------结束
# 关闭游标
cursor.close()
# 关闭数据库链接
conn.close()
