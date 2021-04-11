#include "stdafx.h"
#include "Game2k.h"

#include "GameSettings.h"

#include <LaggyDx/Colors.h>
#include <LaggyDx/GameSettings.h>
#include <LaggyDx/IRenderDevice.h>
#include <LaggyDx/Renderer2dGuard.h>
#include <LaggySdk/UniformIntGenerator.h>


namespace
{
  int getRandomField()
  {
    static Sdk::UniformIntGenerator<int> gen(0, 3);
    return gen.getNextValue();
  }

} // anonym NS


Game2k::Game2k()
  : Dx::Game(getGameSettings())
{
}


void Game2k::onGameStart()
{
  getRenderDevice().setClearColor(Dx::Colors::WhiteSmoke);

  d_back.setTexture(getResourceController().getTextureResource("back.png"));
  d_back.resetSizeToTexture();

  createGui();

  createActions();
  startNewGame();

  getInputDevice().showCursor();
}


void Game2k::render()
{
  renderBack();
  Dx::Game::render();
}

void Game2k::renderBack()
{
  Dx::Renderer2dGuard rendererGuard(getRenderer2d());
  getRenderer2d().renderSprite(d_back);
}


void Game2k::clearTiles()
{
  d_field.resetTiles();
  getObjectCollection().getObjects().clear();
}

void Game2k::startNewGame()
{
  clearTiles();
  generateStartTiles();
  hideEndScore();
  setScore(0);
}

void Game2k::generateStartTiles()
{
  static constexpr int StartTilesCount = 3;
  for (int i = 0; i < StartTilesCount; ++i)
    generateNewTile();
}

void Game2k::generateNewTile()
{
  Sdk::Vector2I coords;

  do
  {
    coords.x = getRandomField();
    coords.y = getRandomField();
  } while (d_field.getTile(coords) != nullptr);

  auto tile = std::make_shared<Tile>(2);
  setTileCoords(*tile, coords);
  getObjectCollection().addObject(tile);
}


bool Game2k::checkInsideField(const Sdk::Vector2I& i_coords) const
{
  return
    0 <= i_coords.x && i_coords.x < d_field.Size &&
    0 <= i_coords.y && i_coords.y < d_field.Size;
}


void Game2k::setTileCoords(Tile& i_tile, Sdk::Vector2I i_coords)
{
  d_field.setTile(i_tile, i_coords);
  i_tile.setCoords(std::move(i_coords));
}

bool Game2k::moveTile(Tile& i_tile, const Sdk::Vector2I& i_direction)
{
  const auto oldPos = i_tile.getCoords();
  auto newPos = i_tile.getCoords();

  bool wasMerge = false;

  while (true)
  {
    auto predictedPos = newPos + i_direction;

    if (!checkInsideField(predictedPos))
      break;

    if (auto* nextTile = d_field.getTile(predictedPos))
    {
      if (nextTile->getValue() != i_tile.getValue() || wasMerge)
        break;
      else
      {
        getObjectCollection().deleteObject(*nextTile);
        d_field.resetTile(predictedPos);
        i_tile.setNextValue();

        setScore(d_score + i_tile.getValue());

        wasMerge = true;
      }
    }

    newPos = predictedPos;
  }

  if (newPos == oldPos)
    return false;

  i_tile.setDestination(newPos);
  d_field.resetTile(oldPos);
  d_field.setTile(i_tile, newPos);

  return true;
}


void Game2k::onNewTurn()
{
  if (d_field.hasEmptyField())
    generateNewTile();

  if (isGameOver())
    endGame();
}

void Game2k::endGame()
{
  showEndScore();
}


bool Game2k::isGameOver() const
{
  if (d_field.hasEmptyField())
    return false;

  auto getValue = [&](const Sdk::Vector2I& i_coords) -> std::optional<int>
  {
    if (!checkInsideField(i_coords))
      return std::nullopt;

    if (const auto* tile = d_field.getTile(i_coords))
      return tile->getValue();

    return std::nullopt;
  };

  for (int y = 0; y < d_field.Size; ++y)
  {
    for (int x = 0; x < d_field.Size; ++x)
    {
      const auto* tile = d_field.getTile({ x, y });
      CONTRACT_ASSERT(tile);

      if (const auto valueOpt = getValue({ x + 1, y }); valueOpt && *valueOpt == tile->getValue())
        return false;
      if (const auto valueOpt = getValue({ x, y + 1 }); valueOpt && *valueOpt == tile->getValue())
        return false;
    }
  }

  return true;
}


void Game2k::setScore(const int i_score)
{
  d_score = i_score;
  d_scoreLabel->setText("Score: " + std::to_string(i_score));
}


bool Game2k::isInAnimation() const
{
  const auto& objects = getObjectCollection().getObjects();
  return std::any_of(objects.cbegin(), objects.cend(),
                     [](const auto& i_objPtr)
                     {
                       return std::dynamic_pointer_cast<Tile>(i_objPtr)->isInAnimation();
                     });
}
