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
TESTPATH 	= test/
HEADPATH	= src/
SRCPATH		= src/
BINPATH		= c:\fnMath
TEMP 	= temp/

MAIN = $(TEMP)LinAlg.o $(TEMP)Calculus.o $(TEMP)Optimization.o $(TEMP)Stats.o

LINALG = $(TEMP)Matrix.o $(TEMP)QR.o $(TEMP)LU.o $(TEMP)Cholesky.o $(TEMP)Eigen.o
CALC = $(TEMP)Derivative.o $(TEMP)Integral.o
STATS = $(TEMP)Factorial.o $(TEMP)FisherYates.o $(TEMP)Gamma.o $(TEMP)MetropolisHastings.o $(TEMP)Random.o
OPT	= $(TEMP)GradientDescent.o

ALL = $(LINALG) $(CALC) $(STATS) $(OPT)

# ----- Main Targets
.SILENT:

all	: $(MAIN)
	-@echo ----- Building All -----

TestAll : 
	-@$(MAKE) -C ./$(SRCPATH)/LinAlg Test
	-@$(MAKE) -C ./$(SRCPATH)/Calculus Test
	-@$(MAKE) -C ./$(SRCPATH)/Optimization Test
	-@$(MAKE) -C ./$(SRCPATH)/Stats Test
	
TestStats : 
	-@$(MAKE) -C ./$(SRCPATH)/Stats Test

TestLinAlg : 
	-@$(MAKE) -C ./$(SRCPATH)/LinAlg Test
	
Install: $(TEMP)fnMath.lib
	-@copy temp\fnMath.lib c:\Lib\fnMath /Y
	-@copy src\*.h c:\Lib\fnMath /Y
	-@copy src\*.hpp c:\Lib\fnMath /Y
	
	-@$(MAKE) -C ./$(SRCPATH)/LinAlg Install
	-@$(MAKE) -C ./$(SRCPATH)/Calculus Install
	-@$(MAKE) -C ./$(SRCPATH)/Optimization Install
	-@$(MAKE) -C ./$(SRCPATH)/Stats Install

# ----- Dependencies
$(TEMP)fnMath.lib: $(MAIN)
	-@echo "--------------------------------------------------"
	-@echo "Making fnMath Lib..."
	-@echo "--------------------------------------------------"
	-@ld -r $(ALL) -o $(TEMP)fnMath.lib

$(TEMP)LinAlg.o	: 
	-@echo "--------------------------------------------------"
	-@echo "Making Matrix Routines..."
	-@echo "--------------------------------------------------"
	-@$(MAKE) -C ./$(SRCPATH)LinAlg

$(TEMP)Calculus.o: 
	-@echo "--------------------------------------------------"
	-@echo "Making Calculus Routines..."
	-@echo "--------------------------------------------------"
	-@$(MAKE) -C ./$(SRCPATH)Calculus

$(TEMP)Optimization.o: 
	-@echo "--------------------------------------------------"
	-@echo "Making Optimization Routines..."
	-@echo "--------------------------------------------------"
	-@$(MAKE) -C ./$(SRCPATH)Optimization
	
$(TEMP)Stats.o:
	-@echo "--------------------------------------------------"
	-@echo "Making Statistics Routines..."
	-@echo "--------------------------------------------------"
	-@$(MAKE) -C ./$(SRCPATH)Stats

# ----- Dependencies
Crypto.o	: src/Rijndael.cpp src/Rijndael.hpp
	-@echo "Making Crypto Routines..."
	-@${CC} $(CFLAGS) -c src/Rijndael.cpp ${CFLAGS} -o $(TEMPPATH)Rijndael.o
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
