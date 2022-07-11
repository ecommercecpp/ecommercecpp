#include "autoload.hpp"

/**
 * @brief 	Lista o estoque de maneira especial para o adm
 * 
 */
void EstoqueAdm::listarEstoque()
{
	//percorrer o estoque e listar 
    std::ifstream file("data/estoque.json");
    json::value json = json::parse(file);
    file.close();

    const json::array &a = as_array(json);

    // caso o estoque estiver vazio
    if (a.size() == 0)
    {
        return;
    }

    std::cout<< "+----+------+-----------+-----+-------+"<<std::endl;
    std::cout<< "| ID | NOME | DESCRICAO | QTD | PRECO |"<<std::endl;

    for(auto it = a.begin(); it != a.end(); ++it)
    {
        const json::value &v = *it;
        // converte preco para double
        double preco_double = std::stod(v["preco"].as_string());
        // converte qtd para double
        double qtd_double = std::stod(v["qtd"].as_string());

        std::cout <<"+-----------------------------------------------------+"<<std::endl;
        std::cout << " | " << v["id"].as_string();
        std::cout << " | " << v["nome"].as_string();
        std::cout << " | " << v["descricao"].as_string();
        std::cout << " | " << std::setprecision(2) << std::fixed << qtd_double;
        std::cout << " | " << "R$" << std::setprecision(2) << std::fixed << preco_double << " |" << std::endl;
    }  
    std::cout<<"+-----------------------------------------------------+"<<std::endl;	
}

/**
 * @brief Destroy the Estoque Adm:: Estoque Base object
 * 
 */
EstoqueAdm::~EstoqueAdm(){}

/**
 * @brief Construct a new Estoque Adm:: Estoque Adm object
 * 
 */
EstoqueAdm::EstoqueAdm(){}