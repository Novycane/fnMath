# -------------------------
#      fnMath Make File
# 
#     -by Steven Novak
#
#        12.04.2017
# -------------------------

# ----- Compiler Options
CC 		    = clang++
CFLAGS		= -g -std=c++11

# ----- Directories
TESTPATH 	= test
HEADPATH	= src
SRCPATH		= src
BINPATH		= bin
TEMPPATH 	= tmp

# ----- Main Targets
all		    : Make_Dirs Matrix.o
	-@echo "Building All"

test		: Make_Dirs $(TESTPATH)/main.cpp
	$(CC) $(CFLAGS) -c $(TESTPATH)/main.cpp -o $(TEMPPATH)/main.o
	$(CC) $(CFLAGS) $(TEMPPATH)/main.o -o $(BINPATH)/test.exe	

testMatrix  : Make_Dirs $(TESTPATH)/Matrix.test.cpp
	$(CC) $(CFLAGS) -c $(SRCPATH)/Matrix.cpp -o $(TEMPPATH)/MatrixTest.o
	$(CC) $(CFLAGS) -I $(HEADPATH) -c $(TESTPATH)/Matrix.test.cpp -o $(TEMPPATH)/MTEST.o
	$(CC) $(CFLAGS) $(TEMPPATH)/MTEST.o $(TEMPPATH)/MatrixTest.o -o $(BINPATH)/test
	./bin/test

# ----- Dependencies
Matrix.o	: src/Matrix.cpp src/Matrix.hpp
	-@echo "Making Matrix Routines..."
	-@${CC} $(CFLAGS) -c src/Matrix.cpp ${CFLAGS} -o $(TEMPPATH)/Matrix.o
	-@echo "Done!"

# ----- Utilities
.PHONY		:Make_Dirs
Make_Dirs:	
ifeq ("$(wildcard $(BINPATH)/.)","")
	-@echo "Adding bin path..."
	mkdir $(BINPATH)
endif
ifeq ("$(wildcard $(TEMPPATH)/.)","")
	-@echo "Adding temp path..."
	mkdir $(TEMPPATH)
endif

.PHONY		: clean
clean:
	-@rm $(BINPATH)/*.o
	-@rm $(TEMPPATH)/*.*
	-@rmdir $(TEMPPATH)
	-@rmdir $(BINPATH)
	-@echo "Done Cleaning..."

.PHONY		: help
help:
	-@echo
	-@echo "------ fnMath Library -----"
	-@echo "make all 	: Makes everything"
	-@echo "make clean	: Cleans up all files from make"
	-@echo "make debug	: Makes debugging version of library"
	-@echo "make NoTest	: Makes without unit tests"
	-@echo
