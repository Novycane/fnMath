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
INSTALLPATH	= c:\fnMath\LinAlg\
COMMON		= ../
MATRIX		= $(TEMP)Matrix.o

# ----- Targets
all: $(TEMP)Matrix.o $(TEMP)Tridiagonal.o $(TEMP)LU.o $(TEMP)QR.o $(TEMP)Eigen.o $(TEMP)Cholesky.o $(TEMP)Jacobi.o $(TEMP)GaussSeidel.o
	-@ECHO -n "Creating LinAlg.o ."
	-@ld -r $(TEMP)Matrix.o $(TEMP)Tridiagonal.o $(TEMP)LU.o $(TEMP)QR.o $(TEMP)Eigen.o $(TEMP)Cholesky.o -o $(TEMP)LinAlg.o
	-@ECHO "...ok"

test: $(TEMP)Matrix.test.o $(TEMP)Tridiagonal.test.o $(TEMP)LU.test.o $(TEMP)Cholesky.test.o $(TEMP)GaussSeidel.test.o $(TEMP)Jacobi.test.o $(TEMP)BandedMatrix.test.o
	-@ECHO -n "Testing LinearAlgebra Library"
	-@$(TEMP)Matrix$(EXT)
	-@$(TEMP)Tridiagonal$(EXT)
	-@$(TEMP)BandedMatrix$(EXT)
	-@$(TEMP)LU$(EXT)
	-@$(TEMP)Cholesky$(EXT)
	-@$(TEMP)GaussSeidel$(EXT)
	-@$(TEMP)Jacobi$(EXT)
	

TestGaussSeidel: $(TEMP)GaussSeidel.test.o
	-@ECHO -n "Testing GaussSeidel Functions"
	-@$(TEMP)GaussSeidel$(EXT)

TestJacobi: $(TEMP)Jacobi.test.o
	-@ECHO -n "Testing Jacobi Functions"
	-@$(TEMP)Jacobi$(EXT)

Install: 
	rd c:\Lib\fnMath\LinAlg /S /Q
	mkdir c:\Lib\fnMath\LinAlg
	copy *.*pp c:\Lib\fnMath\LinAlg\


.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Matrix.o
	rm $(TEMP)LU.o
	rm $(TEMP)QR.o
	rm $(TEMP)Eigen.o
	rm $(TEMP)LinAlg.o
	rm $(TEMP)GaussSeidel.o
	rm $(TEMP)Jacobi.o
	rm $(TEMP)Tridiagonal.o
	rm $(TEMP)BandedMatrix.o

$(TEMP)Matrix.o: Matrix.cpp Matrix.hpp 
	-@ECHO -n "Building Matrix.cpp"
	-@$(CC) $(CFLAGS) Matrix.cpp -o $(TEMP)Matrix.o
	-@ECHO "...ok"

$(TEMP)Matrix.test.o: $(TEST)Matrix.test.cpp $(TEMP)Matrix.o
	-@$(CC) $(CFLAGS) $(TEST)Matrix.test.cpp -o $(TEMP)Matrix.test.o
	-@$(CC) $(TEMP)Matrix.o $(TEMP)Matrix.test.o -o $(TEMP)Matrix$(EXT)

$(TEMP)Tridiagonal.o: Tridiagonal.cpp Tridiagonal.hpp 
	-@ECHO -n "Building Tridiagonal.cpp"
	-@$(CC) $(CFLAGS) Tridiagonal.cpp -o $(TEMP)Tridiagonal.o
	-@ECHO "...ok"

$(TEMP)Tridiagonal.test.o: $(TEST)Tridiagonal.test.cpp $(TEMP)Tridiagonal.o
	-@$(CC) $(CFLAGS) $(TEST)Tridiagonal.test.cpp -o $(TEMP)Tridiagonal.test.o
	-@$(CC) $(TEMP)Tridiagonal.o $(TEMP)Tridiagonal.test.o -o $(TEMP)Tridiagonal$(EXT)

$(TEMP)BandedMatrix.o: BandedMatrix.cpp BandedMatrix.hpp 
	-@ECHO -n "Building BandedMatrix.cpp"
	-@$(CC) $(CFLAGS) BandedMatrix.cpp -o $(TEMP)BandedMatrix.o
	-@ECHO "...ok"

$(TEMP)BandedMatrix.test.o: $(TEST)BandedMatrix.test.cpp $(TEMP)BandedMatrix.o
	-@$(CC) $(CFLAGS) $(TEST)BandedMatrix.test.cpp -o $(TEMP)BandedMatrix.test.o
	-@$(CC) $(TEMP)BandedMatrix.o $(TEMP)BandedMatrix.test.o -o $(TEMP)BandedMatrix$(EXT)

$(TEMP)LU.o: LU.cpp LU.hpp $(MATRIX)
	-@ECHO -n "Building LU.cpp..."
	-@$(CC) $(CFLAGS) LU.cpp -o $(TEMP)LU.o
	-@ECHO "....ok"

$(TEMP)LU.test.o: $(TEST)LU.test.cpp $(TEMP)LU.o
	-@$(CC) $(CFLAGS) $(TEST)LU.test.cpp -o $(TEMP)LU.test.o
	-@$(CC) $(TEMP)Matrix.o $(TEMP)LU.o $(TEMP)LU.test.o -o $(TEMP)LU$(EXT)

$(TEMP)Cholesky.o: Cholesky.cpp Cholesky.hpp 
	-@ECHO -n "Building Cholesky.cpp."
	-@$(CC) $(CFLAGS) Cholesky.cpp -o $(TEMP)Cholesky.o
	-@ECHO "...ok"

$(TEMP)Cholesky.test.o: $(TEST)Cholesky.test.cpp $(TEMP)Cholesky.o
	-@$(CC) $(CFLAGS) $(TEST)Cholesky.test.cpp -o $(TEMP)Cholesky.test.o
	-@$(CC) $(TEMP)Matrix.o $(TEMP)Cholesky.o $(TEMP)Cholesky.test.o -o $(TEMP)Cholesky$(EXT)

$(TEMP)Jacobi.o: Jacobi.cpp Jacobi.hpp 
	-@ECHO -n "Building Jacobi.cpp."
	-@$(CC) $(CFLAGS) Jacobi.cpp -o $(TEMP)Jacobi.o
	-@ECHO "...ok"

$(TEMP)Jacobi.test.o: $(TEST)Jacobi.test.cpp $(TEMP)Jacobi.o
	-@$(CC) $(CFLAGS) $(TEST)Jacobi.test.cpp -o $(TEMP)Jacobi.test.o
	-@$(CC) $(TEMP)Matrix.o $(TEMP)Jacobi.o $(TEMP)Jacobi.test.o -o $(TEMP)Jacobi$(EXT)


$(TEMP)GaussSeidel.o: GaussSeidel.cpp GaussSeidel.hpp 
	-@ECHO -n "Building GaussSeidel.cpp."
	-@$(CC) $(CFLAGS) GaussSeidel.cpp -o $(TEMP)GaussSeidel.o
	-@ECHO "...ok"

$(TEMP)GaussSeidel.test.o: $(TEST)GaussSeidel.test.cpp $(TEMP)GaussSeidel.o
	-@$(CC) $(CFLAGS) $(TEST)GaussSeidel.test.cpp -o $(TEMP)GaussSeidel.test.o
	-@$(CC) $(TEMP)Matrix.o $(TEMP)GaussSeidel.o $(TEMP)GaussSeidel.test.o -o $(TEMP)GaussSeidel$(EXT)

$(TEMP)QR.o: QR.cpp QR.hpp $(MATRIX)
	-@ECHO -n "Building QR.cpp...."
	-@$(CC) $(CFLAGS) QR.cpp -o $(TEMP)QR.o
	-@ECHO "...ok"

$(TEMP)Eigen.o: $(TEMP)Matrix.o 
	-@ECHO -n "Building Eigen.cpp."
	-@$(CC) $(CFLAGS) Eigen.cpp -o $(TEMP)Eigen.o
	-@ECHO "...ok"

