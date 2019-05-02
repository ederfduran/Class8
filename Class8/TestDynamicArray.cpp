#include <cassert>

#include "DynamicArray.h"
#include "TestDynamicArray.h"

void cpp_class8_test::TestDynamicArray::testConstructor() 
{
	const size_t mockSize = 10;
	cpp_class8::DynamicArray test(mockSize);
	for (unsigned int i = 0; i < mockSize; i++)
	{
		assert(test.mArray[i]==-1);
	}

	cpp_class8::DynamicArray test2 = test;
	for (unsigned int i = 0; i < mockSize; i++)
	{
		assert(test2.mArray[i] == -1);
	}

}

void cpp_class8_test::TestDynamicArray::testGetSize() 
{
	const size_t mockSize = 100;
	cpp_class8::DynamicArray test(mockSize);
	assert(test.mSize==mockSize && test.getSize()== mockSize);
}

void cpp_class8_test::TestDynamicArray::testBraquetOperator()
{
	const int mockResult[10] = { 0,1,2,3,4,-1,-1,-1,-1,-1 };
	const size_t mockSize = 10;
	cpp_class8::DynamicArray test(mockSize);
	for (unsigned int i = 0;i<mockSize/2;i++) {
		test[i] = i;
	}
	for (unsigned int i = 0; i<mockSize; i++) {
		assert(test[i]==mockResult[i]); 
	}
}

void cpp_class8_test::TestDynamicArray::testPlusEqual()
{
	const int mockResult[10] = { 0,1,2,3,4,5,-1,0,1,2};
	const size_t mockSize = 6;
	const size_t mockSize2 = 4;
	cpp_class8::DynamicArray test(mockSize);
	for (unsigned int i = 0; i<mockSize; i++) {
		test[i] = i;
	}
	cpp_class8::DynamicArray test2(mockSize2);
	for (unsigned int i = 0; i<mockSize2; i++) {
		test2[i] += i;
	}
	test += test2;
	for (unsigned int i = 0; i<10; i++) {
		assert(test[i]== mockResult[i]);
	}
}

void cpp_class8_test::TestDynamicArray::testEqualEqual()
{
	const size_t mockSize = 10;
	cpp_class8::DynamicArray test(mockSize);
	cpp_class8::DynamicArray test2(mockSize);
	for (unsigned int i = 0; i < mockSize; i++)
	{
		test.mArray[i] += i+1;
		test2.mArray[i] += i + 1;
	}
	assert(test==test2);
}

void cpp_class8_test::TestDynamicArray::testDifferent()
{
	const size_t mockSize = 10;
	cpp_class8::DynamicArray test(mockSize);
	cpp_class8::DynamicArray test2(mockSize);
	for (unsigned int i = 0; i < mockSize; i++)
	{
		test.mArray[i] += i + 1;
		test2.mArray[i] += i + 2;
	}
	assert(test != test2);
}

void cpp_class8_test::TestDynamicArray::testPrintOperator()
{
	const size_t mockSize = 10;
	cpp_class8::DynamicArray test(mockSize);
	for (unsigned int i = 0; i < mockSize; i++)
	{
		test.mArray[i] += i + 1;
	}
	std::cout << test << std::endl;
}
