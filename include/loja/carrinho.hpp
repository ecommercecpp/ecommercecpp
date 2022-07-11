#ifndef _CARRINHO_HPP_
#define _CARRINHO_HPP_

#include "autoload.hpp"

class Carrinho
{
	protected:
		std::vector<int> ids_produtos;
		std::string cpf;
	public:
		Carrinho(std::string cpf);
		~Carrinho();
		void adicionarProduto(int id);
		std::vector<int> getCarrinho();
};

#endif