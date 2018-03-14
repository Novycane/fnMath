ifeq ($(OS),Windows_NT)
EXT = .exe
endif

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
all:	Factorial.o Gamma.o Random.o FisherYates.o MetropolisHastings.o
	-@ECHO -n "Creating Sats.o"
	-@ld -r $(TEMP)Factorial.o $(TEMP)Gamma.o $(TEMP)Random.o $(TEMP)MetropolisHastings.o -o $(TEMP)Stats.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Factorial.o
	rm $(TEMP)Gamma.o
	rm $(TEMP)Random.o
	rm $(TEMP)Stats.o

Test: Random.o
	-@ECHO "Testing Random.cpp"
	-@$(CC) $(CFLAGS) $(TEST)Random.test.cpp -o $(TEMP)Random.test.o
	-@$(CC) $(CFLAGS) MetropolisHastings.cpp -o $(TEMP)MetropolisHastings.o
	-@$(CC) $(TEMP)Random.o $(TEMP)Random.test.o $(TEMP)MetropolisHastings.o -o $(TEMP)Random$(EXT)
	-@$(TEMP)Random$(EXT)

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

FisherYates.o: FisherYates.hpp FisherYates.cpp Random.cpp Random.hpp 
	-@ECHO -n "Building FisherYates.cpp...."
	-@$(CC) $(CFLAGS) FisherYates.cpp -o $(TEMP)FisherYates.o
	-@ECHO "...ok"

MetropolisHastings.o: MetropolisHastings.hpp MetropolisHastings.cpp Random.o
	-@ECHO -n "Building MetropolisHastings.cpp...."
	-@$(CC) $(CFLAGS) MetropolisHastings.cpp -o $(TEMP)MetropolisHastings.o
	-@ECHO "...ok"