#include "../../../include/Entidades/Personagem/Inimigo.hpp"

namespace Entidades
{
    namespace Personagem
    {

        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
        Personagem(pos, tam, tp),
        posInicial(pos),
        pJogador(NULL)
        {
            estaNoChao = false;
            tempoAtaque = 0.0f;
        }

        Inimigo::Inimigo()
        {
            pJogador = NULL;
        }

        Inimigo::~Inimigo()
        {
            pJogador = NULL;
        }

        nlohmann::json Inimigo::salvarJogo()
        {
            nlohmann::json j = Personagem::salvarJogo();
            j["posInicial"] = {posInicial.x, posInicial.y};
            return j;
        }
        
        void Inimigo::setJogador(Jogador *jog)
        {
            if(jog)
            {        
                pJogador = jog;
            }
        }

        sf::Vector2f Inimigo::getPosJogador()
        {
            return pJogador->getPosicao();
        }

        void Inimigo::colide(Entidade *ent, const sf::Vector2f intersec)
        {
            switch (ent->getTipo())
            {
            case TIPO::PLATAFORMA:
            {
                if(intersec.x > intersec.y)
                {
                    if(getPosicao().y > ent->getPosicao().y)
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
                    }
                    else
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                        estaNoChao = true;
                    }
                    vel.y = 0.0f;
                }
                else
                {
                    if(getPosicao().x > ent->getPosicao().x)
                    {
                        setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));    
                    }
                    else
                    {
                        setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                    }
                    vel.x = -vel.x;
                }
                break;
            }
            case TIPO::ATIRADOR:
            {
                if(getPosicao().x > ent->getPosicao().x)
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));
                }
                else
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                }
                break;
            }

            case TIPO::CHEFAO:
            {
                if(getPosicao().x > ent->getPosicao().x)
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));
                }
                else
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                }
                break;
            }

            case TIPO::VOADOR:
            {
                if(getPosicao().x > ent->getPosicao().x)
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));
                }
                else
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                }
                break;
            }
            
            default:
                break;
            }
            
        }
    }
}