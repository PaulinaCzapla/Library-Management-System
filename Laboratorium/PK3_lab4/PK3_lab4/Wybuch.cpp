#include "Wybuch.h"

void Wybuch::wywolaj()
{
	PlaySound(TEXT("wybuch.wav"), NULL, SND_FILENAME);
}