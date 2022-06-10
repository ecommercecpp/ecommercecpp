#ifndef _ENDERECO_HPP_
#define _ENDERECO_HPP_

#include "../../autoload.hpp"

class Endereco{
    private:
        std::string rua;
        int numero;
        std::string complemento; 
        int cep; 
        std::string bairro; 
        std::string cidade;
        std::string estado; 
    public:
        std::string getRua();
        void setRua(std::string rua);
        int getNumero();
        void setNumero(int numero);
        std::string getComplemento();
        void setComplemento(std::string complemento);
        int getCep();
        void setCep(int cep);
        std::string getBairro();
        void setBairro(std::string bairro);
        std::string getCidade();
        void setCidade(std::string cidade);
        std::string getEstado();
        void setEstado(std::string estado); 
};

#endif