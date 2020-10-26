
day_week = 3
print("星期一  星期二  星期三  星期四  星期五  星期六  星期日  ")

for k in range(1,day_week):
    print("      ",end = "  ")
for i in range(1,32):
    if (i+day_week-1) % 7 == 0:
        print(i)
    else:
        print(i, end = "\t") 

