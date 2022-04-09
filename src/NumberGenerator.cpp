#include "../headers/NumberGenerator.h"

// NumberGenerator::NumberGenerator(int *arr, int size)
// 	: arr(arr)
// 	, size(size)
// {
// }

int NumberGenerator::seed = 0;

NumberGenerator::NumberGenerator(int size)
	: size(size)
	{ 
	arr = new int[size]; 
	for (int i = 0; i < size; i++){
		srand(i+size+seed);
	  	arr[i] = rand() % 200;
		//   arr[i] = rand() % 1000;
		}
	}

int* NumberGenerator::getArray() const{ return arr; } // does this work?

void NumberGenerator::getArrayContents() const{
	for (int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
 }

int NumberGenerator::getSize() const{ return size; }

int NumberGenerator::changeSeed(){
	seed++;
	return seed;
}

int NumberGenerator::changeSeed(int newSeed){
	seed = newSeed;
	return seed;
}

// NumberGenerator::~NumberGenerator(){
// 	delete[] arr; }