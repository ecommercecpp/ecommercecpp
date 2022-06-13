#include <iostream>
#include <string>
#include <map>

#include "../../../include/produtos/atributos/atributos.hpp"


std::map<std::string, std::map<std::string, std::string>> Atributos::getListaAtributos(){
    return ListaAtributos;
}

void Atributos::setListaAtributos(){
    ListaAtributos = getListaAtributos();
}

std::map<std::string, std::string> Atributos::getListaAtributos(std::string nomeAtributo){
    //retornar anome do atributo na lista
    return nomeAtributo;
}

void Atributos::setAtributo(std::string nomeAtributo){
    this->nomeAtributo = nomeAtributo;
}

void Atributos::adicionarAtributo(std::string nomeAtributo, std::map<std::string, std::string> niveis){
    //adicionar atributos de nome,niveis no mapa de listaAtributos
    std::map<std::string, std::map<std::string, std::string>>::iterator it;
    for (it = ListaAtributos.begin(); it != ListaAtributos.end(); it++) {
        ListaAtributos.insert(std::pair<std::string, std::map<std::string, std::string>>(nomeArquivo, niveis));
    }
}