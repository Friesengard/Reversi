#include "Gamestate.hpp"

void Gamestate::ToggleTurnOwner(){
  if (this->m_turnOwner == PlayerColor::WHITE) {
    this->m_turnOwner = PlayerColor::BLACK;
  } else if(this->m_turnOwner == PlayerColor::BLACK) {
    this->m_turnOwner = PlayerColor::WHITE;
  } else {
    printf("Error: Gamestate has no turn owner\n");
    exit(1);
  }
}


void Gamestate::ApplyMove(const Move& move){

  // Increment turn counter
  this->m_turnCounter++;

  this->ToggleTurnOwner();

  // Add move to move history
  this->m_moveHistory.push_back(move);

  // Set disk on playboard
  char token;
  if (move.GetPlayerColor() == PlayerColor::WHITE) {
    token = Gamestate::WHITE_MARKER;
  } else {
    token = Gamestate::BLACK_MARKER;
  }
  this->m_playboard.fields[move.GetTargetX()][move.GetTargetY()] = token;

  // Apply flip playboard
  Playboard flipPlayboard = move.GetFlipPlayboard();
  this->m_playboard.ApplyFlipPlayboard(flipPlayboard);

  this->WriteFile();
}


void Gamestate::ApplyMoveFromHistory(){
  Move move = this->m_moveHistory.at(this->m_turnCounter);
  this->ApplyMove(move);
}


void Gamestate::StepBackMove(){

    // Decrease turn counter
    this->m_turnCounter--;

    Move move = this->m_moveHistory.at(this->m_turnCounter);

    // Change turn owner
    this->m_turnOwner = move.GetPlayerColor();

    // Revert disks flipped
    Playboard flipPlayboard = move.GetFlipPlayboard();
    flipPlayboard.InversePlayboard();
    m_playboard.ApplyFlipPlayboard(flipPlayboard);

    // Revert disk placed
    m_playboard.ClearField(move.GetTargetX(), move.GetTargetY());
}

void Gamestate::NoActionTurn(){
  ToggleTurnOwner();
  m_noActionCounter++;
}

void Gamestate::CreateFile() const{
  //TODO
}


void Gamestate::WriteFile() const{
  //TODO
}


void Gamestate::LoadFromFile(){
  //TODO
}


void Gamestate::AppendMoveToFile() const{
  //TODO
}
