def sol(mylist):
	go = []
	for i in mylist:
		go.append(i)
	return go

def sol(mylist):
	return list(map(len,mylist))

a=[[2,3],[2]]
print(sol(a))

a=7
b=5
print(divmod(a,b)) # return a//b , a%b

num = '3212'
base = 5
answer = int(num, base)
print(answer)

# s, n = input().strip().split(' ')
s = 'abc'
n = 7
n = int(n)
print(s.ljust(7,' '))
print(s.center(7,' '))
print(s.rjust(7,' '))

list2 = [3,2,1]
print(sorted(list2)) # new list
print(list2.sort()) # None 
print(list2)

mylist = [ [1,2,3], [4,5,6], [7,8,9] ]
new_list = list(map(list, zip(*mylist)))
print(new_list)

l1 = [1,2,3,4]
l2 = [5,6,7,8]
go = []
for i in zip(l1,l2):
	go.append(i)
print(go)

def s(mylist):
    answer = [int(i) for i in mylist]
    answer = list(map(int,mylist))
    return answer

g = ['1', '100', '33']
print(s(g))

def o(mylist):
    # answer = ''.join(str(i) for i in list(map(int,mylist)))
    # answer = ''.join(str(i) for i in list(map(str,mylist)))
    answer = ''.join(mylist)
    return answer

g = ['11', '100', '33']
print(o(g))

a = [''.join('*'*(i+1)+'\n') for i in range(3)]
for i in a:
	print(i,end="")

import itertools

def f(mylist):
	answer = sum(mylist,[])
	answer = list(itertools.chain(*mylist))
	return answer

h = [[1], [2]]
print(f(h))

z = ['2', '1']

def sol(mylist):
	answer = list(map(''.join,itertools.permutations(mylist,3)))
	# print(answer)
	return answer

print(sol(z))

import collections # 중복
my_list = [1, 2, 3, 4, 5, 6, 7, 8, 7, 9, 1, 2, 3, 3, 5, 2, 6, 8, 9, 0, 1, 1, 4, 7, 0]
answer = collections.Counter(my_list)
print(answer)

go = [3,4,5,6]

answer = [i**2 for i in go if i%2==0]
print(answer)

# swap
q = 100
r = 101
q,r=r,q
print(q)
print(r)

# 이진탐색

import bisect
mylist = [1, 2, 3, 7, 9, 11, 33]
print(bisect.bisect(mylist, 3))

max_val = float('inf')
print(max_val)
print(max_val>1000000000000038192381298382183891238989)


# file open

with open('a.out') as f:
	for line in f.readlines():
		print(line.strip().split('\t'))

