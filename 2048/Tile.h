#pragma once

#include <LaggyDx/ObjectBase.h>


class Tile : public Dx::ObjectBase
{
public:
  int value = 2;

  void setCoords(Sdk::Vector2I i_coords);
  const Sdk::Vector2I& getCoords() const;

private:
  Sdk::Vector2I d_coords;
};
