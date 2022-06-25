#ifndef _UNIT_TEST_PRODUTOS_HPP_
#define _UNIT_TEST_PRODUTOS_HPP_

#include "../autoload.hpp"

//testar sets e gets - getId e setId - 

void UnitTestNome::run()//nao pode retornar um caracter vazio e nao pode ser igual hah algum nome já registrado
{
	try
	{
		bool teste = false;
   		// seu código normal
		// ...
		// aqui, caso um valor não for true, lança um erro:
		if(Produto::getNome() == ""){
			teste = false;
		}
		//como consultar nomes que jah existem no banco?

		if(teste == true)
		{
			throw std::runtime_error("a variável 'teste' não é true");
		}

		// caso passar em todos os testes, use pass(); para passar o teste
		pass();
	}
	catch ( std::exception &e )
	{
		std::string aux;
		cin>>aux;
		Produto::setNome(aux);
		fail(std::string(e.what()));
	}
}

#endif