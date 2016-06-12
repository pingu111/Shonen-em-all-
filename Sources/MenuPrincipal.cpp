#include <MenuPrincipal.h>

MenuPrincipal MenuPrincipal::m_instance = MenuPrincipal();

MenuPrincipal::MenuPrincipal()
{
	;
}

MenuPrincipal& MenuPrincipal::Instance(WindowManager* windowArg)
{
	m_instance.window = windowArg;
	return m_instance;
}

void MenuPrincipal::printBackgroundAndButtons()
{

	// On ajoute tous les sprites qu'on veut afficher 
	window->add(std::make_unique<sf::Sprite>(fondSprite));
	window->add(std::make_unique<Bouton>(boutonRNB));

	// On les affiche
	window->draw();
}

EnumChoicesUser MenuPrincipal::waitForUser()
{
	while (window->getWindow()->isOpen())
	{
		sf::Event event;
		while (window->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				std::cout << "sf::Event::Closed\n";
				system("pause");
				return QUIT;
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << " sf::Keyboard::Escape\n";
					system("pause");
					return QUIT;
				}
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (boutonRNB.isClicked(sf::Mouse::getPosition(*window->getWindow())))
				{
					//std::cout << "Clique !\n";
					SceneManager::moveToScene(SceneNames::RNB, window);
					return RYTHM;
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

	boutonGoToRNBSprite.setPosition((float) window->getWindow()->getSize().x / 2	 - boutonGoToRNBSprite.getTextureRect().width  / 2,
									(float) window->getWindow()->getSize().y * 5 / 6 - boutonGoToRNBSprite.getTextureRect().height / 2);

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
	initTextures();
	printBackgroundAndButtons();
	// Boucle verifiant les evenements
	waitForUser();
}

