#include <iostream>
#include <string>
#include <map>

#include "../../../include/autoload.hpp"


std::map<std::string, std::map<std::string, std::string>> Atributos::getListaAtributos(){
    return this->ListaAtributos;
}// ok 

/*void Atributos::setListaAtributos(){// Perguntar o que é pra ser feito aqui
    this->ListaAtributos = getListaAtributos();
}*/// Nesse set, eu fiz o map da ListaAtributos receber o que foi passado no getLista porém não tenho certeza se está correto.

std::map<std::string, std::string> Atributos::getListaAtributos(std::string nomeAtributo){
    //retornar anome do atributo na lista
    return nomeAtributo;
}// ok

/*void Atributos::setAtributo(std::string nomeAtributo){
    //setAtributo = nomeAtributo;
}// Nesse set, como eu não uma variável de nomeAtributo iniciada no construtor, o que eu coloco pra receber
// o nomeAtributo do parâmetro?*/

void Atributos::adicionarAtributo(std::string nomeAtributo, std::map<std::string, std::string> niveis){
    //adicionar atributos de nome,niveis no mapa de listaAtributos
    std::map<std::string, std::map<std::string, std::string>>::iterator it;
    it.insert({ nomeAtributo, niveis });
    //for (auto it = istaAtributos.begin(); it != ListaAtributos.end(); ++it) {
        //ListaAtributos.insert({std::pair<std::string, std::map<std::string, std::string>>(getListaAtributos(nomeAtributo), niveis)});
    //}//Não sei exatamente como inserir o atributo no map ;-;
}