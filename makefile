#Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

#Project executable output file
PROJ = project

#Object files
OBJS = main.o menu.o Tournament.o CircularQueue.o Stack.o Creature.o Die.o

#Source files
SRCS = main.cpp menu.cpp Tournament.cpp CircularQueue.cpp Stack.cpp Creature.cpp Die.cpp

#Header files
HEADERS = menu.hpp Tournament.hpp CircularQueue.hpp Stack.hpp Creature.hpp Die.hpp

#Compile project executable from object files
${PROJ}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROJ}

#Compile object files from source files
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#Remove project executable and object files
clean:
	rm ${PROJ} ${OBJS}

#Citation:
#Format of this makefile based off of: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4