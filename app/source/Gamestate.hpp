#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <vector>
#include <string>

#include "Move.hpp"
#include "Playboard.hpp"

class Gamestate {
public:

  static const char WHITE_MARKER = 'w';
  static const char BLACK_MARKER = 'b';
  static const char EMPTY_MARKER = ' ';

Gamestate() {
  m_turnOwner = PlayerColor::WHITE;
}

// Getter & Setter
Playboard GetPlayboard() const {return m_playboard;}
void SetPlayboard(Playboard playboard) {m_playboard = playboard;}

PlayerColor GetHumanPlayer() const {return m_humanPlayer;}
void SetHumanPlayer(PlayerColor humanPlayer){m_humanPlayer = humanPlayer;}

PlayerColor GetTurnOwner() const {return m_turnOwner;}
void SetTurnOwner(PlayerColor turnOwner){m_turnOwner = turnOwner;}

size_t GetTurnCounter() const {return m_turnCounter;}

bool GetGameOver() const {return m_gameOver;}
void SetGameOver(bool gameOver){m_gameOver = gameOver;}

size_t GetNoActionCounter(){return m_noActionCounter;}


/** @brief Toggles the turn owner to the opposite color.
*
*  @return Void.
*/
void ToggleTurnOwner();

/** @brief Changes the gamestate according to the move.
*
* Changes the turn owner and increments the turn counter.
* Adds the move to the move history.
* Updates the playboard.
* Calls function to write the game file.
*
*  @parm move a constant reference to the move that will be applied to the gamestate.
*  @return Void.
*/
void ApplyMove(const Move& move);


/** @brief Reverts the last move.
*
* Decrements the turn counter.
* Reads previous move from move history and reverts changes to the playboard.
* Change the turnOwner to the player who made the move.
*
*  @return Void.
*/
void StepBackMove();


/** @brief Applies the next move from the move history to the gamestate.
*
*  @return Void.
*/
void ApplyMoveFromHistory();


// /** @brief Resets the gamestate and applies all moves up to the given turn number.
// *
// * Changes the turn owner and increments the turn counter.
// * Adds the move to the move history.
// * Updates the playboard.
// * Calls function to write the game file.
// *
// *  @parm turnNumber number of the turn to which the gamestate will be resetted.
// *  @return Void.
// */
// void ResetGamestateToTurnNumber(size_t turnNumber);


/** @brief Creates a new gamestate file.
*
*  Create new file named with a time tag.
*  Set m_filePath
*
*  @return Void.
*/
void CreateFile() const;


/** @brief Writes the entire gamestate to the game file.
*
*  Overwrites the existing gamefile
*
*  @return Void.
*/
void WriteFile() const;

/** @brief Loads the entire gamestate from the game file.
*
*  @return Void.
*/
void LoadFromFile();

/** @brief Appends one move to the game file.
*
*  @return Void.
*/
void AppendMoveToFile() const;

/** @brief Applies a no action turn to the gamestate.
*
*  Toggle turn owner.
*  Increase no action counter.
*
*  @return Void.
*/
void NoActionTurn();

private:

  PlayerColor m_humanPlayer;
  PlayerColor m_turnOwner;
  size_t m_turnCounter = 0;
  Playboard m_playboard;
  Playboard m_startPlayboard;
  bool m_gameOver = false;
  std::vector<Move> m_moveHistory;
  std::string m_filePath;

  size_t m_noActionCounter = 0;

};

#endif
