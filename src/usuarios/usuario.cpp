#include "../../include/autoload.hpp"

/**
 * @brief Construtor para a Classe Usuário
 * 
 */
Usuario::Usuario(std::string nome, int cpf, std::string email, Endereco endereco, std::string senha){
    this->nome = nome;
    this->cpf = cpf;
    this->email = email;
    this->endereco = endereco;
    this->senha = senha;
}
/**
 * @brief seta o nome
 * 
 */
void Usuario::setNome(std::string nome){
    this->nome = nome;
}
/**
 * @brief seta o cpf do usuario
 * 
 */
void Usuario::setCpf(int cpf){
    this->cpf = cpf;
}
/**
 * @brief seta o email do usuario
 * 
 */
void Usuario::setEmail(std::string email){
    this->email = email;
}
/**
 * @brief seta o endereço do usuario
 * 
 */
void Usuario::setEndereco(Endereco endereco){
    this->endereco = endereco;
}
/**
 * @brief seta a senha do usuario
 * 
 */
void Usuario::setSenha(std::string senha){
    this->senha = senha;
}
/**
 * @brief Retorna o nome do usuario
 * 
 * @return std::string 
 */
std::string Usuario::getNome(){
    return this->nome;
}
/**
 * @brief Retorna o cpf do usuario
 * 
 * @return int 
 */
int Usuario::getCpf(){
    return this->cpf;
}
/**
 * @brief Retorna o email do usuario
 * 
 * @return std::string 
 */
std::string Usuario::getEmail(){
    return this->email;
}
/**
 * @brief Retorna o endereço do usuario
 * 
 * @return std::string 
 */
Endereco Usuario::getEndereco(){
    return this->endereco;
}
/**
 * @brief Retorna a senha do usuario
 * 
 * @return std::string 
 */
std::string Usuario::getSenha(){
    return this->senha;
}
