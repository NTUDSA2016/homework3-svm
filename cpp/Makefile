-include Makefile.common

CXXFLAGS = -std=c++11 -MMD -g -Wall -Wshadow -Wextra -Wconversion -pedantic -Iinclude
CXX = g++

OBJS = \
	bin/instruction \
	bin/tokenizer
TARGET = hw3_1$(exe)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	-$(RM) $(TARGET) $(call fixpath,bin/*)

# Compile the target file (e.g. hw3_1.exe)
$(TARGET): %$(exe): bin/%.o $(OBJS:=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile library files, e.g. `instruction`, `tokenizer`
bin/%.o: src/%.cpp
	$(call if_not_exist,bin,mkdir bin)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Include compiler-generated dependency files
-include $(OBJS:=.d)
