passwords = []
for password in open("wordlist.txt", "r").readlines():
    passwords.append(password.rstrip())

ino = open("_001-array-progmem.ino", "w+")

for line in open("hard-bf-begin.txt", "r").readlines():
    ino.write(line)

ino.write("\n")

i = 0
for password in passwords:
    ino.write('prog_char pass' + str(i) + '[] PROGMEM = "' + password + '";\n')
    i += 1

ino.write("\n\nPROGMEM const char *dico[] =\n{\n")

i = 0
for password in passwords:
    if i != 0:
        ino.write(',\n')
    ino.write('pass' + str(i))
    i += 1

ino.write("};\n\n")

ino.write("for (i=0 ; i < " + str(len(passwords)) + "; i++)")

for line in open("hard-bf-end.txt", "r").readlines():
    ino.write(line)

ino.close()
