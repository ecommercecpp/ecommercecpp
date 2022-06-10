#include "../../include/autoload.hpp"


void UnitTestEndereco::run()
{
	try {
		// cria um vector de 100 endereços aleatórios
		std::vector<Endereco*> enderecos;
		for (int i = 0; i < 100; i++)
		{
			Endereco *endereco = new Endereco(
				"Rua " + std::to_string(i),
				i,
				"Complemento " + std::to_string(i),
				i,
				"Bairro " + std::to_string(i),
				"Cidade " + std::to_string(i),
				"Estado " + std::to_string(i)
			);
			enderecos.push_back(endereco);
		}

		// remove os endereços
		for (int i = 0; i < 100; i++)
		{
			delete enderecos[i];
		}
		
		// remove o vector
		enderecos.clear();

		// thrown an error if the vector is not empty
		if (enderecos.size() != 0)
		{
			throw std::runtime_error("The vector is not empty");
		}

		std::cout << "UnitTestEndereco:" << std::endl;
	}
	catch ( std::exception &e )
	{
		throw std::runtime_error("UnitTestEndereco: ERRO: " + std::string(e.what()));
	}
}