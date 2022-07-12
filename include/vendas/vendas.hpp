#ifndef _VENDAS_HPP_
#define _VENDAS_HPP_

#include "autoload.hpp"

class Vendas
{
	protected:
		std::map<int, std::map<std::string, std::vector<Produto*>>> vendas;
		static int controleId;
	public:
		Vendas();
		~Vendas();
		void adicionarVenda(std::map<int, double> dadosCarrinho, EstoqueBase *estoque, std::string cpf);
		void gerarJsonVenda(int controleId, std::string cpf);
		std::string dataAtual();
		void atualizaEstoque(int controleId, std::string cpf, EstoqueBase *estoque);
		void listarVendas();
		std::string dataVenda(int controleId, std::string cpf);
		double valorVenda(int controleId, std::string cpf);
};

#endif