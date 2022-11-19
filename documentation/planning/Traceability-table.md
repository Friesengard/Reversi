# Traceability table   

[[_TOC_]]

## Introduction  
This document provides the Traceabilty-table of a) Stakeholder Needs and Use Cases and b) System Requirements and Stakeholder Needs of the **Reversi system**.

## Stakeholder Needs and Use Cases 
| Name  | Open game instruction | Start new game | Play game | Load old game | Replay old game | Save game | Exit |
| ----------|----------| ----------|----------| ----------|  ----------|  ----------| ----------|
| Use terminal as GUI  |x|x|x|x|x| | |
| Play Reversi versus KI  | | |x| | | | |
| Limit function size  | | |  | | | | |
| Write human readable save file  | | |  | | |x| |
| Continue old game | | |x|x|x| | |
| Manage via Github  | | | | | | | |
| Use text based inputs and outputs  |x|x|x|x|x| | |
| Run software on Linux  | | | | | | | |
| Use explicit parameters  | | |  | | | | |
| Replay old game  | | |x|x|x| | |
| Use MarkDown-format  | | | | | | | |
| Use Doxygen-Style  | | | | | | | |
| Use C++  | | |  | | | | |
| Use English | | |  | | | | |
| Save moves  | | | | | |x| |

## System Requirements and Stakehoder Needs

|                                    | Use terminal as GUI | Play Reversi versus KI | Limit function size | Write human readable safe file | Continue old game | Manage via Github | Use text based inputs and outputs | Run software on Linux | Use explicit parameters | Replay old game | Use MarkDown-format | Use Doxygen-Style | Use C++ | Use English | Save moves |
| ---------------------------------- | ------------------- | ---------------------- | ------------------- | ------------------------------ | ----------------- | ----------------- | --------------------------------- | --------------------- | ----------------------- | --------------- | ------------------- | ----------------- | ------- | ----------- | ---------- |
| Define human readable save file    |                     |                        |                     | x                              |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Calculate best KI move             |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Use txt format                     |                     |                        |                     | x                              |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Retake turn                        |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Create unique savefile             |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Use explicit function parameters   |                     |                        |                     |                                |                   |                   |                                   |                       | x                       |                 |                     |                   |         |             |            |
| Duplicate save file                |                     |                        |                     |                                | x                 |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Exit replay                        |                     |                        |                     |                                |                   |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Jump to game end                   |                     |                        |                     |                                |                   |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Overide current board cycle        |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Define board                       |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define moves in safe file          |                     |                        |                     | x                              |                   |                   |                                   |                       |                         |                 |                     |                   |         |             | x          |
| Reload old game                    |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Use English                        |                     |                        |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         | x           |            |
| Choose color                       |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define winner in safe file         |                     |                        |                     | x                              | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Turn first disks                   |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Display instructions               |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define current board in save file  |                     |                        |                     | x                              | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Control replay                     |                     |                        |                     |                                |                   |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Save current board                 |                     |                        |                     | x                              | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Display empty box on board         | x                   |                        |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             | x          |
| Save all moves                     |                     |                        |                     | x                              | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Specify color usage                |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Display board                      | x                   | x                      |                     |                                |                   |                   | x                                 |                       |                         |                 |                     |                   |         |             |            |
| Display software instructions      | x                   | x                      |                     |                                |                   |                   | x                                 |                       |                         |                 |                     |                   |         |             |            |
| Name savefile                      |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Define color usage in save file    |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Line up saved moves                |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Start game from old game           |                     |                        |                     |                                | x                 |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define disks                       |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Use MarkDown-Format                |                     |                        |                     |                                |                   |                   |                                   |                       |                         |                 | x                   |                   |         |             |            |
| Define who is in turn in save file |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Display invalid user move          | x                   | x                      |                     |                                |                   |                   | x                                 |                       |                         |                 |                     |                   |         |             |            |
| Save color association             |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Jump to game beginning             |                     |                        |                     |                                |                   |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Choose players turn                |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define starting quadrant           |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Replay game forward                |                     |                        |                     |                                |                   |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Use winning rule                   |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Calculate best move                |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Use finish rule                    |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define flip rule one               |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define flip rule two               |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Run on Linux                       |                     |                        |                     |                                |                   |                   |                                   | x                     |                         |                 |                     |                   |         |             |            |
| Display result                     | x                   | x                      |                     |                                |                   |                   | x                                 |                       |                         |                 |                     |                   |         |             |            |
| Define black                       |                     |                        |                     |                                |                   |                   | x                                 |                       |                         |                 |                     |                   |         |             | x          |
| Decide winner                      |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Save result                        |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Save turn belonging                |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Use text based interface           | x                   |                        |                     |                                |                   |                   | x                                 |                       |                         |                 |                     |                   |         |             |            |
| Validate user move                 |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Save startposition                 |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Save move cycle                    |                     |                        |                     |                                | x                 |                   |                                   |                       |                         |                 |                     |                   |         |             | x          |
| Save who is in turn cycle          |                     |                        |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             | x          |
| Delay KI move                      |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define flip rule three             |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Use C++                            |                     |                        |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   | x       |             |            |
| Replay game backward               |                     |                        |                     |                                |                   |                   |                                   |                       |                         | x               |                     |                   |         |             |            |
| Find valid KI move                 |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define validity rule two           |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Limit function size                |                     |                        | x                   |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define validity rule one           |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Use draw rule                      |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Display players turn               | x                   |                        |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Place first disks                  |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |
| Define start board in save file    |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Define white                       | x                   |                        |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             | x          |
| Use Doxygen-Style                  |                     |                        |                     |                                |                   |                   |                                   |                       |                         |                 |                     | x                 |         |             |            |
| Define game status in save file    |                     |                        |                     |                                | x                 |                   |                                   |                       |                         | x               |                     |                   |         |             | x          |
| Use Ravensburger rule              |                     | x                      |                     |                                |                   |                   |                                   |                       |                         |                 |                     |                   |         |             |            |