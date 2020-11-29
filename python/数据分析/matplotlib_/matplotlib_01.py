import matplotlib.pyplot as plt
import random
import matplotlib
from matplotlib import font_manager
"""
figure(figsize = (20, 10), dpi=80)

中间设置

polt(x,y)
polt.show()

"""



x = range(2, 26, 2)
y = [15, 13, 14.5, 17, 20, 25, 26, 26, 24, 22, 18, 15]

x_in = [x / 2 for x in range(0, 50)]
x_in_word = ['11日 {}'.format(i) for i in range(2, 26, 2)]

font = {'family': 'Microsoft YaHei',
        'weight': 'bold'}
matplotlib.rc('font', **font)
# font_manager.f('font', **font)

plt.figure(figsize=(20, 10), dpi=80)  # 设置图片大小


plt.xticks(x, x_in_word[::], rotation=270)  # 设置x轴的刻度  列表类型 rotation = 270 逆时针旋转270度
""" 
Examples
    --------
    >>> locs, labels = xticks()  # Get the current locations and labels.
    >>> xticks(np.arange(0, 1, step=0.2))  # Set label locations.
    >>> xticks(np.arange(3), ['Tom', 'Dick', 'Sue'])  # Set text labels.
    >>> xticks([0, 1, 2], ['January', 'February', 'March'],
    ...        rotation=20)  # Set text labels and properties.
    >>> xticks([])  # Disable xticks.
    """

plt.plot(x, y)  # 绘图
# plt.savefig('sig_sig.svg')  # 保存为 svg格式的图片
plt.show()
