# target: dependencies
# <tab> rule 
#  
#  # make (without arguments) executes first rule in file 
# Ideally, one target for every object file and a target for final binary.

math: stack_arg.o mathDriver.o math.o
	c99 -o math stack_arg.o mathDriver.o math.o

stack_arg.o: stack_arg.c
	c99 -c stack_arg.c

mathDriver.o: mathDriver.c
	c99 -c mathDriver.c

math.o: math.c
	c99 -c math.c
