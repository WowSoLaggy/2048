#include "stdafx.h"
#include "Field.h"


Field::Field()
{
  for (auto& tile : d_field)
    tile = nullptr;
}


Tile* Field::getTile(int x, int y) const
{
  return d_field.at(x + y * Size);
}

void Field::setTile(Tile& i_tile, int x, int y)
{
  d_field.at(x + y * Size) = &i_tile;
}

void Field::resetTile(int x, int y)
{
  d_field.at(x + y * Size) = nullptr;
}


bool Field::hasEmptyField() const
{
  return std::any_of(d_field.cbegin(), d_field.cend(), [](const auto* i_tile) { return i_tile == nullptr; });
}
