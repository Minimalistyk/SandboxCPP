#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
    // 1. Tworzymy okno graficzne: szerokosc=800, wysokosc=600, tytul="SandSim Test"
    sf::RenderWindow window(sf::VideoMode(800, 600), "SandSim Test");

    // 2. Tworzymy Czerwone Kolo
    sf::CircleShape circle(100.f); // Promieďż˝ 100
    circle.setFillColor(sf::Color::Red); // Ustawiamy kolor wypeďż˝nienia na czerwony
    // Ustawiamy ďż˝rodek koďż˝a w ďż˝rodku okna (800/2, 600/2)
    circle.setOrigin(100.f, 100.f);
    circle.setPosition(400.f, 300.f);

    // 3. Tworzymy Bialy Kwadrat (prostokat, ale z takimi samymi bokami)
    sf::RectangleShape square(sf::Vector2f(80.f, 80.f)); // Szerokosc i wysokosc 80x80
    square.setFillColor(sf::Color::White); // Ustawiamy kolor na bialy
    // Ustawiamy ďż˝rodek kwadratu w ďż˝rodku okna
    square.setOrigin(40.f, 40.f);
    square.setPosition(400.f, 300.f); // Nakladamy go na srodek kola

    // 4. Glowna petla gry (dziaďż˝a dopďż˝ki okno jest otwarte)
    while (window.isOpen()) {
        // Obsďż˝uga eventďż˝w (np. zamkniecie okna)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // --- RYSOWANIE ---

        // A. Czyscimy okno (np. na czarno)
        window.clear(sf::Color::Black);

        // B. Rysujemy ksztaďż˝ty w odpowiedniej kolejnosci (najpierw koďż˝o, na nim kwadrat)
        window.draw(circle);
        window.draw(square);
        window.draw(triangleLeft);
        window.draw(triangleRight);

        // C. Wyswietlamy wszystko, co narysowalismy
        window.display();
    }

    return 0;
}