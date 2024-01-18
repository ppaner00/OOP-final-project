# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -g

# Target executable name
TARGET = programa

# Source files
SOURCES = main.cpp person.cpp student.cpp professor.cpp

# Build target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)

