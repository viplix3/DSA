#include <iostream>

template<typename T, size_t S>
class Array {
private:
	T m_data[S];

public:
	constexpr size_t size() const {
		return S;
	}

	T* data() {
		return m_data;
	}

	const T* data() const {
		return m_data;
	}

	T& operator [](size_t index) {
		return m_data[index];
	}

	const T& operator [](size_t index) const {
		return m_data[index];
	}
};

int main() {
	Array<int, 10> customArray;


	for(int i=0; i<customArray.size(); i++) {
		customArray[i] = i;
		std::cout << i << ": " << customArray[i] << std::endl;
	}

}