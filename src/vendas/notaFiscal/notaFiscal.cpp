
#include "autoload.hpp"

/**
 * @brief Construct a new Nota Fiscal:: Nota Fiscal object
 * 
 * @param vendas 
 */
NotaFiscal::NotaFiscal(std::map<std::string, std::vector<Produto*>> venda)
{
	this->venda = venda;
}

/**
 * @brief Destroy the Nota Fiscal:: Nota Fiscal object
 * 
 */
NotaFiscal::~NotaFiscal()
{
	for (auto it = venda.begin(); it != venda.end(); it++)
	{
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			delete *it2;
		}
	}
}

/**
 * @brief Gera uma nota fiscal para a venda
 * 
 */
void NotaFiscal::gerarNotaFiscal()
{
	std::string nomeArquivo = "./export/" + uuids::to_string(gerarId()) + ".txt";

	std::cout << std::endl << "Gerando nota fiscal em " << nomeArquivo << std::endl << std::endl;

	std::ofstream fw(nomeArquivo, std::ofstream::out);

	if (!fw.is_open())
	{
		std::cout << "Erro ao abrir arquivo de nota fiscal!" << std::endl;
		return;
	}

	fw << "Nota Fiscal" << std::endl;

	for (auto cpf: venda)
	{
		Usuario* usuario = new Usuario();
		usuario = usuario->buscarUsuario(cpf.first);

		// Dados do cliente
		fw  << "+-----------------------------------------------------+"<< std::endl;
		fw  << "|                       CLIENTE                       |"<< std::endl;
		fw  << "+-----------------------------------------------------+"<< std::endl;
		fw  << "| NOME: " << usuario->getNome() << " |" << std::endl;
		fw  << "| CPF: " << usuario->getCpf() << " |" << std::endl;
		fw  << "| E-MAIL: " << usuario->getEmail() << " |" << std::endl;
		fw  << "+-----------------------------------------------------+"<< std::endl;
		fw  << "|                       ENDERECO                      |" << std::endl;
		fw  << "+-----------------------------------------------------+"<< std::endl;
		fw  << "| RUA: " << usuario->getEndereco().getRua() << " |" << std::endl;
		fw  << "| NUMERO: " << usuario->getEndereco().getNumero() << " |" << std::endl;
		fw  << "| BAIRRO: " << usuario->getEndereco().getBairro() << " |" << std::endl;
		fw  << "| CIDADE: " << usuario->getEndereco().getCidade() << " |" << std::endl;
		fw  << "| ESTADO: " << usuario->getEndereco().getEstado() << " |" << std::endl;
		fw  << "| CEP: " << usuario->getEndereco().getCep() << " |" << std::endl;
		fw  << "+-----------------------------------------------------+"<< std::endl;
		fw  << "|                       PRODUTOS                      |" << std::endl;
		fw  << "+-----------------------------------------------------+"<< std::endl;
		for (auto produto : cpf.second)
		{
			fw  << "| NOME: " << produto->getNome() << " |" << std::endl;
			fw  << "| PRECO: " << produto->getPreco() << " |" << std::endl;
			fw  << "| QUANTIDADE: " << produto->getQtd() << " |" << std::endl;
			fw  << "+-----------------------------------------------------+"<< std::endl;
		}
	}

	fw.close();

	std::cout << "Nota fiscal gerada com sucesso em	" << nomeArquivo << std::endl;
}

uuids::uuid NotaFiscal::gerarId()
{
	std::random_device rd;
	auto seed_data = std::array<int, 6> {};
	std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
	std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
	std::ranlux48_base generator(seq);

	uuids::basic_uuid_random_generator<std::ranlux48_base> gen(&generator);
	uuids::uuid const id = gen();
	assert(!id.is_nil());
	assert(id.as_bytes().size() == 16);
	assert(id.version() == uuids::uuid_version::random_number_based);
	assert(id.variant() == uuids::uuid_variant::rfc);

	return id;
}