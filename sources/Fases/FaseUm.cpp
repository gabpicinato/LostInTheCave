#include "../../include/Fases/FaseUm.hpp"

Fases::FaseUm::FaseUm():
Fase()
{

}

Fases::FaseUm::~FaseUm()
{
}

void Fases::FaseUm::criarMapa() {
    try {
        std::ifstream arquivo("../resources/Fases/FaseUm.txt");
        if (!arquivo.is_open()) {
            throw std::runtime_error("Erro ao abrir o arquivo de mapa!");
        }

        std::string linha;
        int y = 0;

        while (getline(arquivo, linha)) {
            for (int x = 0; x < linha.size(); x++) {
                sf::Vector2f pos(x * 50, y * 50);
                criarEntidade(pos, linha[x]);
            }
            y++;
        }

        arquivo.close(); // Fechar o arquivo após o uso

    } catch (const std::ifstream::failure& e) {
        std::cerr << "Exceção ao operar no arquivo: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }
}

void Fases::FaseUm::atualizar(float dt)
{
    listaInimigos->atualizar(dt);
    listaJogadores->atualizar(dt);
    pColisoes->verificarColisoes();

    centralizarCamera();
}

void Fases::FaseUm::desenhar()
{
    listaObstaculos->desenhar(); 
    listaInimigos->desenhar();
    listaJogadores->desenhar();
}

void Fases::FaseUm::executar()
{
    dt = relogio.restart().asSeconds();

    pGraf->limpar();

    pEventos->verificarEventos();
    atualizar(dt);
    desenhar();
    
    pGraf->mostrar();
}