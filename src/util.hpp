#pragma once

#include <cstdint>

class board_iterator_end {};

class board_iterator {
  static constexpr uint64_t msb = UINT64_C(1) << 63;
  uint64_t piece;
  uint64_t board;

public:
  board_iterator() : board(0) {}
  board_iterator(uint64_t board)
      : piece(msb >> __builtin_clzll(board)), board(board) {}
  uint64_t operator*() const { return piece; }
  board_iterator &operator++() {
    board ^= piece;
    piece = msb >> __builtin_clzll(board);
    return *this;
  }
  bool operator!=(const board_iterator_end &) const { return board; }
  bool operator!=(const board_iterator &it) const { return board != it.board; }
};

class piece_range {
  const uint64_t board;

public:
  piece_range(uint64_t board) : board{board} {}
  board_iterator begin() const { return {board}; }
  board_iterator_end end() const { return {}; }
};
