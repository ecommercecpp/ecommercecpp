#ifndef _PRODUTO_HPP_
#define _PRODUTO_HPP_


#include "../autoload.hpp"

class Produto {
    public:
        Produto(unsigned int id, std::string nome, std::string descricao, double qtd);
        Produto();
        unsigned int getId();
        std::string getNome();
        std::string getDescricao();
        double getQtd();
        void setId(unsigned int id);
        void setNome(std::string nome);
        void setDescricao(std::string descricao);
        void setQtd(double qtd);
    private:
        unsigned int id;
        std::string nome;
        std::string descricao;
        double qtd;
        Atributos atributos;
};

#endif