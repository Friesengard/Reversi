#ifndef PLAYBOARD_HPP
#define PLAYBOARD_HPP

#include <cstdint>
#include <stdlib.h>

class Playboard {

public:

  Playboard(){
    Init();
  }
    /**
   * fields[X][Y].
   * valid values are: Gamestate::WHITE_MARKER, Gamestate::BLACK_MARKER and Gamestate::EMPTY_MARKER.
   */
  char fields[8][8];

  /** @brief Initializes the a playboard array with Gamestate::EMPTY_MARKER.
  *
  *  @return Void.
  */
  void Init();

  /** @brief Set field to Gamestate::EMPTY_MARKER.
  *
  *  @return Void.
  */
  void ClearField(uint8_t TargetX, uint8_t TargetY);

  /** @brief Set the disks present in the flipPlayboard to the playboard.
  *
  *  @return Void.
  */
  void ApplyFlipPlayboard(const Playboard& flipPlayboard);

  /** @brief Flip all disks.
  *
  *  @return Void.
  */
  void InversePlayboard();

};

#endif
