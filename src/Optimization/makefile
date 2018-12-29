ifeq ($(OS),Windows_NT)
EXT = .exe
endif

# ----- Compiler
CC 			= clang++ -Xclang -flto-visibility-public-std 
CFLAGS		= -g -Wall -c 
TFLAGS		= -g -Wall -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEST		= ../../test/
TEMP		= ../../temp/
BIN			= ../../bin/
COMMON		= ../

# ----- Targets
all: GradientDescent.o 
	-@ECHO -n "Creating Optimization.o ."
	-@ld -r $(TEMP)GradientDescent.o -o $(TEMP)Optimization.o
	-@ECHO "...ok"

test: GradientDescent.o
	-@ECHO -n "Testing Optimization Library"
	-@$(CC) $(CFLAGS) $(TEST)Optimization.test.cpp -o $(TEMP)Optimization.test.o
	-@$(CC) $(TEMP)GradientDescent.o $(TEMP)Optimization.test.o -o $(TEMP)Optimization$(EXT)
	-@$(TEMP)Optimization$(EXT)

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	del "$(TEMP)GradientDescent.o"

GradientDescent.o: GradientDescent.cpp GradientDescent.hpp 
	-@ECHO -n "GradientDescent.cpp"
	-@$(CC) $(CFLAGS) GradientDescent.cpp -o $(TEMP)GradientDescent.o
	-@ECHO "...ok"
	
LevenbergMarquad.o: LevenbergMarquad.cpp LevenbergMarquad.hpp 
	-@ECHO -n "LevenbergMarquad.cpp"
	-@$(CC) $(CFLAGS) LevenbergMarquad.cpp -o LevenbergMarquad.o
	-@ECHO "...ok"
