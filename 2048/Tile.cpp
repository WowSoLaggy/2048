#include "stdafx.h"
#include "Tile.h"


void Tile::setCoords(Sdk::Vector2I i_coords)
{
  d_coords = std::move(i_coords);
  setPosition({ 196.0 + double(d_coords.x * (128 + 8)), 273.0 + double(d_coords.y * (128 + 8)) });
}

const Sdk::Vector2I& Tile::getCoords() const
{
  return d_coords;
}
