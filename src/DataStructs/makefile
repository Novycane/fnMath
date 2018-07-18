RM = rm

ifeq ($(OS),Windows_NT)
EXT = .exe
RM = del
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
all: BSP.o
	-@ECHO -n "Creating DataStructs.o"
	-@ld -r $(TEMP)BSP.o -o $(TEMP)DataStructs.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	$(RM) $(TEMP)Factorial.o
	
Test: BSP.o
	-@ECHO "Testing BSP.cpp"
	-@$(CC) $(CFLAGS) $(TEST)BSP.test.cpp -o $(TEMP)BSP.test.o
	-@$(CC) $(TEMP)BSP.o $(TEMP)BSP.test.o -o $(TEMP)BSP$(EXT)
	-@$(TEMP)BSP$(EXT)
	$(RM) $(TEMP)BSP$(EXT)

BSP.o: BSP.cpp BSP.hpp
	-@ECHO -n "Building BSP"
	-@$(CC) $(CFLAGS) BSP.cpp -o $(TEMP)BSP.o
	-@ECHO "...ok"
