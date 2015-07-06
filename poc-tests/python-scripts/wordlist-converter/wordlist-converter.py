wordlist = "500-worst-passwords.txt"
passwords = []
result = ""

for password in open(wordlist, "r").readlines():
    passwords.append(password.rstrip())

result = "const char *dico[] = { "
for password in passwords:
    result += '"' + password.replace('"', '\\"') + '", '

result = result[0:-2] + ' };'

print result
