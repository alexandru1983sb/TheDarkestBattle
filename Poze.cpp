#include "Poze.h"
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"



// Constructor (opțional, dacă este necesar)
Poze::Poze() {
    // Inițializează orice alte membri dacă este necesar
}

// Metoda pentru încărcarea texturii și setarea sprite-ului
void Poze::Background()
{
    texureBackground.loadFromFile("images/background.png");
    if (!textureGoblin.loadFromFile("images/background.png")) {
        std::cout <<  RED << "Eroare incarcare poza background" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza background s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteBackground.setTexture(texureBackground);
}

// Metoda pentru încărcarea texturii și setarea sprite-ului
void Poze::Pergament()
{
    texturePergament.loadFromFile("images/pergament.png");
    if (!texturePergament.loadFromFile("images/pergament.png")) {
        std::cout << RED <<  "Eroare incarcare poza pergament" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza pergament s-a incarcat cu succes." << RESET << std::endl;
    }

    SpritePergament.setTexture(texturePergament);
}

// Metoda pentru încărcarea texturii și setarea sprite-ului
void Poze::Goblin() {
    textureGoblin.loadFromFile("images/goblin.png");
    if (!textureGoblin.loadFromFile("images/goblin.png")) {
        std::cout << RED << "Eroare incarcare poza goblin" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza goblin s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteGoblin.setTexture(textureGoblin);
}

// Metoda pentru încărcarea texturii și setarea sprite-ului
void Poze::Orc()
{
    textureOrc.loadFromFile("images/orc.png");
    if (!textureOrc.loadFromFile("images/orc.png")) {
        std::cout << RED << "Eroare incarcare poza orc" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza goblin s-a incarcat cu succes." << RESET <<  std::endl;
    }

    SpriteOrc.setTexture(textureOrc);
}

// Metoda pentru încărcarea texturii și setarea sprite-ului
void Poze::Troll()
{ 
    textureTroll.loadFromFile("images/troll.png");
    if (!textureTroll.loadFromFile("images/troll.png")) {
        std::cout << RED << "Eroare incarcare poza orc" << RESET << std::endl;
    }
    else {
        std::cout << GREEN <<  "Poza troll s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteTroll.setTexture(textureTroll);
}

void Poze::Cufar1()
{
    textureCufar1.loadFromFile("images/Chest.png");
    if (!textureCufar1.loadFromFile("images/Chest.png")) {
        std::cout << RED << "Eroare incarcare poza Chest" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza Chest s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteCufar1.setTexture(textureCufar1);
}

void Poze::Cufar2()
{
    textureCufar2.loadFromFile("images/Chest.png");
    if (!textureCufar2.loadFromFile("images/Chest.png")) {
        std::cout << RED << "Eroare incarcare poza Chest" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza Chest s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteCufar2.setTexture(textureCufar2);
}

void Poze::Cufar3()
{
    textureCufar3.loadFromFile("images/Chest.png");
    if (!textureCufar3.loadFromFile("images/Chest.png")) {
        std::cout << RED << "Eroare incarcare poza Chest" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza Chest s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteCufar3.setTexture(textureCufar3);
}

void Poze::Mar()
{
    textureMar.loadFromFile("images/mar.png");
    if (!textureMar.loadFromFile("images/mar.png")) {
        std::cout << RED << "Eroare incarcare poza mar" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza mar s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteMar.setTexture(textureMar);
}

void Poze::Piatra()
{
    texturePiatra.loadFromFile("images/piatra.png");
    if (!texturePiatra.loadFromFile("images/piatra.png")) {
        std::cout << RED << "Eroare incarcare poza piatra" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza piatra s-a incarcat cu succes." << RESET << std::endl;
    }

    SpritePiatra.setTexture(texturePiatra);
}

void Poze::Sageata()
{
    textureSageata.loadFromFile("images/sageata.png");
    if (!textureSageata.loadFromFile("images/sageata.png")) {
        std::cout << RED << "Eroare incarcare poza sageata" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Poza sageata s-a incarcat cu succes." << RESET << std::endl;
    }

    SpriteSageata.setTexture(textureSageata);
}



// Metoda pentru a obține sprite-ul
sf::Sprite& Poze::getSpriteBackground()
{
    return SpriteBackground;
}

sf::Sprite& Poze::getSpritePergament()
{
    return SpritePergament;
}


sf::Sprite& Poze::getSpriteGoblin() {
    return SpriteGoblin;
}

sf::Texture& Poze::gettextureGoblin()
{
    return textureGoblin;
}

sf::Sprite& Poze::getSpriteOrc()
{
    return SpriteOrc;
}

sf::Texture& Poze::gettextureOrc()
{
    return textureOrc;
}

sf::Sprite& Poze::getSpriteTroll()
{
    return SpriteTroll;
}

sf::Texture& Poze::gettextureTroll()
{
    return textureTroll;
}

sf::Sprite& Poze::getSpriteCufar1()
{
    return SpriteCufar1;
}


sf::Texture& Poze::gettextureCufar1()
{
    return textureCufar1;
}

sf::Sprite& Poze::getSpriteCufar2()
{
    return SpriteCufar2;
}

sf::Texture& Poze::gettextureCufar2()
{
    return textureCufar2;
}

sf::Sprite& Poze::getSpriteCufar3()
{
    return SpriteCufar3;
}

sf::Texture& Poze::gettextureCufar3()
{
    return textureCufar3;
}

sf::Sprite& Poze::getSpriteMar()
{
    return SpriteMar;
}

sf::Texture& Poze::gettextureMar()
{
    return textureMar;
}

sf::Sprite& Poze::getSpritePiatra()
{
    return SpritePiatra;
}

sf::Texture& Poze::gettexturePiatra()
{
    return texturePiatra;
}

sf::Sprite& Poze::getSpriteSageata()
{
    return SpriteSageata;
}

sf::Texture& Poze::gettextureSageata()
{
    return textureSageata;
}


