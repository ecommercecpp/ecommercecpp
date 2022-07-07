#ifndef CLI_HPP
#define CLI_HPP

#include "autoload.hpp"

class CLI
{
	public:
		CLI();
		CLI(int argc, char *argv[]);
		void help();
		bool login();
		bool cadastro();
		void titulo();
		void test(int argc, char *argv[]);
		void mostrarOpcoesMenuInicial();
		void lerOpcoesMenuInicial();
		void mostrarLoja();
};
#endif