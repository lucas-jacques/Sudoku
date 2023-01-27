TO_COMPILE = main.cpp grid/*.cpp solver/*.cpp utils/*.cpp

run:
	g++ -o SudokuSolver-build  $(TO_COMPILE)    && ./SudokuSolver-build
build:
	g++ -o SudokuSolver-build  $(TO_COMPILE)
debug:
	g++ -g -o SudokuSolver-build-debug  $(TO_COMPILE)    && ./SudokuSolver-debug