import json


str = {"1":"a","2":"b"}
print(str)
str_j = json.dumps(str)
print(str_j)
with open("mm.json","w") as ff:
    ff.writelines(str_j)