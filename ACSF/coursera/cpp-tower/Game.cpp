/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  // Prints out the state of the game:
  // cout << *this << endl;

  // @TODO -- Finish solving the game!
  // solution 1
  // while (stacks_[2].size() != 4)
  // {
  //   pattern(0, 1);
  //   cout << *this << endl;
  //   pattern(0, 2);
  //   cout << *this << endl;
  //   pattern(1, 2);
  //   cout << *this << endl;
  // }

  // solution 2
  move(0, stacks_[0].size() - 1, stacks_[0], stacks_[1], stacks_[2]);
}

void Game::move(uint16_t begin, uint16_t end, Stack &source, Stack &spare, Stack &target)
{
  if (begin == end)
  {
    target.push_back(source.removeTop());
    cout << *this << endl;
  }
  else
  {
    move(begin + 1, end  , source, target, spare);
    move(begin    , begin, source, spare , target);
    move(begin + 1, end  , spare , source, target);
  }
}

void Game::pattern(uint8_t idx1, uint8_t idx2)
{
  if (stacks_[idx1].size() > 0 && stacks_[idx2].size() == 0) {
    stacks_[idx2].push_back(stacks_[idx1].removeTop());
  } else if (stacks_[idx1].size() == 0 && stacks_[idx2].size() > 0) {
    stacks_[idx1].push_back(stacks_[idx2].removeTop());
  } else if (stacks_[idx1].size() > 0 && stacks_[idx2].size() > 0) {
    if (stacks_[idx1].peekTop().getLength() > stacks_[idx2].peekTop().getLength())
      stacks_[idx1].push_back(stacks_[idx2].removeTop());
    else
      stacks_[idx2].push_back(stacks_[idx1].removeTop());
  }
}

// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }

  // Create the four cubes, placing each on the [0]th stack:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
