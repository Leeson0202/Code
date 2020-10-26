# 控制台进度条
# \r 回到行首
import time
start_time = time.time()
for i in range(100):
    real_side = "■"* i
    free_side = "□"* (100-i)
    currt_time = time.time()
    print("\r{:>3d}% ".format(i+1)+"[{}{}] 耗时：{:.1f}s".format(real_side,free_side,currt_time-start_time),end = "")
    time.sleep(0.1)
    

