#include "../../include/autoload.hpp"

/**
 * @brief Teste unitário para a classe EstoqueBase
 * 
 */
void UnitTestEstoqueBase::run()
{
	try {

		// cria um estoque
		EstoqueBase* estoqueX = new EstoqueBase();	
		

		// adiciona 50 produtos ao estoque
		
		for(int i = 1; i < 51; i++)
		{
			Produto prod = Produto(i, "nomeProduto", "descricao qualquer", i);
			estoqueX->EstoqueBase::adicionar(prod);
		}

		// busca todos produtos
		for(int i = 1; i < 51; i++)
		{
			estoqueX->EstoqueBase::buscar(i);
		}
		

		// retorna o estoque
		estoqueX.EstoqueBase::getEstoque();

		// remove todos produtos
		for(int i = 1; i < 51; i++)
		{
			estoqueX.EstoqueBase::remover(i);
		}
		

		//deleta o  estoque
		delete estoqueX;

		// pass the test
		pass();
	}
	catch ( std::exception &e )
	{
		// fail the test
		fail(std::string(e.what()));
	}
}