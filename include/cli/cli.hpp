#ifndef CLI_HPP
#define CLI_HPP

#include "autoload.hpp"
//criar dentro da clase um metodo void sem parametro chamado login, que vou ler e tratar as excecoes pelo login do 
//usuario
/*
Crie no HPP o método e adicione-o dentro da opção correta em void CLI::lerOpcoesMenuInicial()
*/
class CLI
{
	public:

		CLI();
		CLI(int argc, char *argv[]);
		void help();
		void login();
		void titulo();
		void test(int argc, char *argv[]);
		void cadastro();
		void mostrarOpcoesMenuInicial();
		void lerOpcoesMenuInicial();
		void mostrarLoja();
};
#endif