#ifndef _ENDERECO_HPP_
#define _ENDERECO_HPP_

#include "../../autoload.hpp"

class Endereco
{
    private:
        std::string rua;
        int numero;
        std::string complemento; 
        int cep; 
        std::string bairro; 
        std::string cidade;
        std::string estado; 
    public:
        Endereco();
        Endereco(std::string rua, int numero, std::string complemento, int cep, std::string bairro, std::string cidade, std::string estado);
        std::string getRua();
        int getNumero();
        std::string getComplemento();
        int getCep();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        void setRua(std::string rua);
        void setNumero(int numero);
        void setComplemento(std::string complemento);
        void setCep(int cep);    
        void setBairro(std::string bairro);
        void setCidade(std::string cidade);
        void setEstado(std::string estado);
};

#endif