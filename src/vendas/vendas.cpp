#include "autoload.hpp"

int Vendas::controleId = 1;

/**
 * @brief Construct a new Vendas:: Vendas object
 * 
 */
Vendas::Vendas()
{

}

/**
 * @brief Destroy the Vendas:: Vendas object
 * 
 */
Vendas::~Vendas()
{
	
}

/**
 * @brief Atualiza o estoque de um produto vendido
 * 
 * @param controleId 
 * @param cpf 
 * @param estoque 
 */
void Vendas::atualizaEstoque(int controleId, std::string cpf, EstoqueBase *estoque)
{
	for (auto produto: vendas[controleId][cpf])
	{
		Produto *p = estoque->buscar(produto->getId());
		double qtd = 0;
		if (p != nullptr)
		{
			if((p->getQtd() - produto->getQtd()) >= 0)
			{
				qtd = p->getQtd() - produto->getQtd();
			}
		}
		estoque->removerQtd(produto->getId(), qtd);
	}
}

/**
 * @brief Retorna a data atual da venda em d/m/Y
 * 
 * @return std::string 
 */
std::string Vendas::dataAtual()
{
	time_t t = time(0);
	struct tm * now = localtime( & t );
	char buffer[80];
	strftime(buffer, 80, "%d/%m/%Y", now);
	return std::string(buffer);
}

/**
 * @brief Grava o json de venda
 * 
 * @param controleId 
 * @param cpf 
 */
void Vendas::gerarJsonVenda(int controleId, std::string cpf)
{
	std::ifstream filer("./data/vendas.json");
    json::value json = json::parse(filer);
	filer.close();

	// cria um string com a data de execução em d/m/Y
	std::string data = dataAtual();

	// acha o valor total da venda
	double valorTotal = 0;


	auto jsonArray = json::object{
        {"id", controleId},
		{"cpf", cpf},
		{"data", data},
		{"valor", 0.00},
		{"produtos", json::array()}
    };

	// para cada produto da venda, adiciona no jsonArray
	for (auto produto: vendas[controleId][cpf])
	{
		auto jsonProduto = json::object{
			{"id", produto->getId()},
			{"nome", produto->getNome()},
			{"descricao", produto->getDescricao()},
			{"preco", produto->getPreco()},
			{"qtd", produto->getQtd()}
		};
		valorTotal += produto->getPreco() * produto->getQtd();
		jsonArray["produtos"].push_back(jsonProduto);
	}

	jsonArray["valor"] = valorTotal;

	// adiciona o jsonArray no json
	json.push_back(jsonArray);

	std::ofstream file("./data/vendas.json");
    file << stringify(json);
    file.close();
}

/**
 * @brief Adiciona a venda no array
 * 
 * @param dadosCarrinho 
 * @param estoque 
 * @param cpf 
 */
void Vendas::adicionarVenda(std::map<int, double> dadosCarrinho, EstoqueBase *estoque, std::string cpf)
{
	std::vector<Produto*> produtos;

	for (auto dadoCarrinho: dadosCarrinho)
	{
		Produto *produtoTPM = estoque->buscar(dadoCarrinho.first);
		if (produtoTPM != nullptr)
		{
			Produto *produto = new Produto(produtoTPM->getId(), produtoTPM->getNome(), produtoTPM->getDescricao(), produtoTPM->getQtd(), produtoTPM->getPreco());
			produto->setQtd(dadoCarrinho.second);
			produtos.push_back(produto);
		}
		delete produtoTPM;
	}

	vendas[controleId][cpf] = produtos;

	gerarJsonVenda(controleId, cpf);

	atualizaEstoque(controleId, cpf, estoque);

	controleId++;
}