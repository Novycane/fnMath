# ----- Compiler
CC 		= clang++
CFLAGS		= -g -Wall -c -std=c++14
TFLAGS		= -g -Wall -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
BIN			= ../../bin/
TEST		= ../../test/
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

# ----- Testing Targets
Test: Integral Derivative
	-@ECHO -n -------- Integral.cpp --------
	-@$(CC) $(CFLAGS) $(TEST)Integral.test.cpp -o $(TEMP)Integral.test.o
	-@$(CC) $(TEMP)Integral.o $(TEMP)Integral.test.o -o $(TEMP)Integral
	-@$(TEMP)Integral
	-@ECHO .
	-@ECHO -n -------- Derivative.cpp ---------
	-@$(CC) $(CFLAGS) $(TEST)Derivative.test.cpp -o $(TEMP)Derivative.test.o
	-@$(CC) $(TEMP)Derivative.o $(TEMP)Derivative.test.o -o $(TEMP)Derivative
	-@$(TEMP)Derivative