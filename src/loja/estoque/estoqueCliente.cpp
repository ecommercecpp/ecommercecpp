#include "autoload.hpp"

/**
 * @brief 	Lista o estoque de maneira especial para o cliente
 * 
 */
void EstoqueCliente::listarEstoque()
{
	// caso o estoque estiver vazio
    if (this->estoque.size() == 0)
    {
        return;
    }

    std::cout<< "+----+------+-----------+-----+-------+"<<std::endl;
    std::cout<< "| NUMERO | NOME | DESCRICAO | QTD | PRECO |"<<std::endl;

    int controle = 0;

    // lista o this->estoque usando foreach
    for ( auto dados: this->estoque )
    {
        std::cout <<"+-----------------------------------------------------+"<<std::endl;
        std::cout << " | " << controle;
        std::cout << " | " << dados.second.getNome();
        std::cout << " | " << dados.second.getDescricao();
        std::cout << " | " << std::setprecision(2) << std::fixed << dados.second.getQtd();
        std::cout << " | " << "R$" << std::setprecision(2) << std::fixed << dados.second.getPreco() << " |" << std::endl;
        controle++;
    }
    std::cout<<"+-----------------------------------------------------+"<<std::endl;	
}

/**
 * @brief Destroy the Estoque Cliente:: Estoque Cliente object
 * 
 */
EstoqueCliente::~EstoqueCliente(){}

/**
 * @brief Construct a new Estoque Cliente:: Estoque Cliente object
 * 
 */
EstoqueCliente::EstoqueCliente(){}