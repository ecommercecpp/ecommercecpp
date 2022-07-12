#ifndef _LOJA_HPP_
#define _LOJA_HPP_

#include "autoload.hpp"

class Loja
{
	protected:
		Usuario* usuarioLogado;
		EstoqueBase* estoque;
		Carrinho *carrinho;
		Vendas* vendas;
	public:
		Loja(Usuario* usuarioLogado, EstoqueBase* estoque, Carrinho* carrinho, Vendas* vendas);
		Loja();
		~Loja();
		void mostrarLoja();
		void adicionarProdutoCarrinho();
		void adicionarProdutoEstoque();
		void removerProdutoEstoque();
		void removerProdutosNoCarrinho();
		void listarProdutosNoCarrinho();
		void opcoesAdm();
		void opcoesUsuario();
		void finalizarCompra();
		void listarVendas();
};

#endif