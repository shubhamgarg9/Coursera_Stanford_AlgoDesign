fo = open('kargerMinCut.txt','r+')
text = fo.read()
text = text.split('\n')
# print text/

fo.close()


with open('kargerMinCut.txt','w+') as fi:
	for i in text:
		fi.write(i + '-1\t\n')