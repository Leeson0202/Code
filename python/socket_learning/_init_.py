import socket

# 创建一个套接字 socket.AF_INET表示使用ipv4,SOCK_STREAM表示使用TCP协议
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 创建一个套接字 socket.AF_INET表示使用ipv4,SOCK_DGRAM表示使用UDP协议
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


s.close()  # 关闭套接字
