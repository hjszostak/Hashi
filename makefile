CXXFLAGS= -O -Wall -g -std=c++0x -MMD
CXX=g++
OBJECTS = \
Main.o Hashi.o Coordinate.o Grid.o GridComponent.o\
Island.o Bridge.o BadBridge.o\
IslandIterator.o BridgeIterator.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC=hashi

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS) 


clean:
	rm -f *.o $(EXEC) $(TESTS) $(DEPENDS)

-include ${DEPENDS}