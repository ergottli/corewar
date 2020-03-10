.name "Banan_clone"
.comment "Clone_banan"

    ld %33554431, r4
    ld %4278845435, r5
    ld %48, r3 # смещение для размещения live
    ld %47, r6 # смещение для размещения zjmp
    ld %8, r7
    ld %38, r8 # стартовое значение для fork
    ld %65535, r10 # Для &
    ld %101449728, r11 # Для |
    ld %0, r2

start:
    live %-1
    sti r4, r2, r3
    sti r5, r2, r6
    fork %38 # смещение на начало нового кода
    add r2, r7, r2
    add r8, r7, r8
    and r8, r10, r8
    or r8, r11, r8
    st r8, -24
    ld %0, r9
    zjmp %:start
