# Development

---
##Week 1

####**04-18-20**
- Cloned final project and CinderBlock
- [x] Need to add block to project

#### **04-19-20**
- Converted CMake file from XML to .cmake by referring to [Cmake Guide](https://courses.grainger.illinois.edu/cs126/sp2020/notes/cmake/)'s
case studies.
- Started playing around with the cinder::app and cinder::gl commands.
- [x] Need to test header files to see if they come up
- [ ] Need write code to show that the library is in fact connected and working

#### **04-20-20**
- All header files were showing up
- Wrote some code to test the functions of the library implemented but did not run
- [x] Need to figure out how to make a MIDI listener

#### **04-21-20**
- Tried implementing the listener again and finally got it to run
- Tried connecting my keyboard to my program but wasn't able to get the code to find the correct
[MIDI port](https://support.apple.com/en-gb/HT201840)
- Kept trying different ways to try and get my code to recognise my device, but did not work. Feel like I need to pivot now...
- Need to speak to CA to figure out if it's allowed (GONNA MISS THE DEADLINE THIS WEEK THOUGH)

---
##Week 2

#### **04-22-20**
- Tried getting into the Queue for over 13 hours, but was not able to speak to a CA.
- Got a response from my Code Mod saying that I can change my project (Now need to catch up)
- [ ] Need to find new project

#### **04-23-20**
- Added new CinderBlocks and tested them

#### **04-26-20**
- Started working on the main game.
- Set up paddle, ball, engine, and player classes.
- As of now the paddle is controllable but there is no ball motion yet

#### **04-28-20**
- Added the ball
- Single row of bricks is visible
- Need to:
- [x] Add multiple rows
- [x] Setup points system
- [x] Implement lives and rounds into the engine
- [x] Game Over screen

---
##Week 3
#### **04-30-20**
- Completed basic (not to code imo) brick-breaker game (previous Week's checklist)
- [x] Need to add directional paddle rebounding
- [x] Need to fix bug in which ball ReflectsY coord when hitting a brick from the side (should ReflectX)

#### **05-01-20**
- Added directional paddle rebounding
- Updated proposal as adding power-ups seems too far-fetched as of now (will add a leader-board instead)

#### **05-04-20**
- Imported SQL libraries to work on the leader-board
- **BUG**: leaderboard.* files were unable to access the sql headers for some reason
- [x] Need to check how to reimport headers properly

#### **05-01-20**
- Fixed improper import (Had to add library to src's cmake file)
- Added an All-Time leader-board as well as an Individual leader-board

#### **06-01-20**
- Fixed bug so that ball now reflects across the correct axis