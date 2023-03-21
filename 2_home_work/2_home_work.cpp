
#include <iostream>
class smart_array {
private:
	int size = 0;
	int* arr;
	int index_ = 0;
public:
	


	smart_array(int size_) {
		size = size_;
		arr = new int[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = 0;
		}
	}
	smart_array(const smart_array& new_array) {
		index_ = new_array.index_;
		size = new_array.size;
		arr = new int[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = new_array.arr[i];
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

		if ((index < size) && (index >= 0)) {
			return arr[index];
		}
		else if (index < 0) {
			throw std::runtime_error("Index must be a positive number");
		}

		else {
			throw std::runtime_error("Array index, greater than the number of elements");
		}
	}

	smart_array& operator=(const smart_array& new_array) {
		if (this != &new_array) {
			delete[] arr;
			index_ = new_array.index_;
			size = new_array.size;
			arr = new int[size];
			for (int i = 0; i < size; ++i) {
				arr[i] = new_array.arr[i];
			}
		}
		return *this;
	}
};

int main()
{

	try {
		smart_array arr(5);
		arr.add_element(5);
		arr.add_element(18);
		arr.add_element(155);

		smart_array new_arr(2);
		new_arr.add_element(1);
		new_arr.add_element(4);

		new_arr = arr;
		smart_array arr2(arr);
		
// Проверка
		for (int i = 0; i < 5; ++i) {
			std::cout << arr.get_element(i) << "\t";
		}
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	}
