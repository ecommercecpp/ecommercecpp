#include "../../autoload.hpp"

//testar sets e gets - Id, nome, descricao e quantidade

//deixa as letras maiusculas
std::string maiuscula(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return s;
}

//void UnitTestNome::run(){} -> considerei desnecessário porque mesmo apagando um id, todos os ids vão ser +1 do registrado anteriormente

void UnitTestNome::run()
{
	try
	{
		bool teste = false;

		//se o nome digitado tiver mais de 20 caracteres
		if(std::length(Produto::getNome()) >= 20){
			teste = true;
			throw std::runtime_error("Digite um nome com no máximo 20 caracteres\n");
		}
		//se o nome possui caracteres especiais
		bool caracter = true;
		if(caracter == true){
			char nome[99] = maiuscula(Produto::getNome());
			for (i = 0; nome[i] != '\0'; i++) { 
					if (nome[i] < 'A' || nome[i] > 'Z') { //lógica mais adequada
						break; //encerra o laço, não tem porque continuar, achou algo que não muda mais
					}
				}
				if (nome[i] != '\0'){caracter = false;} //se não chegou ao fim			
				throw std::runtime_error("Voce não pode digitar um nome com caracteres especiais(" ",/,*,$,#,%)\n");
				teste = true;
		}		
		if(Produto::getNome() == ""){
			throw std::runtime_error("Voce precisa digitar um nome!\n");
			teste = true;
		}
		//como consultar nomes que jah existem no banco?
		//se existir um nome pass() senao erro

		if(teste == true)
		{
			throw std::runtime_error("a variável 'teste' não é true");
		}

		// caso passar em todos os testes, use pass(); para passar o teste
		pass();
	}
	catch ( std::exception &e )
	{
		//std::string aux;
		//limitar para 20 letras
		char nome[20];
		int i = std::length(nome);
		while (i >= 20){
			throw std::runtime_error("Digite um nome com no máximo 20 caracteres");
		}
		std::cin>>aux;
		Produto::setNome(aux);
		fail(std::string(e.what()));
	}
}
void UnitTestQtd::run()//nao pode retornar um caracter vazio e nao pode ser igual hah algum nome já registrado
{
	try
	{
		bool teste = false;
		if(Produto::getQtd() == 0){
			throw std::runtime_error("Voce não pode ter 0 de quantidade!\n");
			teste = true;
		}
		if(teste == true)
		{
			throw std::runtime_error("a variável 'teste' não é true");
		}
		pass();
	}
	catch ( std::exception &e )
	{
		double aux;
		std::cin>>aux;
		Produto::setQtd(aux);
		fail(std::string(e.what()));
	}
}
void UnitTestDescricao::run()
{
	try
	{
		bool teste = false;
		if(Produto::getDescricao() == ""){
			throw std::runtime_error("Digite uma descrição!\n");
			teste = true;
		}
		//limitar descricao ah 300 caracteres
		if(std::length(Produto::getDescricao()) >= 300){
			throw std::runtime_error("Voce ultrapassou o máximo de 300 caracteres!\n");
			teste = true;
		}
		if(teste == true)
		{
			throw std::runtime_error("a variável 'teste' não é true");
		}
		pass();
	}
	catch ( std::exception &e )
	{
		char nome[300];
		int i = std::length(nome);
		while (i >= 300){
			throw std::runtime_error("Voce ultrapassou o máximo de 300 caracteres!\n");
		}
		std::string aux;
		std::cin>>aux;
		Produto::setDescricao(aux);
		fail(std::string(e.what()));
	}
}
