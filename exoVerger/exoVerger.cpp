#include <iostream>
#include <stdlib.h>   
#include <time.h> 
#include "Orchard.h"


int main()
{
	srand(time(NULL));
	Orchard ourOrchard;
	ourOrchard.ChooseOurPlanting();
}