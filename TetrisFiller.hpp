#ifndef TETRIS_FILLER
#define TETRIS_FILLER

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <queue>
#include <algorithm>
#include "BlocksAndPieces.hpp"
#include "Utility.hpp"

using namespace std;

class TetrisFiller {
public:
  TetrisFiller(vector<vector<shared_ptr<BlockBase > > > * grid);
  bool fill(int i, int j);  
private:
  vector<vector<shared_ptr<BlockBase > > > * grid;
  stack<shared_ptr<PieceBase> > pieces;
  bool selectFittingPiece(int i, int j);
  bool surroundPiece(shared_ptr<PieceBase> piece);
  void addPiece(shared_ptr<PieceBase> piece);
  void removeUpToAndIncluding(shared_ptr<PieceBase> piece);  
  // Method searches for unmarked squares surrounding a piece. The
  // method assumes that the piece itself has already been marked. 
  bool getEmptyPieceSurrounding(shared_ptr<PieceBase> piece, int &i, int &j);
  // Finds an blank unmarked bock surrounding the input block. Assumes
  // the block is located inside of the grid.
  bool getEmptyBlockSurrounding(shared_ptr<BlockBase> blockPtr, int &i, int &j);
  bool pieceFits(shared_ptr<PieceBase> piece);
};

#endif
