#pragma once

#include "Fase.hpp"

namespace Fases
{
    class FaseUm : public Fase
    {
    private:
        // Entidades::Chave* chave; essa é a chave necessaria para passar de fase

    public:
        FaseUm();
        ~FaseUm();

        void criarMapa();

        void atualizar(const float dt);
        void desenhar();
        void executar();
    };
    
    
};