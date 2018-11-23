SHELL:=bash
CC = gcc
CXX = g++
CFLAGS = -std=c99
CXXFLAGS = -std=c++0x # C++11; -std=c++1y # C++14 
CXXFLAGS += -Wall # turn on all warnings
CXXFLAGS += -pedantic-errors # be sure to strictly enforce standard
# CXXFLAGS += -g # debugging info / for gdb use
# CXXFLAGS += -03 # optimization (should not be used with -g)
LDFLAGS = -lboost_date_time # to be utilized at a later date
# add --track-origins=yes to troubleshoot uninitialized values or conditional jumps
VGFLAGS = --tool=memcheck --leak-check=full #--show-leak-kinds=all
EXEC = tournament
CWD:=$(shell pwd)

HEADERS:=$(shell find . -maxdepth 2 -name "*.hpp")
SRCS:=$(shell find . -maxdepth 2 -name "*.cpp") 

# for all the source (.cpp) files found, generate .o filenames and assign to OBJS
OBJS = $(SRCS:.cpp=.o)

# target: dependencies
#		rule to build

# build executable from object files in cwd (using notdir to strip filepath from find)
${EXEC}: ${OBJS}
	${CXX} ${CXXFLAGS} $(notdir ${OBJS}) -o ${EXEC}

# build object files
${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

# run valgrind
.PHONY: valgrind 
valgrind:
	valgrind ${VGFLAGS} ${EXEC}

# clean cwd of object files and executable
.PHONY: clean
clean:
	rm -f *.o ${EXEC}
