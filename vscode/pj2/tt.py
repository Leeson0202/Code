import hashlib

message = "基础教学 jichujiaoxue"
k1 = message.encode()
k2 = k1.decode()
print('k1 =',k1,'\n','k2 =',k2)
# md5 = hashlib.md5(message.encode())
# print("%s\n%s"%(message,md5.hexdigest()))