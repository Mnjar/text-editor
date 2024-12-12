# Variabel
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = 
SRC = src/text_editor.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = text_editor

# Testing
TEST_SRC = test/test_editor.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_TARGET = run_tests

# Build rule
all: $(TARGET)

$(TARGET): $(OBJ) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Testing rule
test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_OBJ) $(TEST_TARGET) main.o

# Phony target
.PHONY: all clean
