#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\Lab 6.4 rec\Lab 6.4 rec\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<double> arr = { 1.5, -2.0, 3.5, -4.0, 0.0, 5.0 };
			double result = sum_positive_elements(arr);
			Assert::AreEqual(10.0, result, 0.01);
		}
	};
}
