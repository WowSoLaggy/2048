#pragma once

#include <LaggyDx/ObjectBase.h>


class Tile : public Dx::ObjectBase
{
public:
  int getValue() const { return d_value; }
  void setValue(const int i_value) { d_value = i_value; }

private:
  int d_value = 2;
};
