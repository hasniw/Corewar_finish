.name "Basic"
.comment "B"

	st		r1, 6
	live	%1
	fork	%:trap
	ld		%0, r2
	zjmp	%:start

trap:
	ld		%655359, r3
	st		r3, -39
	ld		%512, r3		# offset - 7
	st		r3, -55
	ld		%42991616, r3		# offset - 7
	st		r3, -71
	ld		%0, r3
	zjmp	%:trap

start:
	st		r1, 6
	live	%1
	ld		%0, r2
	zjmp	%:start
	



#	ld		%-7, r3		#
#	st		r3, -39
#	ld 		%9, r2		#
#	st		r2, -55
#	ld 		%2, r2		#
#	st		r2, -70
#	ld 		%167936, r2
#	st		r2, -86
#	ld		%0, r3
#	zjmp	%:trap


#ld %1, r2
#sti r2, %100, %56
#ld %1, r3
#sti r3, %85, %56
#ld %7, r3
#sti r3, %85, %40
#ld %1, r5
#sti r5, %55,%54
#ld %104, r4
#sti r4, %55, %39
#ld %11, r2
#sti r2, %55, %24

#start:
#		sti		r1, %:live, %1
#live:
#		live	%1
