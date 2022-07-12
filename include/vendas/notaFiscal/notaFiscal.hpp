#ifndef _NOTA_FISCAL_HPP_
#define _NOTA_FISCAL_HPP_

#include "autoload.hpp"

class NotaFiscal
{
	protected:
		std::map<std::string, std::vector<Produto*>> venda;
	public:
		NotaFiscal(std::map<std::string, std::vector<Produto*>>);
		~NotaFiscal();
		void gerarNotaFiscal();
};

#endif