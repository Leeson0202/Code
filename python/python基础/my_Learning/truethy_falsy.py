# truethy and falsy
# bool()函数 只有True 和 False 只有 None、0 、""、()、[]、{} 为 False
print("\n")

print(bool(-1))  # true
print(bool(""))  # False
print(bool([]))  # False
print(bool(None))  # False

if 1 > 0:
    print(True)
else:
    print(False)


print("\n")