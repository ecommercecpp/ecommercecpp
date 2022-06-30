#ifndef _ESTOQUE_BASE_HPP_
#define _ESTOQUE_BASE_HPP_

#include "../../../autoload.hpp"

class EstoqueBase {
	protected:
		std::map<int, Produto> estoque;
	public:
		EstoqueBase();
		void adicionar(Produto produto);
		void remover(int id);
		Produto* buscar(int id);
		std::map<int, Produto>* getEstoque();
};

#endif