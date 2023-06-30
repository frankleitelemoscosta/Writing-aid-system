all: 

	g++ ./src/main.cpp ./src/TotalMap.cpp ./src/Readtext.cpp ./src/Readtext.hpp ./src/TotalMap.hpp ./src/Utils.cpp ./src/Utils.hpp ./src/PartialMap.cpp ./src/PartialMap.hpp ./src/StopWords.hpp ./src/StopWords.cpp ./src/Expression.hpp ./src/Expression.cpp -o ./build/objects/executavel

clean:

	rm -rf ./build/objects/executavel

run:

	./build/objects/executavel