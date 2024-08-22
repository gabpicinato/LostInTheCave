#pragma once

#include "Inimigo.hpp"

#define VEL_VOADOR 180.0f 

class Voador: public Inimigo::Inimigo
{
private:
    bool endiabrado; //se for endiabrado ele voa mais rapido

public:
    Voador(sf::Vector2f pos);
    Voador();
    ~Voador();

    bool consegueAtacar();
    bool atingiuJogador();
    void atacar();
    void agir();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};