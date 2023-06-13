all: 

	g++ ./src/main.cpp ./src/File.cpp ./src/File.hpp ./src/Hashtable.cpp ./src/Hashtable.hpp -o ./build/objects/executavel

clean:

	rm -rf ./build/objects/executavel

run:

	./build/objects/executavel