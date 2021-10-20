#include <iostream>
#include <ctime>

void PrintIntro(int LevelDiff)
{
  std::cout << "\n\nYou are a hacker breaking into a LEVEL " << LevelDiff;
  std::cout << " secure server...\nEnter de correct code to continue...";
}

bool PlayGame(int LevelDiff)
{
  PrintIntro(LevelDiff);
  const int CodeA = rand() % LevelDiff + LevelDiff;
  const int CodeB = rand() % LevelDiff + LevelDiff;
  const int CodeC = rand() % LevelDiff + LevelDiff;
  int GuessA, GuessB, GuessC;

  int CodeSum = CodeA + CodeB + CodeC;
  int CodeProduct = CodeA * CodeB * CodeC;

  std::cout << "\n\n+ There are 3 numbers in the code";
  std::cout << "\n+ The sum of the numbers in the code is " << CodeSum;
  std::cout << "\n+ The multiplication of the numbers is " << CodeProduct;

  std::cout << std::endl << std::endl << "Enter Code: ";
  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  if (CodeSum == GuessSum && CodeProduct == GuessProduct)
  {
    std::cout << "\nACCESS GRANTED";
    return true;
  }
  else
  {
    std::cout << "\nACCESS DENIED";
    return false;
  }
}

int main()
{
  srand(time(NULL)); // Create new seed for rand based on time
  int LevelDiff = 1;
  int const MaxDiff = 5;

  while (LevelDiff <= MaxDiff)
  {
    bool LevelComplete = PlayGame(LevelDiff);
    std::cin.clear();
    std::cin.ignore();

    if (LevelComplete)
    {
      ++LevelDiff;
    }
  }
  return 0;
}