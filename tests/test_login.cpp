#include "autoload.hpp"
#include "doctest"

TEST_CASE("Testa o login corretamente")
{
	Usuario usuario = Usuario();
	usuario.setCpf("12341234123");
	usuario.setSenha("senha");
	CHECK(usuario.login());
}

TEST_CASE("Testa o login com usuário que não existe")
{
	Usuario usuario = Usuario();
	usuario.setCpf("32132132132");
	usuario.setSenha("senha");
	CHECK_THROWS_AS(usuario.login(), UsuarioNaoEncontradoException);
}

TEST_CASE("Testa o login com senha invalida")
{
	Usuario usuario = Usuario();
	usuario.setCpf("12341234123");
	usuario.setSenha("123");
	CHECK_THROWS_AS(usuario.login(), UsuarioSenhaInvalidaException);
}

TEST_CASE("Testa o cadastro corretamente")
{
	Endereco endereco;
	endereco.setRua("rua");
	endereco.setNumero("123");
	endereco.setBairro("bairro");
	endereco.setCidade("cidade");
	endereco.setEstado("estado");
	endereco.setCep("12312312");
	Usuario usuario = Usuario("nome", "32132132132", "email", endereco, "senha");
	CHECK(usuario.cadastro());
}

TEST_CASE("Testa o cadastro com usuário existente")
{
	Endereco endereco;
	endereco.setRua("rua");
	endereco.setNumero("123");
	endereco.setBairro("bairro");
	endereco.setCidade("cidade");
	endereco.setEstado("estado");
	endereco.setCep("12312312");
	Usuario usuario = Usuario("nome", "12341234123", "email", endereco, "senha");
	CHECK_THROWS_AS(usuario.cadastro(), UsuarioExistenteException);
}