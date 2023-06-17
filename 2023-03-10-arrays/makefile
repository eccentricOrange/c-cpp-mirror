build-dir:
	mkdir -p build

determinant: build-dir determinant.cpp
	g++ ./determinant.cpp -o build/determinant -std=c++20

determinant-inheritance: build-dir determinant-inheritance.cpp
	g++ ./determinant-inheritance.cpp -o build/determinant-inheritance -std=c++20

arrays-from-scratch: build-dir arrays-from-scratch.cpp
	g++ ./arrays-from-scratch.cpp -o build/arrays-from-scratch -std=c++20

matrices: build-dir matrices.cpp
	g++ ./matrices.cpp -o build/matrices -std=c++20

all: determinant determinant-inheritance arrays-from-scratch matrices