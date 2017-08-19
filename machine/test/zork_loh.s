.name "zork"
.comment "I'M ALIIIIVE"


		aff r1
l2:		sti r1, %:live, %1
		and r1, %0, r1 # if (*r1 == 0) carry = 1;
		sti r1, %200, %0

live:	live %1
		zjmp %:live # if (carry == 1)
		aff r1
