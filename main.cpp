#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include "Poze.h"
#include "Sound.h"
#include "Texte.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"


int main() {
    sf::RenderWindow DisplayGame(sf::VideoMode(800, 800), "The Darkest Battle");
   
    int DerulatorSunet = 0; // De modificat in 0 Am ramas la 8
    int DerulatorJoc = 0; // De modificat in 0 Am ramas la 10
    int TimpPrezentareText = 55; // De setat viteza de 55
    int TimpDeplasarePersonaje = 10;
    int PowerJucator = 10;
    int PowerComputer = 10;
    bool cursorPeTextNext = false;
    bool butonClicat = false; // Indicator pentru clic
    int goblinx = 300, gobliny = 600, orcx = 300, orcy = 600, trollx = 300, trolly = 600;
    int goblintextx = 350, goblintexty = 265, orctextx = 350, orctexty = 265, trolltextx = 350, trolltexty = 265;
    //Mutarea personajelor
    sf::Clock clock;
    float totalTime = 3.f; // Timpul total (3 secunde)
    float elapsedTime = 0.f;
    // Alegem personajele Random
    int secret_box1 = 0, secret_box2 = 0, secret_box3 = 0, PlayerAlegere = 0, CalculatorAlege = 0;
    // Cine incepe jocul
    int startGame = 0;
    // Variabila pentru a stoca numele introdus
    std::string inputName;
    // Sunet castigator
    int Winner = 0;

    int weapon1 = 0, weapon2 = 0, weapon3 = 0, Jucator = 10, ComputerPC = 10;

    sf::Font Font4Text;
    Font4Text.loadFromFile("GreatVibes-Regular.ttf");
    if (!Font4Text.loadFromFile("GreatVibes-Regular.ttf"))
    {
        std::cout << RED << "Eroare incarcare GreatVibes-Regular" << RESET << std::endl;
    }
    else {
        std::cout << GREEN << "Font-ul GreatVibes-Regular s-a incarcat cu succes." << RESET << std::endl;
    }

    // Creează o instanță a clasei Poze
    Poze poze;
    // Apelează metoda pentru a încărca textura și seta sprite-ul
    poze.Background();
    poze.Pergament();
    poze.Goblin();
    poze.Orc();
    poze.Troll();
    poze.Cufar1();
    poze.Cufar2();
    poze.Cufar3();
    poze.Mar();
    poze.Piatra();
    poze.Sageata();

    // Accesează sprite-ul folosind metoda publică 
    sf::Sprite& spriteBackground = poze.getSpriteBackground();
    sf::Sprite& spritePergament = poze.getSpritePergament();
    sf::Sprite& spriteGoblin = poze.getSpriteGoblin();
    sf::Texture& textureGoblin = poze.gettextureGoblin();
    sf::Sprite& spriteOrc = poze.getSpriteOrc();
    sf::Texture& textureOrc = poze.gettextureOrc();
    sf::Sprite& spriteTroll = poze.getSpriteTroll();
    sf::Texture& textureTroll = poze.gettextureTroll();
    sf::Sprite& spriteCufar1 = poze.getSpriteCufar1();
    sf::Texture& textureCufar1 = poze.gettextureCufar1();
    sf::Sprite& spriteCufar2 = poze.getSpriteCufar2();
    sf::Texture& textureCufar2 = poze.gettextureCufar2();
    sf::Sprite& spriteCufar3 = poze.getSpriteCufar3();
    sf::Texture& textureCufar3 = poze.gettextureCufar3();
    sf::Sprite& spriteMar = poze.getSpriteMar();
    sf::Texture& textureMar = poze.gettextureMar();
    sf::Sprite& spritePiatra = poze.getSpritePiatra();
    sf::Texture& texturePiatra = poze.gettexturePiatra();
    sf::Sprite& spriteSageata = poze.getSpriteSageata();
    sf::Texture& textureSageata = poze.gettextureSageata();

    // Creează o instanță a clasei Sound
    Sound sound;
   
    // Creează o instanță a clasei Texte
    Texte texte;
    //Apelam o metoda
    texte.Text_GameName();
    texte.Text_Goblin();
    texte.Text_Goblin_Name();
    texte.Text_Orc();
    texte.Text_Orc_Name();
    texte.Text_Troll();
    texte.Text_Troll_Name();
    texte.Text_Play();
    texte.Text_Exit();
    texte.Text_Next();
    texte.Text_AlegeCutia();
    texte.Text_playerNameLabel();
    texte.Text_NumeJucator();
    texte.Text_Castigator();

    // Accesează Text folosind metoda publică 
    sf::Text& NumeJoc = texte.getNumeJoc();
    sf::Text& GoblinText = texte.getGoblinText();
    sf::Text& GoblinName = texte.getGoblinName();
    sf::Text& OrcText = texte.getOrcText();
    sf::Text& OrcName = texte.getOrcName();
    sf::Text& TrollText = texte.getTrollText();
    sf::Text& TrollName = texte.getTrollName();
    sf::Text& PlayText = texte.getTextPlay();
    sf::Text& ExitText = texte.getTextExit();
    sf::Text& TextNext = texte.getNext();
    sf::Text& AlegeCutia = texte.getAlegeCutia();
    sf::Text& playerNameLabel = texte.getplayerNameLabel();
    sf::Text& NumeJucator = texte.getNumeJucator();
    sf::Text& Castigator = texte.getCastigator();

    // Titlul Jocului
    NumeJoc.setCharacterSize(65);
    NumeJoc.setPosition(170, 50);
    NumeJoc.setFillColor(sf::Color::White);
    NumeJoc.setFont(Font4Text);

    // Goblin Prezentare 
    GoblinText.setCharacterSize(28);
    GoblinText.setPosition(110, 315);
    GoblinText.setFillColor(sf::Color::White);
    GoblinText.setFont(Font4Text);
    //Goblin Nume
    GoblinName.setCharacterSize(38);
    GoblinName.setPosition(350, 265);
    GoblinName.setFillColor(sf::Color::White);
    GoblinName.setFont(Font4Text);
    //Goblin Poza
    sf::Vector2f targetSizeGoblin(200.0f, 200.0f);
    float scaleGoblinX, scaleGoblinY;
    scaleGoblinX = targetSizeGoblin.x / textureGoblin.getSize().x;
    scaleGoblinY = targetSizeGoblin.y / textureGoblin.getSize().y;
    spriteGoblin.setScale(scaleGoblinX, scaleGoblinY);
    spriteGoblin.setPosition(300, 600);

    // Cufar 1
    sf::Vector2f targetSizeCufar1(80.0f, 80.0f);
    float scaleCufar1X, scaleCufar1Y;
    scaleCufar1X = targetSizeCufar1.x / textureCufar1.getSize().x;
    scaleCufar1Y = targetSizeCufar1.y / textureCufar1.getSize().y;
    spriteCufar1.setScale(scaleCufar1X, scaleCufar1Y);
    spriteCufar1.setPosition(160, 450);
    // Cufar 2
    sf::Vector2f targetSizeCufar2(80.0f, 80.0f);
    float scaleCufar2X, scaleCufar2Y;
    scaleCufar2X = targetSizeCufar2.x / textureCufar2.getSize().x;
    scaleCufar2Y = targetSizeCufar2.y / textureCufar2.getSize().y;
    spriteCufar2.setScale(scaleCufar2X, scaleCufar2Y);
    spriteCufar2.setPosition(350, 450);
    // Cufar 3
    sf::Vector2f targetSizeCufar3(80.0f, 80.0f);
    float scaleCufar3X, scaleCufar3Y;
    scaleCufar3X = targetSizeCufar3.x / textureCufar3.getSize().x;
    scaleCufar3Y = targetSizeCufar3.y / textureCufar3.getSize().y;
    spriteCufar3.setScale(scaleCufar3X, scaleCufar3Y);
    spriteCufar3.setPosition(540, 450);

    //Orc Prezentare
    OrcText.setCharacterSize(28);
    OrcText.setPosition(110, 315);
    OrcText.setFillColor(sf::Color::White);
    OrcText.setFont(Font4Text);
    //Orc Nume
    OrcName.setCharacterSize(38);
    OrcName.setPosition(350, 265);
    OrcName.setFillColor(sf::Color::White);
    OrcName.setFont(Font4Text);
    //orc Poza
    sf::Vector2f targetSizeOrc(200.0f, 200.0f);
    float scaleOrcX, scaleOrcY;
    scaleOrcX = targetSizeOrc.x / textureOrc.getSize().x;
    scaleOrcY = targetSizeOrc.y / textureOrc.getSize().y;
    spriteOrc.setScale(scaleOrcX, scaleOrcY);
    spriteOrc.setPosition(300, 600);

    // Troll Prezentare 
    TrollText.setCharacterSize(28);
    TrollText.setPosition(110, 315);
    TrollText.setFillColor(sf::Color::White);
    TrollText.setFont(Font4Text);
    //Troll Nume
    TrollName.setCharacterSize(38);
    TrollName.setPosition(350, 265);
    TrollName.setFillColor(sf::Color::White);
    TrollName.setFont(Font4Text);
    //Troll Poza
    sf::Vector2f targetSizeTroll(200.0f, 200.0f);
    float scaleTrollX, scaleTrollY;
    scaleTrollX = targetSizeTroll.x / textureTroll.getSize().x;
    scaleTrollY = targetSizeTroll.y / textureTroll.getSize().y;
    spriteTroll.setScale(scaleTrollX, scaleTrollY);
    spriteTroll.setPosition(300, 600);

    // Mar
    sf::Vector2f targetSizeMar(80.0f, 80.0f);
    float scaleMarX, scaleMarY;
    scaleMarX = targetSizeMar.x / textureMar.getSize().x;
    scaleMarY = targetSizeMar.y / textureMar.getSize().y;
    spriteMar.setScale(scaleMarX, scaleMarY);
    spriteMar.setPosition(140, 650);

    // Piatra
    sf::Vector2f targetSizePiatra(80.0f, 80.0f);
    float scalePiatraX, scalePiatraY;
    scalePiatraX = targetSizePiatra.x / texturePiatra.getSize().x;
    scalePiatraY = targetSizePiatra.y / texturePiatra.getSize().y;
    spritePiatra.setScale(scalePiatraX, scalePiatraY);
    spritePiatra.setPosition(140, 650);

    // Sageata
    sf::Vector2f targetSizeSageata(80.0f, 80.0f);
    float scaleSageataX, scaleSageataY;
    scaleSageataX = targetSizePiatra.x / textureSageata.getSize().x;
    scaleSageataY = targetSizePiatra.y / textureSageata.getSize().y;
    spriteSageata.setScale(scaleSageataX, scaleSageataY);
    spriteSageata.setPosition(140, 650);

    //Display Play
    PlayText.setCharacterSize(35);
    PlayText.setPosition(180, 350);
    PlayText.setFillColor(sf::Color::White);
    PlayText.setFont(Font4Text);

    //Display Exit
    ExitText.setCharacterSize(35);
    ExitText.setPosition(540, 350);
    ExitText.setFillColor(sf::Color::White);
    ExitText.setFont(Font4Text);

    //Next button
    TextNext.setCharacterSize(35);
    TextNext.setPosition(600, 700);
    TextNext.setFillColor(sf::Color::Black);
    TextNext.setFont(Font4Text);

    //Alege Cutia
    AlegeCutia.setCharacterSize(30);
    AlegeCutia.setPosition(110, 290);
    AlegeCutia.setFillColor(sf::Color::White);
    AlegeCutia.setFont(Font4Text);

    // playerNameLabel
    playerNameLabel.setCharacterSize(45);
    playerNameLabel.setPosition(280, 350);
    playerNameLabel.setFillColor(sf::Color::White);
    playerNameLabel.setFont(Font4Text);
    //Player Name
    NumeJucator.setCharacterSize(45);
    NumeJucator.setPosition(280, 450);
    NumeJucator.setFillColor(sf::Color::White);
    NumeJucator.setFont(Font4Text);
   
    sf::Text jucator;
    jucator.setFont(Font4Text);
    jucator.setString(std::to_string(PowerJucator));
    jucator.setCharacterSize(24);
    jucator.setPosition(160, 740);

    sf::Text pc;
    pc.setFont(Font4Text);
    pc.setString(std::to_string(PowerComputer));
    pc.setCharacterSize(24);
    pc.setPosition(570, 740);

    Castigator.setFont(Font4Text);
    Castigator.setCharacterSize(36);
    Castigator.setPosition(300, 300);

    sf::Text Computer;
    Computer.setString("Computer");
    Computer.setFillColor(sf::Color::White);
    Computer.setCharacterSize(30);
    Computer.setFont(Font4Text);
    Computer.setPosition(550, 290);

    spritePergament.setPosition(0, 40);

    while (DisplayGame.isOpen()) {
        sf::Event event;
        // Obține poziția cursorului mouse-ului în coordonate locale

        while (DisplayGame.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                // Apel destructor. Trebuie sa il declar :-)
                DisplayGame.close();
        }

        DisplayGame.clear();
        DisplayGame.draw(spriteBackground);
        DisplayGame.draw(spritePergament);
        DisplayGame.draw(NumeJoc);
        // DisplayGame.display();

         // Verificăm poziția cursorului
        sf::Vector2i mousePos = sf::Mouse::getPosition(DisplayGame);
        if (mousePos.x >= 600 && mousePos.y >= 700) {
            // Cursorul se află pe TextNext
            TextNext.setFillColor(sf::Color::Red); // Schimbăm culoarea la roșu
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // Incrementare DerulatorNext la fiecare clic

                if (!butonClicat) {
                    // Incrementare DerulatorNext doar o dată
                    DerulatorJoc++;
                    butonClicat = true;
                }
            }
        }
        else {
            // Cursorul nu se află pe TextNext
            TextNext.setFillColor(sf::Color::Green); // Revenim la culoarea verde
            butonClicat = false;
        }

        // Prezentare Goblin
        if (DerulatorJoc == 0) {
            //Conversie de la sf::Text la std::string
            
            std::string GoblinString = GoblinText.getString().toAnsiString();
            if (DerulatorJoc == 0) {
                if (DerulatorSunet == 0 && DerulatorJoc == 0) {
                    sound.Sound_Goblin();
                    sf::Sound& SoundGoblin = sound.getSoundGoblin();
                    DerulatorSunet = DerulatorSunet + 1;
                }
                for (size_t i = 0; i < GoblinString.size(); ++i) {
                    DisplayGame.clear();
                    // Afișează doar primele i caractere
                    GoblinText.setString(GoblinString.substr(0, i + 1));
                    DisplayGame.draw(spriteBackground);
                    DisplayGame.draw(spritePergament);
                    DisplayGame.draw(NumeJoc);
                    DisplayGame.draw(GoblinName);
                    DisplayGame.draw(GoblinText);
                    DisplayGame.display(); // Actualizează fereastra
                    sf::sleep(sf::milliseconds(TimpPrezentareText)); 
                }
                DerulatorJoc = 1;
            }
        }
        else if (DerulatorJoc == 1) {
            // std::cout << DerulatorJoc << std::endl;
            DisplayGame.draw(NumeJoc);
            DisplayGame.draw(GoblinName);
            DisplayGame.draw(GoblinText);
            DisplayGame.draw(spriteGoblin);
            DisplayGame.draw(TextNext);
            DisplayGame.display();
            if (DerulatorSunet == 1 && DerulatorJoc == 1) {
                sound.Sound_GoblinVoice();
                sf::Sound& SoundGoblinVoice = sound.getSoundGoblinVoice();
                DerulatorSunet = DerulatorSunet + 1;
            }
            
        }

        //Prezentare Orc
        if (DerulatorJoc == 2) {
            //Conversie de la sf::Text la std::string
            std::string orcString = OrcText.getString().toAnsiString();
            if (DerulatorJoc == 2) {
                //Apelam Sunetul
                if (DerulatorSunet == 2 && DerulatorJoc == 2) {
                    sound.Sound_Orc();
                    sf::Sound& SoundOrc = sound.getSoundOrc();
                    DerulatorSunet = DerulatorSunet + 1;
                }
                //  std::cout << DerulatorJoc << std::endl;
                for (size_t x = 0; x < orcString.size(); ++x) {
                    DisplayGame.clear();
                    // Afișează doar primele i caractere
                    OrcText.setString(orcString.substr(0, x + 1));
                    DisplayGame.draw(spriteBackground);
                    DisplayGame.draw(spritePergament);
                    DisplayGame.draw(NumeJoc);
                    DisplayGame.draw(OrcName);
                    DisplayGame.draw(OrcText);
                    DisplayGame.display(); // Actualizează fereastra
                    sf::sleep(sf::milliseconds(TimpPrezentareText)); 
                }
                DerulatorJoc = 3;
            }

        }
        else  if (DerulatorJoc == 3) {
            DisplayGame.draw(spritePergament);
            DisplayGame.draw(NumeJoc);
            DisplayGame.draw(OrcName);
            DisplayGame.draw(OrcText);
            DisplayGame.draw(spriteOrc);
            DisplayGame.draw(TextNext);
            DisplayGame.display();
            sf::sleep(sf::milliseconds(100)); // Așteaptă 100 ms între caractere
            if (DerulatorSunet == 3 && DerulatorJoc == 3) {
                sound.Sound_OrcVoice();
                sf::Sound& SoundOrcVoice = sound.getSoundOrcVoice();
                DerulatorSunet = DerulatorSunet + 1;
            }

        }

        //Prezentare Troll
        if (DerulatorJoc == 4) {
            //Conversie de la sf::Text la std::string
            std::string TrollString = TrollText.getString().toAnsiString();
            if (DerulatorJoc == 4) {
                //  std::cout << DerulatorJoc << std::endl;
                if (DerulatorSunet == 4 && DerulatorJoc == 4) {
                    sound.Sound_Troll();
                    sf::Sound& SoundOrc = sound.getSoundTroll();
                    DerulatorSunet = DerulatorSunet + 1;
                }
                for (size_t i = 0; i < TrollString.size(); ++i) {
                    DisplayGame.clear();
                    // Afișează doar primele i caractere
                    TrollText.setString(TrollString.substr(0, i + 1));
                    DisplayGame.draw(spriteBackground);
                    DisplayGame.draw(spritePergament);
                    DisplayGame.draw(NumeJoc);
                    DisplayGame.draw(TrollName);
                    DisplayGame.draw(TrollText);
                    DisplayGame.display(); // Actualizează fereastra
                    sf::sleep(sf::milliseconds(TimpPrezentareText)); 
                }
                DerulatorJoc = 5;
            }
        }
        else  if (DerulatorJoc == 5) {
            DisplayGame.draw(spritePergament);
            DisplayGame.draw(NumeJoc);
            DisplayGame.draw(TrollName);
            DisplayGame.draw(TrollText);
            DisplayGame.draw(spriteTroll);
            DisplayGame.draw(TextNext);
            DisplayGame.display();
            if (DerulatorSunet == 5 && DerulatorJoc == 5) {
                sound.Sound_TrollVoice();
                sf::Sound& SoundTrollVoice = sound.getSoundTrollVoice();
                DerulatorSunet = DerulatorSunet + 1;
            }
        }

        if (DerulatorJoc == 6) {
            DisplayGame.draw(TextNext);
            DisplayGame.display();

        }
        if (DerulatorJoc == 6) {
            DisplayGame.clear();
            DisplayGame.draw(spritePergament);
            DisplayGame.draw(NumeJoc);
            DisplayGame.draw(spriteGoblin);
            DisplayGame.display();
            DerulatorJoc = 7;

            if (DerulatorSunet == 6 && DerulatorJoc == 7) {
                sound.Sound_Menu();
                sf::Sound& SoundMenu = sound.getSoundMenu();
                DerulatorSunet = DerulatorSunet + 1;
            }

            // Goblin
            if (DerulatorJoc == 7) {
                DisplayGame.draw(spritePergament);
                DisplayGame.draw(NumeJoc);
                spriteGoblin.setPosition(goblinx, gobliny);
                DisplayGame.draw(spriteGoblin);

                for (int i = 0; i < 3; i++) {
                    if (i == 0) {
                        //Goblin deplasare X, Y si Text
                        //Goblin deplasare pe x
                        for (int i = 0; i < 20; i++) {
                            goblinx = goblinx - i;
                            spriteGoblin.setPosition(goblinx, gobliny);
                            std::this_thread::sleep_for(std::chrono::milliseconds(TimpDeplasarePersonaje));
                            DisplayGame.clear();
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            DisplayGame.draw(spriteGoblin);
                            DisplayGame.display();
                        }
                        //Goblin deplasare y
                        for (int i = 0; i < 25; i++) {
                            gobliny = gobliny - i;
                            spriteGoblin.setPosition(goblinx, gobliny);
                            std::this_thread::sleep_for(std::chrono::milliseconds(TimpDeplasarePersonaje));
                            DisplayGame.clear();
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            DisplayGame.draw(GoblinName);
                            DisplayGame.draw(spriteGoblin);
                            DisplayGame.display();
                        }
                        // Goblin Text
                        for (int i = 0; i < 20; i++) {
                            goblintextx = goblintextx - i;
                            GoblinName.setPosition(goblintextx, goblintexty);
                            std::this_thread::sleep_for(std::chrono::milliseconds(TimpDeplasarePersonaje));
                            DisplayGame.clear();
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            DisplayGame.draw(GoblinName);
                            DisplayGame.draw(spriteGoblin);
                            DisplayGame.display();
                        }
                    }

                    // Troll deplasare X, Y si text
                    if (i == 1) {
                        //Troll deplasare pe x
                        for (int i = 0; i < 20; i++) {
                            trollx = trollx + i;
                            spriteTroll.setPosition(trollx, trolly);
                            std::this_thread::sleep_for(std::chrono::milliseconds(TimpDeplasarePersonaje));
                            DisplayGame.clear();
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            GoblinName.setPosition(goblintextx, goblintexty);
                            DisplayGame.draw(GoblinName);
                            spriteGoblin.setPosition(goblinx, gobliny);
                            DisplayGame.draw(spriteGoblin);
                            DisplayGame.draw(spriteTroll);
                            DisplayGame.display();
                        }
                        //Troll deplasare y
                        for (int i = 0; i < 25; i++) {
                            trolly = trolly - i;
                            spriteTroll.setPosition(trollx, trolly);
                            std::this_thread::sleep_for(std::chrono::milliseconds(TimpDeplasarePersonaje));
                            DisplayGame.clear();
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            GoblinName.setPosition(goblintextx, goblintexty);
                            DisplayGame.draw(GoblinName);
                            spriteGoblin.setPosition(goblinx, gobliny);
                            DisplayGame.draw(spriteGoblin);
                            DisplayGame.draw(TrollName);
                            DisplayGame.draw(spriteTroll);
                            DisplayGame.display();
                        }
                        // Troll Text
                        for (int i = 0; i < 18; i++) {
                            trolltextx = trolltextx + i;
                            TrollName.setPosition(trolltextx, trolltexty);
                            std::this_thread::sleep_for(std::chrono::milliseconds(TimpDeplasarePersonaje));
                            DisplayGame.clear();
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            GoblinName.setPosition(goblintextx, goblintexty);
                            DisplayGame.draw(GoblinName);
                            spriteGoblin.setPosition(goblinx, gobliny);
                            DisplayGame.draw(spriteGoblin);
                            DisplayGame.draw(TrollName);
                            DisplayGame.draw(spriteTroll);
                            DisplayGame.display();
                        }
                    }

                    //Orc deplasare Y si text
                    if (i == 2) {

                        for (int i = 0; i < 25; i++) {
                            orcy = orcy - i;
                            spriteOrc.setPosition(orcx, orcy);
                            std::this_thread::sleep_for(std::chrono::milliseconds(TimpDeplasarePersonaje));
                            DisplayGame.clear();
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            //Goblin
                            GoblinName.setPosition(goblintextx, goblintexty);
                            DisplayGame.draw(GoblinName);
                            spriteGoblin.setPosition(goblinx, gobliny);
                            DisplayGame.draw(spriteGoblin);
                            //Troll
                            TrollName.setPosition(trolltextx, trolltexty);
                            DisplayGame.draw(TrollName);
                            spriteTroll.setPosition(trollx, trolly);
                            DisplayGame.draw(spriteTroll);
                            //Orc
                            DisplayGame.draw(spriteOrc);
                            DisplayGame.display();
                        }
                        // Orc Text
                        DisplayGame.draw(OrcName);
                        DisplayGame.display();
                        DerulatorJoc = 8;

                    }

                }

            }

        }

        if (DerulatorJoc == 8) {

            //Goblin
            GoblinName.setPosition(goblintextx, goblintexty);
            DisplayGame.draw(GoblinName);
            spriteGoblin.setPosition(goblinx, gobliny);
            DisplayGame.draw(spriteGoblin);
            //Troll
            TrollName.setPosition(trolltextx, trolltexty);
            DisplayGame.draw(TrollName);
            spriteTroll.setPosition(trollx, trolly);
            DisplayGame.draw(spriteTroll);

            //Orc
            OrcName.setPosition(orctextx, orctexty);
            DisplayGame.draw(OrcName);
            spriteTroll.setPosition(orcx, orcy);
            DisplayGame.draw(spriteOrc);
            DisplayGame.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            DerulatorJoc = 9;
        }

        if (DerulatorJoc == 9) {

            // Verificăm poziția cursorului
            sf::Vector2i mousePoss = sf::Mouse::getPosition(DisplayGame);

            // Cursorul se află pe TextPlay
            if (mousePoss.x >= 180 && mousePoss.x <= 245 && mousePoss.y >= 355 && mousePoss.y <= 385 && DerulatorJoc == 9) {

                PlayText.setFillColor(sf::Color::Red); // Schimbăm culoarea la roșu
                DisplayGame.draw(PlayText);
                //std::cout << "Sunt in Start" << std::endl;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    // Incrementare DerulatorNext la fiecare clic

                    if (!butonClicat) {
                        // Incrementare DerulatorNext doar o dată
                        DerulatorJoc = 10;
                        butonClicat = true;
                    }
                }
            }
            else {
                PlayText.setFillColor(sf::Color::Green); // Schimbăm culoarea la verde 
                DisplayGame.draw(PlayText);
                butonClicat = false;
            }

            if (mousePoss.x >= 540 && mousePoss.x <= 600 && mousePoss.y >= 355 && mousePoss.y <= 385 && DerulatorJoc == 9) {

                ExitText.setFillColor(sf::Color::Red); // Schimbăm culoarea la roșu
                DisplayGame.draw(ExitText);
                //std::cout << "Exit" << std::endl;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    // Incrementare DerulatorNext la fiecare clic

                    if (!butonClicat) {
                        // Incrementare DerulatorNext doar o dată
                        DerulatorJoc = 12;
                        butonClicat = true;
                    }
                }
            }
            else {
                ExitText.setFillColor(sf::Color::Green); // Schimbăm culoarea la verde 
                DisplayGame.draw(ExitText);
                butonClicat = false;
            }

            DisplayGame.display();
        }

        if (DerulatorJoc == 12) {
            DisplayGame.close();
        }

        //Apelam Sunetul
        if (DerulatorSunet == 7 && DerulatorJoc == 10) {
            sound.Sound_Laugh();
            sf::Sound& SoundLough = sound.getSoundLaugh();
            SoundLough.play();
            DerulatorSunet = DerulatorSunet + 1;
        }

        if (DerulatorJoc == 10) {
           
            // Verificăm poziția cursorului
            sf::Vector2i mousePossCufar1 = sf::Mouse::getPosition(DisplayGame);
            //std::cout << "x " << mousePossCufar1.x << std::endl;
            //std::cout << "y " << mousePossCufar1.y << std::endl;
            // Cursorul se află pe TextPlay
            if (mousePossCufar1.x >= 164 && mousePossCufar1.x <= 251 && mousePossCufar1.y >= 460 && mousePossCufar1.y <= 523 && DerulatorJoc == 10) {

                // std::cout << "Sunt in Cufar1" << std::endl;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    // Incrementare DerulatorNext la fiecare clic

                    if (!butonClicat) {
                        PlayerAlegere = 1;
                        DerulatorJoc = 13;
                        butonClicat = true;
                    }
                }
            }
            else {
                butonClicat = false;
            }
            //Cufar 2
            sf::Vector2i mousePossCufar2 = sf::Mouse::getPosition(DisplayGame);
            if (mousePossCufar1.x >= 353 && mousePossCufar1.x <= 440 && mousePossCufar1.y >= 460 && mousePossCufar1.y <= 523 && DerulatorJoc == 10) {

                // std::cout << "Sunt in Cufar2" << std::endl;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    // Incrementare DerulatorNext la fiecare clic

                    if (!butonClicat) {
                        PlayerAlegere = 2;
                        DerulatorJoc = 13;
                        butonClicat = true;
                    }
                }
            }
            else {
                butonClicat = false;
            }

            //Cufar 3
            sf::Vector2i mousePossCufar3 = sf::Mouse::getPosition(DisplayGame);
            if (mousePossCufar1.x >= 546 && mousePossCufar1.x <= 633 && mousePossCufar1.y >= 460 && mousePossCufar1.y <= 523 && DerulatorJoc == 10) {

                //  std::cout << "Sunt in Cufar3" << std::endl;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    // Incrementare DerulatorNext la fiecare clic

                    if (!butonClicat) {
                        PlayerAlegere = 3;
                        DerulatorJoc = 13;
                        butonClicat = true;
                    }
                }
            }
            else {
                butonClicat = false;
            }

            if (DerulatorSunet == 8 && DerulatorJoc == 10) {
                sound.Sound_chooseTheBox();
                sf::Sound& SoundChooseThebox = sound.getSoundChooseTheBox();
                SoundChooseThebox.play();
                DerulatorSunet = DerulatorSunet + 1;

                if (DerulatorJoc == 10) {
                    std::string Alegecutia = AlegeCutia.getString().toAnsiString();
                    for (size_t i = 0; i < Alegecutia.size(); ++i) {
                        DisplayGame.clear();
                        // Afișează doar primele i caractere
                        AlegeCutia.setString(Alegecutia.substr(0, i + 1));
                        DisplayGame.draw(spriteBackground);
                        DisplayGame.draw(spritePergament);
                        DisplayGame.draw(NumeJoc);
                        DisplayGame.draw(AlegeCutia);
                        DisplayGame.display(); // Actualizează fereastra
                        sf::sleep(sf::milliseconds(TimpPrezentareText));
                    }
                    
                }
                
            }

            DisplayGame.draw(AlegeCutia);
            DisplayGame.draw(spriteCufar1);
            DisplayGame.draw(spriteCufar2);
            DisplayGame.draw(spriteCufar3);
            DisplayGame.display();

        }

        if (PlayerAlegere >= 1 && DerulatorJoc == 13) {
            DisplayGame.clear();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !inputName.empty()) {
                    // Dacă a fost apăsată tasta Backspace și avem caractere în inputName, ștergem ultimul caracter
                    inputName.pop_back();
                }

                else if (event.text.unicode < 128) {
                    // Dacă a fost introdus un caracter ASCII, îl adăugăm la inputName
                    inputName += static_cast<char>(event.text.unicode);
                    sf::sleep(sf::milliseconds(180)); // Așteaptă 100 ms între caractere
                }
                NumeJucator.setString(inputName);

            }

            DisplayGame.draw(spritePergament);
            DisplayGame.draw(playerNameLabel);
            DisplayGame.draw(NumeJucator);
            DisplayGame.draw(NumeJoc);
            DisplayGame.draw(TextNext);
            DisplayGame.display();
        }

        
        if (DerulatorJoc == 14) {
            // Alocam numerele random
            sf::Text NumeCutie1, NumeCutie2, NumeCutie3;
            
            // Declară pointerul în afara blocurilor if
            sf::Text* Numecutie1 = nullptr;
            sf::Text* Numecutie2 = nullptr;
            sf::Text* Numecutie3 = nullptr;

            Numecutie1 = &NumeCutie1;
            Numecutie2 = &NumeCutie2;
            Numecutie3 = &NumeCutie3;

            while (!secret_box1 || !secret_box2 || !secret_box3 || !CalculatorAlege )
            {
                std::random_device device;
                std::uniform_int_distribution <int> distributie_nr(1, 3);
                if (secret_box1 == 0) {
                    secret_box1 = distributie_nr(device);
                    weapon1 = distributie_nr(device);
                    std::cout << "secret_box1 : " << secret_box1 << std::endl;
                    std::cout << "weapon1 : " << weapon1 << std::endl;   
                }
                if (secret_box2 == 0) {
                    secret_box2 = distributie_nr(device);
                    weapon2 = distributie_nr(device);
                    std::cout << "secret_box2 : " << secret_box2 << std::endl;
                    std::cout << "weapon2 : " << weapon2 << std::endl;  
                }
                if (secret_box3 == 0) {
                    secret_box3 = distributie_nr(device);
                    weapon3 = distributie_nr(device);
                    std::cout << "secret_box3 : " << secret_box3 << std::endl;
                    std::cout << "weapon3 : " << weapon3 << std::endl; 
                }
                if (CalculatorAlege == 0) {
                    CalculatorAlege = distributie_nr(device);
                    std::cout << "Calculatorul a ales : " << CalculatorAlege << std::endl;
                    std::cout << "Player a ales : " << PlayerAlegere << std::endl;  
                }
            }

            if (PlayerAlegere == 1) {
                spriteGoblin.setPosition(110, 340);
                spriteOrc.setPosition(110, 340);
                spriteTroll.setPosition(110, 340);
               
                switch (secret_box1)
                {
                case 1: if (secret_box1 == 1) {
                    DisplayGame.draw(spriteGoblin);
                    DisplayGame.draw(spriteMar);
                    PlayerAlegere = 1;
                } break;
                case 2: if (secret_box1 == 2) {
                    DisplayGame.draw(spriteOrc); 
                    DisplayGame.draw(spritePiatra);
                    PlayerAlegere = 2;
                }break;
                case 3: if (secret_box1 == 3) {
                    DisplayGame.draw(spriteTroll);
                    DisplayGame.draw(spriteSageata);
                    PlayerAlegere = 3;
                }break;
                default:
                    break;
                }     
            }

            else if (PlayerAlegere == 2) {
                spriteGoblin.setPosition(110, 340);
                spriteOrc.setPosition(110, 340);
                spriteTroll.setPosition(110, 340);

                switch (secret_box2)
                {
                case 1: if (secret_box2 == 1) {
                    DisplayGame.draw(spriteGoblin);
                    DisplayGame.draw(spriteMar);
                    PlayerAlegere = 1;
                } break;
                case 2: if (secret_box2 == 2) {
                    DisplayGame.draw(spriteOrc);
                    DisplayGame.draw(spritePiatra);
                    PlayerAlegere = 2;
                }break;
                case 3: if (secret_box2 == 3) {
                    DisplayGame.draw(spriteTroll);
                    DisplayGame.draw(spriteSageata);
                    PlayerAlegere = 3;
                }break;
                default:
                    break;
                }
            }

            else if (PlayerAlegere == 3) {
                spriteGoblin.setPosition(110, 340);
                spriteOrc.setPosition(110, 340);
                spriteTroll.setPosition(110, 340);

                switch (secret_box3)
                {
                case 1: if (secret_box3 == 1) {
                    DisplayGame.draw(spriteGoblin);
                    DisplayGame.draw(spriteMar);
                    PlayerAlegere = 1;
                } break;
                case 2: if (secret_box3 == 2) {
                    DisplayGame.draw(spriteOrc);
                    DisplayGame.draw(spritePiatra);
                    PlayerAlegere = 2;
                }break;
                case 3: if (secret_box3 == 3) {
                    DisplayGame.draw(spriteTroll);
                    DisplayGame.draw(spriteSageata);
                    PlayerAlegere = 3;
                }break;
                default:
                    break;
                }
            }


            if (CalculatorAlege) {
                spriteGoblin.setPosition(510, 340);
                spriteOrc.setPosition(510, 340);
                spriteTroll.setPosition(510, 340);

                if (CalculatorAlege == 1) {
                    DisplayGame.draw(spriteGoblin);
                    spriteMar.setPosition(550, 650);
                    DisplayGame.draw(spriteMar);
                }
                else if (CalculatorAlege == 2) {
                    DisplayGame.draw(spriteOrc);
                    spritePiatra.setPosition(550, 650);
                    DisplayGame.draw(spritePiatra);
                }
                else if (CalculatorAlege == 3) {
                    DisplayGame.draw(spriteTroll);
                    spriteSageata.setPosition(550, 650);
                    DisplayGame.draw(spriteSageata);
                }

            }
        
            NumeJucator.setCharacterSize(30);
            NumeJucator.setFillColor(sf::Color::White);
            NumeJucator.setFont(Font4Text);
            NumeJucator.setPosition(170, 285);
            DisplayGame.draw(NumeJucator);
            DisplayGame.draw(Computer);
            DisplayGame.draw(jucator);
            DisplayGame.draw(pc);
            DisplayGame.display();
            DerulatorJoc = 15;

            //Prezentare Voce Mar
            if (DerulatorSunet == 9) {
                DisplayGame.draw(spriteMar);
                sound.Sound_Mar();
                sf::Sound& SoundMar = sound.getSoundMar();
                SoundMar.play();
                DerulatorSunet = DerulatorSunet + 1;
            }
            //Prezentare Voce Piatra
            if (DerulatorSunet == 10) {
                sf::sleep(sf::milliseconds(9000));
                DerulatorSunet = DerulatorSunet + 1;
                sound.Sound_Piatra();
                sf::Sound& SoundPiatra = sound.getSoundPiatra();
                SoundPiatra.play();
            }
            //Prezentare Voce Arc
            if (DerulatorSunet == 11) {
                sf::sleep(sf::milliseconds(9000));
                DerulatorSunet = DerulatorSunet + 1;
                sound.Sound_Arc();
                sf::Sound& SoundArc = sound.getSoundArc();
                SoundArc.play();
            }
   
            if (DerulatorJoc == 15) {

                sf::sleep(sf::milliseconds(10000));
                while (!startGame)
                {
                    std::random_device deviceNum;
                    std::uniform_int_distribution <int> distributie_nrRandom(1, 10);
                    startGame = distributie_nrRandom(deviceNum);

                    if (startGame == 2 || startGame == 3 || startGame == 6 || startGame == 7 || startGame == 10) {
                        std::cout << "Player incepe jocul : " << startGame << std::endl;
                        sound.Sound_User();
                        sf::Sound& SoundUser = sound.getSoundUser();
                        SoundUser.play();
                        DerulatorJoc = 16;
                    }
                    else {
                        std::cout << "Calculator incepe jocul : " << startGame << std::endl;
                        sound.Sound_Computer();
                        sf::Sound& SoundComputer = sound.getSoundComputer();
                        SoundComputer.play();
                        DerulatorJoc = 17;
                    }

                }

            }

            if (DerulatorJoc == 16) {
               
                
                if (PlayerAlegere == 1 && CalculatorAlege == 1) {
                    std::cout << "Player a castigat jocul" << std::endl;
                    Winner = 1;
                }
                else if (PlayerAlegere == 1 && CalculatorAlege == 2) {
                    std::cout << "Calculatorul a castigat jocul" << std::endl;
                    Winner = 2;
                }
                else if (PlayerAlegere == 1 && CalculatorAlege == 3) {
                    std::cout << "Calculatorul a castigat jocul" << std::endl;
                    Winner = 2;
                }
                else if (PlayerAlegere == 2 && CalculatorAlege == 1) {
                    std::cout << "Player a castigat jocul" << std::endl;
                    Winner = 1;
                }
                else if (PlayerAlegere == 2 && CalculatorAlege == 2) {
                    std::cout << "Player a castigat jocul" << std::endl;
                    Winner = 1;
                }
                else if (PlayerAlegere == 2 && CalculatorAlege == 3) {
                    std::cout << "Calculatorul a castigat jocul" << std::endl;
                    Winner = 2;
                }
                else if (PlayerAlegere == 3 && CalculatorAlege == 1) {
                    std::cout << "Player a castigat jocul" << std::endl;
                    Winner = 1;
                }
                else if (PlayerAlegere == 3 && CalculatorAlege == 2) {
                    std::cout << "Player a castigat jocul" << std::endl;
                    Winner = 1;
                }
                else if (PlayerAlegere == 3 && CalculatorAlege == 3) {
                    std::cout << "Player a castigat jocul" << std::endl;
                    Winner = 1;
                }
                
                if (Winner) {
                    if (Winner == 1 && DerulatorJoc == 16) {
                        sf::sleep(sf::milliseconds(3000));
                        sound.Sound_WinnerPlayer();
                        sf::Sound& SoundWinnerUser = sound.getSoundWinnerUser();
                        SoundWinnerUser.play();
                        DisplayGame.clear();
                        DisplayGame.draw(spriteBackground);
                        DisplayGame.draw(spritePergament);
                        DisplayGame.draw(NumeJoc);
                        DisplayGame.draw(Castigator);
                        NumeJucator.setCharacterSize(50);
                        NumeJucator.setPosition(320, 350);
                        DisplayGame.draw(NumeJucator);
                        DisplayGame.display();
                    }
                    else {
                        sf::sleep(sf::milliseconds(3000));
                        sound.Sound_WinnerPC();
                        sf::Sound& SoundWinnerPC = sound.getSoundWinnerPC();
                        SoundWinnerPC.play();
                        DisplayGame.clear();
                        DisplayGame.draw(spriteBackground);
                        DisplayGame.draw(spritePergament);
                        DisplayGame.draw(NumeJoc);
                        DisplayGame.draw(Castigator);
                        Computer.setPosition(320, 350); 
                        Computer.setCharacterSize(50);
                        DisplayGame.draw(Computer);
                        DisplayGame.display();
                    }
                }

            }


                if (DerulatorJoc == 17) {
                    if (CalculatorAlege == 1 && PlayerAlegere == 1) {
                        std::cout << "Calculatorul a castigat jocul" << std::endl;
                        Winner = 2;
                    }
                    else if (CalculatorAlege == 1 && PlayerAlegere == 2) {
                        std::cout << "Player a castigat jocul" << std::endl;
                        Winner = 1;
                    }
                    else if (CalculatorAlege == 1 && PlayerAlegere == 3) {
                        std::cout << "Player a castigat jocul" << std::endl;
                        Winner = 1;
                    }
                    else if (CalculatorAlege == 2 && PlayerAlegere == 1) {
                        std::cout << "Calculatorul a castigat jocul" << std::endl;
                        Winner = 2;
                    }
                    else if (CalculatorAlege == 2 && PlayerAlegere == 2) {
                        std::cout << "Calculatorul a castigat jocul" << std::endl;
                        Winner = 2;
                    }
                    else if (CalculatorAlege == 2 && PlayerAlegere == 3) {
                        std::cout << "Player a castigat jocul" << std::endl;
                        Winner = 1;
                    }
                    else if (CalculatorAlege == 3 && PlayerAlegere == 1) {
                        std::cout << "Calculatorul a castigat jocul" << std::endl;
                        Winner = 2;
                    }
                    else if (CalculatorAlege == 3 && PlayerAlegere == 2) {
                        std::cout << "Calculatorul a castigat jocul" << std::endl;
                        Winner = 2;
                    }
                    else if (CalculatorAlege == 3 && PlayerAlegere == 3) {
                        std::cout << "Calculatorul a castigat jocul" << std::endl;
                        Winner = 2;
                    }
                    if (Winner && DerulatorJoc == 17) {
                        if (Winner == 1) {
                            sf::sleep(sf::milliseconds(3000));
                            sound.Sound_WinnerPlayer();
                            sf::Sound& SoundWinnerUser = sound.getSoundWinnerUser();
                            SoundWinnerUser.play();
                            DisplayGame.clear();
                            DisplayGame.draw(spriteBackground);
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            DisplayGame.draw(Castigator);
                            NumeJucator.setPosition(320, 350);
                            NumeJucator.setCharacterSize(50);
                            DisplayGame.draw(NumeJucator);
                            DisplayGame.display();
                        }
                        else {
                            sf::sleep(sf::milliseconds(3000));
                            sound.Sound_WinnerPC();
                            sf::Sound& SoundWinnerPC = sound.getSoundWinnerPC();
                            SoundWinnerPC.play();
                            DisplayGame.clear();
                            DisplayGame.draw(spriteBackground);
                            DisplayGame.draw(spritePergament);
                            DisplayGame.draw(NumeJoc);
                            DisplayGame.draw(Castigator);
                            Computer.setCharacterSize(50);
                            Computer.setPosition(320, 350);
                            DisplayGame.draw(Computer);
                            DisplayGame.display();
                        }
                    }
                }
        }
    }
     
}
    
    

   