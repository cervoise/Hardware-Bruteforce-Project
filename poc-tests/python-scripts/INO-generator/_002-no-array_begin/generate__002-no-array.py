ino = open("_002-no-array.ino", "w+")

for line in open("_002-no-array_begin.txt", "r").readlines():
    ino.write(line)

ino.write("\n")

for password in open("wordlist.txt", "r").readlines():
    ino.write('pT("' + password.rstrip() + '");\n')
    

ino.write("while(1){}\n}")

ino.close()
