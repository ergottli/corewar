# corewar

## What is Corewar?

* Corewar is a very peculiar game.
It’s about bringing “players” together around a “virtual machine”,
which will load some “champions” who will fight against one
an-other with the support of “processes”, with the objective
being for these championsto stay “alive”.

* The processes are executed sequentially within the same 
virtual machine and mem-ory space. They can therefore, 
among other things, write and rewrite on top ofeach others 
so to corrupt one another, force the others to execute instructions 
thatcan damage them, try to rewrite on the go the coding equivalent 
of aCôtes duRhône 1982(that is one delicious French wine!), etc...

* The game ends when all the processes are dead.  
The winner is the last playerreported to be “alive”.

### [Want more information?](https://en.wikipedia.org/wiki/Core_War) 

## Installing

Clone repository with command ```git clone --recurse-submodules https://github.com/ergottli/corewar.git```

Than enter command ```make``` in the root of repository.

Was compiled on MacOS Catalina 10.15.3

## Usage

### virtual machine

```
Usage: ./corewar [-a (-dump|-d) <num> (-show|-s) <num> -l <num>] [-v] [-n <num>] <champion.cor> <...>
    -a          : Print output from "aff" (Default is off)
    -dump <num> : Dump memory (32 octets per line) after <num> cycles and exit
    -d    <num> : Dump memory (64 octets per line) after <num> cycles and exit
    -show <num> : Run <num> cycles, dump memory (32 octets per line), pause and repeat
    -s    <num> : Run <num> cycles, dump memory (64 octets per line), pause and repeat
    -l    <num> : Log levels
                   1  : Show lives
                   2  : Show cycles
                   4  : Show operations
                   16 : Show PC movements
    -v          : Run visualizer
    -n    <num> : Set <num> of the next player
```

### asm

```
Usage: ./asm <sourcefile.s>
```

### disassembler
```
./diasm 'filename.cor'
```