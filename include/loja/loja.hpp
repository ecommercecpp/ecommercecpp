#ifndef _LOJA_HPP_
#define _LOJA_HPP_

#include "autoload.hpp"

class Loja
{
	protected:
		Usuario* usuarioLogado;
		EstoqueBase* estoque;
		Carrinho *carrinho;
	public:
		Loja(Usuario* usuarioLogado, EstoqueBase* estoque, Carrinho *carrinho);
		Loja();
		~Loja();
		void mostrarLoja();
		void adicionarProdutoCarrinho();
		void adicionarProdutoEstoque();
		void removerProdutoEstoque();
		void opcoesAdm();
		void opcoesUsuario();
};

#endif