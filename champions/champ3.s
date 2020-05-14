.name "Basic++"
.comment "B++"

	st		r1, 6
	live	%1
	fork	%:trap
	ld		%0, r2
	ld		%0, r5
	zjmp	%:start

trap:
	ld		%64, r6
	ld		%655359, r3
	sti		r3, %-59, r5
	ld		%512, r3
	sti		r3, %-75, r5
	ld		%42991616, r3
	sti		r3, %-92, r5
	sub		r5, r6, r5
	ld		%0, r3
	zjmp	%:trap

start:
	st		r1, 28
	st		r1, 28
	st		r1, 28
	st		r1, 28
	st		r1, 28
	st		r1, 28
	st		r1, 28
	ld		%0, r2

live:
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	live	%93999
	zjmp	%:live
