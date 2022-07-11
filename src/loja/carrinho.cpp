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
void Carrinho::adicionarProduto(int id, double qtd)
{
	// se já existe o produto no carrinho, soma a quantidade
	if(ids_produtos.find(id) != ids_produtos.end())
	{
		ids_produtos[id] += qtd;
	}
	// se não existe, adiciona o produto
	else
	{
		ids_produtos[id] = qtd;
	}
}

/**
 * @brief Retorna os dados do carrinho
 * 
 * @return std::map<int, double> 
 */
std::map<int, double> Carrinho::getCarrinho()
{
	return ids_produtos;
}

/**
 * @brief Retorna a quantidade de um produto no carrinho
 * 
 * @param id 
 * @return double 
 */
double Carrinho::qtdNoCarrinho(int id)
{
	// se tiver o id de um produto no carrinho, retorna a quantidade
	if(ids_produtos.find(id) != ids_produtos.end())
	{
		return ids_produtos[id];
	}
	// se não tiver, retorna 0
	else
	{
		return 0;
	}
}

/**
 * @brief Remove um produto do carrinho
 * 
 * @param id 
 * @param qtd 
 */
void Carrinho::removerProduto(int id, double qtd)
{
	// se tiver o id de um produto no carrinho
	if(ids_produtos.find(id) != ids_produtos.end())
	{
		std::cout << ids_produtos[id]  << " " << qtd << std::endl;
		// se a quantidade for maior que a quantidade no carrinho, remove o produto do carrinho
		if(ids_produtos[id] <= qtd)
		{
			// remove do array
			ids_produtos.erase(id);
		}
		else
		{
			// se a quantidade for menor que a quantidade no carrinho, remove a quantidade do carrinho
			ids_produtos[id] -= qtd;
		}
	}
}