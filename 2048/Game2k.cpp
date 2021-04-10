#include "stdafx.h"
#include "Game2k.h"

#include <LaggyDx/Colors.h>
#include <LaggyDx/GameSettings.h>
#include <LaggyDx/IRenderDevice.h>
#include <LaggyDx/Renderer2dGuard.h>
#include <LaggySdk/UniformIntGenerator.h>


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

  const Dx::GameSettings& getGameSettings()
  {
    static const Dx::GameSettings gameSettings{ 800, 800, "2048", "Data/Assets/" };
    return gameSettings;
  }

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

  generateStartTiles();
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


void Game2k::generateStartTiles()
{
  static constexpr int StartTilesCount = 3;
  for (int i = 0; i < StartTilesCount; ++i)
    generateNewTile();
}

void Game2k::generateNewTile()
{
  int x = 0;
  int y = 0;

  do
  {
    x = getRandomField();
    y = getRandomField();
  } while (d_field.getTile(x, y) != nullptr);

  auto tile = std::make_shared<Tile>();
  tile->setTexture(TexturesMap.at(tile->getValue()));
  tile->setPosition({ 196.0 + double(x * (128 + 8)), 273.0 + double(y * (128 + 8)) });
  getObjectCollection().addObject(tile);
  d_field.setTile(*tile, x, y);
}
