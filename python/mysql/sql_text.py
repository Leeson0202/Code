from My_SQL import MySQLConnection
import pymysql
import json


# def begin():
#     return MySQLConnection(host="192.168.43.251", port=3306, user="root",
#                            password="Zhw626938.", database="youdian")
def begin():
    return MySQLConnection(host="localhost", port=3306, user="root",
                           password="123456", database="dictionary")


cursor = begin()
with open(r'E:\Code\TeamPrj\datas\json\a.json', 'r') as fp:
    content = json.load(fp)

# for i in range(5):
#     print(content[i])


for i in content:
    sentence = ';'.join(
        ["{}:{}".format(x, y) for x in i['sentence'].keys() for y in i['sentence'].values()]
    )
    if  not i['tag']:
        i['tag'] = '不常用'
    # print(sentense)
    sql = """insert into word values(0,"{}","{}","{}","{}");""".format(pymysql.escape_string(i['spell']),
                                                                         pymysql.escape_string(i['tag']),
                                                                         pymysql.escape_string(''.join(i['clearfix'])),
                                                                         pymysql.escape_string(sentence))
    cursor.insert(sql)





# from pymysql import *

# class student():
#     def __init__(self):
#         self.conn = connect(host='localhost', port=3306, user='root',
#                             password='123456', charset='utf8', database='shang')
#         self.cursor = self.conn.cursor()

#     @classmethod
#     def printall(self, list):
#         for i in list:
#             print(i)

#     def detail(self, content):
#         self.cursor.execute(content)
#         con = self.cursor.fetchall()
#         self.printall(con)
#         pass

#     @classmethod
#     def meau(self):
#         print(
#             """
# 1.所有商品名字    2.所有商品类型名字
# 3.名字和类型的关联显示    4.退出
# """)
#         return eval(input())

#     def run(self):
#         try:
#             while True:
#                 num = self.meau()
#                 contents = ['', 'select id,name from goods', 'select * from goodcates',
#                             'select g.name,c.name from goods as g inner join goodcates as c on g.category_id=c.id ']
#                 self.detail(contents[num])
#         except Exception as ex:
#             print(ex)
#         finally:
#             self.cursor.close()
#             self.conn.close()


# stu = student()
# stu.run()


# -------------------------------------------------task 1
#
# from pymysql import *
# conn = connect(host='localhost', port=3306, user='root', password='123456', charset='utf8')
# cursor=conn.cursor()

# cursor.execute('use shang;')

# while True:
#     print("""
#     1. 按照类型排序     2.直接输出商品
#     3. 只输出商品类型   4.商品和商品类型一起输出
#     5. 退出""")
#     key = eval(input('请输入：'))
#     if key == 1:
#         cursor.execute('select c.name,group_concat(g.name) from goods as g inner join goodcates as c on g.category_id=c.id group by c.name;')
#         count=cursor.fetchall()
#         for i in count:
#             print(i)

#     if key == 2:
#         cursor.execute('select * from goods;')
#         count=cursor.fetchall()
#         for i in count:
#             print(i)

#     if key==3:
#         cursor.execute('select * from goodcates;')
#         count=cursor.fetchall()
#         for i in count:
#             print(i)


#     if key==4:
#         cursor.execute('select g.id,g.name,c.name from goods as g inner join goodcates as c on g.category_id=c.id;')
#         count=cursor.fetchall()
#         for i in count:
#             print(i)
#     if key==5:
#         exit()
# cursor.close()
# conn.close()
