#include "autoload.hpp"

/**
 * @brief 	Lista o estoque de maneira especial para o adm
 * 
 */
void EstoqueAdm::listarEstoque()
{
    // caso o estoque estiver vazio
    if (this->estoque.size() == 0)
    {
        return;
    }

    std::cout<< "+----+------+-----------+-----+-------+"<<std::endl;
    std::cout<< "| ID | NOME | DESCRICAO | QTD | PRECO |"<<std::endl;

    // lista o this->estoque usando foreach
    for ( auto dados: this->estoque )
    {
        std::cout <<"+-----------------------------------------------------+"<<std::endl;
        std::cout << " | " << dados.second.getId();
        std::cout << " | " << dados.second.getNome();
        std::cout << " | " << dados.second.getDescricao();
        std::cout << " | " << std::setprecision(2) << std::fixed << dados.second.getQtd();
        std::cout << " | " << "R$" << std::setprecision(2) << std::fixed << dados.second.getPreco() << " |" << std::endl;
    }
    std::cout<<"+-----------------------------------------------------+"<<std::endl;	
}

/**
 * @brief Destroy the Estoque Adm:: Estoque Base object
 * 
 */
EstoqueAdm::~EstoqueAdm(){}

/**
 * @brief Construct a new Estoque Adm:: Estoque Adm object
 * 
 */
EstoqueAdm::EstoqueAdm(){}