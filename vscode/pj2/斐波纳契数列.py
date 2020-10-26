def fbn(length):   #------当函数有 yield 时就不是函数，相当于一个生成器
    a,b = 0,1
    n = 0
    while(n<length):
        yield b  #相当于return b 加 暂停 功能
        a,b = b,a+b
        n+=1

def get(length):
    g = fbn(length)
    for i in range(length-1):
        next(g)
    return next(g)

print(get(eval(input('请输入你需要的地第几个数：'))))


