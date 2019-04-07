import random
import string

d = {'A': 3,
     'B': 5,
     'C': 7,
     'D': 11,
     'E': 13,
     'F': 17,
     'G': 19,
     'H': 23,
     'I': 29,
     'J': 31,
     'K': 37,
     'L': 41,
     'M': 43,
     'N': 47,
     'O': 53,
     'P': 59,
     'Q': 61,
     'R': 67,
     'S': 71,
     'T': 73,
     'U': 79,
     'V': 83,
     'W': 89,
     'X': 97,
     'Y': 101,
     'Z': 103,
}

plain = ''
while any(c not in plain for c in string.ascii_uppercase):
    plain += random.choice(string.ascii_uppercase)

while len(plain) < 100:
    plain += random.choice(string.ascii_uppercase)

enc = []
for i in range(len(plain)-1):
    enc.append(d[plain[i]] * d[plain[i+1]])

with open('cryptopangrams_input_gen', 'w') as f:
    f.write("1\n")
    f.write("{} {}\n".format(max(d.values()), len(enc)))
    for e in enc:
        f.write("{} ".format(e))
    f.write("\n")

with open('cryptopangrams_output_gen', 'w') as f:
    f.write(plain)
