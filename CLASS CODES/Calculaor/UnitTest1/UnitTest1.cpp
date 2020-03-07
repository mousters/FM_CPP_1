#include "pch.h"
#include "CppUnitTest.h"

#include <Add.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(Add(1, 2), 3);
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(Add(1.3, 2.4), 3.7, 0.00001);
		}
	};
}
