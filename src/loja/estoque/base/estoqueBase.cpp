#include "../../../../include/autoload.hpp"

/**
 * @brief Construct a new EstoqueBase:: EstoqueBase object
 * 
 */

EstoqueBase::EstoqueBase()
{

}

/**
 * @brief Adiciona um produto ao estoque.
 *
 * @param  Produto produto
 */
void EstoqueBase::adicionar(Produto produto){
    estoque.insert(std::pair<int, Produto>(produto.getId(), produto));
}

/**
 * @brief Remove um produto do estoque.
 *
 * @param  int id
 */
void EstoqueBase::remover(int id){
    estoque.erase(id);
}

/**
 * @brief Busca um produto no estoque.
 *
 * @param  int id
 *
 * @return Produto*  
 */
Produto* EstoqueBase::buscar(int id){
    return &estoque.at(id);
}

/** @brief Retorna o estoque.
 *
 * @return  std::map<int, Produto>*
 */

std::map<int, Produto>* EstoqueBase::getEstoque(){
    return &estoque;
}



