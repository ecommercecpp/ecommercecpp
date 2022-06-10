#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "../autoload.hpp"

class Usuario{
    protected:
        std::string nome;
        int cpf;
        std::string email;
        Endereco endereco;
        std::string senha;
    public:
        std::string getNome();
        int getCpf();
        std::string getEmail();
        Endereco getEndereco();
        std::string getSenha();
        void setNome(std::string nome);
        void setCpf(int cpf);
        void setEmail(std::string email);
        void setEndereco(Endereco endereco);
        void setSenha(std::string senha);
        Usuario(std::string nome, int cpf, std::string email, Endereco endereco, std::string senha);
};
#endif