#include "autoload.hpp"

/**
 * @brief Construct a new Produto:: Produto object
 * 
 * @param id 
 * @param nome 
 * @param descricao 
 * @param qtd 
 */
Produto::Produto(unsigned int id, std::string nome, std::string descricao, double qtd, double preco)
{
    this->id = id;
    this->nome = nome;
    this->descricao = descricao;
    this->qtd = qtd;
    this->preco = preco;
}

/**
 * @brief Construct a new Produto:: Produto object
 * 
 */
Produto::Produto()
{
    this->id = 0;
    this->nome = "";
    this->descricao = "";
    this->qtd = 0;
}

/**
 * @brief Retorna o id
 * 
 * @return unsigned int 
 */
unsigned int Produto::getId()
{
    return this->id;
}

/**
 * @brief Retorna o nome
 * 
 * @return std::string
 */
std::string Produto::getNome()
{
    return this->nome;
}

/**
 * @brief Retorna a descricao
 * 
 * @return std::string
 */
std::string Produto::getDescricao()
{
    return this->descricao;
}

/**
 * @brief Retorna a quantidade
 * 
 * @return double
 */
double Produto::getQtd()
{
    return this->qtd;
}

/**
 * @brief Seta o id
 * 
 * @param id
 */
void Produto::setId(unsigned int id)
{
    this->id = id;
}

/**
 * @brief Seta o nome
 * 
 * @param nome
 */
void Produto::setNome(std::string nome)
{
    this->nome = nome;
}

/**
 * @brief Seta a descricao
 * 
 * @param descricao
 */
void Produto::setDescricao(std::string descricao)
{
    this->descricao = descricao;
}

/**
 * @brief Seta a quantidade
 * 
 * @param qtd
 */
void Produto::setQtd(double qtd)
{
    this->qtd = qtd;
}

void Produto::setPreco(double preco)
{
    this->preco = preco;
}

double Produto::getPreco()
{
    return this->preco;
}