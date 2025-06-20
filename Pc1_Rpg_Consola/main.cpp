#include <iostream>
#include <string>
using namespace std;

class Personaje {
public:
    string nombre;
    int vida;
    int ataque;

    Personaje(string n, int v, int a) : nombre(n), vida(v), ataque(a) {}

    void atacar(Personaje &enemigo) {
        enemigo.vida -= ataque;
        cout << nombre << " ataca a " << enemigo.nombre
             << " y le queda " << enemigo.vida << " de vida.\n";
    }

    bool estaVivo() {
        return vida > 0;
    }
};

int main() {
    Personaje jugador("Héroe", 100, 20);
    Personaje enemigo("Goblin", 60, 15);

    cout << "¡Comienza el combate RPG por consola!\n";

    while (jugador.estaVivo() && enemigo.estaVivo()) {
        jugador.atacar(enemigo);
        if (enemigo.estaVivo()) {
            enemigo.atacar(jugador);
        }
    }

    if (jugador.estaVivo()) {
        cout << jugador.nombre << " ha ganado el combate!\n";
    } else {
        cout << enemigo.nombre << " ha ganado el combate!\n";
    }

    return 0;
}
