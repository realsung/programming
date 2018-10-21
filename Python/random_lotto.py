import random

num = []

for i in range(6):
    num.append(random.randint(1,45))
while(num[0]==num[1]):
    num[1] == random.randint(1,45)
while(num[0]==num[2] or num[1] == num[2]):
    num[2] == random.randint(1,45)
while(num[0]==num[3] or num[1] == num[3] or num[2]==num[3]):
    num[3] == random.randint(1,45)
while(num[0]==num[4] or num[1]==num[4] or num[2]==num[4] or num[3]==num[4]):
    num[4] == random.randint(1,45)
while(num[0]==num[5] or num[1]==num[5] or num[2]==num[5] or num[3]==num[5] or num[4]==num[5]):
    num[5] == random.randint(1,45)

num.sort()
print(num)