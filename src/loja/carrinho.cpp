#include "autoload.hpp"

Carrinho::Carrinho(){}

Carrinho::~Carrinho(){}

void Carrinho::adicionarProduto(Produto* produto)
{
	this->produtos.push_back(produto);
}