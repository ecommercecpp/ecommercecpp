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
	// verifica se o usuario está autenticado
	if (getUsuario()->estaAutenticado() == false)
	{
		titulo();
		mostrarOpcoesMenuInicial();
		lerOpcoesMenuInicial();
	}

	std::cout	<< std::endl << std::endl << "Nossa loja:" << std::endl;
	
	EstoqueBase *estoque;
	if(getUsuario()->ehAdministrador())
	{
		// converte o estoque para o tipo de estoque EstoqueAdm
		estoque = dynamic_cast<EstoqueAdm*>(new EstoqueAdm());
	}
	else
	{
		estoque = dynamic_cast<EstoqueCliente*>(new EstoqueCliente());
	}

	Loja loja(getUsuario(), estoque, new Carrinho(getUsuario()->getCpf()));
	loja.mostrarLoja();

	mostrarLoja();
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
		if(cadastro())
		{
			mostrarLoja();
		}
		else
		{
			mostrarOpcoesMenuInicial();
			lerOpcoesMenuInicial();
		}
	}
	else if(opcao == "2")
	{
	    if(login())
		{
			mostrarLoja();
		}
		else
		{
			mostrarOpcoesMenuInicial();
			lerOpcoesMenuInicial();
		}
	}
	else if(opcao == "3")
	{
		exit(0);
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
 * @brief Realiza o cadastro de um usuario
 * 
 * @return true 
 * @return false 
 */
bool CLI::cadastro()
{
	std::cout << std::endl << std::endl << std::endl << "Cadastro" << std::endl;

	Endereco endereco;
	std::string comando, nome, email, senha, rua, bairro, cidade, estado, numero, cep, cpf;

	while (comando != "sair")
	{
		try
		{
			std::cout << "Digite seu nome ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				nome = comando;

			std::cout << "Digite CPF ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				cpf = comando;
			
			// valida se é um inteiro usando RegExp
			std::regex regex("^[0-9]{11}$");
			if (!std::regex_match(cpf, regex))
			{
				std::cout << "CPF inválido" << std::endl;
				continue;
			}

			std::cout << "Digite seu email ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				email = comando;

			std::cout << "Digite sua senha ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				senha = comando;

			std::cout << "Digite sua rua ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				rua = comando;

			std::cout << "Digite seu numero ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				numero = comando;

			// valida se é um numero inteiro de qualquer tamanho usando regex
			std::regex regex2("^[0-9]{1,}$");
			if (!std::regex_match(numero, regex2))
			{
				std::cout << "Numero inválido" << std::endl;
				continue;
			}

			std::cout << "Digite seu bairro ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				bairro = comando;

			std::cout << "Digite sua cidade ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				cidade = comando;

			std::cout << "Digite seu estado ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				estado = comando;

			std::cout << "Digite seu cep ou sair: " << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				cep = comando;

			// valida se é um cep usando regex_match
			std::regex regex3("^[0-9]{8}$");
			if (!std::regex_match(cep, regex3))
			{
				std::cout << "Cep inválido" << std::endl;
				continue;
			}


			endereco.setRua(rua);
			endereco.setNumero(numero);
			endereco.setBairro(bairro);
			endereco.setCidade(cidade);
			endereco.setEstado(estado);
			endereco.setCep(cep);

			Usuario usuario = Usuario(nome, cpf, email, endereco, senha);
			
			if(usuario.cadastro())
			{
				setUsuario(usuario);
				return true;
			}
			else
			{
				return false;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
	}

	return false;
}

/**
 * @brief Realiza o login do usuario
 * 
 * @return true 
 * @return false 
 */
bool CLI::login()
{
   	std::string comando, cpf, senha;

	while (comando != "sair")
	{
		try
		{
			
			std::cout  << "Dite seu cpf ou sair:" << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				cpf = comando;
			
			std::cout  << "Dite sua senha ou sair:" << std::endl;
			std::cin >> comando;
			if (comando == "sair")
				break;
			else
				senha = comando;

			Usuario usuario = Usuario();
			usuario.setCpf(cpf);
			usuario.setSenha(senha);
			
			if(usuario.login())
			{
				setUsuario(usuario);
				return true;
			}
			else
			{
				std::cout << "Usuario ou senha incorretos" << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
	}

	return false;
}

/**
 * @brief 	GET usuario do CLI
 * 
 * @return Usuario 
 */
Usuario* CLI::getUsuario()
{
	return &usuario;
}

/**
 * @brief 	Set usuario do CLI
 * 
 * @param usuario 
 */
void CLI::setUsuario(Usuario usuario)
{
	this->usuario = usuario;
}