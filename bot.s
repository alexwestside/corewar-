.name "GohomeGohard"
.comment "GO HARD OR GO HOME"

l2:		st r1, 14
		fork %-1024
		live %1
		and r1, %0, r1
		zjmp %400

