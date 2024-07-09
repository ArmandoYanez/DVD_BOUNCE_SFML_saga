#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

int main() {
    // Crear la ventana de SFML.
    sf::RenderWindow window(sf::VideoMode(600, 350), "DVD SUPER PAPU PRO");

    //Array para guardar otros logos de dvd.
    std::string dvdlogos[] = {
            "../dvd_logo.png",
            "../dvd_logo2.png",
            "../dvd_logo3.png",
            "../dvd_logo4.png"
    };

    std::random_device rd;
    std::mt19937 gen(rd());

    // Numero random del 0 a 3.
    std::uniform_int_distribution<> dis(0, 3);

    // Cargar el sprite dvd 1.
    sf::Texture dvdLogoTexture;
    if (!dvdLogoTexture.loadFromFile("../dvd_logo.png")) {
        std::cerr << "Failed to load DVD logo image" << std::endl;
        return 1;
    }

    // Crear el sprite del logo de DVD.
    sf::Sprite dvdLogoSprite(dvdLogoTexture);
    dvdLogoSprite.setPosition(100.f, 100.f); //Pocision inicial.
    float dx = 0.009; //Velocidad.
    float dy = 0.009;

    // Bucle principal.
    while (window.isOpen()) {
        // Manejo de eventos.
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Vector2f position = dvdLogoSprite.getPosition();  // Actualizar la posición del sprite.
        position.x += dx;
        position.y += dy;
        dvdLogoSprite.setPosition(position);

        // Revisar colisión con los bordes de la ventana.
        if (position.x <= 0 || position.x + dvdLogoSprite.getLocalBounds().width >= window.getSize().x) {
            dx = -dx; // Cambiar la dirección en el eje x.

            int Aleatorio = dis(gen); //Nuevo número aletorio.
            if (!dvdLogoTexture.loadFromFile(dvdlogos[Aleatorio])) {
                std::cerr << "Failed to load DVD logo image" << std::endl;
                return 1;
            }
        }
        if (position.y <= 0 || position.y + dvdLogoSprite.getLocalBounds().height >= window.getSize().y) {
            dy = -dy; // Cambiar la dirección en el eje y

            int Aleatorio = dis(gen); //Nuevo número aletorio.
            if (!dvdLogoTexture.loadFromFile(dvdlogos[Aleatorio])) {
                std::cerr << "Failed to load DVD logo image" << std::endl;
                return 1;
            }
        }

        // Limpiar la ventana.
        window.clear();

        // Dibujar el sprite del logo de DVD.
        window.draw(dvdLogoSprite);

        // Mostrar el contenido de la ventana en pantalla.
        // Mostrar el contenido de la ventana en pantalla.
        window.display();
    }

    return 0;
}
