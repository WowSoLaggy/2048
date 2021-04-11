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

  void setDestination(const Sdk::Vector2I& i_destCoords);
  bool isInAnimation() const;

  virtual void setScale(Sdk::Vector2D i_scale) override;

  virtual void update(double i_dt) override;

private:
  int d_value = 2;
  Sdk::Vector2I d_coords;

  std::optional<Sdk::Vector2D> d_destination;

  bool d_isScaling = false;
};
