#ifndef _LOJA_HPP_
#define _LOJA_HPP_

#include "autoload.hpp"

class Loja
{
	protected:
		Usuario* usuarioLogado;
		EstoqueBase* estoque;
	public:
		Loja(Usuario* usuarioLogado, EstoqueBase* estoque);
		Loja();
		~Loja();
		void mostrarLoja();
		void adicionarProduto();
		void opcoesAdm();
};

#endif