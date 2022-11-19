#include "Controller.hpp"

#include "Gamestate.hpp"


using namespace std;

char GetCharTurnOwner(const Gamestate& gamestate){
  if(gamestate.GetTurnOwner() == PlayerColor::WHITE) return Gamestate::WHITE_MARKER;
  if(gamestate.GetTurnOwner() == PlayerColor::BLACK) return Gamestate::BLACK_MARKER;
}

char GetCharNotTurnOwner(const Gamestate& gamestate){
  if(gamestate.GetTurnOwner() == PlayerColor::WHITE) return Gamestate::BLACK_MARKER;
  if(gamestate.GetTurnOwner() == PlayerColor::BLACK) return Gamestate::WHITE_MARKER;
}

void Controller::CopyTempBoardToFlipBoard(const Gamestate& gamestate,char board[8][8], Move& move){
  char cTurnOwner = GetCharTurnOwner(gamestate);
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(board[i][j] == cTurnOwner) {
        move.SetFlipBoardField(i,j,cTurnOwner);
      }
    }
  }
}

size_t Controller::CountColumnFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move){
  int  count = 0, tmpCount = 0, mem = i;
  Playboard tmpBoard;
  char cTurnOwner = GetCharTurnOwner(gamestate), cNotTurnOwner = GetCharNotTurnOwner(gamestate);
  for(++i;i < 7; i++){
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner) break;
    tmpCount++;
    tmpBoard.fields[i][j] = cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate,tmpBoard.fields, move);
  }
  i = mem;
  tmpCount = 0;
  tmpBoard.Init();
  for(--i; i > 0; i--){
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner)break;
    tmpCount++;
    tmpBoard.fields[i][j] = cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate, tmpBoard.fields, move);
  }
  return count;
}

size_t Controller::CountRowFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move){
  int  count = 0, tmpCount = 0, mem = j;
  Playboard tmpBoard;
  char cTurnOwner = GetCharTurnOwner(gamestate), cNotTurnOwner = GetCharNotTurnOwner(gamestate);
  for(++j;j < 7; j++){
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner) break;
    tmpCount++;
    tmpBoard.fields[i][j] = cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate,tmpBoard.fields, move);
  }
  j = mem;
  tmpCount = 0;
  tmpBoard.Init();
  for(--j; j > 0; j--){
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner)break;
    tmpCount++;
    tmpBoard.fields[i][j] = cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate,tmpBoard.fields, move);
  }
  return count;
}

size_t Controller::CountRightDiagonalFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move){
  int count = 0, tmpCount = 0, mem_i = i, mem_j = j;
  Playboard tmpBoard;
  char cTurnOwner = GetCharTurnOwner(gamestate), cNotTurnOwner = GetCharNotTurnOwner(gamestate);;
  while(i < 7 && j < 7){ // rechts unten
    i++;j++;
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner) break;
    tmpCount++;
    tmpBoard.fields[i][j] = cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate,tmpBoard.fields, move);
  }
  i = mem_i;
  j = mem_j;
  tmpCount = 0;
  tmpBoard.Init();
  while(i > 0 && j < 7){ // rechts oben
    i--;j++;
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner) break;
    tmpCount++;
    tmpBoard.fields[i][j] = cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate,tmpBoard.fields, move);
  }
  return count;
}

size_t Controller::CountLeftDiagonalFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move){
  int count = 0, tmpCount = 0, mem_i = i, mem_j = j;
  Playboard tmpBoard;
  char cTurnOwner = GetCharTurnOwner(gamestate), cNotTurnOwner = GetCharNotTurnOwner(gamestate);
  while(i < 7 && j > 0){ // links unten
      i++;j--;
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner) break;
    tmpCount++;
    tmpBoard.fields[i][j] = cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate,tmpBoard.fields, move);
  }
  i = mem_i;j = mem_j;
  tmpCount = 0;
  tmpBoard.Init();
  while(i > 0 && j > 0){ // links oben
    i--;j--;
    if(gamestate.GetPlayboard().fields[i][j] != cNotTurnOwner) break;
    tmpCount++;
    tmpBoard.fields[i][j]= cTurnOwner;
  }
  if(gamestate.GetPlayboard().fields[i][j] == cTurnOwner && tmpCount > 0) {
    count += tmpCount;
    CopyTempBoardToFlipBoard(gamestate,tmpBoard.fields, move);
  }
  return count;
}

vector<Move> Controller::GetPossibleMoves(const Gamestate& gamestate){
  int possibleDisksFlipped;
  vector<Move> possibleMoves;
  Playboard tmpBoard;
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      if(gamestate.GetPlayboard().fields[i][j] == ' '){

        Move newMove;
        possibleDisksFlipped = 0;
        possibleDisksFlipped += CountColumnFlipsAndSetMoveFlipBoard(gamestate,i,j,newMove);
        possibleDisksFlipped += CountRowFlipsAndSetMoveFlipBoard(gamestate,i,j,newMove);
        possibleDisksFlipped += CountRightDiagonalFlipsAndSetMoveFlipBoard(gamestate,i,j,newMove);
        possibleDisksFlipped += CountLeftDiagonalFlipsAndSetMoveFlipBoard(gamestate,i,j,newMove);
        if(possibleDisksFlipped > 0){


          newMove.SetTargetX(i);
          newMove.SetTargetY(j);
          newMove.SetPlayerColor(gamestate.GetTurnOwner());
          //newMove.setDisksToBeFlipped(possibleDisksFlipped);
          possibleMoves.push_back(newMove);
        }
      }

    }
  }
  return possibleMoves;
}

vector<Move> Controller::GetPossibleStartMoves(const Gamestate& gamestate){

  vector<Move> possibleMoves;
  Playboard playboard = gamestate.GetPlayboard();

  for (size_t i = 3; i < 5; i++) {
    for (size_t j = 3; j < 5; j++) {
      if (playboard.fields[i][j] == Gamestate::EMPTY_MARKER) {
        Move move = Move(i,j);

        move.SetPlayerColor(gamestate.GetTurnOwner());
        possibleMoves.push_back(move);
      }
    }
  }

  return possibleMoves;
}

vector<Move> Controller::GetPossibleMovesByPhase(const Gamestate& gamestate){
  if (gamestate.GetTurnCounter() < 4) {
    return GetPossibleStartMoves(gamestate);
  } else {
    return GetPossibleMoves(gamestate);
  }
}

void Controller::PlayComputerTurn(Gamestate& gamestate){

  vector<Move> possibleMoves = GetPossibleMovesByPhase(gamestate);

  if (possibleMoves.empty()) {
    gamestate.NoActionTurn();
  } else {
    Move bestMove = GetBestMove(possibleMoves);
    gamestate.ApplyMove(bestMove);
    gamestate.WriteFile();
  }

}

int Controller::SetMoveFromVectorByCoordinates(Move& move, const vector<Move>& moves, const uint8_t& moveX, const uint8_t& moveY){

  int result = -1;
  for (vector<Move>::const_iterator it = moves.begin(); it != moves.end(); it++) {
    Move moveInList = (*it);
    if (moveInList.GetTargetX() == moveX && moveInList.GetTargetY() == moveY) {
      move = moveInList;
      result = 0;
    }
  }

  return result;
}

Move Controller::GetBestMove(const vector<Move>& possibleMoves){

  uint8_t biggestFlip = 0;
  size_t biggestFlipIndex = 0;

  size_t index = 0;
  for (vector<Move>::const_iterator it = possibleMoves.begin(); it != possibleMoves.end(); it++) {
    Move move = (*it);
    uint8_t flips = CountFlipsOnFlipboard(move.GetFlipPlayboard());
    if (flips > biggestFlip) {
      biggestFlip = flips;
      biggestFlipIndex = index;
    }
  }

  Move biggestFlipMove = possibleMoves.at(biggestFlipIndex);

  return biggestFlipMove;
}

uint8_t Controller::CountDisks(const Playboard& playboard, PlayerColor playerColor){
  uint8_t whiteDisks = 0;
  uint8_t blackDisks = 0;
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      if (playboard.fields[i][j] == Gamestate::WHITE_MARKER) {
        whiteDisks++;
      } else if(playboard.fields[i][j] == Gamestate::BLACK_MARKER){
        blackDisks++;
      }
    }
  }

  if (playerColor == PlayerColor::WHITE) {
    return whiteDisks;
  } else {
    return blackDisks;
  }
}

uint8_t Controller::CountFlipsOnFlipboard(const Playboard& flipPlayboard){

  uint8_t disksToBeFlipped = 0;
  uint8_t whiteDisks = CountDisks(flipPlayboard, PlayerColor::WHITE);
  uint8_t blackDisks = CountDisks(flipPlayboard, PlayerColor::BLACK);

  if (whiteDisks > 0 && blackDisks == 0) {
    disksToBeFlipped = whiteDisks;
  } else if (blackDisks > 0 && whiteDisks == 0) {
    disksToBeFlipped = blackDisks;
  } else if(blackDisks == 0 && whiteDisks == 0) {
    disksToBeFlipped = 0;
  } else {
    printf("ERROR: Invalid flip playboard.\n");
    exit(1);
  }

  return disksToBeFlipped;
}

PlayerColor Controller::DetermineWinner(const Gamestate& gamestate){
  Playboard playboard = gamestate.GetPlayboard();
  uint8_t whiteDisks = CountDisks(playboard, PlayerColor::WHITE);
  uint8_t blackDisks = CountDisks(playboard, PlayerColor::BLACK);

  PlayerColor winner;
  PlayerColor defaultWinner = PlayerColor::BLACK;

  if (whiteDisks>blackDisks) {
    winner = PlayerColor::WHITE;
  } else if (whiteDisks<blackDisks){
    winner = PlayerColor::WHITE;
  } else {
    winner = defaultWinner;
  }

  return winner;

}

void Controller::CreateNewGame(){
  //TODO
}

Gamestate Controller::CreateNewGameFromReplay(const Gamestate& gamestate, size_t turnNumber){
  //TODO
}
