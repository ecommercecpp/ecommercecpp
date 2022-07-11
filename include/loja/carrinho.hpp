#ifndef _CARRINHO_HPP_
#define _CARRINHO_HPP_

#include "autoload.hpp"

class Carrinho
{
	protected:
		std::vector<Produto*> produtos;
	public:
		Carrinho();
		~Carrinho();
		void adicionarProduto(Produto* produto);
};

#endif