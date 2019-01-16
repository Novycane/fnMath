ifeq ($(OS),Windows_NT)
EXT = .exe
endif

# ----- Compiler
CC 		= clang++ -Xclang -flto-visibility-public-std
CFLAGS		= -g -Wall -c 
TFLAGS		= -g -Wall -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
TEST		= ../../test/
BIN			= ../../bin/
COMMON		= ../

# ----- Targets
all:	$(TEMP)Factorial.o $(TEMP)Gamma.o $(TEMP)Random.o $(TEMP)FisherYates.o $(TEMP)MetropolisHastings.o
	-@ECHO "Creating Sats.o"
	-@ld -r $(TEMP)Factorial.o $(TEMP)Gamma.o $(TEMP)Random.o $(TEMP)MetropolisHastings.o -o $(TEMP)Stats.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Factorial.o
	rm $(TEMP)Gamma.o
	rm $(TEMP)Random.o
	rm $(TEMP)Stats.o

Test: $(TEMP)Random.o
	-@ECHO "Testing Random.cpp"
	-@$(CC) $(CFLAGS) $(TEST)Random.test.cpp -o $(TEMP)Random.test.o
	-@$(CC) $(CFLAGS) MetropolisHastings.cpp -o $(TEMP)MetropolisHastings.o
	-@$(CC) $(TEMP)Random.o $(TEMP)Random.test.o $(TEMP)MetropolisHastings.o -o $(TEMP)Random$(EXT)
	-@$(TEMP)Random$(EXT)

Install: 
	rd c:\Lib\fnMath\Stats /S /Q
	mkdir c:\Lib\fnMath\Stats
	copy *.hpp c:\Lib\fnMath\Stats\

$(TEMP)Factorial.o: Factorial.cpp Factorial.hpp
	-@ECHO "Building Factorial"
	-@$(CC) $(CFLAGS) Factorial.cpp -o $(TEMP)Factorial.o
	-@ECHO "...ok"

$(TEMP)Gamma.o: Gamma.cpp Gamma.hpp 
	-@ECHO "Building Gamma.cpp..."
	-@$(CC) $(CFLAGS) Gamma.cpp -o $(TEMP)Gamma.o
	-@ECHO "....ok"

$(TEMP)Random.o: Random.cpp Random.hpp 
	-@ECHO "Building Random.cpp...."
	-@$(CC) $(CFLAGS) Random.cpp -o $(TEMP)Random.o
	-@ECHO "...ok"

$(TEMP)FisherYates.o: FisherYates.hpp FisherYates.cpp Random.cpp Random.hpp 
	-@ECHO "Building FisherYates.cpp...."
	-@$(CC) $(CFLAGS) FisherYates.cpp -o $(TEMP)FisherYates.o
	-@ECHO "...ok"

$(TEMP)MetropolisHastings.o: MetropolisHastings.hpp MetropolisHastings.cpp Random.o
	-@ECHO "Building MetropolisHastings.cpp...."
	-@$(CC) $(CFLAGS) MetropolisHastings.cpp -o $(TEMP)MetropolisHastings.o
	-@ECHO "...ok"