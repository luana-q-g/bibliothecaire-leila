#ifndef LIVRO_H
#define LIVRO_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory> // Para std::shared_ptr

class Livro {
private:
    std::wstring nome;                 // Nome do livro
    std::wstring autor;                // Autor do livro
    std::wstring categoria;            // Categoria do livro
    int ano_lancamento;                // Ano de lançamento
    std::wstring editora;              // Editora do livro
    sf::RectangleShape shape;          // Representação gráfica do livro
    sf::Vector2f posicao;              // Posição do livro
    std::wstring texturaCaminho;       // Caminho para a textura
    std::shared_ptr<sf::Texture> texture; // Textura do livro
    sf::Texture texturaLivro;          // Textura para fallback
    float velocidadeQueda;             // Velocidade de queda
    sf::Color cor;                     // Cor do livro

public:
    // Construtores
    Livro();
    Livro(std::wstring _nome, std::wstring _autor, std::wstring _categoria,
          int _anoLancamento, std::wstring _editora, sf::Vector2f _posicao,
          const std::wstring& caminhoImagem, sf::Color _cor);

    // Getters
    std::wstring getNome() const;
    std::wstring getAutor() const;
    std::wstring getCategoria() const;
    int getAnoLancamento() const;
    std::wstring getEditora() const;
    sf::RectangleShape getShape() const;
    sf::Texture getTextura() const;
    sf::Color getCor() const;

    // Setters
    void setNome(std::wstring _nome);
    void setAutor(std::wstring _autor);
    void setCategoria(std::wstring _categoria);
    void setAnoLancamento(int _ano_lancamento);
    void setEditora(std::wstring _editora);
    void setTextura(const std::string& caminhoTextura);
    void setVelocidadeQueda(float velocidade);
    void setCor(const sf::Color& novaCor) {
        cor = novaCor;              // Atualiza a variável membro `cor`
        shape.setFillColor(cor);    // Aplica a nova cor ao retângulo gráfico do livro
}


    // Métodos de movimento
    void mover(sf::RenderWindow& window);
    void cair();

    // Sobrecarga de operadores
    bool operator>(const Livro& livro) const;
    bool operator<(const Livro& livro) const;
    bool operator==(const Livro& livro) const;

    // Operador de saída para impressão
    friend std::wostream& operator<<(std::wostream& output, const Livro& l1);
};

#endif // LIVRO_H
