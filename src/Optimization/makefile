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
all: $(TMEP)GradientDescent.o 
	-@ECHO -n "Creating Optimization.o ."
	-@ld -r $(TEMP)GradientDescent.o -o $(TEMP)Optimization.o
	-@ECHO "...ok"

test: GradientDescent.o
	-@ECHO "Testing Optimization Library"
	-@$(CC) $(CFLAGS) $(TEST)Optimization.test.cpp -o $(TEMP)Optimization.test.o
	-@$(CC) $(TEMP)GradientDescent.o $(TEMP)Derivative.o $(TEMP)Optimization.test.o -o $(TEMP)Optimization$(EXT)
	-@$(TEMP)Optimization$(EXT)

Install: 
	rd c:\Lib\fnMath\Optimization /S /Q
	mkdir c:\Lib\fnMath\Optimization
	copy *.hpp c:\Lib\fnMath\Optimization\

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	del "$(TEMP)GradientDescent.o"

$(TMEP)GradientDescent.o: GradientDescent.cpp GradientDescent.hpp 
	-@ECHO "GradientDescent.cpp"
	-@$(CC) $(CFLAGS) GradientDescent.cpp -o $(TEMP)GradientDescent.o
	-@ECHO "...ok"
	
$(TMEP)LevenbergMarquad.o: LevenbergMarquad.cpp LevenbergMarquad.hpp 
	-@ECHO "LevenbergMarquad.cpp"
	-@$(CC) $(CFLAGS) LevenbergMarquad.cpp -o LevenbergMarquad.o
	-@ECHO "...ok"
