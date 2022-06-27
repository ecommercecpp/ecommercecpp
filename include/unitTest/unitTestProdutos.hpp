#ifndef _UNIT_TEST_PRODUTOS_HPP_
#define _UNIT_TEST_PRODUTOS_HPP_

#include "../autoload.hpp"

class UnitTestNome : public UnitTest
{
    public:
        void run() override;
};

class UnitTestQtd : public UnitTest
{
    public:
        void run() override;
};

class UnitTestDescricao : public UnitTest
{
    public:
        void run() override;
};

#endif