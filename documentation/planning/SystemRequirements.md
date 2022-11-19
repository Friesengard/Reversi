---
Cameo Project Name: Reversi     
Cameo Project Version: 266  
Export Date: 26.10.2022  
---
# System Requirements report  

[[_TOC_]]

## Introduction  
This document provides the list of system requirements of the **Reversi system**. It is based on the MBSE solution domain analysis as defined in the NoMagic MagicGrid approach.  

## Requirements
<!-- [com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@48abd229, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@e28ccec3, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@3a0db128, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@c7143a51, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@74fee6d3, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@b396cd1a, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@e4ce9514, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@7ca71cfe, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@844c4ed3, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@967f05c0, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@fdaab387, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@a2a5fee7, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@15bc5eea, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@66d9f13d, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@3b00a657, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@8f720c05, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@a68aea08, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@1bcf49d0, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@436ea19b, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@113e5177, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@750e577c, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@3d81866d, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@a221eed7, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@6fc19c82, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@1505852d, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@6cf7d715, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@88358400, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@332e5a64, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@81aa5585, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@1beeb242, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@5719065d, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@c847fbb3, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@f4cee399, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@ca9c3924, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@574be3df, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@c1417258, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@9c28f9c1, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@3df85a3d, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@76f10f6, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@5d0128ec, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@4b7960b9, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@5763605f, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@ea5bdbc6, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@7cbfe7cb, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@51551c42, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@4307b424, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@88780190, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@2986754c, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@a4a2aaab, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@647573a2, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@aba5d091, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@ad85fa41, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@7fb4431b, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@ba5e673f, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@95a037fc, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@ead5d134, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@4cc43f1b, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@3c08526a, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@c6a29363, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@357c2661, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@f8e86859, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@5df71add, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@7006c7e0, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@66776301, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@c90edbfa, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@10668442, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@2dc58a55, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@7dcff39f, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@5b8057c3, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@580afc77, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@a68c837, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@644f67cc, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@d2bf1572, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@a2c2689d, com.nomagic.uml2.ext.magicdraw.classes.mdkernel.impl.ClassImpl@f7802db5] -->
| **Number** | **Name** | **Text** |
|------------|----------|----------|
| 84 | Define human readable save file | The save file for games SHALL be human readable |
| 22 | Calculate best KI move | The KI SHALL place the next disk at the calculated best position |
| 86 | Use txt format | The save file SHALL be in the format txt |
| 69 | Retake turn | WHEN the player can’t make a valid move the other player SHALL be taking his turn |
| 14 | Create unique savefile | The game SHALL have one save file per game |
| 83 | Use explicit function parameters | The software SHALL use explicit function parameters |
| 38 | Duplicate save file | WHEN the user plays a game from a replayed game the game SHALL duplicate the information until the entry point of the turn in a new save file |
| 47 | Exit replay | The user SHALL be able to exit a replay |
| 45 | Jump to game end | The game SHALL be able to jump to the end of the game in a replay |
| 89 | Overide current board cycle | The current board save SHALL override the last current board save in every move |
| 62 | Define board | The board SHALL be a quadrant with 8x8 boxes |
| 95 | Define moves in safe file | The lines 21 and the following SHALL save moves made by user and KI |
| 39 | Reload old game | The user SHALL be able to select a game file he wants to replay |
| 78 | Use English | The software SHALL be documented in English |
| 66 | Choose color | The user SHALL decides which color he wants to play |
| 94 | Define winner in safe file | The lines 19 and 20 in the save file SHALL be dedicated to the information if the user won or not |
| 61 | Turn first disks | The rules for who is next during the starting disks SHALL be alternating between both players |
| 34 | Display instructions | The game SHALL have an option to display the game instruction |
| 88 | Define current board in save file | The lines 4 to 12 in the save file SHALL be dedicated to the current board |
| 46 | Control replay | The user SHALL be able to decide the replay function |
| 16 | Save current board | The game SHALL save the the current board after a move |
| 85 | Display empty box on board | An empty box on the board SHALL be saved and displayed with a underscore |
| 19 | Save all moves | The game SHALL save the players moves |
| 67 | Specify color usage | The user and KI SHALL be able to play only one color during a game |
| 33 | Display board | The game SHALL display the current board |
| 35 | Display software instructions | The game SHALL have an option to display how to play the game |
| 37 | Name savefile | The save file SHALL have following naming convention ‚day_month_year_hour_minute |
| 90 | Define color usage in save file | The lines 13 and 14 in the save file SHALL be dedicated to the information which color the user plays |
| 97 | Line up saved moves | The moves SHALL line up in the save file  |
| 48 | Start game from old game | WHEN the user decides to play the current position of the replay, the game SHALL be able to enter the replay in the current turn and the user starts playing from there |
| 63 | Define disks | The used disks SHALL be black and white|
| 79 | Use MarkDown-Format | The text based documentation SHALL be written in the MarkDown-Format. |
| 91 | Define who is in turn in save file  | The lines 15 and 16 in the save file SHALL be dedicated to the information if the next turn is the Users turn or not |
| 26 | Display invalid user move | WHEN the users move is not valid, the game SHALL prompt the user to make another move |
| 17 | Save color association | The game SHALL save which player is white |
| 44 | Jump to game beginning | The game SHALL be able to jump to the beginning of the game in a replay |
| 68 | Choose players turn | After a player has made a move the other player SHALL be taking his turn |
| 60 | Define starting quadrant | The starting quadrant of the board SHALL be central 4 boxes |
| 42 | Replay game forward | The game SHALL be able to replay a game forward |
| 56 | Use winning rule | The winner SHALL be the player with the most colored disks on the board |
| 54 | Calculate best move | The best calculated move for the KI SHALL be the one where the most disks are flipped |
| 58 | Use finish rule | WHEN both players can’t make a valid move the software SHALL end the game |
| 72 | Define flip rule one | After placing a disks, the enemy disks enclosed by two of your own disks SHALL become disks of your own color |
| 73 | Define flip rule two | Only the disks that were enclosed by the disk just placed SHALL become disks of your own color |
| 76 | Run on Linux | The software SHALL run on a Linux system |
| 32 | Display result | The game SHALL display the result |
| 64 | Define black | Black SHALL be saved and displayed as x |
| 55 | Decide winner | The game SHALL decide the winner after game ends |
| 20 | Save result | The game SHALL save the result |
| 18 | Save turn belonging | The game SHALL save which player turn it is |
| 81 | Use text based interface | The software SHALL use text based inputs and outputs |
| 25 | Validate user move | The game SHALL validate the users move |
| 15 | Save startposition | The game SHALL save the startposition in a save file |
| 96 | Save move cycle | Each move SHALL be saved after every turn |
| 92 | Save who is in turn cycle | The information who is in turn SHALL be saved after every turn |
| 24 | Delay KI move | The KI SHALL place the disk after a 3 seconds |
| 74 | Define flip rule three | If a disk is placed in such a way that it encloses disk of the opponent in several directions at the same time, all these disks SHALL become disks of the own color |
| 75 | Use C++ | The software SHALL be implemented in C++ |
| 43 | Replay game backward | The game SHALL be able to replay a game backward |
| 23 | Find valid KI move | The KI SHALL place only valid moves |
| 71 | Define validity rule two | The enclosed disks SHALL be in a straight contiguous row, this can be either vertically, horizontally or diagonally |
| 80 | Limit function size | All software functions SHALL be limited to a maximum of 20 lines |
| 70 | Define validity rule one | The disks SHALL be placed in such a way that one or more of the opponent's disks are enclosed |
| 57 | Use draw rule | WHEN there is a draw the player with the black disks SHALL be the winner |
| 31 | Display players turn | The game SHALL display who’s turn it is |
| 59 | Place first disks | The first 4 placed disks by the players SHALL be only placed in the starting quadrant of the board |
| 87 | Define start board in save file | The first three lines in the save file SHALL be dedicated to the start board |
| 65 | Define white | White SHALL be saved and display as o |
| 77 | Use Doxygen-Style | The software SHALL be documented in Doxygen-Style |
| 93 | Define game status in save file | The lines 17 and 18 in the save file SHALL be dedicated to the information if the game is over or not |
| 53 | Use Ravensburger rule | The game SHALL implement the Ravensburger rules |

