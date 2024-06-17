#include "Texte.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

Texte::Texte()
{
}


void Texte::Text_GameName()
{
	
	
	NumeJoc.setString("The Darkest Battle");
	
	

}

void Texte::Text_Goblin()
{
	GoblinText.setString(" The goblin is an evil and grotesque creature that appears in\n European folklore. The first attestation of goblins comes from\n stories from the Middle Ages. They have contradictory abilities, \ntemperaments and aspects, ranging from mischievous house spirits to\n evil and bestial thieves. They usually have magical abilities similar\n to fairies or demons, such as the ability to transform.");
}

void Texte::Text_Goblin_Name()
{
	GoblinName.setString("Goblin");
}

void Texte::Text_Orc()
{
	OrcText.setString(" An orc is a mythical creature that appears in many mythologies \nand works of fiction. Originally, orcs were considered elves, \nbut they were transformed into aggressive and fearsome beings after \nbeing beaten and tortured. Orcs are a race of humanoids, tough and\n born warriors. Physically, they can be portrayed in different ways, \nfrom stronger to weaker, but always in large numbers.");
}

void Texte::Text_Orc_Name()
{
	OrcName.setString("Orc");
}

void Texte::Text_Troll()
{
	TrollText.setString("A troll is a person who deliberately launches provocative \ndiscussions or posts in the online environment, with the aim of \ncreating conflicts, stirring up controversies or irritating other \nusers. Trolls can use sensitive or well-known topics to provoke strong\n reactions and create tumult in online communities. It is usually \nadvised not to feed the trolls.");
}

void Texte::Text_Troll_Name()
{
	TrollName.setString("Troll");
}

void Texte::Text_Play()
{
	TextPlay.setString("Play");
}

void Texte::Text_Exit()
{
	TextExit.setString("Exit");
}


void Texte::Text_Next()
{
	TextNext.setString("Next");
}

void Texte::Text_AlegeCutia()
{
	AlegeCutia.setString("Choose a chest.\nThe chosen chest will represent you throughout the game.\nThe decision will be a difficult one.\nWalk healthy!");
}

void Texte::Text_playerNameLabel()
{
	playerNameLabel.setString("Player Name :");
}

void Texte::Text_NumeJucator()
{
	NumeJucator.setString(" ");
}




sf::Text& Texte::getNumeJoc()
{
	return NumeJoc;
}

sf::Text& Texte::getGoblinText()
{
	return GoblinText;
}

sf::Text& Texte::getGoblinName()
{
	return GoblinName;
}

sf::Text& Texte::getOrcText()
{
	return OrcText;
}

sf::Text& Texte::getOrcName()
{
	return OrcName;
}

sf::Text& Texte::getTrollText()
{
	return TrollText;
}

sf::Text& Texte::getTrollName()
{
	return TrollName;
}

sf::Text& Texte::getTextPlay()
{
	return TextPlay;
}

sf::Text& Texte::getTextExit()
{
	return TextExit;
}


sf::Text& Texte::getNext()
{
	return TextNext;
}

sf::Text& Texte::getAlegeCutia()
{
	return AlegeCutia;
}

sf::Text& Texte::getplayerNameLabel()
{
	return playerNameLabel;
}

sf::Text& Texte::getNumeJucator()
{
	return NumeJucator;
}

