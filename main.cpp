#include <iostream>
//#include <string>

class Array {
public:
	Array(int size) {
		this->size = size;
		this->ptr = new int[this->size];
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
		if (i >= this->size) {
			std::cout << "The number is out of range" << std::endl;
			exit(0);
		}
		else {
			return this->ptr[i];
		}
	}

	//Time operator+(const Time& lhs, const Time& rhs) {
//	Time temp = lhs;
//	temp.seconds += rhs.seconds;
//	temp.minutes += temp.seconds / 60;
//	temp.seconds %= 60;
//	temp.minutes += rhs.minutes;
//	temp.hours += temp.minutes / 60;
//	temp.minutes %= 60;
//	temp.hours += rhs.hours;
//	return temp;
//}

private:
	int* ptr;
	int size;
public:
	int gen_element(int x) {
		return x;
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

	Array arr(10);
	arr.print();
	std::cout << arr[18];

	std::cout << std::endl;

	Array arr_1(7);
	arr_1.print();
	
	std::cout << std::endl;

	arr_1 = arr;
	arr.print();
	std::cout << std::endl;
	Array arr_2 = arr;
	arr_2.print();

	return 0;
}
