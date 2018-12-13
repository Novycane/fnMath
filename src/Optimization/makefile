# ----- Compiler
CC 		= clang++
CFLAGS		= -g -c -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
BIN			= ../../bin/
COMMON		= ../

# ----- Targets
all:	
	-@ECHO -n "Creating Optimization.o ."
	-@ld -r LevenbergMarquad.o -o $(TEMP)Optimization.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	#rm $(TEMP)Matrix.o
	
LevenbergMarquad.o: LevenbergMarquad.cpp LevenbergMarquad.hpp 
	-@ECHO -n "LevenbergMarquad.cpp"
	-@$(CC) $(CFLAGS) LevenbergMarquad.cpp -o LevenbergMarquad.o
	-@ECHO "...ok"
