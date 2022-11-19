#include "Playboard.hpp"

#include "Gamestate.hpp"

#include <stdio.h>

void Playboard::Init(){
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      fields[i][j] = Gamestate::EMPTY_MARKER;
    }
  }
}

void Playboard::ClearField(uint8_t TargetX, uint8_t TargetY){
  if (TargetX > 7 || TargetY > 7) {
    /* code */
    printf("ERROR: ClearField(): parameters out of range\n");
  }
  fields[TargetX][TargetY] = Gamestate::EMPTY_MARKER;
}

void Playboard::ApplyFlipPlayboard(const Playboard& flipPlayboard){
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      if (flipPlayboard.fields[i][j] == 'w') {
        this->fields[i][j] = 'w';
      } else if(flipPlayboard.fields[i][j] == 'b'){
        this->fields[i][j] = 'b';
      }
    }
  }
}

void Playboard::InversePlayboard(){
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      if (this->fields[i][j] == 'w') {
        this->fields[i][j] = 'b';
      } else if(this->fields[i][j] == 'b'){
        this->fields[i][j] = 'w';
      }
    }
  }
}
