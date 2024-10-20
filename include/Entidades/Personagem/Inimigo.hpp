/*
Inimigo.hpp - Filha de Personagem - Classe Abstrata
*/

#pragma once

#include "Jogador.hpp"
#include "../../Listas/ListaEntidades.hpp"

#define COOLDOWN_ATIRADOR 1.7f
#define COOLDOWN_CHEFAO 1.5f
#define COOLDOWN_VOADOR 1.0f

#define DANO_ATIRADOR 10.0f
#define DANO_CHEFAO 20.0f
#define DANO_VOADOR 5.0f

#define PONTUACAO_ATIRADOR 75.0f
#define PONTUACAO_CHEFAO 250.0f
#define PONTUACAO_VOADOR 150.0f

namespace Entidades
{
    namespace Personagem
    {
        class Inimigo: public Personagem
        {
        protected:
            Jogador* pJogador;
            sf::Vector2f posInicial;

        protected:
            virtual void inicializarAnimacao() = 0;
            virtual void atualizarAnimacao() = 0;
            virtual bool consegueAtacar() = 0;
            virtual void atacar() = 0;

        public:
            Inimigo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
            Inimigo();
            virtual ~Inimigo();

            virtual nlohmann::json salvarJogo();
            void setJogador(Jogador* jog);
            void setPosInicial(const sf::Vector2f pos);
            const sf::Vector2f getPosJogador() const;
            virtual void agir() = 0;
            virtual const float getPontuacao() const = 0;

            virtual void executar(const float dt) = 0;
            virtual void colide(Entidade* ent, const sf::Vector2f intersec) = 0;
        };
    }
}