CXX=g++
CXXFLAGS=-Wall

LIBRARIES=
EXECUTABLE=bibliotech

SOURCES := ${wildcard *.cpp} ${wildcard **/*.cpp}

all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXECUTABLE) $(LIBRARIES)

clean:
	rm $(EXECUTABLE)
