def translate(string, key, mode):
    translated_string = ""
 
    if mode == 'decrypt':
        key = -key
 
    for char in string:
        if char.isalpha():
            num = ord(char)
            num += key
 
            if char.isupper():
                if num > ord('Z'):
                    num -= 26
                elif num < ord('A'):
                    num += 26
            elif char.islower():
                if num > ord('z'):
                    num -= 26
                elif num < ord('a'):
                    num += 26
            translated_string += chr(num)
        else:
            translated_string += char
    return translated_string

encrypted = 'IODJ{MXOLXV_FDHVDU_FUBSWR_VFRUH_1}' # input
for i in range(1, 26):
    decrypted = translate(encrypted, i, 'decrypt')
    print ("".join(['ROT', str(i), ': ', decrypted]))