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
  void createActions();

  Dx::Sprite d_back;
  void renderBack();

  Field d_field;

  void generateStartTiles();
  void generateNewTile();

  bool checkInsideField(const Sdk::Vector2I& i_coords);

  void setTileCoords(Tile& i_tile, Sdk::Vector2I i_coords);
  void moveTile(Tile& i_tile, const Sdk::Vector2I& i_direction);

  void onUp();
  void onDown();
  void onLeft();
  void onRight();
};
