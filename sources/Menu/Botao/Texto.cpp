#include "../../../include/Menu/Botao/Texto.hpp"

Texto::Texto(const char *caminhoFonte):
    pGraf(Gerenciadores::GerenciadorGrafico::getInstancia()),
    texto()
{
    fonte.loadFromFile(caminhoFonte);
    texto.setFont(fonte);
    texto.setString("palavra");
}

Texto::~Texto()
{
}

void Texto::operator=(string informacao)
{
    if(informacao.empty())
    {
        texto.setString("");
    }
    else
        texto.setString(informacao);
}

void Texto::setPos(sf::Vector2f pos)
{
    texto.setPosition(pos);
}

void Texto::setCor(sf::Color cor)
{
    texto.setFillColor(cor);
}

void Texto::setTamanhoFonte(int tam)
{
    texto.setCharacterSize(tam);
}

string Texto::getInfo()
{
    if(texto.getString().isEmpty())
    {
        return "";
    }
    return texto.getString();
}

const sf::Vector2f Texto::getTamanho() const
{
    sf::FloatRect textoRect = texto.getLocalBounds();
    return sf::Vector2f(textoRect.width, textoRect.height);
}

const sf::Vector2f Texto::getPos() const
{
    return texto.getPosition();
}

void Texto::desenhar()
{
    pGraf->desenhar(texto);
}