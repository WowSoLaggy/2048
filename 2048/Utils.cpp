#include "stdafx.h"
#include "Utils.h"


Sdk::Vector2D getCellPosition(const Sdk::Vector2I& i_coords)
{
  return { 196.0 + double(i_coords.x * (128 + 8)), 273.0 + double(i_coords.y * (128 + 8)) };
}
