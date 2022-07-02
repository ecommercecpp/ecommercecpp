#ifndef _ATRIBUTOS_HPP_
#define _ATRIBUTOS_HPP_

#include "autoload.hpp"

class Atributos
{
	private:
		std::map<std::string, std::map<std::string, std::string>> ListaAtributos;
	public:
		Atributos();
		std::map<std::string, std::map<std::string, std::string>> getListaAtributos();
		std::map<std::string, std::string> getListaAtributos(std::string nomeAtributo);
		void adicionarAtributo(std::string nomeAtributo, std::map<std::string, std::string> niveis);
};

#endif