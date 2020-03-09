.name "or"
.comment "test or"
		
start:	ld %1, r2
        ld %2, r3
		ld	%0,  r10
		live %-1
		or %2, %1, r4
		ld %0, r10
		aff r4
		zjmp %:start
