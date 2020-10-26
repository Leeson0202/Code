class vocabulary:
    # clearfix为一个列表 sentences 为一个元组
    def __init__(self, word_spell=None, Mean_tag__2vGcf=None, clearfix=None, sentences=None):
        self.word_spell = word_spell     # 单词的拼写
        self.Mean_tag__2vGcf = Mean_tag__2vGcf  # 四六级、高中
        self.clearfix = clearfix        # 词性和翻译
        self.sentence = sentences    # 单词的例句
    def keys(self):
             #当对实例化对象使用dict(obj)的时候, 会调用这个方法,这里定义了字典的键, 其对应的值将以obj['name']的形式取,
                # 但是对象是不可以以这种方式取值的, 为了支持这种取值, 可以为类增加一个方法'''
        return ('word_spell', 'Mean_tag__2vGcf', 'clearfix','sentence')

    def __getitem__(self, item):
        '''内置方法, 当使用obj['name']的形式的时候, 将调用这个方法, 这里返回的结果就是值'''
        return getattr(self, item)

x = vocabulary('a','四级', '一个', 'I have a pen')

dictionary_list= list()

dictionary_list.append( dict(x) )
print(dictionary_list)
