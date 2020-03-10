.name "xor"
.comment "test xor"
		
start:	ld %10, r2
        ld %5, r3
		ld	%0,  r10
		live %-1
		xor r2, r3, r4
		ld %0, r10
		aff r4
		zjmp %:start
