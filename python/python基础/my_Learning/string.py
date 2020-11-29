# len()长度 
number = 4
print(len("hello world"))  #len()返回字符串长度
print('\t\\\n numeber') #/t  //  /n
print( 'C:\nnumber')  # 访问文件时，此处\n有效果
print( 'C:\\nnumber')  # 此处\n无效果
print( r'C:\nnumber') # r 可访问文件 \n无效果

print("""  """)#中间随便加 样式不变
print("""
line1
line2
line3
line4""")  #想几行就几行

line1 = "abc"
line2 = "def"
print(line1 + line2)  #直接将两个字符串并接
print(line1 * 3) #将line1重复3遍
