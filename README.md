<div id="top"></div>

# EcommerceCPP

> O EcommerceCPP é uma abstração de um sistema de e-commerce.

[![Contributors][contributors-shield]][contributors-url]
[![Tamanho][tamanho-shield]][tamanho-url]
[![Linguagens][linguagens-shield]][linguagens-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<br/>

> O EcommerceCPP possui uma política de qualidade de código, onde garantimos que todos os códigos são testados, seguros e corretos. Status:           [![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=ecommercecpp_ecommercecpp&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=ecommercecpp_ecommercecpp)

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Sumário</summary>
  <ol>
    <li>
      <a href="#ecommercecpp">O Projeto</a>
    </li>
    <li>
      <a href="#começando-">Começando 🚀</a>
      <ul>
        <li><a href="#pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#instalação">Instalação</a></li>
      </ul>
    </li>
    <li><a href="#como-utilizar-o-ecommercecpp">Como utilizar o EcommerceCPP</a></li>
    <li><a href="#contruibuindo">Contruibuindo</a></li>
    <li><a href="#-user-stories">☕ User Stories</a></li>
    <li><a href="#-colaboradores">🤝 Colaboradores</a></li>
    <li><a href="#-links-úteis">🔗 Links Úteis</a></li>
  </ol>
</details>


## Começando 🚀

> [![Documentação Doxygen][documentacao-shield]][documentacao-url]

Para começar a utilizar o repositório, você precisa cumprir todos os requisitos abaixo:

### Pré-requisitos

* Ter um compilador c++ instalado.
* Ter o mingw na versão 11.2.0 e/ou c++ na versão 17 ou superior.
* Ter o cmake instalado.
* Ter o git instalado.
* Estar em um ambiente linux e/ou derivado.

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

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
<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

## Como utilizar o EcommerceCPP

Para começar a utilizar, após a instalação, basta rodar:

- Para Linux:

```sh
  ./main
```
- Para Windows:

```sh
  ./main.exe
```

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

## Contruibuindo

As contribuições são o que tornam a comunidade de código aberto um lugar incrível para aprender, inspirar e criar. Quaisquer contribuições que você fizer são **muito apreciadas**.

Se você tiver uma sugestão para melhorar o projeto, por favor, faça um fork do repositório e crie um pull request. Você também pode simplesmente abrir um issue com a tag "melhoria".
Não se esqueça de dar uma estrela ao projeto! Obrigado novamente!

1. Dê um fork no projeto
2. Cria sua branch de melhoria (`git checkout -b feature/MelhoriaIncrivel`)
3. Faça um commit de suas mudanças (`git commit -m 'feat: adicionado uma melhoria incrível'`)
4. Faça um push para sua branch (`git push origin feature/MelhoriaIncrivel`)
5. Abra um pull request.

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

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

<p align="right">(<a href="#top">Voltar para o topo</a>)</p>

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
- [UUID](https://github.com/mariusbancila/stduuid)
- [GLS](https://github.com/microsoft/GSL)

[documentacao-shield]: https://img.shields.io/badge/Documentação%20Doxygen-clique%20aqui-blue
[documentacao-url]: https://ecommercecpp.github.io/ecommercecpp/annotated.html
[linguagens-shield]: https://img.shields.io/github/languages/count/ecommercecpp/ecommercecpp?style=for-the-badge
[linguagens-url]: https://github.com/ecommercecpp/ecommercecpp/
[tamanho-shield]: https://img.shields.io/github/repo-size/ecommercecpp/ecommercecpp?style=for-the-badge
[tamanho-url]: https://github.com/ecommercecpp/ecommercecpp/
[contributors-shield]: https://img.shields.io/github/contributors/ecommercecpp/ecommercecpp.svg?style=for-the-badge
[contributors-url]: https://github.com/ecommercecpp/ecommercecpp/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/ecommercecpp/ecommercecpp.svg?style=for-the-badge
[forks-url]: https://github.com/ecommercecpp/ecommercecpp/network/members
[stars-shield]: https://img.shields.io/github/stars/ecommercecpp/ecommercecpp.svg?style=for-the-badge
[stars-url]: https://github.com/ecommercecpp/ecommercecpp/stargazers
[issues-shield]: https://img.shields.io/github/issues/ecommercecpp/ecommercecpp.svg?style=for-the-badge
[issues-url]: https://github.com/ecommercecpp/ecommercecpp/issues
[license-shield]: https://img.shields.io/github/license/ecommercecpp/ecommercecpp.svg?style=for-the-badge
[license-url]: https://github.com/ecommercecpp/ecommercecpp/blob/master/LICENSE.txt
