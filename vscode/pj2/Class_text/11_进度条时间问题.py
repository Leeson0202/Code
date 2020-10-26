
#     进度条——时间问题

import time

long = 30
time_start = time.time()
for i in range(long+1):
    did = '■'*i
    no = '□'*(long-i)
    percent = (i/long)*100
    time_end = time.time()
    print('\r {:<3.0f}% {}{} {:5.2f}s'.format(percent,did,no,time_end-time_start),end= ' ')
    time.sleep(0.1)



