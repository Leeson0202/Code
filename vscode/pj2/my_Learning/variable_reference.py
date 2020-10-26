#id() 返回变量的地址
x = 10
y = x

print(id(x))
print(id(y))

x = 20    # x的地址改变 y没改变
print(id(x)) 
print(id(y))

a = [10]
b = a
print(a)
print(id(a[0]))
print(id(b[0]))
a[0] = 20 

print(a[0])
print(b[0])
print(id(a[0]))
print(id(b[0]))