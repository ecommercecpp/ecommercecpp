#include "../../include/autoload.hpp"

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

