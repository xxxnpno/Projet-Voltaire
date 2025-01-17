#include "main.h"

void Main::Init()
{
    SetConsoleOutputCP(CP_UTF8);

    std::cout << Logger::Info() << "Press Enter when you are ready" << std::endl;
    while (!GetAsyncKeyState(VK_RETURN));
    std::this_thread::sleep_for(std::chrono::microseconds(100));

    Base::Init();
}

void Main::Loop()
{
    while (true)
    {
        Sleep(500);
        Base::Loop();
    }
}

int main()
{
    Main::Init();

    Main::Loop();
}