#include "stdafx.h"
#include "GameSettings.h"


const Dx::GameSettings& getGameSettings()
{
  static const Dx::GameSettings gameSettings{ 800, 800, "2048", "Data/Assets/" };
  return gameSettings;
}
