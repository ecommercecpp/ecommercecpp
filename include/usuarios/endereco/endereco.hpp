#ifndef _ENDERECO_HPP_
#define _ENDERECO_HPP_
#include <string>
class Endereco{
    private:
        std::string rua; // obriagtorio
        int numero; // obrigatorio
        std::string complemento; // opcional
        int cep; // obrigatorio
        std::string bairro; // obrigatorio
        std::string cidade; // obrigatorio
        std::string estado; // obrigatorio
    public:
    ///get e set para todos os atributos
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