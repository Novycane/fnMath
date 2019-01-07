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
MATRIX		= $(TEMP)Matrix.o

# ----- Targets
all: $(TEMP)Matrix.o $(TEMP)LU.o $(TEMP)QR.o $(TEMP)Eigen.o
	-@ECHO -n "Creating LinAlg.o ."
	-@ld -r $(TEMP)Matrix.o $(TEMP)LU.o $(TEMP)QR.o $(TEMP)Eigen.o -o $(TEMP)LinAlg.o
	-@ECHO "...ok"

test: $(TEMP)Matrix.o $(TEST)Matrix.test.cpp
	-@ECHO -n "Testing LinearAlgebra Library"
	-@$(CC) $(CFLAGS) $(TEST)Matrix.test.cpp -o $(TEMP)Matrix.test.o
	-@$(CC) $(TEMP)Matrix.o $(TEMP)Matrix.test.o -o $(TEMP)Matrix$(EXT)
	-@$(TEMP)Matrix$(EXT)

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Matrix.o
	rm $(TEMP)LU.o
	rm $(TEMP)QR.o
	rm $(TEMP)Eigen.o
	rm $(TEMP)LinAlg.o

$(TEMP)Matrix.o: Matrix.cpp Matrix.hpp $(COMMON)Error.hpp
	-@ECHO -n "Building Matrix.cpp"
	-@$(CC) $(CFLAGS) Matrix.cpp -o $(TEMP)Matrix.o
	-@ECHO "...ok"

$(TEMP)LU.o: LU.cpp LU.hpp $(MATRIX)
	-@ECHO -n "Building LU.cpp..."
	-@$(CC) $(CFLAGS) LU.cpp -o $(TEMP)LU.o
	-@ECHO "....ok"

$(TEMP)QR.o: QR.cpp QR.hpp $(MATRIX)
	-@ECHO -n "Building QR.cpp...."
	-@$(CC) $(CFLAGS) QR.cpp -o $(TEMP)QR.o
	-@ECHO "...ok"

$(TEMP)Eigen.o: $(TEMP)Matrix.o $(COMMON)Error.hpp
	-@ECHO -n "Building Eigen.cpp."
	-@$(CC) $(CFLAGS) Eigen.cpp -o $(TEMP)Eigen.o
	-@ECHO "...ok"

