all: clean build

build:
	cmake -B build
	cmake --build build
run:
	build/newbuuz
clean:
	rm -rf build