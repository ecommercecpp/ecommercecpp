#include "autoload.hpp"

/**
 * @brief Teste unitário para a classe Usuario
 * 
 */
void UnitTestUsuario::run()
{
    try{
        // criar um vetor de 100 usuários aleatórios
        std::vector<Usuario*> usuarios;
        for(int i = 0; i < 100; i++){

        
            Usuario *usuario = new Usuario(
               "Nome " + std::to_string(i),
                i,
                "Email " + std::to_string(i),
                Endereco("Rua " + std::to_string(i), i, "Complemento " + std::to_string(i), i, "Bairro " + std::to_string(i), "Cidade " + std::to_string(i), "Estado " + std::to_string(i)),
                "Senha " + std::to_string(i)

            );
            usuarios.push_back(usuario);
        }

        for(int i = 0; i < 100; i++)
        {
            if(usuarios[i]->getNome() != "Nome " + std::to_string(i))
                throw std::runtime_error("Erro ao testar o nome do usuário " + std::to_string(i));
            if(usuarios[i]->getCpf() != i)
                throw std::runtime_error("Erro ao testar o cpf do usuário " + std::to_string(i));
            if(usuarios[i]->getEmail() != "Email " + std::to_string(i))
                throw std::runtime_error("Erro ao testar o email do usuário " + std::to_string(i));
            if(usuarios[i]->getEndereco().getRua() != "Rua " + std::to_string(i))
                throw std::runtime_error("Erro ao testar o rua do usuário " + std::to_string(i));
            if(usuarios[i]->getEndereco().getNumero() != i)
                throw std::runtime_error("Erro ao testar o numero do usuário " + std::to_string(i));
            if(usuarios[i]->getEndereco().getComplemento() != "Complemento " + std::to_string(i))
                throw std::runtime_error("Erro ao testar o complemento do usuário " + std::to_string(i));
            if(usuarios[i]->getEndereco().getBairro() != "Bairro " + std::to_string(i))
                throw std::runtime_error("Erro ao testar o bairro do usuário " + std::to_string(i));
            if(usuarios[i]->getEndereco().getCidade() != "Cidade " + std::to_string(i))
                throw std::runtime_error("Erro ao testar a cidade do usuário " + std::to_string(i));
            if(usuarios[i]->getEndereco().getEstado() != "Estado " + std::to_string(i))
                throw std::runtime_error("Erro ao testar o estado do usuário " + std::to_string(i));
            if(usuarios[i]->getEndereco().getCep() != i)
                throw std::runtime_error("Erro ao testar o cep do usuário " + std::to_string(i));
            if(usuarios[i]->getSenha() != "Senha " + std::to_string(i))
                throw std::runtime_error("Erro ao testar a senha do usuário " + std::to_string(i));
        }

        // testa todos os sets
        for(int i = 0; i < 100; i++)
        {
            usuarios[i]->setNome("Nome " + std::to_string(i));
            usuarios[i]->setCpf(i);
            usuarios[i]->setEmail("Email " + std::to_string(i));
            usuarios[i]->setEndereco(Endereco("Rua " + std::to_string(i), i, "Complemento " + std::to_string(i), i, "Bairro " + std::to_string(i), "Cidade " + std::to_string(i), "Estado " + std::to_string(i)));
            usuarios[i]->setSenha("Senha " + std::to_string(i));
        }

        //remove os usuários
        for(int i = 0; i < 100; i++){
            delete usuarios[i];
        }
        //remove o vetor
        usuarios.clear();
        // thrown an error if the vector is not empty
        if(usuarios.size() != 0)
        {
            throw std::runtime_error("The vector is not empty");
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

