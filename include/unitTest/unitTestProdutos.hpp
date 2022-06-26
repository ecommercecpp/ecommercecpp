#ifndef _UNIT_TEST_PRODUTOS_HPP_
#define _UNIT_TEST_PRODUTOS_HPP_

#include "../autoload.hpp"

//testar sets e gets - Id, nome, descricao e quantidade

//deixa as letras maiusculas
string maiuscula(string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return s;
}

/*int contarPalavras(const string& frase) {
  int quantidadePalavras = 0;
	char caracterAnterior = ' ';

	for_each(frase.begin(), frase.end(), [&](const char& caracterAtual) {

		if(!isalpha(caracterAnterior) && isalpha(caracterAtual))
			quantidadePalavras++;

		caracterAnterior = caracterAtual;
	});

	return quantidadePalavras;
}*/

void UnitTestId::run()//nao pode retornar um caracter vazio e nao pode ser igual hah algum nome já registrado
{
	try
	{
		bool teste = false;
		if(Produto::getId() /*SeforRepetido*/){
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
		int aux;
		//percorre todos os Ids e define um que nao foi registrado
		//cin>>aux;
		Produto::setId(aux);
		fail(std::string(e.what()));
	}
}

void UnitTestNome::run()//nao pode retornar um caracter vazio e nao pode ser igual hah algum nome já registrado
{
	try
	{
		bool teste = false;
   		// seu código normal
		// ...
		// aqui, caso um valor não for true, lança um erro:
		//se o nome digitado tiver mais de 20 caracteres
		if(std::strlen(Produto::getNome()) >= 20){
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
		int i = strlen(nome);
		while (i >= 20){
			throw std::runtime_error("Digite um nome com no máximo 20 caracteres");
		}
		cin>>aux;
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
		cin>>aux;
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
		if(std::strlen(Produto::getDescricao()) >= 300){
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
		int i = strlen(nome);
		while (i >= 300){
			throw std::runtime_error("Voce ultrapassou o máximo de 300 caracteres!\n");
		}
		std::string aux;
		cin>>aux;
		Produto::setDescricao(aux);
		fail(std::string(e.what()));
	}
}

#endif