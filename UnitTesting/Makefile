CC = g++
CCFLAGS = -Wall -g -lcppunit -ldl -fprofile-arcs -ftest-coverage -std=c++11
OBJS = IntVector.o IntVectorTest.o 
OBJS1 =  IntVector.o Main.o
cppTest : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

Main : $(OBJS1)
	$(CC) $(CCFLAGS) $^ -o $@

%.o : %.cc
	$(CC) $(CCFLAGS) -c $<

## generate the prerequistes and append to the desired file
.prereq : $(OBJS:.o=.cc) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cc) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :
	rm -f *.o *~ #* .#*

.PHONY : clean-all
clean-all : clean
	rm -f cppTest Main
