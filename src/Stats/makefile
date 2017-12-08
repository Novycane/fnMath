# ----- Compiler
CC 		= clang++
CFLAGS		= -g -c -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
BIN		= ../../bin/
COMMON		= ../

# ----- Targets
all:	Factorial.o Gamma.o Random.o
	-@ECHO -n "Creating Sats.o"
	-@ld -r $(TEMP)Factorial.o $(TEMP)Gamma.o $(TEMP)Random.o -o $(TEMP)LinAlg.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Factorial.o
	rm $(TEMP)Gamma.o
	rm $(TEMP)Random.o
	rm $(TEMP)Stats.o

Factorial.o: Factorial.cpp Factorial.hpp
	-@ECHO -n "Building Factorial"
	-@$(CC) $(CFLAGS) Factorial.cpp -o $(TEMP)Factorial.o
	-@ECHO "...ok"

Gamma.o: Gamma.cpp Gamma.hpp 
	-@ECHO -n "Building Gamma.cpp..."
	-@$(CC) $(CFLAGS) Gamma.cpp -o $(TEMP)Gamma.o
	-@ECHO "....ok"

Random.o: Random.cpp Random.hpp 
	-@ECHO -n "Building Random.cpp...."
	-@$(CC) $(CFLAGS) Random.cpp -o $(TEMP)Random.o
	-@ECHO "...ok"

