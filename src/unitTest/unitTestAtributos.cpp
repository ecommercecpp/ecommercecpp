#include "../../include/autoload.hpp"

/**
 * @brief Teste unitário para a classe Atributos
 * 
 */
void UnitTestAtributos::run()
{
	try {
		// cria um vector de 100 atributos aleatorios
		std::vector<Atributos*> atributos;
		for (int i = 0; i < 100; i++)
		{
			Atributos* atributo = new Atributos();
			atributo->adicionarAtributo("atributo" + std::to_string(i), { {"nivel" + std::to_string(i), "valor" + std::to_string(i)}, {"nivel2" + std::to_string(i), "valor2" + std::to_string(i)} });
			atributos.push_back(atributo);
		}	
		
		// verifica se o primeiro atributo tem o nome "atributo0"
		if (atributos[0]->getListaAtributos("atributo0")["nivel0"] != "valor0")
			throw std::runtime_error("Erro ao testar o atributo 0");

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