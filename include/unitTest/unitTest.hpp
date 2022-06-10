#ifndef _UNIT_TEST_HPP_
#define _UNIT_TEST_HPP_

#include "../autoload.hpp"

class UnitTest
{
	protected:
		bool passed = false;
		std::string error;
	public:
		void pass();
		void fail(std::string error);
		virtual void run() = 0;
		~UnitTest();
		void throwError(std::string error);
};

#endif