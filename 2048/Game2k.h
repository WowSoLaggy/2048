#pragma once

#include "Field.h"

#include <LaggyDx/Game.h>
#include <LaggyDx/Sprite.h>


class Game2k : public Dx::Game
{
public:
  Game2k();

  virtual void onGameStart() override;
  virtual void render() override;

private:
  Dx::Sprite d_back;
  void renderBack();

  Field d_field;

  void generateStartTiles();
  void generateNewTile();
};
