#include "Sound.h"
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

// Constructor (opțional, dacă este necesar)
Sound::Sound()
{
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_Menu()
{
	SoundBufferMenu.loadFromFile("sound/MainMenu.wav");
	if (!SoundBufferMenu.loadFromFile("sound/MainMenu.wav")) {
		std::cout << RED << "Eroare incarcare sunet MainMenu" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul MainMenu s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundMenu.setBuffer(SoundBufferMenu);
	SoundMenu.play();
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_Goblin()
{
	SoundBufferGoblin.loadFromFile("sound/goblin.mp3");
	if (!SoundBufferGoblin.loadFromFile("sound/goblin.mp3")) {
		std::cout << RED << "Eroare incarcare sunet goblin" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul goblin s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundGoblin.setBuffer(SoundBufferGoblin);
	SoundGoblin.play();
}

void Sound::Sound_GoblinVoice()
{
	SoundBuferGoblinVoice.loadFromFile("sound/goblinVoice.wav");
	if (!SoundBuferGoblinVoice.loadFromFile("sound/goblinVoice.wav")) {
		std::cout << RED << "Eroare incarcare sunet goblinVoice" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul goblinVoice s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundGblinVoice.setBuffer(SoundBuferGoblinVoice);
	SoundGblinVoice.play();
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_Orc()
{
	SoundBufferOrc.loadFromFile("sound/orc.mp3");
	if (!SoundBufferOrc.loadFromFile("sound/orc.mp3")) {
		std::cout << RED << "Eroare incarcare sunet orc" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul orc s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundOrc.setBuffer(SoundBufferOrc);
	SoundOrc.play();
}

void Sound::Sound_OrcVoice()
{
	SoundBufferOrcVoice.loadFromFile("sound/orcVoice.wav");
	if (!SoundBufferOrcVoice.loadFromFile("sound/orcVoice.wav")) {
		std::cout << RED << "Eroare incarcare sunet orcVoice" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul orcVoice s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundOrcVoice.setBuffer(SoundBufferOrcVoice);
	SoundOrcVoice.play();
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_Troll()
{
	SoundBufferTroll.loadFromFile("sound/troll.mp3");
	if (!SoundBufferTroll.loadFromFile("sound/troll.mp3")) {
		std::cout << RED << "Eroare incarcare sunet troll" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul troll s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundTroll.setBuffer(SoundBufferTroll);
	SoundTroll.play();
}

void Sound::Sound_TrollVoice()
{
	SoundBufferTrollVoice.loadFromFile("sound/trollVoice.wav");
	if (!SoundBufferTrollVoice.loadFromFile("sound/trollVoice.wav")) {
		std::cout << RED << "Eroare incarcare sunet trollVoice" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul trollVoice s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundTrollVoice.setBuffer(SoundBufferTrollVoice);
	SoundTrollVoice.play();
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_Laugh()
{
	SoundBufferLaugh.loadFromFile("sound/Laugh.wav");
	if (!SoundBufferLaugh.loadFromFile("sound/Laugh.wav")) {
		std::cout << RED << "Eroare incarcare sunet Laugh" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul Laugh s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundLaugh.setBuffer(SoundBufferLaugh);
	SoundLaugh.play();
}

void Sound::Sound_chooseTheBox()
{
	SoundBufferchooseTheBox.loadFromFile("sound/Alegecutia.mp3");
	if (!SoundBufferchooseTheBox.loadFromFile("sound/Alegecutia.mp3")) {
		std::cout << RED << "Eroare incarcare sunet Alegecutia" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul Alegecutia s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundChooseTheBox.setBuffer(SoundBufferchooseTheBox);
	SoundChooseTheBox.play();
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_ChooseYourDestiny()
{
	SoundBufferChooseYourDestiny.loadFromFile("sound/chooseyourdestiny.wav");
	if (!SoundBufferChooseYourDestiny.loadFromFile("sound/chooseyourdestiny.wav")) {
		std::cout << RED << "Eroare incarcare sunet chooseyourdestiny" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul chooseyourdestiny s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundChooseYourDestiny.setBuffer(SoundBufferChooseYourDestiny);
	SoundChooseYourDestiny.play();
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_Exploring()
{
	SoundBufferExploring.loadFromFile("sound/exploring.wav");
	if (!SoundBufferExploring.loadFromFile("sound/exploring.wav")) {
		std::cout << RED << "Eroare incarcare sunet exploring" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul exploring s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundExploring.setBuffer(SoundBufferExploring);
	SoundExploring.play();
}

// Metoda pentru încărcarea SoundBuffer și setarea Sound
void Sound::Sound_BattleFinal()
{
	SoundBufferBattleFinal.loadFromFile("sound/battlefinal.wav");
	if (!SoundBufferBattleFinal.loadFromFile("sound/battlefinal.wav")) {
		std::cout << RED << "Eroare incarcare sunet battlefinal" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul battlefinal s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundBattleFinal.setBuffer(SoundBufferBattleFinal);
	SoundBattleFinal.play();
}

// Metoda pentru incarcare ThreeWeapons
void Sound::Sound_ThreeWeapons()
{
	SoundBufferThreeWeapons.loadFromFile("sound/ThreeWeapons.wav");
	if (!SoundBufferThreeWeapons.loadFromFile("sound/ThreeWeapons.wav")) {
		std::cout << RED << "Eroare incarcare sunet ThreeWeapons" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul ThreeWeapons s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundThreeWeapons.setBuffer(SoundBufferThreeWeapons);
	SoundThreeWeapons.play();
}

void Sound::Sound_Mar()
{
	SoundBufferMar.loadFromFile("sound/descrieremar.mp3");
	if (!SoundBufferMar.loadFromFile("sound/descrieremar.mp3")) {
		std::cout << RED << "Eroare incarcare sunet descrieremar" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul descrieremar s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundMar.setBuffer(SoundBufferMar);
	SoundMar.play();
}

void Sound::Sound_Piatra()
{
	SoundBufferPiatra.loadFromFile("sound/descrierepiatra.mp3");
	if (!SoundBufferPiatra.loadFromFile("sound/descrierepiatra.mp3")) {
		std::cout << RED << "Eroare incarcare sunet descrierepiatra" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul descrierepiatra s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundPiatra.setBuffer(SoundBufferPiatra);
	SoundPiatra.play();
}

void Sound::Sound_Arc()
{
	SoundBufferArc.loadFromFile("sound/descrierearc.mp3");
	if (!SoundBufferArc.loadFromFile("sound/descrierearc.mp3")) {
		std::cout << RED << "Eroare incarcare sunet descrierearc" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "Sunetul descrierearc s-a incarcat cu succes." << RESET << std::endl;
	}
	SoundArc.setBuffer(SoundBufferArc);
	SoundArc.play();
}



// Metoda pentru a obține Sound

sf::Sound& Sound::getSoundMenu()
{
	return SoundMenu;
}

sf::Sound& Sound::getSoundGoblin()
{
	return SoundGoblin;
}

sf::Sound& Sound::getSoundGoblinVoice()
{
	return SoundGblinVoice;
}

sf::Sound& Sound::getSoundOrc()
{
	return SoundOrc;
}

sf::Sound& Sound::getSoundOrcVoice()
{
	return SoundOrcVoice;
}

sf::Sound& Sound::getSoundTroll()
{
	return SoundTroll;
}

sf::Sound& Sound::getSoundTrollVoice()
{
	return SoundTrollVoice;
}

sf::Sound& Sound::getSoundChooseYourDestiny()
{
	return SoundChooseYourDestiny;
}

sf::Sound& Sound::getSoundExploring()
{
	return SoundExploring;
}

sf::Sound& Sound::getSoundBattleFinal()
{
	return SoundBattleFinal;
}

sf::Sound& Sound::getSoundLaugh()
{
	return SoundLaugh;
}

sf::Sound& Sound::getSoundChooseTheBox()
{
	return SoundChooseTheBox;
}

sf::Sound& Sound::getSoundThreeWeapons()
{
	return SoundThreeWeapons;
}

sf::Sound& Sound::getSoundMar()
{
	return SoundMar;
}

sf::Sound& Sound::getSoundPiatra()
{
	return SoundPiatra;
}

sf::Sound& Sound::getSoundArc()
{
	return SoundArc;
}






