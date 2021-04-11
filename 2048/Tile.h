#pragma once

#include <LaggyDx/ObjectBase.h>


class Tile : public Dx::ObjectBase
{
public:
  Tile(int i_initialValue);

  void setValue(int i_value);
  void setNextValue();
  int getValue() const;

  void setCoords(Sdk::Vector2I i_coords);
  const Sdk::Vector2I& getCoords() const;

private:
  int d_value = 2;
  Sdk::Vector2I d_coords;
};
