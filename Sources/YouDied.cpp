#include <YouDied.h>

/* Le constructeur de la scene */
YouDied::YouDied()
{

}

YouDied YouDied::m_instance = YouDied();

YouDied& YouDied::Instance()
{
	return m_instance;
}

void YouDied::reload()
{

}