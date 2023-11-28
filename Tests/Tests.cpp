#include "pch.h"
#include "CppUnitTest.h"
#include "..//AKiOS_Lab2/includes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(TestMakeLIFO)
		{			
			LIFOElem* tail = nullptr;
			tail = AddToLIFO(tail, 1);
			tail = AddToLIFO(tail, 2);
			tail = AddToLIFO(tail, 3);
			tail = AddToLIFO(tail, 4);
			tail = AddToLIFO(tail, 5);

			Assert::AreEqual(tail->value, 5);
		}
	};
}
