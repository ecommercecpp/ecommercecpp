#include "autoload.hpp"

/**
 * @brief Construct a new Carrinho:: Carrinho object
 * 
 * @param cpf 
 */
Carrinho::Carrinho(std::string cpf)
{
	this->cpf = cpf;
}

/**
 * @brief Destroy the Carrinho:: Carrinho object
 * 
 */
Carrinho::~Carrinho(){}

/**
 * @brief Adiciona o id de um produto no carrinho
 * 
 * @param id 
 */
void Carrinho::adicionarProduto(int id)
{
	ids_produtos.push_back(id);
}

/**
 * @brief Retorna os ids de produtos no carrinho
 * 
 * @return std::vector<int> 
 */
std::vector<int> Carrinho::getCarrinho()
{
	return ids_produtos;
}