import string
import hashlib
from itertools import product
passwd = 'hash'
hash_value = hashlib.md5(passwd).hexdigest() # 0800fc577294c34e0b28ad2839435945 
chars = string.ascii_lowercase
for length in range(1,5):
	attempt = product(chars, repeat=length)
	for i in attempt:
		brute = ''.join(i)
		print brute
		brute = hashlib.md5(brute).hexdigest()
		if(brute == hash_value):
			print brute
			break