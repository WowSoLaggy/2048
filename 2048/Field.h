#pragma once

#include "Tile.h"

#include <LaggySdk/Vector.h>


class Field
{
public:
  static constexpr int Size = 4;

  Field();

  Tile* getTile(const Sdk::Vector2I& i_coords) const;
  void setTile(Tile& i_tile, const Sdk::Vector2I& i_coords);
  void resetTile(const Sdk::Vector2I& i_coords);
  void resetTiles();

  bool hasEmptyField() const;

private:
  std::array<Tile*, Size * Size> d_field;
};
