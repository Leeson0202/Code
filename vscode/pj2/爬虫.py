from urllib.request import *

file = urlopen("https://www.icourse163.org/")
dataline = file.readlines()
print(data.decode())
