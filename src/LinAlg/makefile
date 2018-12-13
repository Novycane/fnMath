# ----- Compiler
CC 		= clang++
CFLAGS		= -g -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
BIN		= ../../bin/
COMMON		= ../
MATRIX		= $(TEMP)Matrix.o

# ----- Targets
all:	Matrix LU QR Eigen
	-@ECHO -n "Creating LinAlg.o ."
	-@ld -r $(TEMP)Matrix.o $(TEMP)LU.o $(TEMP)QR.o $(TEMP)Eigen.o -o $(TEMP)LinAlg.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Matrix.o
	rm $(TEMP)LU.o
	rm $(TEMP)QR.o
	rm $(TEMP)Eigen.o
	rm $(TEMP)LinAlg.o

Matrix: Matrix.cpp Matrix.hpp $(COMMON)Error.hpp
	-@ECHO -n "Building Matrix.cpp"
	-@$(CC) $(CFLAGS) Matrix.cpp -o $(TEMP)Matrix.o
	-@ECHO "...ok"

LU: LU.cpp LU.hpp $(MATRIX)
	-@ECHO -n "Building LU.cpp..."
	-@$(CC) $(CFLAGS) LU.cpp -o $(TEMP)LU.o
	-@ECHO "....ok"

QR: QR.cpp QR.hpp $(MATRIX)
	-@ECHO -n "Building QR.cpp...."
	-@$(CC) $(CFLAGS) QR.cpp -o $(TEMP)QR.o
	-@ECHO "...ok"

Eigen: Matrix $(COMMON)Error.hpp
	-@ECHO -n "Building Eigen.cpp."
	-@$(CC) $(CFLAGS) Eigen.cpp -o $(TEMP)Eigen.o
	-@ECHO "...ok"

