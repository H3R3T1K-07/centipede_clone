#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "GameLoop.h"
#include "GameDefinitions.h"

using namespace std;



int main()
{

    Centipede::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Centipede");

    return 0;
}
