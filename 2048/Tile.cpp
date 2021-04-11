#include "stdafx.h"
#include "Tile.h"

#include "Utils.h"


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

  int getIntMultiplier(const double i_value1, const double i_value2)
  {
    if (i_value1 > i_value2)
      return +1;
    else if (i_value1 < i_value2)
      return -1;
    else
      return 0;
  }

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
  setPosition(getCellPosition(i_coords));
  d_coords = std::move(i_coords);
}

const Sdk::Vector2I& Tile::getCoords() const
{
  return d_coords;
}


void Tile::setDestination(const Sdk::Vector2I& i_destCoords)
{
  d_destination = getCellPosition(i_destCoords);
  d_coords = i_destCoords;

  const auto curPosition = getPosition();

  constexpr double SpeedValue = 4000;
  const int speedSignX = getIntMultiplier(d_destination->x, curPosition.x);
  const int speedSignY = getIntMultiplier(d_destination->y, curPosition.y);
  setSpeed({ speedSignX * SpeedValue, speedSignY * SpeedValue });
}

bool Tile::isInAnimation() const
{
  return d_destination.has_value();
}


void Tile::update(const double i_dt)
{
  ObjectBase::update(i_dt);

  if (d_destination)
  {
    const auto diff = getPosition() - *d_destination;
    if (diff.dot(getSpeed()) < 0)
      return;

    setSpeed(Sdk::Vector2D::zero());
    setPosition(getCellPosition(d_coords));
    d_destination.reset();
  }
}
