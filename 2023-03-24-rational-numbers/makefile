build-dir:
	mkdir -p build

rational-numbers: build-dir rational-numbers.cpp
	g++ ./rational-numbers.cpp -o build/rational-numbers -std=c++23

rational-numbers-templated: build-dir rational-numbers-templated.cpp
	g++ ./rational-numbers-templated.cpp -o build/rational-numbers-templated -std=c++23

all: rational-numbers rational-numbers-templated