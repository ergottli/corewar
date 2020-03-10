.name "sub"
.comment "test sub"
		
start:	ld %70, r2
        ld %5, r3
		ld	%0,  r10
		live %-1
		sub r2, r3, r4
		ld %0, r10
		aff r4
		zjmp %:start
