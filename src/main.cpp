#include "../include/autoload.hpp"

// int main com args
int main(int argc, char *argv[])
{
	// se o argc for maior que 1
	if (argc > 1)
	{
		// se o primeiro argumento for "--help"
		if (std::string(argv[1]) == "--help")
		{
			// imprime o help
			std::cout << "Ecommerce: " << std::endl;
			std::cout << "  --help: mostra essa mensagem" << std::endl;
			std::cout << "  --test: executa os testes" << std::endl;
		}
		else if (std::string(argv[1]) == "--test")
		{	
			if (std::string(argv[2]) == "endereco")
			{
				UnitTestEndereco unitTestEndereco;
				unitTestEndereco.run();
			}

			if (std::string(argv[2]) == "produtos")
			{
				UnitTestProdutos unitTestProdutos;
				unitTestProdutos.run();
			}

			if (std::string(argv[2]) == "atributos")
			{
				UnitTestAtributos unitTestAtributos;
				unitTestAtributos.run();
			}

			if (std::string(argv[2]) == "usuario")
			{
				UnitTestUsuario unitTestUsuario;
				unitTestUsuario.run();
			}

			if (std::string(argv[2]) == "estoqueBase")
			{
				UnitTestEstoqueBase unitTestEstoqueBase;
				unitTestEstoqueBase.run();
			}
		}
		
	}
	else
	{
		std::cout << "Hello World!" << std::endl;
	}

	return 0;
}