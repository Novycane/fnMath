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
RIJNDAEL 	= $(TEMP)Rijndael.o
PRIME 		= $(TEMP)Prime.o

# ----- Targets
all:	Rijndael, Prime
	-@ECHO -n "Creating Crypto.o ."
	-@ld -r $(TEMP)Rijndael.o -o $(TEMP)Crypto.o
	-@ECHO "...ok"

.PHONY:
clean:	
	-@ECHO "Cleaning Files"
	rm $(TEMP)Rijndael.o
	rm $(TEMP)Prime.o
	
Rijndael:
	-@ECHO -n "Building Rijndael.cpp"
	-@$(CC) $(CFLAGS) Rijndael.cpp -o $(TEMP)Rijndael.o
	-@ECHO "...ok"

Prime:
	-@ECHO -n "Building Prime.cpp"
	-@$(CC) $(CFLAGS) Prime.cpp -o $(TEMP)Prime.o
	-@ECHO "...ok"

Test: Prime
	-@ECHO Testing Prime.cpp
	-@$(CC) $(CFLAGS) $(TEST)Prime.test.cpp -o $(TEMP)Prime.test.o
	$(CC) $(TEMP)Prime.o $(TEMP)Prime.test.o -o $(TEMP)Prime
	-@$(TEMP)Prime