/*
Observador.hpp - Classe Abstrata
----------------------------------------------------
 * Padrão de projeto Observer.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorInputs.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"
#include <map>
#include <string>

namespace Observadores
{
    class Observador
    {
    protected:
        Gerenciadores::GerenciadorInputs* pInp;
        Gerenciadores::GerenciadorEstados* pEstados;
        map<sf::Keyboard::Key, std::string> teclado;
        map<sf::Keyboard::Key, std::string> tecladoEspecial;

    private:
        void inicializaTeclado();

    public:
        Observador();
        virtual ~Observador();

        virtual void notificarPressionada(const sf::Keyboard::Key tecla) = 0;
        virtual void notificarSolta(const sf::Keyboard::Key tecla) = 0;
    };
}; 