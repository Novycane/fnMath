# -------------------------
#      fnMath Make File
# 
#     -by Steven Novak
#
#        12.04.2017
# -------------------------

# ----- Compiler Options
CC 		= clang++
CFLAGS		= -g -std=c++11

# ----- Directories
SRCPATH		= src
BINPATH		= bin
TEMPPATH 	= tmp

# ----- Source Compilation
all		: Make_Dirs Matrix.o
	-@echo "Building All"

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
