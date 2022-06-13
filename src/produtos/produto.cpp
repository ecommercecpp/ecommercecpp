#include "../../include/autoload.hpp"

Produto::Produto(unsigned int id, std::string nome, std::string descricao, double qtd){
    this->_id = id;
    this->_nome = nome;
    this->_descricao = descricao;
    this->_qtd = qtd;
}

Produto::Produto(){
    this->_id = 0;
    this->_nome = "";
    this->_descricao = "";
    this->_qtd = 0;
}

unsigned int Produto::getId(){
    return this->_id;
}

std::string Produto::getNome(){
    return this->_nome;
}

std::string Produto::getDescricao(){
    return this->_descricao;
}

double Produto::getQtd(){
    return this->_qtd;
}

void Produto::setId(unsigned int id){
    this->_id = id;
}

void Produto::setNome(std::string nome){
    this->_nome = nome;
}

void Produto::setDescricao(std::string descricao){
    this->descricao = descricao;
}

void Produto::setQtd(double qtd){
    this->_qtd = qtd;
}