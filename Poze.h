#pragma once

#include <SFML/Graphics.hpp>


class Poze {
public:
    // Constructor 
    Poze();

    // Metoda pentru încărcarea texturii și setarea sprite-ului
    void Background();  
    void Pergament();
    void Goblin();
    void Orc();
    void Troll();
    void Cufar1();
    void Cufar2();
    void Cufar3();
    void Mar();
    void Piatra();
    void Sageata();
    

    // Metoda pentru a obține sprite-ul
    sf::Sprite& getSpriteBackground();
    sf::Sprite& getSpritePergament();
    sf::Sprite& getSpriteGoblin();
    sf::Texture& gettextureGoblin();
    sf::Sprite& getSpriteOrc();
    sf::Texture& gettextureOrc();
    sf::Sprite& getSpriteTroll();
    sf::Texture& gettextureTroll();
    sf::Sprite& getSpriteCufar1();
    sf::Texture& gettextureCufar1();
    sf::Sprite& getSpriteCufar2();
    sf::Texture& gettextureCufar2();
    sf::Sprite& getSpriteCufar3();
    sf::Texture& gettextureCufar3();
    sf::Sprite& getSpriteMar();
    sf::Texture& gettextureMar();
    sf::Sprite& getSpritePiatra();
    sf::Texture& gettexturePiatra();
    sf::Sprite& getSpriteSageata();
    sf::Texture& gettextureSageata();
    

private:

    // Poza fundal
    sf::Texture texureBackground;
    sf::Sprite SpriteBackground;
    // Poza pergament
    sf::Texture texturePergament;
    sf::Sprite SpritePergament;
    //Goblin
    sf::Texture textureGoblin;
    sf::Sprite SpriteGoblin;
    //Orc
    sf::Texture textureOrc;
    sf::Sprite SpriteOrc;
    //Troll
    sf::Texture textureTroll;
    sf::Sprite SpriteTroll;
   //Cufar 1
    sf::Texture textureCufar1;
    sf::Sprite SpriteCufar1;
    //Cufar 2
    sf::Texture textureCufar2;
    sf::Sprite SpriteCufar2;
    //Cufar 3
    sf::Texture textureCufar3;
    sf::Sprite SpriteCufar3;
    // Mar
    sf::Texture textureMar;
    sf::Sprite SpriteMar;
    // Piatra
    sf::Texture texturePiatra;
    sf::Sprite SpritePiatra;
    //Sageata
    sf::Texture textureSageata;
    sf::Sprite SpriteSageata;
};



