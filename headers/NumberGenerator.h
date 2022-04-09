#pragma once
#define NUMBERGENERATOR_H

#include <random>
#include <iostream>

class NumberGenerator{
private:
	int size;
	int *arr;
	static int seed; // seed for the generator
public:
	// NumberGenerator(int *arr, int size);
	NumberGenerator();
	NumberGenerator(int size); // generator is based on size and seed
	int* getArray() const;
	void getArrayContents() const;
	int getSize() const;
	int changeSeed();
	int changeSeed(int newSeed);
	~NumberGenerator(){
		delete[] arr;
	}
};
