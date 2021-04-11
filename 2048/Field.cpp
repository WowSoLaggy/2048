#include "stdafx.h"
#include "Field.h"


Field::Field()
{
  for (auto& tile : d_field)
    tile = nullptr;
}


Tile* Field::getTile(const Sdk::Vector2I& i_coords) const
{
  return d_field.at(i_coords.x + i_coords.y * Size);
}

void Field::setTile(Tile& i_tile, const Sdk::Vector2I& i_coords)
{
  d_field.at(i_coords.x + i_coords.y * Size) = &i_tile;
}

void Field::resetTile(const Sdk::Vector2I& i_coords)
{
  d_field.at(i_coords.x + i_coords.y * Size) = nullptr;
}


bool Field::hasEmptyField() const
{
  return std::any_of(d_field.cbegin(), d_field.cend(), [](const auto* i_tile) { return i_tile == nullptr; });
}
