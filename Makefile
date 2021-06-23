CXX=g++
CXXFLAGS=-Wall

LIBRARIES=-lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE=bibliotech

SOURCES := $(wildcard *.cpp) $(wildcard **/*.cpp)

all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXECUTABLE) $(LIBRARIES)

run: all
	./$(EXECUTABLE) && rm $(EXECUTABLE)

clean:
	rm $(EXECUTABLE)
