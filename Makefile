###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Victoria Chen



##
## Put your variables and rules here.  You can use previous Makefiles
## as examples, and you can refer to the "make" documentation on the
## course Reference page.
##  --- Delete this comment and put appropriate comments in ---


##
## Here is a rule for compiling .cyl files for use in your testing
##
%.cylc:  %.cyl
	./cylc $^

CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3


INCLUDES = $(shell echo *.h)
EXECS    = testDatumStack testRPNCalc CalcYouLater

DatumStack: DatumStack.o Datum.o main.o
	${CXX} ${LDFLAGS} $^ -o $@

CalcYouLater: RPNCalc.o DatumStack.o Datum.o main.o
	${CXX} ${LDFLAGS} $^ -o $@

testDatumStack: testDatumStack.o Datum.o
	${CXX} ${LDFLAGS} $^ -o $@

testRPNCalc: testRPNCalc.o RPNCalc.o DatumStack.o Datum.o
	${CXX} ${LDFLAGS} $^ -o testRPNCalc



%.o: %.cpp ${INCLUDES}
	${CXX} ${CXXFLAGS} -c -o $@ $<

.PHONY: clean
clean:
	rm -f ${EXECS} *.o *.dSYM./
