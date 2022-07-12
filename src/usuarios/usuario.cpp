#include "autoload.hpp"

/**
 * @brief Construtor para a Classe Usuário
 * 
 */
Usuario::Usuario(std::string nome, std::string cpf, std::string email, Endereco endereco, std::string senha){
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
void Usuario::setCpf(std::string cpf){
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
 * @return std::string 
 */
std::string Usuario::getCpf(){
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
Usuario::Usuario(){
}

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
    std::ifstream filer("./data/usuarios.json");
    json::value json = json::parse(filer);
    filer.close();
    
    const json::array &dados = as_array(json);
    if (dados.size() > 0)
    {
        bool usuario_encontrado = false;
        for(auto it = dados.begin(); it != dados.end(); ++it)
        {
            const json::value &v = *it;

            if (v["cpf"].as_string() == this->cpf)
            {
                usuario_encontrado = true;
            }
        }

        if(!usuario_encontrado)
        {
            throw UsuarioNaoEncontradoException();
        }

        bool senha_valida = false;
        for(auto it = dados.begin(); it != dados.end(); ++it)
        {
            const json::value &v = *it;

            if (v["senha"].as_string() == this->senha)
            {
                senha_valida = true;
            }
        }

        if(!senha_valida)
        {
            throw UsuarioSenhaInvalidaException();
        }

        // preenche todos os dados do usuario
        for(auto it = dados.begin(); it != dados.end(); ++it)
        {
            const json::value &v = *it;
        
            if (v["cpf"].as_string() == this->cpf)
            {
                this->nome = v["nome"].as_string();
                this->cpf = v["cpf"].as_string();
                this->email = v["email"].as_string();
                this->senha = v["senha"].as_string();
                this->autenticado = true;
                if(v["tipo"].as_string() == "false")
                {
                    this->tipo = false;
                }
                else
                {
                    this->tipo = true;
                }

                Endereco endereco;
                endereco.setRua(v["endereco"]["rua"].as_string());
                endereco.setNumero(v["endereco"]["numero"].as_string());
                endereco.setBairro(v["endereco"]["bairro"].as_string());
                endereco.setCidade(v["endereco"]["cidade"].as_string());
                endereco.setEstado(v["endereco"]["estado"].as_string());
                endereco.setCep(v["endereco"]["cep"].as_string());
                this->endereco = endereco;
            }
        }
        
        return true;
    }

    return false;
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

    const json::array &dados = as_array(json);
    if (dados.size() > 0)
    {
        for(auto it = dados.begin(); it != dados.end(); ++it)
        {
            const json::value &v = *it;

            if (v["cpf"].as_string() == this->cpf)
            {
                throw UsuarioExistenteException();
            }
        }
    }

    // converte tipo de bool para string
    auto jsonArray = json::object{
        {"tipo", (this->tipo) ? "true" : "false"},
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
void Usuario::logout()
{
    this->autenticado = false;
};

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

/**
 * @brief  Seta o tipo do usuario
 * 
 * @param tipo 
 */
void Usuario::setTipo(bool tipo)
{
    this->tipo = tipo;
}

/**
 * @brief Busca um usuário por CPF
 * 
 * @param cpf 
 * @return Usuario* 
 */
Usuario* Usuario::buscarUsuario(std::string cpf)
{
    std::ifstream filer("./data/usuarios.json");
    json::value json = json::parse(filer);
    filer.close();
    
    const json::array &dados = as_array(json);
    if (dados.size() > 0)
    {
        for(auto it = dados.begin(); it != dados.end(); ++it)
        {
            const json::value &v = *it;

            if (v["cpf"].as_string() == cpf)
            {
                Usuario *usuario = new Usuario();
                usuario->nome = v["nome"].as_string();
                usuario->cpf = v["cpf"].as_string();
                usuario->email = v["email"].as_string();
                usuario->senha = v["senha"].as_string();
                usuario->autenticado = true;
                if(v["tipo"].as_string() == "false")
                {
                    usuario->tipo = false;
                }
                else
                {
                    usuario->tipo = true;
                }

                Endereco endereco;
                endereco.setRua(v["endereco"]["rua"].as_string());
                endereco.setNumero(v["endereco"]["numero"].as_string());
                endereco.setBairro(v["endereco"]["bairro"].as_string());
                endereco.setCidade(v["endereco"]["cidade"].as_string());
                endereco.setEstado(v["endereco"]["estado"].as_string());
                endereco.setCep(v["endereco"]["cep"].as_string());
                usuario->endereco = endereco;
                return usuario;
            }
        }
    }
    return nullptr;
}