import matplotlib.pyplot as plot
import matplotlib

y = [1, 2, 1, 1, 1, 0, 1, 0, 3, 2, 1, 2, 3, 1, 2]
x = range(10, 25)
x_in = ['{}岁-'.format(i) for i in x]

font = {
    'family': 'Microsoft YaHei',
    'weight': 'bold'
}
matplotlib.rc('font', **font)
plot.figure(figsize=(20, 8), dpi=80)
plot.xticks(x, x_in)

plot.plot(x, y)

plot.show()
