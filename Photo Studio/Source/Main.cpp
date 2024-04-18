#include "Application.h"

int main(int, char**)
{
    Application::InitGL();
    Application App;
    App.Run();
    return 0;
}