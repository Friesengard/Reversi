#include <iostream>
#include <unistd.h>
#include <map>

#include "Gui.hpp"

#include "Controller.hpp"

using namespace std;

static const size_t g_invalidInputClearWaitSeconds = 1;
static const size_t g_defaultPrintSleepTime = 1;

static const string colorReset = "\033[0m";
static const string colorGrayBackground = "\033[97m";
static const string colorWhiteBackground = "\033[47m";
static const string colorBlackBackground = "\033[40m";
static const string colorRedBoldText = "\033[1;31m";
static const string fieldWidth = "  ";

map<size_t, string> g_yesNoMenuMap;
static const string g_menuEntryString_yesNo_yes = "Yes";
static const string g_menuEntryString_yesNo_no = "No";

map<size_t, string> g_mainMenuMap;
static const string g_menuEntryString_main_gameInstructions = "Show game instructions";
static const string g_menuEntryString_main_startNewGame = "Start new game";
static const string g_menuEntryString_main_loadGame = "Load saved game";
static const string g_menuEntryString_main_exit = "Exit game";

map<size_t, string> g_startGameMenuMap;
static const string g_menuEntryString_startGame_white = "Play as white";
static const string g_menuEntryString_startGame_black = "Play as black";

map<size_t, string> g_replayGameMenuMap;
static const string g_menuEntryString_replayGame_forward = "Step forward";
static const string g_menuEntryString_replayGame_backward = "Step backward";
static const string g_menuEntryString_replayGame_jumpToBeginning = "Jump to beginning";
static const string g_menuEntryString_replayGame_jumpToEnd = "Jump to end";
static const string g_menuEntryString_replayGame_exit = "Exit replay";

map<size_t, string> g_computerTurnMenuMap;
static const string g_menuEntryString_computerTurn_playTurn = "Play computer turn";
static const string g_menuEntryString_computerTurn_exit = "Exit game";


// Helper:

void Gui::PrintSleepClear(const string& stringToPrint, size_t timeToShow){
  cout << stringToPrint << endl;
  sleep(timeToShow);
  system("clear");
}

void Gui::PrintWelcomeBanner() {
  string spacingLeft = "          ";
  cout << spacingLeft << spacingLeft << colorRedBoldText << "Welcome to VTR for Reversi" << colorReset << endl;
  cout << spacingLeft << "Press enter to continue into the World of Terminal..." << endl;
}

pair<size_t, string> Gui::ShowNumericSelectionDialog(const string& preambel, const map<size_t, string>& selectionMap){
  bool selectionValid = false;
  pair<size_t, string> result;

  system("clear");

  while (selectionValid == false) {

    cout << preambel << endl;

    for (map<size_t, string>::const_iterator it = selectionMap.begin(); it != selectionMap.end(); it++) {
      size_t index = (*it).first;
      string option = (*it).second;
      cout << index << ": " << option << endl;
    }

    cout << "Enter number: ";
    string inputLine;
    std::getline(std::cin, inputLine);

    try {
      size_t selectionIndex = stoi(inputLine);
      map<size_t, string>::const_iterator findResult = selectionMap.find(selectionIndex);
      if (findResult != selectionMap.end()) {
        selectionValid = true;
        result = (*findResult);
      } else {
        throw exception();
      }
    } catch(exception& e) {
      PrintSleepClear("Invalid input", g_invalidInputClearWaitSeconds);
    }
  }

  return result;
}

void Gui::PrintPlayboard(const Gamestate& gamestate){

  stringstream render = GetPlayboardRender(gamestate);
  cout << render.str();
}

stringstream Gui::GetPlayboardHeaderRender(const Gamestate& gamestate){
  string turnOwnerString;
  if (gamestate.GetTurnOwner() == PlayerColor::WHITE) {
    turnOwnerString = "White";
  } else {
    turnOwnerString = "Black";
  }

  string humanPlayerString;
  if (gamestate.GetHumanPlayer() == PlayerColor::WHITE) {
    humanPlayerString = "White";
  } else {
    humanPlayerString = "Black";
  }

  stringstream returnStream;
  string spacing = "      ";
  returnStream << endl;
  returnStream << "Turn number: " << gamestate.GetTurnCounter();
  returnStream << spacing;
  returnStream << "Turn owner: " << turnOwnerString;
  returnStream << spacing;
  returnStream << "Player Color: " << humanPlayerString;
  returnStream << endl;

  return returnStream;
}

stringstream Gui::GetPlayboardRender(const Gamestate& gamestate) {
  Playboard playboard = gamestate.GetPlayboard();
  stringstream returnStream;


  returnStream << GetPlayboardHeaderRender(gamestate).str();
  returnStream << "   a  b  c  d  e  f  g  h" <<endl;
  returnStream << "  ________________________" <<endl;
  returnStream << 1;
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      if (playboard.fields[i][j] == Gamestate::WHITE_MARKER) {
        returnStream << "|"  << colorWhiteBackground << fieldWidth << colorReset;
      } else if (playboard.fields[i][j] == Gamestate::BLACK_MARKER) {
        returnStream << "|" << colorBlackBackground << fieldWidth << colorReset;
      } else {
        returnStream << "|"  << colorGrayBackground << fieldWidth << colorReset;
      }
    }
    returnStream <<"|"<< endl;
    returnStream << "  ________________________" <<endl;
    if (i!=7) {
      returnStream << i+2;
    }
  }
  returnStream << endl;
  return returnStream;
}

int Gui::StringToMoveCoordinate(const string input, uint8_t& moveX, uint8_t& moveY){

  if (input.size() != 2) {
    return -1;
  }

  char yChar = input.at(0);
  char xChar = input.at(1);

  if (yChar < 'a' || yChar > 'h' || xChar < '1' || xChar > '8') {
    return -1;
  }

  uint8_t asciiNum_a = 'a'; // 97
  moveY = yChar - asciiNum_a;

  uint8_t asciiNum_1 = '1'; // 49
  moveX = xChar - asciiNum_1;

  return 0;
}


void Gui::ShowIntro(){
  string inputLine;

  system("clear");
  PrintWelcomeBanner();
  std::getline(std::cin, inputLine);
  Gui::ShowMainMenu();
}


  // Menu maps

void Gui::InitYesNoMenuMap(){
  if (g_yesNoMenuMap.empty()) {
    g_yesNoMenuMap.insert(pair<size_t, string>(1, g_menuEntryString_yesNo_yes));
    g_yesNoMenuMap.insert(pair<size_t, string>(2, g_menuEntryString_yesNo_no));
  }
}

map<size_t, string> Gui::GetYesNoMenuMap(){
  InitYesNoMenuMap();
  return g_yesNoMenuMap;
}


void Gui::InitMainMenuMap(){
  if (g_mainMenuMap.empty()) {
    g_mainMenuMap.insert(pair<size_t, string>(1, g_menuEntryString_main_gameInstructions));
    g_mainMenuMap.insert(pair<size_t, string>(2, g_menuEntryString_main_startNewGame));
    g_mainMenuMap.insert(pair<size_t, string>(3, g_menuEntryString_main_loadGame));
    g_mainMenuMap.insert(pair<size_t, string>(0, g_menuEntryString_main_exit));
  }
}

map<size_t, string> Gui::GetMainMenuMap(){
  InitMainMenuMap();
  return g_mainMenuMap;
}


void Gui::InitStartGameMenuMap(){
  if (g_startGameMenuMap.empty()) {
    g_startGameMenuMap.insert(pair<size_t, string>(1, g_menuEntryString_startGame_white));
    g_startGameMenuMap.insert(pair<size_t, string>(2, g_menuEntryString_startGame_black));
  }
}

map<size_t, string> Gui::GetStartGameMenuMap(){
  InitStartGameMenuMap();
  return g_startGameMenuMap;
}


void Gui::InitComputerTurnMenuMap(){
  if (g_computerTurnMenuMap.empty()) {
    g_computerTurnMenuMap.insert(pair<size_t, string>(1, g_menuEntryString_computerTurn_playTurn));
    g_computerTurnMenuMap.insert(pair<size_t, string>(0, g_menuEntryString_computerTurn_exit));
  }
}

map<size_t, string> Gui::GetComputerTurnMenuMap(){
  InitComputerTurnMenuMap();
  return g_computerTurnMenuMap;
}


void Gui::InitReplayGameMenu(){
  if (g_replayGameMenuMap.empty()) {
    g_replayGameMenuMap.insert(pair<size_t, string>(0, g_menuEntryString_replayGame_forward));
    g_replayGameMenuMap.insert(pair<size_t, string>(1, g_menuEntryString_replayGame_backward));
    g_replayGameMenuMap.insert(pair<size_t, string>(2, g_menuEntryString_replayGame_jumpToBeginning));
    g_replayGameMenuMap.insert(pair<size_t, string>(3, g_menuEntryString_replayGame_jumpToEnd));
    g_replayGameMenuMap.insert(pair<size_t, string>(4, g_menuEntryString_replayGame_exit));
  }
}

map<size_t, string> Gui::GetReplayGameMenuMap(){
  InitReplayGameMenu();
  return g_replayGameMenuMap;
}


  // Show menu functions

void Gui::ShowMainMenu(){

  while (true) {

    pair<size_t, string> selection = ShowNumericSelectionDialog("Main menu:", GetMainMenuMap());

    if (selection.second == g_menuEntryString_main_gameInstructions){
     Gui::ShowInstructionGameMenu();
    }else if(selection.second == g_menuEntryString_main_startNewGame){
      Gui::ShowStartGameMenu();
    }else if(selection.second == g_menuEntryString_main_loadGame){
      Gui::ShowLoadGameMenu();
    }else if(selection.second == g_menuEntryString_main_exit){
      Gui::ShowExitGameMenu();
    }
  }

}

void Gui::ShowStartGameMenu(){

  pair<size_t, string> selection = ShowNumericSelectionDialog("Choose the color you want to play with", GetStartGameMenuMap());

  PlayerColor playerColor;
  if (selection.second == g_menuEntryString_startGame_white){
    playerColor = PlayerColor::WHITE;
    cout << "White selected" << endl;
  } else {
    playerColor = PlayerColor::BLACK;
    cout << "Black selected" << endl;
  }

  Gamestate gamestate = Gamestate();
  gamestate.SetHumanPlayer(playerColor);

  PrintSleepClear("Starting new game...");
  Gui::ShowRunningGameMenu(gamestate);

}

void Gui::ShowLoadGameMenu(){
  string inputLine;
  system("clear");
  //TODO: Get Information about displayed files
  cout << "OldFile1" << endl;
  cout << "Type in the file name you want to load" << endl;

  char a[10];
  a[10] = 0;

  std::getline(std::cin, inputLine);
  system("clear");
  cout << "Loading old game file" << endl;
  sleep(1);
  Gui::ShowReplayGameMenu();
}

void Gui::ShowRunningGameMenu(Gamestate& gamestate){

  bool exitGame = false;
  string exitCode = "0";

  while (exitGame == false) {

    if (gamestate.GetNoActionCounter() > 1) {
      gamestate.SetGameOver(true);
    }

    if (gamestate.GetGameOver() == true) {
      ShowGameOverMenu(gamestate, exitGame);
    } else if (gamestate.GetTurnOwner() == gamestate.GetHumanPlayer()) {
      ShowHumanTurnMenu(gamestate, exitGame);
    } else {
      ShowComputerTurnMenu(gamestate, exitGame);
    }

  }

  PrintSleepClear("Stopping game...");
}

void Gui::ShowHumanTurnMenu(Gamestate& gamestate, bool& exitGame){

  string exitCode = "0";

  while (1) {
    system("clear");
    PrintPlayboard(gamestate);

    vector<Move> possibleMoves = Controller::GetPossibleMovesByPhase(gamestate);
    if (possibleMoves.empty()) {
      gamestate.NoActionTurn();
      PrintSleepClear("No move possible. Continuing with next turn...", 2);
      break;
    }

    cout << "a1 - h8: place disk" << endl;
    cout << "0: Exit game" << endl;

    string inputLine;
    std::getline(std::cin, inputLine);

    if (inputLine == exitCode) {
      exitGame = true;
      break;
    }
    uint8_t moveX, moveY;
    if ( StringToMoveCoordinate(inputLine, moveX, moveY) != 0 ) {
      PrintSleepClear("Invalid input", g_invalidInputClearWaitSeconds);
      continue;
    }



    Move newMove = Move();

    if ( Controller::SetMoveFromVectorByCoordinates(newMove, possibleMoves, moveX, moveY) != 0 ) {
      PrintSleepClear("Invalid move", g_invalidInputClearWaitSeconds);
      continue;
    }

    gamestate.ApplyMove(newMove);
    gamestate.WriteFile();
    break;
  }

}

void Gui::ShowComputerTurnMenu(Gamestate& gamestate, bool& exitGame){
    string exitCode = "0";

    while (1) {

      pair<size_t, string> selection = ShowNumericSelectionDialog(GetPlayboardRender(gamestate).str(), GetComputerTurnMenuMap());

      if (selection.second == g_menuEntryString_computerTurn_exit){
        exitGame = true;
        break;
      } else if (selection.second == g_menuEntryString_computerTurn_playTurn) {
        size_t oldTurnCounter = gamestate.GetTurnCounter();
        Controller::PlayComputerTurn(gamestate);
        if (oldTurnCounter == gamestate.GetTurnCounter()) {
          PrintSleepClear("Computer can not make a move. Continuing with next turn...", 5);
        }
        break;
      }
    }
}

void Gui::ShowGameOverMenu(Gamestate& gamestate, bool& exitGame){
  string exitCode = "0";

  while (1) {
    system("clear");
    PrintPlayboard(gamestate);
    std::cout << "Game Over" << '\n';
    cout << "0: Exit game" << endl;

    string inputLine;
    std::getline(std::cin, inputLine);

    if (inputLine == exitCode) {
      exitGame = true;
      break;
    } else {
      PrintSleepClear("Invalid input", g_invalidInputClearWaitSeconds);
    }
  }
}

void Gui::ShowReplayGameMenu(){


  pair<size_t, string> selection = ShowNumericSelectionDialog("Replay game menu", GetReplayGameMenuMap());

  // PrintPlayboardDemo();

  if (selection.second == g_menuEntryString_replayGame_forward){
    cout << "forward function is not implemented yet" << endl;
  } else if(selection.second == g_menuEntryString_replayGame_backward){
    cout << "backward function is not implemented yet" << endl;
  } else if(selection.second == g_menuEntryString_replayGame_jumpToBeginning){
    cout << "beginning function is not implemented yet" << endl;
  } else if(selection.second == g_menuEntryString_replayGame_jumpToEnd){
    cout << "end function is not implemented yet" << endl;
  } else if(selection.second == g_menuEntryString_replayGame_exit){
    cout << "Returning to main menu" << endl;
  }

  sleep(1);
  system("clear");
}

void Gui::ShowExitGameMenu(){

  pair<size_t, string> selection = ShowNumericSelectionDialog("Do you want to exit the game?", GetYesNoMenuMap());

  if (selection.second == g_menuEntryString_yesNo_yes){
   cout << "Until we see us next time player!" << endl;
   sleep(1);
   system("clear");
   exit(0);
  }
}

void Gui::ShowInstructionGameMenu(){
  string inputLine;
  system("clear");
  cout << "How to Play: \n";
  cout << "The board has number and letters assigned, to make exact coordinates for\n";
  cout << "each square. To place a disk, type in the number and letter of the quadrat\n";
  cout << "you want your disk to be placed. \n\n";
  cout << "Game preparation:\n";
  cout << "The player chooses the color he wants to play. After that the first two \n";
  cout << "disks from each player need to be placed in the middle quadrant of the\n";
  cout << "playboard. The middle quadrants of the playboard are d4, d5, e4 and e5.\n\n";
  cout << "Gameplay: \n";
  cout << "The disks shall be placed in such a way, that one or more of the \n";
  cout << "oppenent's disks are enclosed. The enclosed disks shall be in a straight\n";
  cout << "contiguous row, this can be either vertically, horizontally or diagonally \n";
  cout << "After placing a disks, the enemy disks enclosed by two of your own disks\n";
  cout << "become disks of your own color. Beware, only the disks that were enclosed\n";
  cout << "by the disk just placed become disks of your own color. If a disk is placed\n";
  cout << "in such a way that it encloses disk of the opponent in several directions\n";
  cout << "at the same time, all these disks become disks of the own color. If a \n";
  cout << "player can't make a valid move, it is the oppenents turn. If the oppenent\n";
  cout << "also can't make a valid move, the game ends. After the game ends, a winner\n";
  cout << "is determined. The winner is the player with the most disks on the playfield.\n";
  cout << "If there are even disks, the player which disks are black is the winner.\n\n";
  cout << "0: Exit game instruction" << endl;
  std::getline(std::cin, inputLine);
  if(inputLine=="0"){
    Gui::ShowMainMenu();
  }
  Gui::ShowInstructionGameMenu();
}
