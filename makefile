# -------------------------
#      fnMath Make File
# 
#     -by Steven Novak
#
#        12.04.2017
# -------------------------

# ----- Variables

MAKE 		= make

# ----- Directories
TESTPATH 	= test
HEADPATH	= src
SRCPATH		= src
BINPATH		= bin
TEMPPATH 	= temp

# ----- Main Targets
all	: Matrix.o
	-@echo ----- Building All -----
	-@echo .
	-@echo .
	-@$(MAKE) -C ./$(SRCPATH)/LinAlg
	-@$(MAKE) -C ./$(SRCPATH)/Calculus
	-@$(MAKE) -C ./$(SRCPATH)/Optimization

TestAll : 
	-@$(MAKE) -C ./$(SRCPATH)/LinAlg Test

# ----- Dependencies
Matrix.o	: src/Matrix.cpp src/Matrix.hpp
	-@echo "Making Matrix Routines..."
	-@$(MAKE) -C ./$(SRCPATH)/LinAlg

# ----- Dependencies
Crypto.o	: src/Rijndael.cpp src/Rijndael.hpp
	-@echo "Making Crypto Routines..."
	-@${CC} $(CFLAGS) -c src/Rijndael.cpp ${CFLAGS} -o $(TEMPPATH)/Rijndael.o
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
	-@rm $(BINPATH)\*.o
	-@rm $(TEMPPATH)\*.*
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
