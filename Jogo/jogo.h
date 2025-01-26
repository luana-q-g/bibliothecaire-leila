#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "livro/livro.h"
#include "livro/pilha.h"
#include "button/button.h"
#include "baselist/baselist.h"
#include <SFML/System/Vector2.hpp>
#include "cestas/tipoCesta.cpp"
#include "cestas/cesta.h"

class Jogo{
    private:
        int pontuacao;
    public:
        Jogo() : pontuacao(0) {}
        void verificarLivroNaCesta(const Livro& livro, std::vector<Cesta>& cestas,Jogo& jogo1, float& queda , int& pontosconsec);
        int getPontuacao();
        void setPontuacao(int novaPontuacao);

};


