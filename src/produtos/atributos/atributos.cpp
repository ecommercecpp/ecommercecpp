#include "autoload.hpp"

/**
 * @brief Construct a new Atributos:: Atributos object
 * 
 */
Atributos::Atributos()
{
    ListaAtributos = std::map<std::string, std::map<std::string, std::string>>();
}

/**
 * @brief Retorna a lista de atributos do produto
 * 
 * @return std::map<std::string, std::map<std::string, std::string>> 
 */
std::map<std::string, std::map<std::string, std::string>> Atributos::getListaAtributos()
{
    return this->ListaAtributos;
}

/**
 * @brief Retorna o atributo do produto
 * 
 * @param nomeAtributo 
 * @return std::map<std::string, std::string> 
 */
std::map<std::string, std::string> Atributos::getListaAtributos(std::string nomeAtributo)
{
    return this->ListaAtributos[nomeAtributo];
}

/**
 * @brief Adiciona uma atributo ao produto
 * 
 * @param nomeAtributo 
 * @param niveis 
 */
void Atributos::adicionarAtributo(std::string nomeAtributo, std::map<std::string, std::string> niveis)
{
    this->ListaAtributos[nomeAtributo] = niveis;
}