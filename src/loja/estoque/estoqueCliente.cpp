#include "autoload.hpp"

/**
 * @brief 	Lista o estoque de maneira especial para o cliente
 * 
 */
void EstoqueCliente::listarEstoque()
{
	//percorrer o estoque e listar 
    std::ifstream file("data/estoque.json");
    json::value json = json::parse(file);
    file.close();

    const json::array &a = as_array(json);

    int i = 1;

    // caso o estoque estiver vazio
    if (a.size() == 0)
    {
        return;
    }

    std::cout<< "+--------+------+-----------+-----+-------+"<<std::endl;
    std::cout<< "| NUMERO | NOME | DESCRICAO | QTD | PRECO |"<<std::endl;

    for(auto it = a.begin(); it != a.end(); ++it)
    {
        const json::value &v = *it;

        std::string idstr = v["id"].as_string();
        std::string nomestr = v["nome"].as_string();
        std::string descstr = v["descricao"].as_string();

        // converte preco para double
        double preco_double = std::stod(v["preco"].as_string());
        // converte qtd para double
        double qtd_double = std::stod(v["qtd"].as_string());

        std::cout <<"+-----------------------------------------------------+"<<std::endl;
        std::cout << "| "<< i;
        std::cout << " | " << nomestr;
        std::cout << " | " << descstr;
        std::cout << " | " << std::setprecision(2) << std::fixed << qtd_double;
        std::cout << " | " << "R$" << std::setprecision(2) << std::fixed << preco_double << std::endl;
        i++;
    }  
    std::cout<<"+-----------------------------------------------------+"<<std::endl;
}

/**
 * @brief Destroy the Estoque Cliente:: Estoque Cliente object
 * 
 */
EstoqueCliente::~EstoqueCliente(){}

/**
 * @brief Construct a new Estoque Cliente:: Estoque Cliente object
 * 
 */
EstoqueCliente::EstoqueCliente(){}