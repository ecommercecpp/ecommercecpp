#ifndef _ESTOQUE_ADM_HPP
#define _ESTOQUE_ADM_HPP

#include "autoload.hpp"

class EstoqueAdm: public EstoqueBase
{
	public:
		EstoqueAdm();
		virtual void listarEstoque() override;
		~EstoqueAdm();
};

#endif