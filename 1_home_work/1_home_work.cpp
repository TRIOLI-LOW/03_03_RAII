﻿
#include <iostream>
class smart_array {
private:
	int size = 0;
	int* arr;
	int index_ = 0;
public:
	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;

	smart_array(int size_) {
		size = size_;
		arr = new int[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = 0;
		}
	}
	
	~smart_array() {
		delete[] arr;
	}

	void add_element(int element) {
		
		if (index_ == size) {
			throw std::runtime_error("The array is full!");
		}
		if (index_ < size) {
			arr[index_] = element;
			(++index_);
		}
		
		
	}
	int get_element(int index) {

		if ((index < size) && (index >= 0)){
			return arr[index];
		}
		else if(index < 0){
			throw std::runtime_error("Index must be a positive number");
		}

		else {
			throw std::runtime_error ("Array index, greater than the number of elements");
		}
	}
	
};

int main()
{
	
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(0) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

