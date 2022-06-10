#include "../../../../include/autoload.hpp"

void EstoqueBase::adicionar(Produto produto){
    estoque.insert(std::pair<int, Produto>(produto.getId(), produto));
}

void EstoqueBase::remover(int id){
    estoque.erase(id);
}

Produto* EstoqueBase::buscar(int id){
    return &estoque.at(id);
}

std::map<int, Produto>* EstoqueBase::getEstoque(){
    return &estoque;
}

