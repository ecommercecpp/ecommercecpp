#include "../../include/autoload.hpp"

void UnitTest::pass()
{
	this->passed = true;
}

void UnitTest::fail(std::string error)
{
	this->passed = false;
	this->error = error;
}

UnitTest::~UnitTest()
{
	if (this->passed)
	{
		std::cout << "UnitTest: pass" << std::endl;
	}
	else
	{
		std::cout << "UnitTest: fail" << std::endl;
		throwError(this->error);
	}
}

void UnitTest::throwError(std::string error)
{
	throw std::runtime_error(error);
}