msg = input()

if '.' in msg:
    sep = '.'
else:
    sep = "-"


def binay2int(string): return int(string, 2)


pos = map(binay2int, msg.split(sep))


def format_int(num): return f"{num:02o}"


print("-".join(map(format_int, pos)))
