#include "main.h"

void Main::Init()
{
    SetConsoleOutputCP(CP_UTF8);
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());

    SetProcessDPIAware();

    std::cout << Logger::Info() << "Press Enter when you are ready" << std::endl;
    while (!GetAsyncKeyState(VK_RETURN));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    Base::Init();
}

void Main::Loop()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        Base::Loop();
    }
}

int main()
{
    Main::Init();

    Main::Loop();
}