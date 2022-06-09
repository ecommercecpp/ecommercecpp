#include <map>

class Atributos
{
	private:
		map<string, map<string, string>> ListaAtributos;
	public:
		Atributos();
		map<string, map<string, string>> getListaAtributos();
		void setListaAtributos();
		map<string, string> getListaAtributos(string nomeAtributo);
		void setAtributo(string nomeAtributo);
		void adicionarAtributo(string nomeAtributo, map<string, string> niveis);
};