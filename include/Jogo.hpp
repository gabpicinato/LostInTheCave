#pragma once

#include "Entidades/Personagem/Jogador.hpp"
#include "Entidades/Personagem/Voador.hpp"
#include "Entidades/Personagem/Chefao.hpp"
#include "Entidades/Personagem/Atirador.hpp"
#include "Entidades/Obstaculos/Teia.hpp"
#include "Entidades/Obstaculos/Espinho.hpp"
#include "Gerenciadores/GerenciadorEstados.hpp"
#include "Fases/FaseUm.hpp"

class Jogo
{
private:
    Gerenciadores::GerenciadorGrafico* pGraf;
    Gerenciadores::GerenciadorEventos* pEventos;
    Gerenciadores::GerenciadorEstados* pEstados;

public:
    Jogo();
    ~Jogo();

    void executar();
};