#include <iostream>
#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void PrintIntroduction() 
{
    std::cout << "You're a l33t h4ck3r breaking into a secure bank account.\n";
    std::cout << "You need to enter the correct pin code to gain access to the account\n\n";

}


bool PlayGame(int Difficulty) 
{
    srand(time(NULL));

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << "This is a Level [" << Difficulty << "] account. There are 3 numbers in the code" << "\n";
    std::cout << " - They add up to " << CodeSum << "\n";
    std::cout << " - They mulitply together to " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    std::cout << "Enter your guess...\n";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct)) {
        std::cout << std::endl << "\n\n$$$ Account Unlocked $$$\n\n";
        int i = 0;
        std::cout << "Transferring Funds:\n[";
        while (i < 40) 
        {
            std::cout << "#";
            Sleep(25); 
            i++;
        }
        std::cout << "]\n\n";
        Sleep(1000);
        std::cout << "==========================";
        std::cout << "\n   [Transfer Complete]\n";
        std::cout << "==========================\n\n";

        Sleep(1000);

        return true;
    }

    std::cout << std::endl << "\n\n[Access Denined]\n\n";
    return false;
}

int main () 
{
  
    int LevelDifficulty = 1;
    int MaxLevels = 5;

    PrintIntroduction();
    while (LevelDifficulty <= MaxLevels) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "Congratz. You've fleeced those suckers for everything they have...";

    return 0;
}

