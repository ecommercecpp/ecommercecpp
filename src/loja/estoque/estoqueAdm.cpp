#include "autoload.hpp"

#include "./base/json.hpp"

using namespace std;

//https://linuxhint.com/parse-json-data-cpp/
//https://github.com/nlohmann/json/releases


/**
 * @brief 	Lista o estoque de maneira especial para o adm
 * 
 */
void EstoqueAdm::listarEstoque()
{
	//percorrer o estoque e listar 
    std::ifstream file("data/estoque.json");
    json::value json = json::parse(file);

    const json::array &a = as_array(json);

    int i = 1;
    // caso o estoque estiver vazio
    if (a.size() == 0)
    {
        return;
    }

    std::cout<< "+---+----+------+-----------+-----+-------+"<<std::endl;
    std::cout<< "|   | ID | NOME | DESCRICAO | QTD | PRECO |"<<std::endl;

    for(auto it = a.begin(); it != a.end(); ++it)
    {
        /* json::value v;*/
        nlohmann::json v;
        std::string idstr = v["id"];
        std::string nomestr = v["nome"];
        std::string descstr = v["descricao"];
        std::string qtdstr = v["qtd"];
        long int precostr = v["preco"];

        std::cout<<"+-----------------------------------------------------+"<<std::endl;
        std::cout<< "| "<<i;
        std::cout<< " | " << idstr << std::endl;
        std::cout<< " | " << nomestr << std::endl;
        std::cout<< " | " << descstr << std::endl;
        std::cout<< " | " << qtdstr << std::endl;
        std::cout<< " | " << "R$" << setprecision(2) << fixed << precostr << std::endl;
        i++;
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
EstoqueAdm::EstoqueAdm()
{
	
}