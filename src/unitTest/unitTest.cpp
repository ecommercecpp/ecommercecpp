#include "../../include/autoload.hpp"

/**
 * @brief Passa o teste unitário
 * 
 */
void UnitTest::pass()
{
	this->passed = true;
}

/**
 * @brief Rejeita o teste unitário
 * 
 * @param error 
 */
void UnitTest::fail(std::string error)
{
	this->passed = false;
	this->error = error;
}

/**
 * @brief Destroy the Unit Test:: Unit Test object
 * 
 */
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

/**
 * @brief Lança uma exceção de erro
 * 
 * @param error 
 */
void UnitTest::throwError(std::string error)
{
	throw std::runtime_error(error);
}