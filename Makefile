build-dir:
	mkdir -p build

exp: exp.cpp build-dir
	g++ exp.cpp -o build/exp -std=c++23

play: play.c build-dir
	gcc play.c -o build/play