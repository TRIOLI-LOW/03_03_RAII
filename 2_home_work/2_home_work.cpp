
#include <iostream>
class smart_array {
private:
	int size = 0;
	int* arr;
public:

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

		int i = 0;
		while ((i < size) && (arr[i] != 0)) {
			++i;
		}
		if (i == size) {
			throw std::runtime_error("The array is full!");
		}
		arr[i] = element;
	}
	int get_element(int index) {

		if (index < size) {
			return arr[index];
		}
		else {
			throw std::runtime_error("Array index, greater than the number of elements");
		}
	}
	smart_array& operator=(smart_array& new_array) {
			delete[] arr;
			size = new_array.size;
			arr = new int[size];
			for (int i = 0; i < size; ++i) {
				arr[i] = new_array.arr[i];
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

		arr = new_arr;
// Проверка
		for (int i = 0; i < 5; ++i) {
			std::cout << arr.get_element(i) << "\t";
		}
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	}
