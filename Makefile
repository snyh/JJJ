help:
	@echo "use make win or make lin"

win: 
	[ -d ./build/win ] || mkdir -p build/win
	cp ./mingw32.cmake build/win
	cd build/win/ && cmake -DCMAKE_TOOLCHAIN_FILE=./mingw32.cmake ../../ && make

lin:
	[ -d ./build/lin ] || mkdir -p build/lin
	cd build/lin/ && cmake ../../ && make
