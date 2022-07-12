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
    // verifica se o produto ja existe usando o método buscar
    if(buscar(produto.getId()) != nullptr)
    {
        // se já existe, apaga o produto antigo usando remover
        remover(produto.getId());
    }

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

    // insere o estoque no array e no arquivo
    estoque.insert(std::pair<int, Produto>(produto.getId(), produto));
}

/**
 * @brief Remove uma quantidade de itens em estoque de um produto
 * 
 * @param id 
 * @param qtd 
 */
void EstoqueBase::removerQtd(int id, double qtd)
{
    auto it = estoque.find(id);
    if(it != estoque.end())
    {
        it->second.setQtd(qtd);

        // atualiza o arquivo com o novo estoque
        adicionar(it->second, true);
    }
}

/**
 * @brief Remove um produto do estoque.
 *
 * @param  int id
 */
void EstoqueBase::remover(int id)
{
    // remove do objeto
    estoque.erase(id);
    // remove do arquivo json
    std::ifstream filer("./data/estoque.json");
    json::value json = json::parse(filer);
    json::array &a = as_array(json);
    filer.close();

    // cria um array temporario para remover o produto
    json::array temp;
    for(auto it = a.begin(); it != a.end(); ++it)
    {
        const json::value &v = *it;

        if (v["id"].as_string() != std::to_string(id))
        {
            temp.push_back(v);
        }
    }
    std::ofstream file("./data/estoque.json");
    file << stringify(temp);
    file.close();
}

/**
 * @brief Busca um produto no estoque.
 *
 * @param  int id
 *
 * @return Produto*  
 */
Produto* EstoqueBase::buscar(int id)
{
    // busca no objeto
    auto it = estoque.find(id);
    if(it != estoque.end())
    {
        return &it->second;
    }
    return nullptr;
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

/**
 * @brief Busca um produto base por SKU
 * 
 * @param sku 
 * @return Produto* 
 */
Produto* EstoqueBase::buscarPorSku(int sku)
{
    return nullptr;
}