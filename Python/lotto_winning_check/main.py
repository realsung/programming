import pandas as pd

df = pd.read_excel('numbers.xlsx', engine='openpyxl')

arr = [[0]*6 for i in range(len(df[1]))]
for i in range(0, 6):
    for j in range(0, len(df[1])):
        arr[j][i] = df[i+1][j]

nums = input('숫자 6개를 입력하세요. (공백 단위) : ')
nums = list(map(int,nums.split(' ')))
nums.sort()
if len(nums) != 6:
    print('숫자 6개만 입력해주세요.')
    exit(0)

if nums in arr:
    print('1등 중복됩니다.')
else:
    print('1등 중복되는 번호가 없습니다.')

print('[*] 보너스(2등) 체크')

chk = False

for i in range(0, 6):
    arr2 = [[0]*6 for i in range(len(df[1]))]
    for n in range(0, 6):
        for m in range(0, len(df[1])):
            arr2[m][n] = df[n+1][m]    
    for j in range(0, len(df[1])):
        arr2[j][i] = df['보너스'][j]
        arr2[j].sort()
    if nums in arr2:
        chk = True

if chk:
    print('2등 중복됩니다.')
else:
    print('2등 중복되는 번호가 없습니다.')