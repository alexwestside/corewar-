.name "fafa"
.comment "I'M ALIIIIVE"

l2:
		sti r1, %:live, %1
		and r1, %0, r1
.name

live:
		live %1
		and r1, %0, r1
		zjmp %:live
live:
		live %1
		and r1, %0, r1
		zjmp %:live

live:
		live %1
		and r1, %0, r1
		zjmp %:live
