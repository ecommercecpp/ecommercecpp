#ifndef _ESTOQUE_CLIENTE_HPP
#define _ESTOQUE_CLIENTE_HPP

#include "autoload.hpp"

class EstoqueCliente: public EstoqueBase
{
	public:
		virtual void listarEstoque() override;
};

#endif