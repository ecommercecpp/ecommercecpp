#ifndef _CARRINHO_HPP_
#define _CARRINHO_HPP_

#include "autoload.hpp"

class Carrinho
{
	protected:
		std::map<int, double> ids_produtos;
		std::string cpf;
	public:
		Carrinho(std::string cpf);
		~Carrinho();
		void adicionarProduto(int id, double qtd);
		double qtdNoCarrinho(int id);
		void removerProduto(int id, double qtd);
		std::map<int, double> getCarrinho();
};

#endif