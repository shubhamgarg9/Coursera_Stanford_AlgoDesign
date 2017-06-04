fo = open("dijkstraData.txt",'r+')
data = fo.read()
line = data.split('\n')
del line[len(line)-1]
fo.close()


fo = open("dijkstraData2.txt",'w+')

for i in line:
	j = i.split('\t')
	t = j[0]
	del j[len(j)-1]
	# print j
	print j
	del j[0]
	for k in j:
		k = k.split(',')
		# print 'line no: ' + t
		# print 'node: ' + k[0]
		# print 'weight: ' + k[1]
		fo.write(t + ' ' + k[0] + ' ' + k[1] + '\n')