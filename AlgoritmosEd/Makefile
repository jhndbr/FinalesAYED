# Makefile

# Default target
all: run

# Compile the program
%.o: %.cpp
	g++ -o $@ $<

# Run the program
%: %.cpp
	g++ -o $@ $<
	./$@
	rm -f $@

# Clean up
clean:
	rm -f *.o nombreprograma