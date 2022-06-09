#ifndef _ESTOQUE_BASE_HPP_
#define _ESTOQUE_BASE_HPP_

#include "../../autoload.hpp"

class EstoqueBase {
	protected:
		std::map<int, Produtos> estoque;
};

#endif