#ifndef _ESTOQUE_CLIENTE_HPP
#define _ESTOQUE_CLIENTE_HPP

#include "autoload.hpp"

class EstoqueCliente: public EstoqueBase
{
	public:
		EstoqueCliente();
		virtual void listarEstoque() override;
		~EstoqueCliente();
		virtual Produto* buscarPorSku(int sku) override;
};

#endif