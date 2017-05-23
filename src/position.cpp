#include "position.hpp"

#include "util.hpp"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &o, const position &p) {
  enum color { white, black };
  enum type { pawn, rook, knight, bishop, queen, king };

  constexpr uint64_t white_squares{0xaa55aa55aa55aa55};
  const string color_reset{"\e[0m"};

  if (p.active == position::white)
    cout << "To play: White" << endl;
  else
    cout << "To play: Black" << endl;

  for (const uint64_t square : piece_range{UINT64_MAX}) {
    if (square & white_squares)
      cout << "\e[30;47m";
    else
      cout << "\e[30;44m";

    if (square & p.pieces[white][pawn])
      cout << "♙";
    else if (square & p.pieces[white][rook])
      cout << "♖";
    else if (square & p.pieces[white][knight])
      cout << "♘";
    else if (square & p.pieces[white][bishop])
      cout << "♗";
    else if (square & p.pieces[white][queen])
      cout << "♕";
    else if (square & p.pieces[white][king])
      cout << "♔";
    else if (square & p.pieces[black][pawn])
      cout << "♟";
    else if (square & p.pieces[black][rook])
      cout << "♜";
    else if (square & p.pieces[black][knight])
      cout << "♞";
    else if (square & p.pieces[black][bishop])
      cout << "♝";
    else if (square & p.pieces[black][queen])
      cout << "♛";
    else if (square & p.pieces[black][king])
      cout << "♚";
    else
      cout << ' ';

    if (!(7 & __builtin_ctzll(square)))
      cout << color_reset << endl;
  }

  return o;
}

uint64_t position::white_pieces() const {
  uint64_t retval = 0;
  for (uint64_t pieces : pieces[white])
    retval |= pieces;
  return retval;
}
uint64_t position::black_pieces() const {
  uint64_t retval = 0;
  for (uint64_t pieces : pieces[black])
    retval |= pieces;
  return retval;
}
