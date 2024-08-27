#include "../../include/Observadores/ObsMenu.hpp"
#include "../../include/Menu/Menu.hpp"

Observadores::ObsMenu::ObsMenu(Menu::Menu *pM):
Observador(),
pMenu(pM)
{
    cima = sf::Keyboard::Key::Up;
    baixo = sf::Keyboard::Key::Down;
    enter = sf::Keyboard::Key::Enter;

    if(pMenu->getEstadoID() == Estados::EstadoID::MenuJogarUm || 
       pMenu->getEstadoID() == Estados::EstadoID::MenuJogarDois ||
       pMenu->getEstadoID() == Estados::EstadoID::MenuColocacao)
    {
        podeSelecionar = false;
    }
    else
    {
        podeSelecionar = true;
    }
}

Observadores::ObsMenu::ObsMenu():
Observador()
{
}

Observadores::ObsMenu::~ObsMenu()
{
    pMenu = NULL;
}

void Observadores::ObsMenu::notificarPressionada(const sf::Keyboard::Key tecla)
{
    if(!pMenu->getAtivo())
        return;

    if(tecla == cima)
    {
        pMenu->irParaCima();
    }
    else if(tecla == baixo)
    {
        pMenu->irParaBaixo();
    }
    else if(tecla == enter && podeSelecionar)
    {
        pMenu->selecionar(pMenu->getBotaoSelecionado());
    }
}

void Observadores::ObsMenu::notificarSolta(const sf::Keyboard::Key tecla)
{
    if(tecla == enter)
    {
        podeSelecionar = true;
    }
}