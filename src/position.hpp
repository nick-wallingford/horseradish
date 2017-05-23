#pragma once

#include <array>
#include <cstdint>

class position {
  enum color { white, black };
  enum type { pawn, rook, knight, bishop, queen, king };

  std::array<std::array<uint64_t, 6>, 2> pieces;
  color active;

  uint64_t white_pieces() const;
  uint64_t black_pieces() const;

public:
  position()
      : pieces{{{{0xff00, 0x81, 0x42, 0x24, 0x10, 0x8}},
                {{0x00ff000000000000, 0x8100000000000000, 0x4200000000000000,
                  0x2400000000000000, 0x1000000000000000,
                  0x0800000000000000}}}},
        active{white} {}

  friend std::ostream &operator<<(std::ostream &, const position &);
};
