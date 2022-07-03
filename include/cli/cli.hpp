#ifndef CLI_HPP
#define CLI_HPP

#include "autoload.hpp"

class CLI
{
	public:
		CLI();
		CLI(int argc, char *argv[]);
		void help();
		void titulo();
		void test(int argc, char *argv[]);
		void cadastro();
		void mostrarOpcoesMenuInicial();
		void lerOpcoesMenuInicial();
		void mostrarLoja();
};
#endif