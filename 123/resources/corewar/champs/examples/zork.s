.name "zork
name_"
.comment "I'M ALIIIIVE
comment_"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
