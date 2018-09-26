import turtle as tur

i = 90
tur.shape('turtle')
tur.color('#FF69B4')
tur.speed('fasttest')
tur.begin_fill()
for i in range(300):
	tur.forward(i)
	tur.right(100)

tur.end_fill()
tur.mainloop()