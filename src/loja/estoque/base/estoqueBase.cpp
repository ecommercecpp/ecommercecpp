#include "autoload.hpp"

/**
 * @brief Construct a new EstoqueBase:: EstoqueBase object
 * 
 */
EstoqueBase::EstoqueBase()
{
    std::ifstream filer("./data/estoque.json");
    json::value json = json::parse(filer);

    const json::array &a = as_array(json);

    // caso o arquivo estiver vazio
    if (a.size() == 0)
    {
        return;
    }

    for(auto it = a.begin(); it != a.end(); ++it)
    {
        const json::value &v = *it;

        // cria o produto
        Produto produto = Produto(
            std::stoi(v["id"].as_string()),
            v["nome"].as_string(),
            v["descricao"].as_string(),
            std::stod(v["qtd"].as_string()),
            std::stod(v["preco"].as_string())
        );

        // adiciona o produto no estoque
        adicionar(produto, false);
    }
}

/**
 * @brief Adiciona um produto ao estoque.
 *
 * @param  Produto produto
 */
void EstoqueBase::adicionar(Produto produto, bool adicionarNoArquivo)
{
    // insere o estoque no array e no arquivo
    estoque.insert(std::pair<int, Produto>(produto.getId(), produto));

    if(adicionarNoArquivo)
    {
        std::ifstream filer("./data/estoque.json");
        json::value json = json::parse(filer);

        // cria o objeto de produto
        json::value jsonProduto = json::object{
                {"id", produto.getId()},
                {"nome", produto.getNome()},
                {"descricao", produto.getDescricao()},
                {"qtd", produto.getQtd()},
                {"preco", produto.getPreco()}
        };

        // insere o produto no array
        json.push_back(jsonProduto);

        std::ofstream file("./data/estoque.json");
        file << stringify(json);
        file.close();
    }
}

/**
 * @brief Remove um produto do estoque.
 *
 * @param  int id
 */
void EstoqueBase::remover(int id){
    estoque.erase(id);
}

/**
 * @brief Busca um produto no estoque.
 *
 * @param  int id
 *
 * @return Produto*  
 */
Produto* EstoqueBase::buscar(int id){
    return &estoque.at(id);
}

/** @brief Retorna o estoque.
 *
 * @return  std::map<int, Produto>*
 */

std::map<int, Produto>* EstoqueBase::getEstoque(){
    return &estoque;
}

/** @brief Destruct a new EstoqueBase::~ EstoqueBase object
 * 
 */
EstoqueBase::~EstoqueBase(){}