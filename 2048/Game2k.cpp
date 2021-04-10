#include "stdafx.h"
#include "Game2k.h"

#include <LaggyDx/GameSettings.h>


namespace
{
  const Dx::GameSettings& getGameSettings()
  {
    static const Dx::GameSettings gameSettings{ 1600, 900, "2048", "Data/Assets/" };
    return gameSettings;
  }

} // anonym NS


Game2k::Game2k()
  : Dx::Game(getGameSettings())
{
}
