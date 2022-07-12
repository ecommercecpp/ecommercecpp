
#include "autoload.hpp"

/**
 * @brief Construct a new Nota Fiscal:: Nota Fiscal object
 * 
 * @param vendas 
 */
NotaFiscal::NotaFiscal(std::map<std::string, std::vector<Produto*>> venda)
{
	this->venda = venda;
}

/**
 * @brief Destroy the Nota Fiscal:: Nota Fiscal object
 * 
 */
NotaFiscal::~NotaFiscal()
{
	for (auto it = venda.begin(); it != venda.end(); it++)
	{
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			delete *it2;
		}
	}
}

/**
 * @brief Gera uma nota fiscal para a venda
 * 
 */
void NotaFiscal::gerarNotaFiscal()
{
	std::cout << "Nota fiscal gerada com sucesso!" << std::endl;
}