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
	if (usuarioLogado->ehAdministrador() == 1)
	{
		opcoesAdm();
	}
	else
	{
		std::cout << "Digite os IDs dos produtos para adicionar ao carrinho e digite 0 para sair" << std::endl;
	}
}

void Loja::opcoesAdm()
{
	std::cout << std::endl << "Opcoes de administrador:" << std::endl;
	std::cout << "1. Adicionar ou atualizar algum produto" << std::endl;
	std::cout << "3. Sair" << std::endl << std::endl;

	int opcao;
	std::cin >> opcao;

	switch (opcao)
	{
		case 1:
			adicionarProduto();
			break;
		case 3:
			break;
		default:
			break;
	}

	mostrarLoja();
}

void Loja::adicionarProduto()
{
	std::cout << std::endl << "Adicionar ou atualizar Produto:" << std::endl;

	std::string comando, nome, descricao, categoria, preco, quantidade, id;

	while (comando != "sair")
	{
		std::cout << "Digite o nome do produto ou sair: " << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
			nome = comando;

		std::cout << "Digite a descricao do produto ou sair: " << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
			descricao = comando;

		std::cout << "Digite o preco do produto ou sair: " << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
			preco = comando;

		std::cout << "Digite a quantidade do produto ou sair: " << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
			quantidade = comando;

		std::cout << "Digite o id do produto ou sair: " << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
			id = comando;

		// converte id para inteiro
		int idInt = std::stoi(id);
		// converte preco e quantidade para double
		double precoDouble = std::stod(preco);
		double quantidadeDouble = std::stod(quantidade);
		Produto produto(idInt, nome, descricao, quantidadeDouble, precoDouble);

		estoque->adicionar(produto, true);

		opcoesAdm();
	}
}