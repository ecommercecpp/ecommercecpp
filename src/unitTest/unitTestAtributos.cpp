#include "../../include/autoload.hpp"

/**
 * @brief Teste unitário para a classe Atributos
 * 
 */
void UnitTestEndereco::run()
{
	try {
		// cria um vector de 100 atributos aleatórios
		std::vector<Atributos*> atributos;
		for (int i = 0; i < 100; i++)
		{
			Atributos *atributo = new Atributos();
			atributos.push_back(atributo);
		}

		// remove os endereços
		for (int i = 0; i < 100; i++)
		{
			delete atributos[i];
		}
		
		// remove o vector
		atributos.clear();

		// thrown an error if the vector is not empty
		if (atributos.size() != 0)
		{
			throw std::runtime_error("The vector is not empty");
		}

		// pass the test
		pass();
	}
	catch ( std::exception &e )
	{
		// fail the test
		fail(std::string(e.what()));
	}
}