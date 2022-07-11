#include "autoload.hpp"

/**
 * @brief Construct a new Loja:: Loja object
 * 
 * @param usuarioLogado 
 * @param estoque 
 */
Loja::Loja(Usuario* usuarioLogado, EstoqueBase* estoque)
{
	this->usuarioLogado = usuarioLogado;
	this->estoque = estoque;
}

/**
 * @brief Construct a new Loja:: Loja object
 * 
 */
Loja::Loja(){}

/**
 * @brief Destroy the Loja:: Loja object
 * 
 */
Loja::~Loja()
{
	delete usuarioLogado;
	delete estoque;
}

/**
 * @brief 	Mostra a loja
 * 
 */
void Loja::mostrarLoja()
{
	std::cout << std::endl << "Loja" << std::endl << std::endl << std::endl;
	
	estoque->listarEstoque();

	// caso o usuario seja administrador
	if (usuarioLogado->getTipo() == true)
	{
		// da opção de adicionar um produto
		std::cout << "Adicionar produto: " << std::endl;
		std::cout << "1 - Sim" << std::endl;
		std::cout << "2 - Não" << std::endl;

		int opcao;
		std::cin >> opcao;

		if (opcao == 1)
		{
			std::cout << "Digite o nome do produto: " << std::endl;
			std::string nome;
			std::cin >> nome;

			std::cout << "Digite a descricao do produto: " << std::endl;
			std::string descricao;
			std::cin >> descricao;

			std::cout << "Digite o preco do produto: " << std::endl;
			double preco;
			std::cin >> preco;

			std::cout << "Digite a quantidade do produto: " << std::endl;
			int quantidade;
			std::cin >> quantidade;

			std::cout << "Digite o id do produto: " << std::endl;
			int id;
			std::cin >> id;

			Produto produto(id, nome, descricao, quantidade, preco);
			estoque->adicionar(produto, true);
		}
		else
		{
			std::cout << "Não adicionou produto" << std::endl;
		}
	}
}
