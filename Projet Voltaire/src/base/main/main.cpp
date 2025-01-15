#include "../../src/base/base.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    Base b;
    b.Init();

    while (!GetAsyncKeyState(VK_DELETE))
    {
        b.Loop();
        std::this_thread::sleep_for(std::chrono::microseconds(20));
    }
}