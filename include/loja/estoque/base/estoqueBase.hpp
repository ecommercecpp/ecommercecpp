#ifndef _ESTOQUE_BASE_HPP_
#define _ESTOQUE_BASE_HPP_

#include "autoload.hpp"

class EstoqueBase {
	protected:
		std::map<int, Produto> estoque;
	public:
		EstoqueBase();
		void adicionar(Produto produto, bool adicionarNoArquivo);
		void remover(int id);
		void removerQtd(int id, double qtd);
		Produto* buscar(int id);
		virtual Produto* buscarPorSku(int sku);
		std::map<int, Produto>* getEstoque();
		virtual void listarEstoque() = 0;
		virtual ~EstoqueBase();
};

#endif