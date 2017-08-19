.name "kill_zork"
.comment "I'M ALIIIIVE"

sti r1, %:live, %1
sti r1, %:live2, %1
and r1, %0, r2

fork %511

live:
	live %1
	fork %:live2
	zjmp %:live # if (carry == 1)



live2:	live %1
		zjmp %:live # if (carry == 1)
