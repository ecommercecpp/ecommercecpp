#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include "autoload.hpp"

class UsuarioExistenteException : public std::exception
{
	private:
		std::string msg = "Erro: Não foi possível criar o usuário. Usuário já existe.";
    public:
		virtual const char* what() const throw()
		{
			return msg.c_str();
		}
};

class UsuarioNaoEncontradoException : public std::exception
{
	private:
		std::string msg = "Erro: Não foi possível encontrar o usuário.";
    public:
		virtual const char* what() const throw()
		{
			return msg.c_str();
		}
};

class UsuarioSenhaInvalidaException : public std::exception
{
	private:
		std::string msg = "Erro: Senha inválida.";
    public:
		virtual const char* what() const throw()
		{
			return msg.c_str();
		}
};

#endif