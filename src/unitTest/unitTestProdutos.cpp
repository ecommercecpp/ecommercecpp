#include "../../include/autoload.hpp"

using namespace std;

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
		//se o nome digitado tiver mais de 20 caracteres
		if(length(getNome()) >= 20){
			throw std::runtime_error("Digite um nome com no máximo 20 caracteres\n");
		}
		//se o nome possui caracteres especiais
		bool caracter = true;
		if(caracter == true){
			char nome[99] = maiuscula(getNome());
			for (int i = 0; nome[i] != '\0'; i++) { 
					if (nome[i] < 'A' || nome[i] > 'Z') { //lógica mais adequada
						break; //encerra o laço, não tem porque continuar, achou algo que não muda mais
					}
				}
				if (nome[i] != '\0'){caracter = false;} //se não chegou ao fim			
				throw std::runtime_error("Voce não pode digitar um nome com caracteres especiais(" ",/,*,$,#,%)\n");
		}		
		if(getNome() == ""){
			throw std::runtime_error("Voce precisa digitar um nome!\n");
		}
		// caso passar em todos os testes, use pass(); para passar o teste
		pass();
	}
	catch ( std::exception &e )
	{
		//falha no teste
		fail(std::string(e.what()));
	}
}
void UnitTestQtd::run()
{
	try
	{
		if(getQtd() == 0){
			throw std::runtime_error("Voce não pode ter 0 de quantidade!\n");
		}
		pass();
	}
	catch ( std::exception &e )
	{
		//falha no teste
		fail(std::string(e.what()));
	}
}
void UnitTestDescricao::run()
{
	try
	{
		if(getDescricao() == ""){
			throw std::runtime_error("Digite uma descrição!\n");
		}
		//limitar descricao ah 300 caracteres
		if(length(getDescricao()) >= 300){
			throw std::runtime_error("Voce ultrapassou o máximo de 300 caracteres!\n");
		}
		pass();
	}
	catch ( std::exception &e )
	{
		//falha no teste
		fail(std::string(e.what()));
	}
}
