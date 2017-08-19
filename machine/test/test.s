.name "ass rape"
.comment "just do something"


#zork:
#l2:		sti r1, %:live, %1
# 		and r1, %0, r1 # if (*r1 == 0) carry = 1;
# 		sti r1, %101, %0

# live:	live %1
# 		zjmp %:live # if (carry == 1)


start:
ld 0, r16
add r1, r16, r16

sti r16, %:end, %1
sti r1, %:end, %6
# zjmp %:start
end:
