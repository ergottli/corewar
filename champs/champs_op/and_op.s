.name "and"
.comment "test and"
		
start:	ld %65535, r2
        ld %65, r3
		ld	%0,  r10
		live %-1
		and %65535, %65, r4
		ld %0, r10
		aff r4
		zjmp %:start
