#include "autoload.hpp"

/**
 * @brief Construct a new Endereco:: Endereco object
 * 
 */
Endereco::Endereco()
{
	this->rua = "";
	this->numero = "";
	this->complemento = "";
	this->cep = "";
	this->bairro = "";
	this->cidade = "";
	this->estado = "";
}

/**
 * @brief Construct a new Endereco:: Endereco object
 * 
 * @param rua 
 * @param numero 
 * @param complemento 
 * @param cep 
 * @param bairro 
 * @param cidade 
 * @param estado 
 */
Endereco::Endereco(std::string rua, std::string numero, std::string complemento, std::string cep, std::string bairro, std::string cidade, std::string estado)
{
	this->rua = rua;
	this->numero = numero;
	this->complemento = complemento;
	this->cep = cep;
	this->bairro = bairro;
	this->cidade = cidade;
	this->estado = estado;
}

/**
 * @brief Retorna a rua do endereço
 * 
 * @return std::string 
 */
std::string Endereco::getRua()
{
	return this->rua;
}

/**
 * @brief Retorna o número do endereço
 * 
 * @return std::string 
 */
std::string Endereco::getNumero()
{
	return this->numero;
}

/**
 * @brief Retorna o complemento do endereço
 * 
 * @return std::string 
 */
std::string Endereco::getComplemento()
{
	return this->complemento;
}

/**
 * @brief Retorna o cep do endereço
 * 
 * @return std::string 
 */
std::string Endereco::getCep()
{
	return this->cep;
}

/**
 * @brief Retorna o bairro do endereço
 * 
 * @return std::string 
 */
std::string Endereco::getBairro()
{
	return this->bairro;
}

/**
 * @brief Retorna a cidade do endereço
 * 
 * @return std::string 
 */
std::string Endereco::getCidade()
{
	return this->cidade;
}

/**
 * @brief Retorna o estado do endereço
 * 
 * @return std::string 
 */
std::string Endereco::getEstado()
{
	return this->estado;
}

/**
 * @brief Seta a rua do endereço
 * 
 * @param rua 
 */
void Endereco::setRua(std::string rua)
{
	this->rua = rua;
}

/*
 * @brief Seta o número do endereço
 * 
 * @param numero 
 */
void Endereco::setNumero(std::string numero)
{
	this->numero = numero;
}

/**
 * @brief Seta o complemento do endereço
 * 
 * @param complemento 
 */
void Endereco::setComplemento(std::string complemento)
{
	this->complemento = complemento;
}

/*
 * @brief Seta o cep do endereço
 * 
 * @param cep 
 */
void Endereco::setCep(std::string cep)
{
	this->cep = cep;
}  

/*
 * @brief Seta o bairro do endereço
 * 
 * @param bairro 
 */
void Endereco::setBairro(std::string bairro)
{
	this->bairro = bairro;
}

/*
 * @brief Seta a cidade do endereço
 * 
 * @param std::string cidade 
 */
void Endereco::setCidade(std::string cidade)
{
	this->cidade = cidade;
}

/*
 * @brief Seta o estado do endereço
 * 
 * @param std::string estado 
 */

void Endereco::setEstado(std::string estado)
{
	this->estado = estado;
}




