def str_split(sen):
    return sen.split()

def str_join(word):
    return word.join()


sentences = "I am a Chinese"
word = str_split(sentences)
print(word)
# lang = str_join(word)
lan = word.join(word)
print(lan)
