/*
Teia.hpp - Filha de Obstaculo
*/

#pragma once

#include "Obstaculo.hpp"

#define CAMINHO_TEXTURA_TEIA "../assets/sprites/Teia/Teia.png"

namespace Entidades
{
    namespace Obstaculos
    {
        class Teia : public Obstaculo
        {
        private:
            float densidade;
            
        public:
            Teia(sf::Vector2f pos);
            Teia();
            ~Teia();

            nlohmann::json salvarJogo();
            void setDensidade(float den);
            const float getDensidade() const;

            void colide(Entidade *ent, const sf::Vector2f intersec);
        };
    }
}