#include <vector>
#include <ctime>
#include <stdexcept>
#include "livro.h"
#include <locale> // Necessário para configurar o locale

#ifndef TIPOLIVRO_H
#define TIPOLIVRO_H



class tipoLivro {
private:
    std::vector<Livro> livros;

    // Retorna uma cor baseada na categoria
    sf::Color obterCorPorCategoria(const std::wstring& categoria) {
        if (categoria == L"Letras") return sf::Color::Blue;
        if (categoria == L"Filosofia") return sf::Color::Green;
        if (categoria == L"Geografia") return sf::Color::Yellow;
        if (categoria == L"História") return sf::Color::Red;
        if (categoria == L"Matemática") return sf::Color::Cyan;
        if (categoria == L"Psicologia") return sf::Color::Magenta;
        if (categoria == L"Informática") return sf::Color::Black;
        if (categoria == L"Química") return sf::Color(255, 140, 0); // Laranja
        if (categoria == L"Arte") return sf::Color(128, 0, 128);    // Roxo
        return sf::Color::Black; // Cor padrão
    }

public:
    tipoLivro() {
                // Adiciona todos os livros
        // Caminho para a textura
        std::wstring texturaCaminho = L"/home/davy/ProjetoPOO/bibliothecaire-leila/livro.png";

        // Letras
        livros.emplace_back(L"Libras: conhecimento além dos sinais", L"Maria Cristina da Cunha", L"Letras", 2011, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Letras"));
        livros.emplace_back(L"Comunicação e linguagem", L"Thelma de Carvalho Guimarães", L"Letras", 2012, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Letras"));
        livros.emplace_back(L"Teoria da Literatura I", L"Pedro Paulo da Silva", L"Letras", 2009, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Letras"));
        livros.emplace_back(L"Língua latina", L"Charlene Martins Miotti", L"Letras", 2010, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Letras"));

        // Filosofia
        livros.emplace_back(L"Introdução à Filosofia", L"João Mattar", L"Filosofia", 2010, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Filosofia"));
        livros.emplace_back(L"Ética", L"Maria Thereza Pompa Antunes", L"Filosofia", 2012, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Filosofia"));
        livros.emplace_back(L"Correntes modernas de filosofia", L"José Ferraz Neto", L"Filosofia", 2013, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Filosofia"));
        livros.emplace_back(L"Genealogia da Moral", L"Friedrich Nietzsche", L"Filosofia", 1887, L"Vozes", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Filosofia"));

        // Geografia
        livros.emplace_back(L"Hidrologia", L"Diego Barreto de Oliveira", L"Geografia", 2015, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Geografia"));
        livros.emplace_back(L"Espaço Geográfico: ensino e representação", L"Rosangela Doin de Almeida", L"Geografia", 1989, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Geografia"));
        livros.emplace_back(L"Pensamento geográfico brasileiro", L"Ruy Moreira", L"Geografia", 2008, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Geografia"));
        livros.emplace_back(L"Globalização e espaço geográfico", L"Eustáquio de Sene", L"Geografia", 2004, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Geografia"));

        // História
        livros.emplace_back(L"No Tempo das Especiarias: o império da pimenta e do açúcar", L"Fábio Pestana", L"História", 2006, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"História"));
        livros.emplace_back(L"Dicionário de Datas da História do Brasil", L"Circe Bittencour", L"História", 2007, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"História"));
        livros.emplace_back(L"História do Café", L"Ana Luiza Martins", L"História", 2008, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"História"));
        livros.emplace_back(L"As Primeiras Civilizações", L"Jaime Pinsky", L"História", 2011, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"História"));

        // Matemática
        livros.emplace_back(L"Geometria Analítica: Um Tratamento Vetorial", L"Ivan de Camargo", L"Matemática", 2005, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Matemática"));
        livros.emplace_back(L"Matemática financeira", L"André Wakamatsu", L"Matemática", 2018, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Matemática"));
        livros.emplace_back(L"Métodos numéricos em equações diferenciais", L"Marina Vargas", L"Matemática", 2021, L"Intersaberes", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Matemática"));
        livros.emplace_back(L"Geometrias Não Euclidianas", L"Nelson Pereira", L"Matemática", 2020, L"Intersaberes", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Matemática"));

        // Psicologia
        livros.emplace_back(L"Teorias da Personalidade", L"Howard S. Friedman", L"Psicologia", 2003, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Psicologia"));
        livros.emplace_back(L"Introdução à Psicologia", L"Charles G. Morris", L"Psicologia", 2004, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Psicologia"));
        livros.emplace_back(L"A Psicanálise nas Tramas da Cidade", L"Bernardo Tanis", L"Psicologia", 2009, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Psicologia"));
        livros.emplace_back(L"Burnout: quando o trabalho ameaça o bem-estar do trabalhador", L"Ana Maria Benevides Pereira", L"Psicologia", 2014, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Psicologia"));

        // Informática
        livros.emplace_back(L"Aprenda Programação Orientada a Objetos em 21 dias", L"Anthony Sintes", L"Informática", 2002, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Informática"));
        livros.emplace_back(L"Treinamento em Linguagem C++: módulo 1", L"Victorine Viviane Mizrahi", L"Informática", 1996, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Informática"));
        livros.emplace_back(L"Manual Completo do Linux: guia do administrador", L"Evi Nemeth", L"Informática", 2004, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Informática"));
        livros.emplace_back(L"Compiladores: princípios, técnicas e ferramentas", L"Alfred V. Alho", L"Informática", 2007, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Informática"));

        // Química
        livros.emplace_back(L"Química Orgânica", L"Bianca Sandrino", L"Química", 2020, L"Intersaberes", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Química"));
        livros.emplace_back(L"Química Quântica: Origens e Aplicações", L"Liziane Barbara Bugalski", L"Química", 2019, L"Intersaberes", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Química"));
        livros.emplace_back(L"Manual de Ar Comprimido e Gases", L"John P. Rollins", L"Química", 2003, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Química"));
        livros.emplace_back(L"Estudos de eletroquímica: reações químicas e energia", L"Ana Luiza Lorenzen", L"Química", 2017, L"Intersaberes", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Química"));

        // Arte
        livros.emplace_back(L"Estética e história da arte", L"Humberta Gomes Machado Porto", L"Arte", 2016, L"Pearson", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Arte"));
        livros.emplace_back(L"História do cinema mundial", L"Fernando Mascarello", L"Arte", 2014, L"Papirus", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Arte"));
        livros.emplace_back(L"Beethoven: as muitas faces de um gênio", L"João Mauricio Galindo", L"Arte", 2019, L"Contexto", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Arte"));
        livros.emplace_back(L"O cinema de Quentin Tarantino", L"Mauro Baptista", L"Arte", 2018, L"Papirus", sf::Vector2f(400, 0), texturaCaminho, obterCorPorCategoria(L"Arte"));

        std::srand(std::time(nullptr));

}

    // Retorna um livro aleatório
Livro getLivroAleatorio() {
    // Gera um índice aleatório com base no tamanho do vetor
    int indice = rand() % livros.size();

    // Carrega a textura para o livro no índice
    if (!livros[indice].textura.loadFromFile("livro.png")) {
        std::wcerr << L"Erro ao carregar a textura do livro no índice " << indice << std::endl;

        // Retorna um objeto padrão em caso de erro
        return Livro();
    }
   
    // Configura a textura do shape usando um método público
    livros[indice].setTextura(livros[indice].textura);

    // Retorna o livro selecionado
    return livros[indice];
}

    std::vector<Livro> getLivros() const {
        return livros; // Retorna todos os livros
    }

    

};

#endif