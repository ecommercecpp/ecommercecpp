#ifndef _PRODUTO_HPP_
#define _PRODUTO_HPP_


#include "autoload.hpp"

class Produto {
    public:
        Produto(unsigned int id, std::string nome, std::string descricao, double qtd, double preco);
        Produto();
        unsigned int getId();
        std::string getNome();
        std::string getDescricao();
        double getQtd();
        void setId(unsigned int id);
        void setNome(std::string nome);
        void setDescricao(std::string descricao);
        void setQtd(double qtd);
        void setPreco(double preco);
        double getPreco();
    private:
        unsigned int id;
        std::string nome;
        std::string descricao;
        double qtd, preco;
        Atributos atributos;
};

#endif