#include "stdafx.h"
#include "Game2k.h"

#include "GameSettings.h"

#include <LaggyDx/Colors.h>
#include <LaggyDx/IFontResource.h>


void Game2k::createGui()
{
  const std::string FontName = "play.spritefont";

  d_endPanel = std::make_shared<Dx::Panel>();
  d_endPanel->setTexture("blank.png");
  d_endPanel->setSize({ (float)getGameSettings().screenWidth, (float)getGameSettings().screenHeight });
  d_endPanel->setColor(Dx::colorWithAlpha(Dx::Colors::Black, 0.8f));

  d_endLabel = std::make_shared<Dx::Label>();
  d_endLabel->setFont(FontName);
  d_endLabel->setTextColor(Dx::Colors::Gold);

  d_scoreLabel = std::make_shared<Dx::Label>();
  d_scoreLabel->setFont(FontName);
  d_scoreLabel->setTextColor(Dx::Colors::DarkGreen);
  d_scoreLabel->setPosition({ 100, 100 });
  getForm().addChild(d_scoreLabel);

  d_helpLabel = std::make_shared<Dx::Label>();
  d_helpLabel->setFont(FontName);
  d_helpLabel->setTextColor(Dx::Colors::DarkGreen);
  d_helpLabel->setTextScale(0.33f);
  d_helpLabel->setText("Esc - exit\nF5 - new game");
  d_helpLabel->setPosition({ 600, 0 });
  getForm().addChild(d_helpLabel);
}


void Game2k::showEndScore()
{
  setEndScoreText();
  getForm().addChild(d_endPanel);
  getForm().addChild(d_endLabel);
}

void Game2k::hideEndScore()
{
  getForm().removeChild(*d_endPanel);
  getForm().removeChild(*d_endLabel);
}

void Game2k::setEndScoreText()
{
  const std::string scoreText = "Score: " + std::to_string(d_score);
  d_endLabel->setText(scoreText);
  
  auto* font = d_endLabel->getFontResource();
  CONTRACT_ASSERT(font);

  const auto rect = font->getStringRect(scoreText);
  d_endLabel->setPosition({
    (float)(getGameSettings().screenWidth - rect.width()) / 2.0f,
    (float)(getGameSettings().screenHeight - rect.height()) / 2.0f });
}
