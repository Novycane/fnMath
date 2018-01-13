# ----- Compiler
CC 		= clang++
CFLAGS		= -g -c -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
BIN		= ../../bin/
COMMON		= ../
RIJNDAEL 	= $(TEMP)Rijndael.o

# ----- Targets
all:	Rijndael
	-@ECHO -n "Creating Crypto.o ."
	-@ld -r $(TEMP)Rijndael.o -o $(TEMP)Crypto.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Rijndael.o
	
Rijndael: $(RIJNDAEL) 
	-@ECHO -n "Building Rijndael.cpp"
	-@$(CC) $(CFLAGS) Rijndael.cpp -o $(TEMP)Rijndael.o
	-@ECHO "...ok"

