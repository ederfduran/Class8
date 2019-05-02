#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_
#include <iostream>

namespace cpp_class8_test {
	class TestDynamicArray;
}

namespace cpp_class8 {
	class DynamicArray {
	private:
		size_t mSize;
		int* mArray;
	public:
		friend class cpp_class8_test::TestDynamicArray;
		DynamicArray(const size_t size);
		DynamicArray(const DynamicArray& other);
		~DynamicArray();
		size_t getSize() const;
		int& operator[](const size_t value)const;
		const DynamicArray& operator=(const DynamicArray& other);
		const DynamicArray& operator+=(const DynamicArray&);
		DynamicArray operator+(const DynamicArray&)const;
		bool operator ==(const DynamicArray&)const;
		bool operator !=(const DynamicArray&)const;
		friend std::ostream& operator <<(std::ostream &os,const DynamicArray&) ;
	
	};
}

#endif // !DYNAMIC_ARRAY_H_

