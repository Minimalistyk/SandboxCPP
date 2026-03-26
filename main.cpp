#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
    // 1. Tworzymy okno graficzne: szerokosc=800, wysokosc=600, tytul="SandSim Test"
    sf::RenderWindow window(sf::VideoMode(800, 600), "SandSim Test");

    // 2. Tworzymy Czerwone Kolo
    sf::CircleShape circle(100.f); // Promieñ 100
    circle.setFillColor(sf::Color::Red); // Ustawiamy kolor wype³nienia na czerwony
    // Ustawiamy œrodek ko³a w œrodku okna (800/2, 600/2)
    circle.setOrigin(100.f, 100.f);
    circle.setPosition(400.f, 300.f);

    // 3. Tworzymy Bialy Kwadrat (prostokat, ale z takimi samymi bokami)
    sf::RectangleShape square(sf::Vector2f(80.f, 80.f)); // Szerokosc i wysokosc 80x80
    square.setFillColor(sf::Color::White); // Ustawiamy kolor na bialy
    // Ustawiamy œrodek kwadratu w œrodku okna
    square.setOrigin(40.f, 40.f);
    square.setPosition(400.f, 300.f); // Nakladamy go na srodek kola

    // Trójk¹t lewy
    sf::CircleShape triangleLeft(50.f, 3); // Promieñ 50, 3 wierzcho³ki
    triangleLeft.setFillColor(sf::Color::Yellow);
    triangleLeft.setOrigin(50.f, 50.f);
    triangleLeft.setPosition(200.f, 300.f); // Odsuniêty w lewo

    // Trójk¹t prawy
    sf::CircleShape triangleRight(50.f, 3);
    triangleRight.setFillColor(sf::Color::Yellow);
    triangleRight.setOrigin(50.f, 50.f);
    triangleRight.setPosition(600.f, 300.f); // Odsuniêty w prawo

    // 4. Glowna petla gry (dzia³a dopóki okno jest otwarte)
    while (window.isOpen()) {
        // Obs³uga eventów (np. zamkniecie okna)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // --- RYSOWANIE ---

        // A. Czyscimy okno (np. na czarno)
        window.clear(sf::Color::Black);

        // B. Rysujemy kszta³ty w odpowiedniej kolejnosci (najpierw ko³o, na nim kwadrat)
        window.draw(circle);
        window.draw(square);
        window.draw(triangleLeft);
        window.draw(triangleRight);

        // C. Wyswietlamy wszystko, co narysowalismy
        window.display();
    }

    return 0;
}