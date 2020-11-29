
# for i in content:
#     sql = """
#     insert into word_a values(0,"{}","{}","{}","{}");
#     """.format(pymysql.escape_string(i['word_spell']), pymysql.escape_string(i['Mean_tag__2vGcf']), pymysql.escape_string('/'.join(i['clearfix'])), pymysql.escape_string(json.dumps(i['sentence'])))
#     cursor.insert(sql)