#ifndef _AUTOLOAD_HPP_
#define _AUTOLOAD_HPP_

#include <vector>
#include <map>
#include <string>
#include <iostream>

// include de usuarios
#include "./usuarios/usuario.hpp"
#include "./usuarios/tipos/cliente.hpp"
#include "./usuarios/tipos/administrador.hpp"
#include "./usuarios/endereco/endereco.hpp"

// include de produtos
#include "./produtos/atributos/atributos.hpp"
#include "./produtos/produto.hpp"

// include de vendas
#include "./vendas/venda.hpp"
#include "./vendas/notaFiscal/notaFiscal.hpp"

// include da loja
#include "./loja/estoque/base/estoqueBase.hpp"
#include "./loja/loja.hpp"

//include de testes
#include "./unitTest/unitTest.hpp"
#include "./unitTest/unitTestEndereco.hpp"

#endif