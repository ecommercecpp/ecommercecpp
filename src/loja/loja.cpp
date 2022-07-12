#include "autoload.hpp"

/**
 * @brief Construct a new Loja:: Loja object
 * 
 * @param usuarioLogado 
 * @param estoque 
 * @param carrinho 
 */
Loja::Loja(Usuario* usuarioLogado, EstoqueBase* estoque, Carrinho *carrinho, Vendas* vendas)
{
	this->usuarioLogado = usuarioLogado;
	this->estoque = estoque;
	this->carrinho = carrinho;
	this->vendas = vendas;
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
	delete carrinho;
	delete vendas;
}

/**
 * @brief Lista as vendas realizadas
 * 
 */
void Loja::listarVendas()
{
	std::cout << std::endl << "Vendas" << std::endl;
	vendas->listarVendas();

	std::cout << std::endl << "Deseja gerar alguma nota fiscal? (s/n)" << std::endl;
	std::string opcao;
	std::cin >> opcao;
	std::transform(opcao.begin(), opcao.end(), opcao.begin(), ::tolower);
	if (opcao == "s")
	{
		gerarNotaFiscal();
	}
}

/**
 * @brief 	Gera uma nota fiscal para a venda
 * 
 */
void Loja::gerarNotaFiscal()
{
	std::cout << " Nota fiscal " << std::endl;
}

/**
 * @brief Finaliza a compra do carrinho
 * 
 */
void Loja::finalizarCompra()
{
	listarProdutosNoCarrinho();

	std::cout << std::endl << std::endl << "Deseja finalizar a compra com os itens do carrinho? (s/n)" << std::endl;
	std::string opcao;
	std::cin >> opcao;
	std::transform(opcao.begin(), opcao.end(), opcao.begin(), ::tolower);
	if (opcao == "s")
	{
		vendas->adicionarVenda(carrinho->getCarrinho(), estoque, usuarioLogado->getCpf());
		std::cout << std::endl << "Compra finalizada com sucesso!" << std::endl;
		carrinho->limparCarrinho();
	}
	else
	{
		std::cout << std::endl << "Compra cancelada! Voltando a menu..." << std::endl;
	}
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
		opcoesUsuario();
	}
}

/**
 * @brief Remove um produto do carrinho
 * 
 */
void Loja::removerProdutosNoCarrinho()
{
	std::cout << std::endl << "Remover Produto do carrinho:" << std::endl;
	std::string comando, id, quantidade;

	listarProdutosNoCarrinho();

	while (comando != "sair")
	{
		std::cout << "Digite o ID do produto que deseja remover ou sair:" << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
			id = comando;

		std::cout << "Digite a quantidade do produto que deseja remover ou sair:" << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
			quantidade = comando;

		carrinho->removerProduto(std::stoi(id), std::stod(quantidade));

		listarProdutosNoCarrinho();
	}

	opcoesUsuario();
}

/**
 * @brief Lista os produtos do carrinho
 * 
 */
void Loja::listarProdutosNoCarrinho()
{
	std::map<int, double> idsDoCarrinho = carrinho->getCarrinho();
	double totalCarrinho = 0;
	std::cout<< "+----+------+-----------+-----+-------+"<< std::endl;
    std::cout<< "| ID | NOME | DESCRICAO | QTD | PRECO |"<< std::endl;

	for (auto dados: idsDoCarrinho)
	{
		Produto *produto = estoque->buscar(dados.first);
		if (produto != nullptr)
		{
			std::cout <<"+-----------------------------------------------------+"<<std::endl;
			std::cout << "| " << produto->getId();
			std::cout << " | " << produto->getNome();
			std::cout << " | " << produto->getDescricao();
			std::cout << " | " << std::setprecision(2) << std::fixed << dados.second;
			std::cout << " | " << "R$" << std::setprecision(2) << std::fixed << produto->getPreco() << " |" << std::endl;
			totalCarrinho += produto->getPreco() * dados.second;
		}
	}
	std::cout<<"+-----------------------------------------------------+"<<std::endl;
	std::cout<< "| Total: R$" << std::setprecision(2) << std::fixed << totalCarrinho << " |"  << std::endl;
	std::cout<<"+-----------------------------------------------------+"<<std::endl;
}

/**
 * @brief Adiciona um produto ao carrinho
 * 
 */
void Loja::adicionarProdutoCarrinho()
{
	std::cout << "Digite os SKUs dos produtos para adicionar ao carrinho e digite 0 para sair" << std::endl;
	int id;
	std::cin >> id;
	while (id != 0)
	{
		Produto *produto = estoque->buscarPorSku(id);
		if (produto != nullptr)
		{
			if(produto->getQtd() >= (carrinho->qtdNoCarrinho(produto->getId()) + 1))
			{
				carrinho->adicionarProduto(produto->getId(), 1);
				std::cout << "Produto " << id << " adicionado ao carrinho!" << std::endl;
			}
			else
			{
				std::cout << "Produto sem estoque" << std::endl;
			}
		}
		else
		{
			std::cout << "Produto nao encontrado" << std::endl;
		}
		std::cin >> id;
	}
}

/**
 * @brief Mostra as opcoes do usuario
 * 
 */
void Loja::opcoesUsuario()
{
	std::cout << std::endl << "Opcoes:" << std::endl;
	std::cout << "1. Adicionar produto no carrinho" << std::endl;
	std::cout << "2. Listar produtos no carrinho" << std::endl;
	std::cout << "3. Remover produtos no carrinho" << std::endl;
	std::cout << "4. Listar estoque novamente" << std::endl;
	std::cout << "5. Finalizar compra" << std::endl;
	std::cout << "6. Sair" << std::endl << std::endl;

	int opcao;
	std::cin >> opcao;

	switch (opcao)
	{
		case 1:
			adicionarProdutoCarrinho();
			break;
		case 2:
			listarProdutosNoCarrinho();
			break;
		case 3:
			removerProdutosNoCarrinho();
			break;
		case 4:
			estoque->listarEstoque();
			break;
		case 5:
			finalizarCompra();
			break;
		case 6:
			usuarioLogado->logout();
			return;
			break;
		default:
			opcoesUsuario();
			break;
	}

	opcoesUsuario();
}

/**
 * @brief Mostra as opcoes do administrador
 * 
 */
void Loja::opcoesAdm()
{
	std::cout << std::endl << "Opcoes de administrador:" << std::endl;
	std::cout << "1. Adicionar ou atualizar algum produto no estoque" << std::endl;
	std::cout << "2. Remover algum produto no estoque" << std::endl;
	std::cout << "3. Listar estoque novamente" << std::endl;
	std::cout << "4. Listar compras" << std::endl;
	std::cout << "5. Sair" << std::endl << std::endl;

	std::string opcao;
	std::cin >> opcao;

	// verifica se opção é um número de 1 a 5, caso contrário, volta para o menu de administrador
	if (opcao.size() > 1 || opcao.size() == 0 || opcao[0] < '1' || opcao[0] > '5')
	{
		opcoesAdm();
	}
	else
	{
		switch (opcao[0])
		{
			case '1':
				adicionarProdutoEstoque();
				break;
			case '2':
				removerProdutoEstoque();
				break;
			case '3':
				estoque->listarEstoque();
				break;
			case '4':
				listarVendas();
				break;
			case '5':
				usuarioLogado->logout();
				return;
				break;
			default:
				opcoesAdm();
				break;
		}
	}
	
	opcoesAdm();
}

/**
 * @brief Remove um produto do estoque
 * 
 */
void Loja::removerProdutoEstoque()
{
	std::cout << std::endl << "Remover Produto:" << std::endl;

	std::string comando;

	while (comando != "sair")
	{
		std::cout << "Digite o ID do produto que deseja remover ou sair:" << std::endl;
		std::cin >> comando;
		if (comando == "sair")
			break;
		else
		{
			int id = std::stoi(comando);
			estoque->remover(id);
		}
	}
}

/**
 * @brief Adicionar um produto no estoque
 * 
 */
void Loja::adicionarProdutoEstoque()
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
	}
}