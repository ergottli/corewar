.name "st"
.comment "test st"
		
start:	ld %65535, r2
		ld	%0,  r1
		live %-1
		st r2, 312455
		zjmp %:start
