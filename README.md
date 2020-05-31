# Brick Breaker

###Author: Adit Kapoor

---
### Description
I have made a [Brick Breaker](https://en.wikipedia.org/wiki/Brick_Breaker) game - one of the all time Atari classics.
As you clear all the bricks on a particular round, the game becomes slightly harder to challenge you gamers.

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.
---
###Dependancies Used:
- [CMake](https://cmake.org/)
- [MSVC 2015](https://my.visualstudio.com/Downloads?q=visual%20studio%202015&wt.mc_id=o%7Emsft%7Evscom%7Eolder-downloads)
 *(for MSW based systems)*

###Libraries Used:
- [Cinder](https://libcinder.org/)
- [ciAnimatedGif](https://github.com/cwhitney/ciAnimatedGif) (CinderBlock)
- [Cinder-SoundPlayer](https://github.com/redpaperheart/Cinder-SoundPlayer) (CinderBlock)
- [SqliteModernCpp](https://github.com/SqliteModernCpp/sqlite_modern_cpp)
- [Gflags](https://github.com/gflags/gflags)
---
####ow to Build the Project:
1. [Download](https://libcinder.org/download) and install Cinder *(you can find a tutorial
[here](https://courses.grainger.illinois.edu/cs126/sp2020/assignments/snake/))*
2. Add all required code to the CMake files for both the
[SqliteModernCpp](https://github.com/SqliteModernCpp/sqlite_modern_cpp) library as well as the
[Gflags](https://github.com/gflags/gflags) library
3. Download the CinderBlocks, place them into your *~/Cinder/Blocks* folder and follow the cinderblock.xml file found
in the downloaded code to set up the blocks for your own use
---
###Controls:
Key  | Action
------------- | -------------
Left Arrow / A Key | Move the paddle left
Right Arrow / D Key | Move the paddle right
M Key | Mute/unmute the background music
Return Key | Start the game
