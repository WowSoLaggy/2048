#pragma once

#include "Field.h"

#include <LaggyDx/Game.h>
#include <LaggyDx/Label.h>
#include <LaggyDx/Panel.h>
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

  std::shared_ptr<Dx::Label> d_scoreLabel;
  std::shared_ptr<Dx::Label> d_helpLabel;
  std::shared_ptr<Dx::Panel> d_endPanel;
  std::shared_ptr<Dx::Label> d_endLabel;
  void createGui();

  Field d_field;

  bool isInAnimation() const;

  int d_score = 0;
  void setScore(int i_score);

  void clearTiles();
  void startNewGame();
  void generateStartTiles();
  void generateNewTile();

  bool checkInsideField(const Sdk::Vector2I& i_coords) const;

  void setTileCoords(Tile& i_tile, Sdk::Vector2I i_coords);
  bool moveTile(Tile& i_tile, const Sdk::Vector2I& i_direction);

  void onUp();
  void onDown();
  void onLeft();
  void onRight();

  void onNewTurn();
  void endGame();
  void showEndScore();
  void hideEndScore();
  void setEndScoreText();

  bool isGameOver() const;
};
