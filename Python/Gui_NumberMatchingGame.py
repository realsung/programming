# Use Easygui module
import easygui, random
rand = random.randint(1,101) # 1~100 RandNum Create
guess = 0
tries = 0
easygui.msgbox("!!Random Game!! Choose One in 1~100") # print start msgbox
while guess != rand and tries < 6:
	guess = easygui.integerbox("Choose One")
	if not guess:
		break
	if guess < rand:
		easygui.msgbox(str(guess) + "is too low")
	elif guess > rand:
		easygui.msgbox(str(guess) + "is too high")
	tries += 1
if guess == rand:
	easygui.msgbox("You got it!!!! G00D J0B")
else:
	easygui.msgbox("No More guess... The random number is" + str(guess))
	