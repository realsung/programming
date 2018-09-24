import easygui
easygui.msgbox("Gugudan!")
while 1:
	guess = easygui.integerbox("Choose One of dan")
	if not guess: 
		break
	for dan in range(1,11): 
		easygui.msgbox(str(guess) + "*" + str(dan) + "=" + str(guess*dan))