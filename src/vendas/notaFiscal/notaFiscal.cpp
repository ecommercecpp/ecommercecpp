
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
	std::cout << std::endl << "Nota Fiscal" << std::endl;
	for (auto cpf: venda)
	{
		Usuario* usuario = new Usuario();
		usuario = usuario->buscarUsuario(cpf.first);

		// Dados do cliente
		std::cout << "+-----------------------------------------------------+"<< std::endl;
		std::cout << "|                       CLIENTE                       |"<< std::endl;
		std::cout << "+-----------------------------------------------------+"<< std::endl;
		std::cout << "| NOME: " << usuario->getNome() << " |" << std::endl;
		std::cout << "| CPF: " << usuario->getCpf() << " |" << std::endl;
		std::cout << "| E-MAIL: " << usuario->getEmail() << " |" << std::endl;
		std::cout << "+-----------------------------------------------------+"<< std::endl;
		std::cout << "|                       ENDERECO                      |" << std::endl;
		std::cout << "+-----------------------------------------------------+"<< std::endl;
		std::cout << "| RUA: " << usuario->getEndereco().getRua() << " |" << std::endl;
		std::cout << "| NUMERO: " << usuario->getEndereco().getNumero() << " |" << std::endl;
		std::cout << "| BAIRRO: " << usuario->getEndereco().getBairro() << " |" << std::endl;
		std::cout << "| CIDADE: " << usuario->getEndereco().getCidade() << " |" << std::endl;
		std::cout << "| ESTADO: " << usuario->getEndereco().getEstado() << " |" << std::endl;
		std::cout << "| CEP: " << usuario->getEndereco().getCep() << " |" << std::endl;
		std::cout << "+-----------------------------------------------------+"<< std::endl;
		std::cout << "|                       PRODUTOS                      |" << std::endl;
		std::cout << "+-----------------------------------------------------+"<< std::endl;
		for (auto produto : cpf.second)
		{
			std::cout << "| NOME: " << produto->getNome() << " |" << std::endl;
			std::cout << "| PRECO: " << produto->getPreco() << " |" << std::endl;
			std::cout << "| QUANTIDADE: " << produto->getQtd() << " |" << std::endl;
			std::cout << "+-----------------------------------------------------+"<< std::endl;
		}
	}
}