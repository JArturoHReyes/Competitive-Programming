import fileinput

c=42
suma=0

def f(line):
    return int(line.split(',')[0])

for line in fileinput.input():
    line = line.rstrip()
    mul = 0
    if(line[0]=='|'):
        suma = suma + c * len(line)
    else:
	if len(line.split('-')[1]) == 0:
		mul = 1
	else:
		mul = len(line.split('-')[1])
        suma = suma + f(line) * mul
        
print("{},-".format((suma + 9) // 10 * 10))
