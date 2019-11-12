# target: dependencies
# # <tab> rule 
# #  
# #  # make (without arguments) executes first rule in file 
# # Ideally, one target for every object file and a target for final binary.


math_stuff: math_stuff.o 
	c99 -o math_stuff math_stuff.o

math_stuff.o: math_stuff.c
	 c99 -c math_stuff.c
