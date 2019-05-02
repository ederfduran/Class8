#include <algorithm>
#include <cassert>

#include "DynamicArray.h"

cpp_class8::DynamicArray::DynamicArray(const size_t size) :mSize(size), mArray(new int[size])
{
	for (unsigned int i = 0;i<size;i++) {
		mArray[i] = -1;
	}
}

cpp_class8::DynamicArray::DynamicArray(const DynamicArray & other):mSize(other.getSize()),mArray(new int[other.getSize()])
{
	// What Option is better?
	std::memcpy(mArray,other.mArray,sizeof(int)* other.getSize());
	/*for (unsigned int i = 0; i< other.getSize(); i++) {
		mArray[i] = other.mArray[i];
	}*/
}

cpp_class8::DynamicArray::~DynamicArray()
{
	delete[] mArray;
}

size_t cpp_class8::DynamicArray::getSize() const
{
	return mSize;
}

int & cpp_class8::DynamicArray::operator[](const size_t value)const
{
	assert(mSize>value);
	return mArray[value];
}

const cpp_class8::DynamicArray & cpp_class8::DynamicArray::operator=(const DynamicArray & other)
{
	if (this==&other) {
		return *this;
	}
	mSize = other.getSize();
	delete[] mArray;
	mArray = new int[mSize];
	for (unsigned int i = 0; i< mSize; i++) {
		mArray[i] = other.mArray[i];
	}
	return *this;
}

const cpp_class8::DynamicArray& cpp_class8::DynamicArray::operator+=(const DynamicArray& other) {
	const size_t newSize = mSize + other.getSize();
	int* const newArray = new int[newSize];
	unsigned int i = 0;
	for (;i<mSize;i++) {
		newArray[i] = mArray[i];
	}
	for (unsigned int j=0; j<other.getSize(); j++) {
		newArray[i] = other.mArray[j];
		i++;
	}
	delete[] mArray;
	mArray = newArray;
	mSize = newSize;
	return *this;
}

cpp_class8::DynamicArray cpp_class8::DynamicArray::operator+(const DynamicArray & other)const{
	const size_t newSize = mSize + other.getSize();
	DynamicArray newArr(newSize);
	unsigned int i = 0;
	for (; i<mSize; i++) {
		newArr.mArray[i] = mArray[i];
	}
	for (unsigned int j = 0; j<other.getSize(); j++) {
		newArr.mArray[i] = other.mArray[j];
		i++;
	}

	return newArr;
}

bool cpp_class8::DynamicArray::operator==(const DynamicArray & arr)const
{
	if (arr.getSize()!=mSize) {
		return false;
	}
	for (unsigned int i = 0;i<mSize;i++) {
		if (mArray[i]!=arr.mArray[i]) {
			return false;
		}
	}
	return true;
}

bool cpp_class8::DynamicArray::operator!=(const DynamicArray & arr)const
{
	if (arr.getSize() != mSize) {
		return true;
	}
	for (unsigned int i = 0; i<mSize; i++) {
		if (mArray[i] != arr.mArray[i]) {
			return true;
		}
	}
	return false;
}

std::ostream & cpp_class8::operator<<(std::ostream & os, const DynamicArray & arr)
{
	os << "[";
	for (unsigned int i = 0;i<arr.getSize()-1;i++) {
		os << arr.mArray[i]<< ", ";
	}
	os <<  arr.mArray[arr.getSize() - 1] << "]";
	return os;
}
