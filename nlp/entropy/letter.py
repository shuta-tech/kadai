# -*- coding: utf-8 -*-
import collections
import math

f = open('sample.txt')
data = f.read()
print(len(data))
length = len(data)


freq = collections.Counter(data)

# counting
words = {}
for word in list(data):
    words[word] = words.get(word, 0) + 1


# sort by count
d = [(v,k) for k,v in words.items()]
d.sort()
d.reverse()
n = 0

for count, word in d[:60]:
    print(round((100 * count / length), 3), count, word)
    a = count / len(data)
    n += -(a * math.log(a))
    print(n)
    

print("--------------")
for count, word in freq.most_common(30):
    print(word, count)

#3.030811093270824