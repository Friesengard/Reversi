#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <vector>
#include <cstdint>

#include "PlayerColor.hpp"

class Move;
class Gamestate;
class Playboard;

class Controller {
public:

  /** @brief Returns a vector containing all possible Moves for a given gamestate.
  *
  *  Creates a vector of all possible Moves for the player who is turn owner.
  *
  *  @parm gamestate a constant reference to the gamestate.
  *  @return vector of all possible Moves of the turn owner.
  */
  static std::vector<Move> GetPossibleMoves(const Gamestate& gamestate);


  //TODO: add description
  static void CopyTempBoardToFlipBoard(const Gamestate& gamestate,char board[8][8], Move& move);


  //TODO: add description
  static size_t CountColumnFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move);


  //TODO: add description
  static size_t CountRowFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move);


  //TODO: add description
  static size_t CountRightDiagonalFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move);


  //TODO: add description
  static size_t CountLeftDiagonalFlipsAndSetMoveFlipBoard(const Gamestate& gamestate, size_t i, size_t j, Move& move);


  //TODO: add description
  static std::vector<Move> GetPossibleStartMoves(const Gamestate& gamestate);

  //TODO: add description
  static std::vector<Move> GetPossibleMovesByPhase(const Gamestate& gamestate);

  //TODO: add description
  static int SetMoveFromVectorByCoordinates(Move& move, const std::vector<Move>& moves, const uint8_t& moveX, const uint8_t& moveY);

  /** @brief Plays out the computer turn and applies it to the gamestate.
  *
  *  Gets a vector of all possible Moves and selects the Move with the highest number of disks it will flip.
  *  Applies the Move to the gamestate.
  *
  *  @parm gamestate a reference to the gamestate.
  *  @return Void.
  */
  static void PlayComputerTurn(Gamestate& gamestate);

  /** @brief Returns the number of flips present in a flip board.
  *
  *
  *  @parm flipPlayboard a constant reference to the flip board belonging to a Move.
  *  @return uint8_t number of flips.
  */
  static uint8_t CountFlipsOnFlipboard(const Playboard& flipPlayboard);



  /** @brief Returns the best Move from a given vector of Moves.
  *
  *  Finds the Move which will result in the most flips.
  *  If more than one Move will result in the maximum amount of flips, the first Move is selected.
  *
  *  @parm vector<Move> a constant reference to the vector containing the Moves.
  *  @return Move copy of the selected Move.
  */
  static Move GetBestMove(const std::vector<Move>& possibleMoves);


  /** @brief Returns the number of disks of the given PlayerColor on the playboard.
  *
  *  @parm playboard a constant reference to the playboard.
  *  @parm playerColor the color to count.
  *  @return the number of disks.
  */
  static uint8_t CountDisks(const Playboard& playboard, PlayerColor playerColor);


  /** @brief Returns the winner of a given gamestate as PlayerColor.
  *
  * Counts all disks on the playboard. The player with most disks wins.
  * If equal the default color (=black) will win.
  *
  *  @parm gamestate a constant reference to the gamestate.
  *  @return the winner as PlayerColor.
  */
  static PlayerColor DetermineWinner(const Gamestate& gamestate);


  /** @brief Creates a new gamestate object.
  *
  *  Creates a new gamestate object and calls the functions to create a gamestate file.
  *
  *  @return Void.
  */
  static void CreateNewGame();


  /** @brief Creates a new gamestate object from an existing gamestate and resets .
  *
  *  Creates a new gamestate object and calls the functions to create a gamestate file.
  *
  *  @parm gamestate a constant reference to the gamestate.
  *  @parm turnNumber the turn to which the game will be resetted.
  *  @return the new gamestate.
  */
  static Gamestate CreateNewGameFromReplay(const Gamestate& gamestate, size_t turnNumber);


  /** @brief Checks if a given Move is in the given vector of Moves.
  *
  *  Checks if a given Move is in the given vector of Moves by comparing the coordinates and the player color of the Move objects.
  *
  *  @return boolean if the Move is in the vector.
  */
  static bool CheckIfMoveInVector(const Move& move, const std::vector<Move>& moveVector);
};

#endif
