import numpy as np

array = np.array([[1, 2, 3, 5],
                  [2, 3, 4, 6],
                  [3, 4, 5, 7],
                  [2, 3, 5, 5]], dtype=np.int)
# dtype = np.int 数据类型定义为int

print(array.max(axis=0))
print(array.min(axis=1))



# print(array<3)
# print(array)
# print(array.ndim)  # array.ndim  # 几维  正方形数组 2维
# print(array.shape)  # array.shape  形状
# print(array.size)  # array.size 元素的个数
