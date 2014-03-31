-include Makefile.common

CXXFLAGS = -std=c++11 -g -Wall -Wshadow -Wextra -Wconversion -pedantic
CXX = g++

TARGET = hw3_1$(exe) hw3_2$(exe)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	-$(RM) $(TARGET)

%$(exe): %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
