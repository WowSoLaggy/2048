#include "stdafx.h"
#include "Tile.h"


namespace
{
  const std::map<int, std::string> TexturesMap = {
    { 2, "2.png" },
    { 4, "4.png" },
    { 8, "8.png" },
    { 16, "16.png" },
    { 32, "32.png" },
    { 64, "64.png" },
    { 128, "128.png" },
    { 256, "256.png" },
    { 512, "512.png" },
    { 1024, "1024.png" },
    { 2048, "2048.png" },
    { 4096, "4096.png" },
    { 8192, "8192.png" },
    { 16384, "16384.png" },
    { 32768, "32768.png" },
    { 65536, "65536.png" },
  };

} // anonym NS


Tile::Tile(const int i_initialValue)
{
  setValue(i_initialValue);
}


void Tile::setValue(const int i_value)
{
  d_value = i_value;
  setTexture(TexturesMap.at(d_value));
}

void Tile::setNextValue()
{
  setValue(getValue() * 2);
}

int Tile::getValue() const
{
  return d_value;
}


void Tile::setCoords(Sdk::Vector2I i_coords)
{
  d_coords = std::move(i_coords);
  setPosition({ 196.0 + double(d_coords.x * (128 + 8)), 273.0 + double(d_coords.y * (128 + 8)) });
}

const Sdk::Vector2I& Tile::getCoords() const
{
  return d_coords;
}
