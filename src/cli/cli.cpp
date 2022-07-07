#include "autoload.hpp"

/**
 * @brief Construct a new CLI::CLI object
 * 
 */
CLI::CLI(){}

/**
 * @brief Construct a new CLI::CLI object
 * 
 * @param argc 
 * @param argv 
 */
CLI::CLI(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (std::string(argv[1]) == "--test")
		{
			test(argc, argv);
		}
		else if (std::string(argv[1]) == "--help")
		{
			help();
		}
		else
		{
			help();
		}
	}
	else
	{
		titulo();
		mostrarOpcoesMenuInicial();
		lerOpcoesMenuInicial();
	}
}

/**
 * @brief 	Mostra a loja
 * 
 */
void CLI::mostrarLoja()
{
	std::cout << "Mostrar loja" << std::endl;
	// cria uma loja com o usuario logado, obs: obrigatorio testar se o usuario logado existe e se está autenticado
	

	// apenas pra testar, cria um usuario fake
	Usuario* usuarioLogado = new Usuario(
		"nome",
		123,
		"email",
		Endereco("rua", 123, "complemento", 123, "bairro", "cidade", "estado"),
		"senha"
	);

	// verifica o tipo do cliente, se é adm ou nao e cria um estoque de acordo com o tipo

	// apenas pra testar, cria um estoque fake
	EstoqueAdm* estoque = new EstoqueAdm();
	Loja loja(usuarioLogado, estoque);
	loja.mostrarLoja();
}

/**
 * @brief 	Mostra o menu inicial do programa
 * 
 */
void CLI::lerOpcoesMenuInicial()
{
	std::string opcao;
	std::cin >> opcao;
	if(opcao == "1")
	{
		cadastro();
	}
	else if(opcao == "2")
	{
		std::cout << "Login" << std::endl;
		mostrarLoja();
		return;
	}
	else if(opcao == "3")
	{
		return;
	}
	else
	{
		mostrarOpcoesMenuInicial();
		lerOpcoesMenuInicial();
	}
}

/**
 * @brief 	Mostra as opções do menu inicial do programa
 * 
 */
void CLI::mostrarOpcoesMenuInicial()
{
	std::cout << "Escolha uma opção: " << std::endl;
	std::cout << "1 - Cadastrar" << std::endl;
	std::cout << "2 - Fazer Login" << std::endl;
	std::cout << "3 - Sair" << std::endl;
}

/**
 * @brief 	Mostra o titulo do programa
 * 
 */
void CLI::titulo()
{
	std::cout << R"(  ______                                                   _____           
 |  ____|                                                 / ____|_     _   
 | |__   ___ ___  _ __ ___  _ __ ___   ___ _ __ ___ ___  | |   _| |_ _| |_ 
 |  __| / __/ _ \| '_ ` _ \| '_ ` _ \ / _ \ '__/ __/ _ \ | |  |_   _|_   _|
 | |___| (_| (_) | | | | | | | | | | |  __/ | | (_|  __/ | |____|_|   |_|  
 |______\___\___/|_| |_| |_|_| |_| |_|\___|_|  \___\___|  \_____|          
                                                                           
                                                                           )" << std::endl;
}

/**
 * @brief 	Mostra o menu de ajuda do programa
 * 
 */
void CLI::help()
{
	std::cout << "Ecommerce: " << std::endl;
	std::cout << "  --help: mostra essa mensagem" << std::endl;
	std::cout << "  --test: executa os testes" << std::endl;
}

/**
 * @brief 	Executa os testes do programa
 * 
 * @param argc 
 * @param argv 
 */
void CLI::test(int argc, char *argv[])
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

/**
 * @brief 	Mostra o menu de cadastro do programa
 * 
 */
bool CLI::cadastro()
{
	std::cout << std::endl << std::endl << std::endl << "Cadastro" << std::endl;

	Endereco endereco;
	int numero, cep, cpf;
	std::string nome, email, senha, rua, bairro, cidade, estado;
	std::cout << "Digite seu nome: ";
	std::cin >> nome;
	std::cout << "Digite CPF: ";
	std::cin >> cpf;
	std::cout << "Digite seu email: ";
	std::cin >> email;
	std::cout << "Digite sua senha: ";
	std::cin >> senha;
	std::cout << "Digite sua rua: ";
	std::cin >> rua;
	std::cout << "Digite seu numero: ";
	std::cin >> numero;
	std::cout << "Digite seu bairro: ";
	std::cin >> bairro;
	std::cout << "Digite sua cidade: ";
	std::cin >> cidade;
	std::cout << "Digite seu estado: ";
	std::cin >> estado;
	std::cout << "Digite seu cep: ";
	std::cin >> cep;
	endereco.setRua(rua);
	endereco.setNumero(numero);
	endereco.setBairro(bairro);
	endereco.setCidade(cidade);
	endereco.setEstado(estado);
	endereco.setCep(cep);

	Usuario usuario = Usuario(nome, cpf, email, endereco, senha);
	usuario.cadastro();
}