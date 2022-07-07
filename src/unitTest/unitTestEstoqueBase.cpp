#include "autoload.hpp"

/**
 * @brief Teste unitário para a classe EstoqueBase
 * 
 */
void UnitTestEstoqueBase::run()
{
	try {

		// cria um estoque
		EstoqueCliente* estoqueX = new EstoqueCliente();	

		// adiciona 50 produtos ao estoque
		for(unsigned int i = 1; i <= 50; i++)
		{
			// adiciona um produto ao estoque base
			estoqueX->adicionar(Produto(i, "Produto " + std::to_string(i), "Produto legal que é o numero " + std::to_string(i),i * 10, i * 11.5), true);
		}

		// busca todos produtos e confere se as informacoes estao corretas
		for(unsigned int i = 1; i <= 50; i++)
		{
			// busca um produto no estoque base
			Produto* produto = estoqueX->buscar(i);
			// confere se as informacoes estao corretas
			if(produto->getId() != i || produto->getNome() != "Produto " + std::to_string(i) || produto->getDescricao() != "Produto legal que é o numero " + std::to_string(i) || produto->getQtd() != i * 10)
			{
				throw std::runtime_error("Erro ao buscar produto no estoque base");
			}
		}
		
		// valida se a função de getEstoque retorna o estoque correto
		if(estoqueX->getEstoque()->size() != 50)
		{
			throw std::runtime_error("Erro ao retornar estoque base");
		}

		// testa a função para deleção de todos os produtos do estoque
		for(unsigned int i = 1; i <= 50; i++)
		{
			// remove um produto do estoque base
			estoqueX->remover(i);
		}

		// pass the test
		pass();
	}
	catch ( std::exception &e )
	{
		// fail the test
		fail(std::string(e.what()));
	}
}