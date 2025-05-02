# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Default target
all: matrixlang

# Rule to build the executable
matrixlang: lex.yy.c parser.tab.c matrix.cpp utils.cpp
	$(CXX) $(CXXFLAGS) -o matrixlang lex.yy.c parser.tab.c matrix.cpp utils.cpp

# Rule to generate lexer source
lex.yy.c: lexer.l
	flex lexer.l

# Rule to generate parser source and header
parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

# Rule to clean up generated files
clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h matrixlang
