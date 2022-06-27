#include "../../../include/autoload.hpp"

std::map<std::string, std::map<std::string, std::string>> Atributos::getListaAtributos(){
    return this->ListaAtributos;
}// ok 

std::map<std::string, std::string> Atributos::getListaAtributos(std::string nomeAtributo){
    //retornar anome do atributo na lista
    return nomeAtributo;
}// ok


void Atributos::adicionarAtributo(std::string nomeAtributo, std::map<std::string, std::string> niveis){
    //adicionar atributos de nome,niveis no mapa de listaAtributos
    std::map<std::string, std::map<std::string, std::string>>::iterator it;
    it.insert({ nomeAtributo, niveis });
}