from pymysql import *
conn = connect(host='localhost', port=3306, user='root', password='123456', charset='utf8')
cursor=conn.cursor()

cursor.execute('use shang;')

while True:
    print("""
    1. 按照类型排序     2.直接输出商品
    3. 只输出商品类型   4.商品和商品类型一起输出
    5. 退出""")
    key = eval(input('请输入：'))
    if key == 1:
        cursor.execute('select c.name,group_concat(g.name) from goods as g inner join goodcates as c on g.category_id=c.id group by c.name;')
        count=cursor.fetchall()
        for i in count:
            print(i)

    if key == 2:
        cursor.execute('select * from goods;')
        count=cursor.fetchall()
        for i in count:
            print(i)
        
    if key==3:
        cursor.execute('select * from goodcates;')
        count=cursor.fetchall()
        for i in count:
            print(i)
        

    if key==4:
        cursor.execute('select g.id,g.name,c.name from goods as g inner join goodcates as c on g.category_id=c.id;')
        count=cursor.fetchall()
        for i in count:
            print(i)
    if key==5:
        exit()
cursor.close()
conn.close()
