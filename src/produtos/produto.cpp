#include "../../include/autoload.hpp"

/**
 * @brief Construtor para a Classe Produto
 * 
 * @param int id, string nome, string descricao, int qtd
 * 
 */

Produto::Produto(unsigned int id, std::string nome, std::string descricao, double qtd){
    this->_id = id;
    this->_nome = nome;
    this->_descricao = descricao;
    this->_qtd = qtd;
}

/**
 * @brief Construtor default para a Classe Produto
 * 
 */

Produto::Produto(){
    this->_id = 0;
    this->_nome = "";
    this->_descricao = "";
    this->_qtd = 0;
}

/**
 * @brief retorna o id
 *
 * @return _id  
 */

unsigned int Produto::getId(){
    return this->_id;
}

/**
 * @brief retorna o nome
 *
 * @return _nome 
 */

std::string Produto::getNome(){
    return this->_nome;
}

/**
 * @brief retorna a descricao
 *
 * @return _descricao  
 */

std::string Produto::getDescricao(){
    return this->_descricao;
}

/**
 * @brief retorna a quantidade
 *
 * @return _qtd  
 */

double Produto::getQtd(){
    return this->_qtd;
}

/**
 * @brief seta o Id do produto
 * 
 */

void Produto::setId(unsigned int id){
    this->_id = id;
}

/**
 * @brief seta o nome do do produto
 * 
 */

void Produto::setNome(std::string nome){
    this->_nome = nome;
}

/**
 * @brief seta a descrição do produto
 * 
 */

void Produto::setDescricao(std::string descricao){
    this->descricao = descricao;
}

/**
 * @brief seta a quantidade do produto
 * 
 */

void Produto::setQtd(double qtd){
    this->_qtd = qtd;
}