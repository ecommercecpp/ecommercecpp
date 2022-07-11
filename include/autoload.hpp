#ifndef _AUTOLOAD_HPP_
#define _AUTOLOAD_HPP_

#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

// include third_party
#include "../third_party/json.hpp"

// exceptions
#include "./exceptions/exceptions.hpp"

// include de usuarios
#include "./usuarios/endereco/endereco.hpp"
#include "./usuarios/usuario.hpp"

// include de produtos
#include "./produtos/atributos/atributos.hpp"
#include "./produtos/produto.hpp"

// include de vendas
#include "./vendas/venda.hpp"
#include "./vendas/notaFiscal/notaFiscal.hpp"

// include da loja
#include "./loja/estoque/base/estoqueBase.hpp"
#include "./loja/estoque/estoqueAdm.hpp"
#include "./loja/estoque/estoqueCliente.hpp"
#include "./loja/loja.hpp"

//include de testes
#include "./unitTest/unitTest.hpp"
#include "./unitTest/unitTestEndereco.hpp"
#include "./unitTest/unitTestAtributos.hpp"
#include "./unitTest/unitTestUsuario.hpp"
#include "./unitTest/unitTestProdutos.hpp"
#include "./unitTest/unitTestEstoqueBase.hpp"

#include "./cli/cli.hpp"

#endif