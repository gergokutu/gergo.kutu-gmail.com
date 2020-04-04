// Refactoring IO to Function Call and Testing
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

// this is a big function
// easier to test smaller ones
// especially with automated testing...
void save_score(int guess_count)
{
  std::ifstream input("best_scores.txt");

  if (!input.is_open())
  {
    std::cout << "Unable to read file\n";
    return;
  }

  int best_score;
  input >> best_score;

  std::ofstream output("best_scores.txt");

  if (!output.is_open())
  {
    std::cout << "Unable to write file\n";
    return;
  }

  if (guess_count < best_score)
  {
    output << guess_count;
  }
  else
  {
    output << best_score;
  }
}

void print_vector(std::vector<int> vector)
{
  for (int i = 0; i < vector.size(); i++)
  {
    std::cout << vector[i] << "\t";
  }
  std::cout << std::endl;
  std::cout << "\n";
}

void play_game()
{
  int guess_count = 0;

  std::vector<int> guesses;
  int random = rand() % 251;
  // next line just shows the random number
  // std::cout << random << std::endl;
  std::cout << "Guess a random number from 0 to 250: " << std::endl;

  while (true)
  {
    int guess;
    std::cin >> guess;
    guess_count++;
    
    guesses.push_back(guess);

    if (guess == random)
    {
      std::cout << "\n!!!!!!!!!!!!!!!YOU WIN!!!!!!!!!!!!!!!!\n\n";
      break;
    } 
    else if (guess < random)
    {
      std::cout << "Too low\n";
    } 
    else
    {
      std::cout << "Too high\n";
    }
  }
  
  save_score(guess_count);
  print_vector(guesses);
}

int main()
{ 
  srand(time(NULL));
  int choice;

  do
  {
    std::cout << "0. Quit" << std::endl << "1. Play Game\n";
    std::cin >> choice;

    switch (choice)
    {
      case 0:
        std::cout << "Good bye!\n";
        return 0;
      case 1:
        std::cout << "Yo, let's play a guess game!\n\n";
        play_game();
        break;
    }
  } 
  while (choice != 0);
}