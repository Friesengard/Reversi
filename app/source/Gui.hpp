#ifndef GUI_HPP
#define GUI_HPP

#include <sstream>
#include <map>

#include "Gamestate.hpp"

class Gui {
  // Helper

private:

  //TODO: description
  static void PrintSleepClear(const std::string& stringToPrint, size_t timeToShow = 1);


  //TODO: description
  static void PrintWelcomeBanner();


  //TODO: description
  static std::pair<size_t, std::string> ShowNumericSelectionDialog(const std::string& preambel, const std::map<size_t, std::string>& selectionMap);


  //TODO: description
  static void PrintPlayboard(const Gamestate& gamestate);


  //TODO: description
  static std::stringstream GetPlayboardHeaderRender(const Gamestate& gamestate);


  /** @brief Returns a stringstream represenation of the playboard according to the given gamestate.
  *
  *  Renders the entire playboard including additional information like turn counter and whos turn it is.
  *
  *  @param gamestate a constant reference to the gamestate.
  *  @return a stringstream representing the playboard.
  */
  static std::stringstream GetPlayboardRender(const Gamestate& gamestate);


  //TODO: description
  static int StringToMoveCoordinate(const std::string input, uint8_t& moveX, uint8_t& moveY);


public:
  /** @brief Show Intro to the User
  *
  *  @return Void.
  */
  static void ShowIntro();


private:

  // Menu maps


  //TODO: description
  static void InitYesNoMenuMap();


  //TODO: description
  static std::map<size_t, std::string> GetYesNoMenuMap();


  //TODO: description
  static void InitMainMenuMap();


  //TODO: description
  static std::map<size_t, std::string> GetMainMenuMap();


  //TODO: description
  static void InitStartGameMenuMap();


  //TODO: description
  static std::map<size_t, std::string> GetStartGameMenuMap();


  //TODO: description
  static void InitComputerTurnMenuMap();


  //TODO: description
  static std::map<size_t, std::string> GetComputerTurnMenuMap();


  //TODO: description
  static void InitReplayGameMenu();


  //TODO: description
  static std::map<size_t, std::string> GetReplayGameMenuMap();


  // Show menu functions

public:

  /** @brief Shows the main menu and reads user input.
  *
  * Depending on the input this function prints the manual, opens one of the other menus or exits the app.
  * Reads and validates user input.
  *
  *  @return Void.
  */
  static void ShowMainMenu();


private:


  /** @brief Shows the menu to start a game.
  *
  * This function reads and validates the players color choice and starts a new game.
  * It calls the StartNewGame() functions.
  *
  *  @return Void.
  */
  static void ShowStartGameMenu();


  /** @brief Shows the menu to load a saved game from file.
  *
  * This function presents the player with a list of available save games.
  * The chosen save game will be loaded from file and started in replay mode.
  *
  *  @return Void.
  */
  static void ShowLoadGameMenu();


  /** @brief Shows the menu for a running game and the current playboard.
  *
  * Main game loop. Reads and validates the users next move.
  * User can also exit the game to go back to the main menu.
  * Calls the functions to update the graphical playboard.
  *
  *  @return Void.
  */
  static void ShowRunningGameMenu(Gamestate& gamestate);


  //TODO: description
  static void ShowHumanTurnMenu(Gamestate& gamestate, bool& exitGame);


  //TODO: description
  static void ShowComputerTurnMenu(Gamestate& gamestate, bool& exitGame);


  //TODO: descripton
  static void ShowGameOverMenu(Gamestate& gamestate, bool& exitGame);


  /** @brief Shows the menu for an active replay game.
  *
  * Reads and validates the users input.
  * User can exit the game to go back to the main menu, jump to first move,
  * step one move forward or backwards or tap into the game to play from the current move onward.
  * Calls the functions to update the graphical playboard.
  *
  *  @return Void.
  */
  static void ShowReplayGameMenu();


  /** @brief Shows the menu asking for confirmation for leaving the game.
  *
  *  @return Void.
  */
  static void ShowExitGameMenu();

   /** @brief Shows the game menu instruction. How to play the game and what the rules are.
  *
  *  @return Void.
  */
  static void ShowInstructionGameMenu();

};

#endif
