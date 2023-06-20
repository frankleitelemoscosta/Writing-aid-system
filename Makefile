all: 

	g++ ./src/main.cpp ./src/File.cpp ./src/File.hpp ./src/Map.hpp ./src/Map.cpp -o ./build/objects/executavel

clean:

	rm -rf ./build/objects/executavel

run:

	./build/objects/executavel