#include <iostream>
#include <windows.h>
#include <cstdlib>

// Made By ISellStuff
// I know this is horrible but I'm just trying to get better with c++ and i want to get into this stuff

struct Cheat {
    // Mem Address of health and all that stuff

    DWORD health = 0x006FCEEC;
    DWORD ammo = 0x006FCF40;

    DWORD nHEALTH = 9999999;
    DWORD nAMMO = 9999999;
};

int main() {
    system("cls");
    Cheat cheat;
    DWORD pid = 19208;
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    std::cout << "Shitty Game Assault Cube Cheat Made In C++\n";

    while (true) {
        int option;

        std::cout << "\n\n[1] Health\n[2] Ammo\n[x] Exit\n> ";
        std::cin >> option;

        if (option == 1) {
            if (WriteProcessMemory(handle, (LPVOID)cheat.health, &cheat.nHEALTH, sizeof(cheat.nHEALTH), NULL)) {
                std::cout << "[+] Gave 9999999 Health";
            } else {
                std::cout << "[!] Failed To Give Health";
            }
        } else if (option == 2) {
            if (WriteProcessMemory(handle, (LPVOID)cheat.ammo, &cheat.nAMMO, sizeof(cheat.nAMMO), NULL)) {
                std::cout << "[+] Gave 9999999 Ammo";
            } else {
                std::cout << "[!] Failed To Give Ammo";
            }
        } else {
            break;
        }
    }

    CloseHandle(handle);
}
