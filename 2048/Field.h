#pragma once

#include "Tile.h"


class Field
{
public:
  static constexpr int Size = 4;

  Field();

  Tile* getTile(int x, int y) const;
  void setTile(Tile& i_tile, int x, int y);
  void resetTile(int x, int y);

  bool hasEmptyField() const;

private:
  std::array<Tile*, Size * Size> d_field;
};
