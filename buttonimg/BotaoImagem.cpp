#include "BotaoImagem.h"

// Construtor
BotaoImagem::BotaoImagem(const std::string& caminhoImagem, const sf::Font& font, const std::string& textoStr, sf::Vector2f tamanho) {
    // Carrega a textura da imagem
    if (!textura.loadFromFile(caminhoImagem)) {
        throw std::runtime_error("Erro ao carregar a imagem: " + caminhoImagem);
    }

    // Configura o sprite
    sprite.setTexture(textura);
    sprite.setScale(
        tamanho.x / textura.getSize().x,
        tamanho.y / textura.getSize().y
    );

    if (!shader.loadFromFile("shader.frag", sf::Shader::Fragment)) {
        std::cerr << "Erro ao carregar o shader!" << std::endl;
    }

    // Configurar o shader
    shader.setUniform("texture", sf::Shader::CurrentTexture); // Passar a textura do sprite

    // Configura a fonte e o texto
    texto.setFont(font);
    texto.setString(textoStr);
    texto.setCharacterSize(12);
    texto.setFillColor(sf::Color::Black);
}

// Define a posição do botão
void BotaoImagem::setPosicao(float x, float y) {
    sprite.setPosition(x, y);

    // Centraliza o texto
    texto.setPosition(
        x + (sprite.getGlobalBounds().width - texto.getLocalBounds().width) / 2.f - texto.getLocalBounds().left,
        y + (sprite.getGlobalBounds().height - texto.getLocalBounds().height) / 2.f - texto.getLocalBounds().top
);
}

// Define a cor do filtro
void BotaoImagem::setCorFiltro(const sf::Color& cor) {
    corAtual = cor;
    shader.setUniform("color", sf::Glsl::Vec4(
        cor.r / 255.f,
        cor.g / 255.f,
        cor.b / 255.f,
        cor.a / 255.f
    ));
}

// Define o texto
void BotaoImagem::setTexto(const std::string& novoTexto) {
    texto.setString(novoTexto);

    // Centraliza o texto novamente
    sf::FloatRect bounds = texto.getLocalBounds();
    texto.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
}

// Desenha o botão
void BotaoImagem::desenhar(sf::RenderWindow& janela) {
    janela.draw(sprite, &shader);      // Desenha o sprite da imagem
    janela.draw(texto);       // Desenha o texto
}

// Verifica se o botão foi clicado
bool BotaoImagem::foiClicado(const sf::Vector2i& posicaoMouse) {
    return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(posicaoMouse));
}