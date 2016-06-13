#include <YouDied.h>

/* Le constructeur de la scene */
YouDied::YouDied()
{
	m_instance.window = WindowManager::Instance();

}

YouDied YouDied::m_instance = YouDied();

YouDied& YouDied::Instance()
{
	return m_instance;
}

void YouDied::reload()
{

}