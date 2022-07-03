# EcommerceCPP

![Tamanho](https://img.shields.io/github/repo-size/ecommercecpp/ecommercecpp?style=for-the-badge)
![Linguagens](https://img.shields.io/github/languages/count/ecommercecpp/ecommercecpp?style=for-the-badge)
![Forks](https://img.shields.io/github/forks/ecommercecpp/ecommercecpp?style=for-the-badge)
![Issues](https://img.shields.io/github/issues/ecommercecpp/ecommercecpp?style=for-the-badge)

<br/>

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=ecommercecpp_ecommercecpp&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=ecommercecpp_ecommercecpp)

> O EcommerceCPP é uma abstração de um sistema de e-commerce.

## ☕ User Stories
    
### Cadastro de novos usuarios (roles: administrador, cliente) | [@EduScf](https://github.com/EduScf)

Como administrador da plataforma, desejo um sistema seguro, rápido e fácil de cadastro. Para isso, quero que seja possível ser cadastrado como cliente, tendo acesso a sua conta que fornecerá dados pessoais e um histórico de compras, ou como administrador, que será possível modificar e consultar os produtos da loja. Sendo que independentemente da categoria, para criação do cadastro deverá ser fornecido o nome completo, CPF, RG e CEP de onde a pessoa mora. Prezando a segurança do banco de dados para que todas as informações fornecidas pelo cliente fiquem em segurança.

### Controle de cadastro de produtos | [@aquila1004](https://github.com/aquila1004)

Como administrador, quero separar os produtor por categorias no momento da escolha. Dessa forma, o próximo passo vai ser fazer uma boa descrição do produto através do seu controle no momento do cadastro. Todos os produtos deverão ter as seguintes informações cedidas no momento de seu cadastro. Sendo assim, deverão possuir foto do produto, peso.


### Controle de cadastro de variações de produtos (produto simples e produto variável) | [@CaioHosken](https://github.com/CaioHosken)

Como administrador, quero a possibilidade de cadastrar dois tipos de produtos (produto simples e produto variável). O produto simples é único, e por isso cadastrado com apenas seu tamanho, cor e quantidade, por não possuir nenhum outro item do do mesmo modelo porém cor ou tamanho diferente, não é preciso separá-lo. Já o produto variável é cadastrado e separado com diferentes tamanhos e cores disponíveis no estoque. Tudo isso para que o cliente saiba quantas unidades temos de cada item, separados por tamanhos, cores e outras espicifidades.

### Cadastro de métodos de entrega | [@FelippeVelosoMarinho](https://github.com/FelippeVelosoMarinho)

Como cliente, quero que seja possível definir o tipo de entrega que desejo ao realizar uma venda e, que haja o calculo do frete conforme a região do endereço indicado. Sendo minimamente necessário uma opção de frete por localização. É de grande importância um sistema de rastreamento na entrega do produto e o auto preenchimento dos dados de endereço ao ser digitado o CEP. Sendo assim, maneiras de obter uma melhor experiência de usuário, e que haja maior transparência durante o processo da compra.

### Cadastro de vendas | [@srgoogle23](https://github.com/srgoogle23)

Como Administrador, quero ver em vendas os produtos ( e suas variações ) selecionados pelo cliente, assim como os principais dados do cliente, como nome, e-mail, CPF, dados de endereço, método de entrega selecionado, método de pagamento selecionado pelo cliente. Para que baseado nessas informações, consiga saber se o pedido (venda) já foi pago, está em andamento, já foi aprovado ou se já posso enviar pro cliente o pedido, conforme o método de entrega e dados de endereço informados.

### Emissão de nota fiscal | [@srgoogle23](https://github.com/srgoogle23)

Como administrador, quero a possibilidade de, após a venda ser efetivada, antes de realizar o envio para o cliente, conseguir emitir uma nota fiscal para o cliente, com os dados dos produtos inclusos na compra, dados de pagamento, dados do cliente e dados de entrega para o cliente, mesclando tudo em uma nota fiscal informativa para o cliente, de modo que consiga anexar isso ao pedido como documentação, para eventuais questionamentos.

## Começando 🚀

Para começar a utilizar o repositório, você precisa cumprir todos os requisitos abaixo:

### Pré-requisitos

- Ter um compilador c++ instalado.
- Ter o mingw na versão 11.2.0
- Ter o cmake instalado.
- Ter o git instalado.
- Estar em um ambiente linux

### Instalação

1. Clone o repositório.
   ```sh
   git clone https://github.com/ecommercecpp/ecommercecpp.git
   ```
2. Entre no diretório do repositório.
    ```sh
    cd ecommercecpp
    ```
3. Execute o comando `make` para gerar o projeto.
    ```sh
    make
    ```

4. (opcional) Execute o comando `make test` para testar o projeto.
    ```sh
    make test
    ```


## 🤝 Colaboradores

Agradecemos às seguintes pessoas que contribuíram para este projeto:

<table>
  <tr>
    <td align="center">
      <a href="#">
        <img src="https://avatars3.githubusercontent.com/u/62403037" width="100px;" alt="srgoogle23"/><br>
        <sub>
          <b>srgoogle23</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars3.githubusercontent.com/u/102927669" width="100px;" alt="EduScf"/><br>
        <sub>
          <b>EduScf</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars3.githubusercontent.com/u/97201817" width="100px;" alt="aquila1004"/><br>
        <sub>
          <b>aquila1004</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars3.githubusercontent.com/u/60450622" width="100px;" alt="FelippeVelosoMarinho"/><br>
        <sub>
          <b>FelippeVelosoMarinho</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars3.githubusercontent.com/u/97640125" width="100px;" alt="CaioHosken"/><br>
        <sub>
          <b>CaioHosken</b>
        </sub>
      </a>
    </td>
  </tr>
</table>


## 🔗 Links Úteis

- [Histórias de usuários com exemplos e um template](https://www.atlassian.com/br/agile/project-management/user-stories)
- [Parser Json](https://github.com/eteran/cpp-json)
