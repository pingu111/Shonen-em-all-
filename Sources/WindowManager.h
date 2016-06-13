#pragma once


#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include <Global.h>
#include <Bouton.h>


class WindowManager
{

private:

	/* Constructeur : cr�� la RenderWindow */
	WindowManager();
	//static WindowManager m_instance;


	/* La RenderWindow d'affichage pour tout le programme */
	sf::RenderWindow window;

	/* La liste des sprites qu'on dessinera */
	std::vector<std::unique_ptr<sf::Sprite>> listSprites;

	/* La liste des textes qu'on dessinera */
	std::vector<std::unique_ptr<sf::Text>> listText;

	/* La liste des textes qu'on dessinera */
	std::vector<std::pair<std::unique_ptr<sf::Text>, int>> listTextWithPeremption;

	/* La liste des boutons � dessiner */
	std::vector<std::unique_ptr<Bouton>> listButtons;

	/* Destructeur*/
	~WindowManager();


public:

	/* Retourne la RenderWinow* */
	sf::RenderWindow* getWindow();

	/* Ajoute l'argument dans le vector des sprites qu'on dessinera */
	void add(std::unique_ptr<sf::Sprite> form);

	/* Ajoute l'argument dans le vector des textes qu'on dessinera */
	void add(std::unique_ptr<sf::Text> form);

	/* Ajoute l'argument dans le vector des textes qu'on dessinera et qui disparaitront */
	void addWithPeremption(std::unique_ptr<sf::Text> form , int peremptionTime);

	/* Ajoute un bouton � la liste des choses � dessiner */
	void add(std::unique_ptr<Bouton> button);


	/* Enleve tous les textes affich�s */
	void clearText();

	/* Dessine la liste des sprites de listSprites 
	 Et vide la liste des sprites � dessiner */
	void draw();

	WindowManager(const WindowManager& wm) = delete;
	void operator=(const WindowManager& wm) = delete;

public:

	static WindowManager& Instance();

};

