#pragma once


#include <SFML/Graphics.hpp>
#include <memory>
#include <Global.h>


class WindowManager
{


public:
	/* Constructeur : créé la RenderWindow */
	WindowManager();

	/* Destructeur*/
	~WindowManager();

	/* Retourne la RenderWinow* */
	sf::RenderWindow* getWindow();

	/* Ajoute l'argument dans le vector des sprites qu'on dessinera */
	void add(std::unique_ptr<sf::Sprite> form);

	/* Ajoute l'argument dans le vector des textes qu'on dessinera */
	void add(std::unique_ptr<sf::Text> form);

	/* Ajoute l'argument dans le vector des textes qu'on dessinera et qui disparaitront */
	void addWithPeremption(std::unique_ptr<sf::Text> form , int peremptionTime);


	/* Enleve tous les textes affichés */
	void clearText();

	/* Dessine la liste des sprites de listSprites 
	 Et vide la liste des sprites à dessiner */
	void draw();

private:
	/* La RenderWindow d'affichage pour tout le programme */
	sf::RenderWindow window;

	/* La liste des sprites qu'on dessinera */
	std::vector<std::unique_ptr<sf::Sprite>> listSprites;

	/* La liste des textes qu'on dessinera */
	std::vector<std::unique_ptr<sf::Text>> listText;

	/* La liste des textes qu'on dessinera */
	std::vector<std::pair<std::unique_ptr<sf::Text>, int>> listTextWithPeremption;
};

