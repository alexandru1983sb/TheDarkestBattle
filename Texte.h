#pragma once
#include <SFML/Graphics.hpp>
class Texte
{
public:
	//Constructor
	Texte();

	// Metoda pentru încărcare
	void Text_GameName();
	void Text_Goblin();
	void Text_Goblin_Name();
	void Text_Orc();
	void Text_Orc_Name();
	void Text_Troll();
	void Text_Troll_Name();
	void Text_Play();
	void Text_Exit();
	void Text_Next();
	void Text_AlegeCutia();
	void Text_playerNameLabel();
	void Text_NumeJucator();

	// Metoda pentru a obține Text
	sf::Text& getNumeJoc();
	//Metoda Goblin
	sf::Text& getGoblinText();
	sf::Text& getGoblinName();
	//Metoda Orc
	sf::Text& getOrcText();
	sf::Text& getOrcName();
	//Metoda Troll
	sf::Text& getTrollText();
	sf::Text& getTrollName();
	//Metoda Play
	sf::Text& getTextPlay();
	//Metoda Exit
	sf::Text& getTextExit();
	//Metoda Next
	sf::Text& getNext();
	sf::Text& getAlegeCutia();
	//Metoda playerNameLabel & NumeJucator
	sf::Text& getplayerNameLabel();
	sf::Text& getNumeJucator();
	

private:

	//Nume joc
	sf::Text NumeJoc;
	//Goblin
	sf::Text GoblinText;
	sf::Text GoblinName;
	//Orc
	sf::Text OrcText;
	sf::Text OrcName;
	//Troll
	sf::Text TrollText;
	sf::Text TrollName;
	//Play
	sf::Text TextPlay;
	//Exit
	sf::Text TextExit;
	//Next
	sf::Text TextNext;
	//Alege cutia
	sf::Text AlegeCutia;
	// Player Name
	sf::Text playerNameLabel;
	// Nume Jucator
	sf::Text NumeJucator;
	
	
};

