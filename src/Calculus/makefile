# ----- Compiler
CC 		= clang++
CFLAGS		= -g -c -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
BIN		= ../../bin/
COMMON		= ../

# ----- Targets
all:	Derivative Integral
	-@ECHO -n "Creating Calculus.o ."
	-@ld -r $(TEMP)Derivative.o $(TEMP)Integral.o -o $(TEMP)Calculus.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Derivative.o
	rm $(TEMP)Integral.o
	rm $(TEMP)Calculus.o

Derivative: Derivative.cpp Derivative.hpp $(COMMON)Function.hpp
	-@ECHO -n "Building Derivative.cpp"
	-@$(CC) $(CFLAGS) Derivative.cpp -o $(TEMP)Derivative.o
	-@ECHO "...ok"

Integral: Integral.cpp Integral.hpp $(COMMON)Function.hpp
	-@ECHO -n "Building Integral.cpp..."
	-@$(CC) $(CFLAGS) Integral.cpp -o $(TEMP)Integral.o
	-@ECHO "....ok"
