.name "ls"
.comment "test ld"
		
start:	ld 	%1, r2
		aff r2
		ld	%0,r1
		live %-1
		zjmp	%:start
