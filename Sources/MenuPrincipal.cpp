#include <MenuPrincipal.h>


MenuPrincipal::MenuPrincipal()
{
	initTextures();
}

MenuPrincipal MenuPrincipal::m_instance = MenuPrincipal();

MenuPrincipal& MenuPrincipal::Instance()
{
	static MenuPrincipal m_instance;
	return m_instance;
}

void MenuPrincipal::printBackground()
{

	// On ajoute tous les sprites qu'on veut afficher 
	WindowManager::Instance().add(std::make_unique<sf::Sprite>(fondSprite));
	WindowManager::Instance().add(std::make_unique<Bouton>(boutonRNB));

	// On les affiche
	WindowManager::Instance().draw();
}

void MenuPrincipal::waitForUser()
{
	while (WindowManager::Instance().getWindow()->isOpen())
	{
		sf::Event event;
		while (WindowManager::Instance().getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				std::cout << "sf::Event::Closed\n";
				system("pause");
				return;
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << " sf::Keyboard::Escape\n";
					system("pause");
					return;
				}
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (boutonRNB.isClicked(sf::Mouse::getPosition(*WindowManager::Instance().getWindow())))
				{
					//std::cout << "Clique !\n";
					SceneManager::moveToScene(SceneNames::RNB);
					return;
				}
			}
		}
	}
}

void MenuPrincipal::initTextures()
{
	// On charge les differentes images 
	assert(fond.loadFromFile("Ressources\\Menuprincipal\\FondMenuPrincipal.jpg") == true);
	fondSprite.setTexture(fond);

	assert(boutonGoToRNB.loadFromFile("Ressources\\Menuprincipal\\TextBoxBlank.gif") == true);
	boutonGoToRNBSprite.setTexture(boutonGoToRNB);

	boutonGoToRNBSprite.setPosition((float)WindowManager::Instance().getWindow()->getSize().x / 2	 - boutonGoToRNBSprite.getTextureRect().width  / 2,
									(float)WindowManager::Instance().getWindow()->getSize().y * 5 / 6 - boutonGoToRNBSprite.getTextureRect().height / 2);

	// On créé le bouton qui cible le Hack n slash
	boutonRNB.setSprite(boutonGoToRNBSprite , std::make_unique<sf::Texture>(boutonGoToRNB));

	sf::Font font;
	assert(font.loadFromFile("Ressources\\ComicSansMS.ttf") == true);
	boutonRNB.setText("Commencer le jeu !", font);
}

MenuPrincipal::~MenuPrincipal()
{
	;
}

void MenuPrincipal::reload()
{
	launchScene();
	
}
void MenuPrincipal::launchScene()
{
	printBackground();
	// Boucle verifiant les evenements
	waitForUser();
}

