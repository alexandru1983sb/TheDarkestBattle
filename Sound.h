#pragma once

#include <SFML/Audio.hpp>

class Sound
{
public:
	// Constructor 
	Sound();

	// Metoda pentru încărcare
	void Sound_Menu();
	void Sound_Goblin();
	void Sound_GoblinVoice();
	void Sound_Orc();
	void Sound_OrcVoice();
	void Sound_Troll();
	void Sound_TrollVoice();
	void Sound_Laugh();
	void Sound_chooseTheBox();
	void Sound_ChooseYourDestiny();
	void Sound_Exploring();
	void Sound_BattleFinal();
	void Sound_ThreeWeapons();
	void Sound_Mar();
	void Sound_Piatra();
	void Sound_Arc();
	void Sound_Computer();
	void Sound_User();


	// Metoda pentru a obține sprite-ul
	sf::Sound& getSoundMenu();
	sf::Sound& getSoundGoblin();
	sf::Sound& getSoundGoblinVoice();
	sf::Sound& getSoundOrc();
	sf::Sound& getSoundOrcVoice();
	sf::Sound& getSoundTroll();
	sf::Sound& getSoundTrollVoice();
	sf::Sound& getSoundChooseYourDestiny();
	sf::Sound& getSoundExploring();
	sf::Sound& getSoundBattleFinal();
	sf::Sound& getSoundLaugh();
	sf::Sound& getSoundChooseTheBox();
	sf::Sound& getSoundThreeWeapons();
	sf::Sound& getSoundMar();
	sf::Sound& getSoundPiatra();
	sf::Sound& getSoundArc();
	sf::Sound& getSoundComputer();
	sf::Sound& getSoundUser();

private:

	//Sunet Meniu
	sf::SoundBuffer SoundBufferMenu;
	sf::Sound SoundMenu;

	//Sunet Goblin
	sf::SoundBuffer SoundBufferGoblin;
	sf::Sound SoundGoblin;
	sf::SoundBuffer SoundBuferGoblinVoice;
	sf::Sound SoundGblinVoice;

	//Sunet Orc
	sf::SoundBuffer SoundBufferOrc;
	sf::Sound SoundOrc;
	sf::SoundBuffer SoundBufferOrcVoice;
	sf::Sound SoundOrcVoice;

	//Sunet Troll
	sf::SoundBuffer SoundBufferTroll;
	sf::Sound SoundTroll;
	sf::SoundBuffer SoundBufferTrollVoice;
	sf::Sound SoundTrollVoice;

	//Sunet Ras
	sf::SoundBuffer SoundBufferLaugh;
	sf::Sound SoundLaugh;

	//Suner Alege cutia
	sf::SoundBuffer SoundBufferchooseTheBox;
	sf::Sound SoundChooseTheBox;

	//Sunet ChooseYourDestiny
	sf::SoundBuffer SoundBufferChooseYourDestiny;
	sf::Sound SoundChooseYourDestiny;

	//Sunet Exploring
	sf::SoundBuffer SoundBufferExploring;
	sf::Sound SoundExploring;

	//Sunet BattleFinal
	sf::SoundBuffer SoundBufferBattleFinal;
	sf::Sound SoundBattleFinal;

	//There_are_three_weapons_you_can_fight_with
	sf::SoundBuffer SoundBufferThreeWeapons;
	sf::Sound SoundThreeWeapons;

	//Descriere mar
	sf::SoundBuffer SoundBufferMar;
	sf::Sound SoundMar;
	
	//Descriere piatra
	sf::SoundBuffer SoundBufferPiatra;
	sf::Sound SoundPiatra;

	//Descriere arc
	sf::SoundBuffer SoundBufferArc;
	sf::Sound SoundArc;

	//Sound Computer
	sf::SoundBuffer SoundBufferComputer;
	sf::Sound SoundComputer;

	//Sound User
	sf::SoundBuffer SoundBufferUser;
	sf::Sound SoundUser;


};

