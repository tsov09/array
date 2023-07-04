#include <iostream>
#include <stdlib.h>
#include <time.h>

class Array {
public:
	Array() {
		this->size = 10;
		this->ptr = new int[this->size];
		this->fill_array();
	}
	Array(int size) {
		this->size = size;
		this->ptr = new int[this->size];
		this->fill_array();
	}
	~Array() {
		delete [] this->ptr;
	}
	Array(const Array& obj) {
		delete[] this->ptr;
		this->ptr = nullptr;
		this->size = obj.size;
		this->ptr = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			this->ptr[i] = obj.ptr[i];
		}
	}
	Array& operator = (const Array& obj) {
		if (this != &obj) {
			delete[] this->ptr;
			this->ptr = nullptr;
			this->size = obj.size;
			this->ptr = new int[this->size];
			for (int i = 0; i < this->size; i++) {
				this->ptr[i] = obj.ptr[i];
			}
		}
		return *this;
	}
	int& operator[] (int i){
		if (i >= this->size || i < 0) {
			std::cout << "The number is out of range" << std::endl << std::endl;
			exit(0);
		}
		else {
			return this->ptr[i];
		}
	}
private:
	int* ptr;
	int size;
	void fill_array() {
		for (int i = 0; i < this->size; i++) {
			this->ptr[i] = rand() % 100 + 10;
		}
	}
public:
	int gen_element(int x) {
		if (x >= this->size || x < 0) {
			std::cout << "The number is out of range" << std::endl << std::endl;
			exit(0);
		}
		else {
			return this->ptr[x];
		}
	}
	void print() {
		std::cout << "{ ";
		for (int i = 0; i < this->size - 1; i++) {
			std::cout << this->ptr[i] << ", ";
		}
		std::cout << this->ptr[this->size - 1] << " }";

	}
};

int main() {
	srand(time(NULL));
	int a = 15;
	int b = 17;
	Array arr;

	std::cout << std::endl;
	arr.print();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << a + 1 << " - " << arr[a] << std::endl;
	std::cout << b + 1 << " - " << arr.gen_element(b) << std::endl;


	return 0;
}
 