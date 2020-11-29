import pandas as pd
import numpy as np

s = pd.Series([1,3,6,np.nan,4]) # np.nan 表示空

k = pd.Series([1, 2, 3, 4], index=list('asdf'))
print(k)
temp_dict = {'name': 'xiaohong', 'age': 18, 'tel': 10086}
temp = pd.Series(temp_dict)
print(temp)
