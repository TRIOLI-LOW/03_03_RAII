
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
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

