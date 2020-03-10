.name "add"
.comment "test add"
		
start:	ld %50, r2
        ld %15, r3
		ld	%0,  r10
		live %-1
		add r2, r3, r4
		ld %0, r10
		aff r4
		zjmp %:start
