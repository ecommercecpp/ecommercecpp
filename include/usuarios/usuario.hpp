#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "autoload.hpp"

class Usuario{
    protected:
        bool tipo = false;
        bool autenticado = false;
        std::string nome;
        std::string cpf;
        std::string email;
        Endereco endereco;
        std::string senha;
    public:
        std::string getNome();
        std::string getCpf();
        std::string getEmail();
        Endereco getEndereco();
        std::string getSenha();
        bool getTipo();
        void setTipo(bool tipo);
        void setNome(std::string nome);
        void setCpf(std::string cpf);
        void setEmail(std::string email);
        void setEndereco(Endereco endereco);
        void setSenha(std::string senha);
        Usuario(std::string nome, std::string cpf, std::string email, Endereco endereco, std::string senha);
        Usuario();
        bool estaAutenticado();
        bool ehAdministrador();
        bool login();
        bool cadastro();
        void logout();
};
#endif