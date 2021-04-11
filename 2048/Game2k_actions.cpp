#include "stdafx.h"
#include "Game2k.h"


void Game2k::createActions()
{
  getActionsMap().setAction(Dx::KeyboardKey::W,
                            Dx::Action(std::bind(&Game2k::onUp, this)),
                            Dx::ActionType::OnPress);
  getActionsMap().setAction(Dx::KeyboardKey::S,
                            Dx::Action(std::bind(&Game2k::onDown, this)),
                            Dx::ActionType::OnPress);
  getActionsMap().setAction(Dx::KeyboardKey::A,
                            Dx::Action(std::bind(&Game2k::onLeft, this)),
                            Dx::ActionType::OnPress);
  getActionsMap().setAction(Dx::KeyboardKey::D,
                            Dx::Action(std::bind(&Game2k::onRight, this)),
                            Dx::ActionType::OnPress);
}


void Game2k::onUp()
{
  for (int y = 0; y < d_field.Size; ++y)
  {
    for (int x = 0; x < d_field.Size; ++x)
    {
      if (auto* tile = d_field.getTile({ x, y }))
        moveTile(*tile, { 0, -1 });
    }
  }
}

void Game2k::onDown()
{
  for (int y = d_field.Size - 1; y >= 0; --y)
  {
    for (int x = 0; x < d_field.Size; ++x)
    {
      if (auto* tile = d_field.getTile({ x, y }))
        moveTile(*tile, { 0, 1 });
    }
  }
}

void Game2k::onLeft()
{
  for (int y = 0; y < d_field.Size; ++y)
  {
    for (int x = 0; x < d_field.Size; ++x)
    {
      if (auto* tile = d_field.getTile({ x, y }))
        moveTile(*tile, { -1, 0 });
    }
  }
}

void Game2k::onRight()
{
  for (int y = 0; y < d_field.Size; ++y)
  {
    for (int x = d_field.Size - 1; x >= 0; --x)
    {
      if (auto* tile = d_field.getTile({ x, y }))
        moveTile(*tile, { 1, 0 });
    }
  }
}
