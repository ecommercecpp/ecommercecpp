#ifndef _ENDERECO_HPP_
#define _ENDERECO_HPP_

#include "autoload.hpp"

class Endereco
{
    private:
        std::string rua;
        std::string numero;
        std::string complemento; 
        std::string cep; 
        std::string bairro; 
        std::string cidade;
        std::string estado; 
    public:
        Endereco();
        Endereco(std::string rua, std::string numero, std::string complemento, std::string cep, std::string bairro, std::string cidade, std::string estado);
        std::string getRua();
        std::string getNumero();
        std::string getComplemento();
        std::string getCep();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        void setRua(std::string rua);
        void setNumero(std::string numero);
        void setComplemento(std::string complemento);
        void setCep(std::string cep);    
        void setBairro(std::string bairro);
        void setCidade(std::string cidade);
        void setEstado(std::string estado);
};

#endif