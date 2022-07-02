#include "autoload.hpp"

/**
 * @brief Teste unitário para a classe Endereco
 * 
 */
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

		// testa todos os gets
		for (int i = 0; i < 100; i++)
		{
			if (enderecos[i]->getRua() != "Rua " + std::to_string(i))
				throw std::runtime_error("Erro ao testar o set da rua");
			if (enderecos[i]->getNumero() != i)
				throw std::runtime_error("Erro ao testar o set do numero");
			if (enderecos[i]->getComplemento() != "Complemento " + std::to_string(i))
				throw std::runtime_error("Erro ao testar o set do complemento");
			if (enderecos[i]->getCep() != i)
				throw std::runtime_error("Erro ao testar o set do CEP");
			if (enderecos[i]->getBairro() != "Bairro " + std::to_string(i))
				throw std::runtime_error("Erro ao testar o set do bairro");
			if (enderecos[i]->getCidade() != "Cidade " + std::to_string(i))
				throw std::runtime_error("Erro ao testar o set da cidade");
			if (enderecos[i]->getEstado() != "Estado " + std::to_string(i))
				throw std::runtime_error("Erro ao testar o set do estado");
		}

		// testa todos os sets
		for (int i = 0; i < 100; i++)
		{
			enderecos[i]->setRua("Rua " + std::to_string(i));
			enderecos[i]->setNumero(i);
			enderecos[i]->setComplemento("Complemento " + std::to_string(i));
			enderecos[i]->setCep(i);
			enderecos[i]->setBairro("Bairro " + std::to_string(i));
			enderecos[i]->setCidade("Cidade " + std::to_string(i));
			enderecos[i]->setEstado("Estado " + std::to_string(i));
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

		// pass the test
		pass();
	}
	catch ( std::exception &e )
	{
		// fail the test
		fail(std::string(e.what()));
	}
}