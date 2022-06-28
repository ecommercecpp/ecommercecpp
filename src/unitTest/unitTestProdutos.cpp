#include "../../include/autoload.hpp"
/**
 * @brief Teste unitário para a classe Produtos
 * 
 */
void UnitTestProdutos::run()
{
	try
	{
		//criando um vector de 100 nomes aleatorios
        std::vector<Produto*> produtos;
        for(int i = 0; i < 100; i++)
		{
            Produto *produto = new Produto(
			   i,	
               "Nome " + std::to_string(i),
			   "Descricao " + std::to_string(i),
			   i
            );
            produtos.push_back(produto);
        }

		// testa todos os gets de Nome e Descricao
		for (int i = 0; i < 100; i++)
		{
			if (produtos[i]->getNome() != "Nome " + std::to_string(i))
				throw std::runtime_error("Erro ao testar o set do Nome");
			if (produtos[i]->getDescricao() != "Descricao " + std::to_string(i))
				throw std::runtime_error("Erro ao testar o set da descricao");				
		}

		// testa todos os gets
		for (unsigned int i = 0; i < 100; i++)
		{
			if (produtos[i]->getId() != i)
				throw std::runtime_error("Erro ao testar o set do ID");
		}	
		// testa todos os gets
		for (double i = 0; i < 100; i++)
		{
			if (produtos[i]->getQtd() != i)
				throw std::runtime_error("Erro ao testar o set da Qtd");
		}			


		// testa os sets de nome e descricao
		for (int i = 0; i < 100; i++)
		{
			produtos[i]->setNome("Nome " + std::to_string(i));
			produtos[i]->setDescricao("Descricao " + std::to_string(i));
		}
		// testa os sets do id
		for (unsigned int i = 0; i < 100; i++)
		{
			produtos[i]->setId(i);
		}	
		// testa os sets da Qtd
		for (double i = 0; i < 100; i++)
		{
			produtos[i]->setQtd(i);
		}					

		// remove os endereços
		for (int i = 0; i < 100; i++)
		{
			delete produtos[i];
		}
		
		// remove o vector
		produtos.clear();

		// thrown an error if the vector is not empty
		if (produtos.size() != 0)
		{
			throw std::runtime_error("The vector is not empty");
		}					

		// caso passar em todos os testes, use pass(); para passar o teste
		pass();
	}
	catch ( std::exception &e )
	{
		//falha no teste
		fail(std::string(e.what()));
	}
}