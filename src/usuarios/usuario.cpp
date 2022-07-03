#include "autoload.hpp"

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

/**
 * @brief Construct a new Usuario:: Usuario object
 * 
 */
Usuario::Usuario(){}

/**
 * @brief  Retorna se o usuario esta autenticado
 * 
 * @return true 
 * @return false 
 */
bool Usuario::estaAutenticado()
{
    return this->autenticado;
}

/**
 * @brief   Retorna se o usuario é administrador
 * 
 * @return true 
 * @return false 
 */
bool Usuario::ehAdministrador()
{
    return this->tipo;
}

/**
 * @brief   Realiza o login do usuario
 * 
 * @return true 
 * @return false 
 */
bool Usuario::login()
{
    return true;
}

/**
 * @brief   Realiza o cadastro do usuario
 * 
 * @return true 
 * @return false 
 */
bool Usuario::cadastro()
{
    std::ifstream filer("./data/usuarios.json");
    json::value json = json::parse(filer);

    auto jsonArray = json::array {
		json::object{
            {"tipo", tipo},
            {"nome", nome},
            {"cpf", cpf},
            {"email", email},
            {"endereco", json::object{
                {"rua", endereco.getRua()},
                {"numero", endereco.getNumero()},
                {"bairro", endereco.getBairro()},
                {"cidade", endereco.getCidade()},
                {"estado", endereco.getEstado()},
                {"cep", endereco.getCep()}
            }},
            {"senha", senha}
		}
	};

    // adiciona o jsonArray no json
    json.push_back(jsonArray);

    std::ofstream file("./data/usuarios.json");
    file << stringify(json);
    file.close();

    return true;
}

/**
 * @brief  Realiza o logout do usuario
 * 
 */
void Usuario::logout(){};

/**
 * @brief   Retorna o tipo do usuario
 * 
 * @return true 
 * @return false 
 */
bool Usuario::getTipo()
{
    return this->tipo;
}

void Usuario::setTipo(bool tipo)
{
    this->tipo = tipo;
}