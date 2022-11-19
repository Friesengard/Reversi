#ifndef MOVE_HPP
#define MOVE_HPP

#include <cstdint>

#include "PlayerColor.hpp"
#include "Playboard.hpp"

class Move {
public:

  Move(){};

  Move(uint8_t targetX, uint8_t targetY){
    m_targetX = targetX;
    m_targetY = targetY;
  };



  // Getter & Setter
  uint8_t GetTargetX() const {return m_targetX;}
  void SetTargetX(uint8_t targetX) {m_targetX = targetX;}

  uint8_t GetTargetY() const {return m_targetY;}
  void SetTargetY(uint8_t targetY) {m_targetY = targetY;}

  PlayerColor GetPlayerColor() const {return m_playerColor;}
  void SetPlayerColor(PlayerColor playerColor) {m_playerColor = playerColor;}

  Playboard GetFlipPlayboard() const {return m_flipPlayboard;}
  void SetFlipPlayboard(Playboard flipPlayboard) {m_flipPlayboard = flipPlayboard;}


  void SetFlipBoardField(size_t i, size_t j, char turnOwner){m_flipPlayboard.fields[i][j] = turnOwner;};

private:

  /**
   * X coordinate between 0 and 7.
   */
  uint8_t m_targetX;

  /**
   * Y coordinate between 0 and 7.
   */
  uint8_t m_targetY;

  /**
   * The player color doing the move.
   */
  PlayerColor m_playerColor;

  /**
   * A Playboard with only the fields which would be flipped by this move set to the color they would be flipped to.
   */
  Playboard m_flipPlayboard;

};

#endif
