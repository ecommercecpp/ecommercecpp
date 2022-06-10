#include "../../../include/autoload.hpp"

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
 * @return int 
 */
int Endereco::getNumero()
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
 * @return int 
 */
int Endereco::getCep()
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
void Endereco::setNumero(int numero)
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
void Endereco::setCep(int cep)
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
 * @param cidade 
 */
void Endereco::setCidade(std::string cidade)
{
	this->cidade = cidade;
}

/*
 * @brief Seta o estado do endereço
 * 
 * @param estado 
 */
void Endereco::setEstado(std::string estado)
{
	this->estado = estado;
}