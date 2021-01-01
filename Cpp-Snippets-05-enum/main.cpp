#include <iostream>

enum class GameState
{
  MainMenu,
  Idle,
  Play,
  Exit
};
void Start();
void SetGameState(GameState newState);
void Update();
GameState gameState=GameState::Idle;

void Start()
{
  gameState = GameState::Idle;
  SetGameState(GameState::MainMenu);
}

void SetGameState(GameState newState)
{
  // check if already in the new state
  if (gameState == newState)
    return;

  // set the new gameState
  gameState = newState;

  // here you can call functions that only fire once on state change
  switch (gameState)
  {
  case GameState::Idle:
    //SetToIdle();
    break;

  case GameState::MainMenu:
    //SetToMainMenu();
    break;
  }
};

void Update()
{
  // here you can call functions every update fframe
  switch (gameState)
  {
  case GameState::Idle:
    std::cout << "the game is in Idle state" << std::endl;
    // UpdateIdle();
    break;

  case GameState::MainMenu:
    std::cout << "the game is loading main menu" << std::endl;
    //  UpdateMainMenu();
    break;
  }
}

int main()
{

  Update();
  Start();
  Update();

  return EXIT_SUCCESS;
};
