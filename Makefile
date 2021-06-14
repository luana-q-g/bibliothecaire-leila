CXX=g++
CXXFLAGS=-Wall

LIBRARIES=
EXECUTABLE=output

SOURCES := ${wildcard *.cpp} ${wildcard **/*.cpp}

all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXECUTABLE) $(LIBRARIES)

clean:
	rm $(EXECUTABLE)
