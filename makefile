# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

fill: stack_ll.o fillDriver.o fill.o
	c99 -o fill stack_ll.o fillDriver.o fill.o

stack_ll.o: stack_ll.c
	c99 -c stack_ll.c

fillDriver.o: fillDriver.c
	c99 -c fillDriver.c

fill.o: fill.c
	c99 -c fill.c
