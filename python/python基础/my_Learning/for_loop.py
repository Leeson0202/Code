# range()函数 实际是一个类
for i in range(5):  # 表示0 1 2 3 4 5
    print(i)
print("\n")
# 相当于
lst = [0, 1, 2, 3, 4]  # lst 被定义为列表
for i in lst:
    print(i)
print("\n")

for i in range(1, 5):  # 1 2 3 4
    print(i)
print("\n")
for i in range(0, 10, 3):  # 0 3 6 9
    print(i)
print("\n")

# for 累加
sum = 0
a, b = 1, 20
for num in range(a, b+1, 2):
    sum += num

print(sum)

# for 阶乘
sum = 1
a, b = 1, 10
for num in range(a, b+1):
    sum *= num

print(sum)
