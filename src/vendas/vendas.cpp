#include "autoload.hpp"

int Vendas::controleId = 1;

/**
 * @brief Construct a new Vendas:: Vendas object
 * 
 */
Vendas::Vendas()
{
	std::ifstream filer("./data/vendas.json");
    json::value json = json::parse(filer);
	const json::array &dados = as_array(json);
	for(auto it = dados.begin(); it != dados.end(); ++it)
	{
		const json::value &v = *it;
		int id = std::stoi(v["id"].as_string());
		std::string cpf = v["cpf"].as_string();
		std::vector<Produto*> produtos;

		// para cada item do array de "produtos"
		const json::array &produtosJson = as_array(v["produtos"]);
		for(auto it2 = produtosJson.begin(); it2 != produtosJson.end(); ++it2)
		{
			const json::value &v2 = *it2;

			int id = std::stoi(v2["id"].as_string());
			std::string nome = v2["nome"].as_string();
			std::string descricao = v2["descricao"].as_string();
			double preco = std::stod(v2["preco"].as_string());
			double qtd = std::stod(v2["qtd"].as_string());
			produtos.push_back(new Produto(id, nome, descricao, qtd, preco));
		}

		this->vendas[id][cpf] = produtos;
		controleId = id + 1;
	}
}

/**
 * @brief Destroy the Vendas:: Vendas object
 * 
 */
Vendas::~Vendas()
{
	// para cada id
	for(auto it = this->vendas.begin(); it != this->vendas.end(); ++it)
	{
		// para cada cpf
		for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
		{
			// para cada produto
			for(auto it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
			{
				delete *it3;
			}
		}
	}
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
	}
	vendas[controleId][cpf] = produtos;
	gerarJsonVenda(controleId, cpf);
	atualizaEstoque(controleId, cpf, estoque);
	controleId++;
}

/**
 * @brief Retorna o valor da venda
 * 
 * @param controleId 
 * @param cpf 
 * @return double 
 */
double Vendas::valorVenda(int controleId, std::string cpf)
{
	std::ifstream filer("./data/vendas.json");
	json::value json = json::parse(filer);
	filer.close();
	const json::array &dados = as_array(json);
	for(auto it = dados.begin(); it != dados.end(); ++it)
	{
		const json::value &v = *it;
		if(std::stoi(v["id"].as_string()) == controleId && v["cpf"].as_string() == cpf)
		{
			return std::stod(v["valor"].as_string());
		}
	}

	return 0;
}

/**
 * @brief Retorna a data da venda
 * 
 * @param controleId 
 * @param cpf 
 * @return std::string 
 */
std::string Vendas::dataVenda(int controleId, std::string cpf)
{
	std::ifstream filer("./data/vendas.json");
	json::value json = json::parse(filer);
	filer.close();
	const json::array &dados = as_array(json);
	for(auto it = dados.begin(); it != dados.end(); ++it)
	{
		const json::value &v = *it;
		if(std::stoi(v["id"].as_string()) == controleId && v["cpf"].as_string() == cpf)
		{
			return v["data"].as_string();
		}
	}

	return "";
}

/**
 * @brief Lista as vendas
 * 
 */
void Vendas::listarVendas()
{
	std::cout << "+----+-----+------+-------------+---------------+"<< std::endl;
    std::cout << "| ID | CPF | DATA | VALOR TOTAL | QTD. PRODUTOS |"<< std::endl;
	std::cout << "+-----------------------------------------------+"<< std::endl;
	// exibe: id, cpf, data, valor, quantidade de produtos
	for(auto venda: vendas)
	{
		for(auto produto: venda.second)
		{
			std::cout << "| " << venda.first;
			std::cout << " | " << produto.first;
			std::cout << " | " << dataVenda(venda.first, produto.first);
			std::cout << " | " << valorVenda(venda.first, produto.first);
			std::cout << " | " << produto.second.size() << " |" << std::endl;
		}
	}

	std::cout << "+-----------------------------------------------+"<< std::endl;
}

/**
 * @brief Gera uma nota fiscal pra venda
 * 
 * @param id 
 */
void Vendas::gerarNotaFiscal(int id)
{
	// verifica se tem uma venda com o id informado
	if(vendas.find(id) == vendas.end())
	{
		std::cout << "Venda não encontrada" << std::endl;
		return;
	}
	else
	{
		NotaFiscal notaFiscal(vendas[id]);
		notaFiscal.gerarNotaFiscal();
	}
}