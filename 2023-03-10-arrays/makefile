build-dir:
	mkdir -p build

determinant: build-dir determinant.cpp
	g++ ./determinant.cpp -o build/determinant -std=c++23

determinant-inheritance: build-dir determinant-inheritance.cpp
	g++ ./determinant-inheritance.cpp -o build/determinant-inheritance -std=gnu++23

arrays-from-scratch: build-dir arrays-from-scratch.cpp
	g++ ./arrays-from-scratch.cpp -o build/arrays-from-scratch -std=c++23

matrices: build-dir matrices.cpp
	g++ ./matrices.cpp -o build/matrices -std=c++23

all: determinant determinant-inheritance arrays-from-scratch matrices