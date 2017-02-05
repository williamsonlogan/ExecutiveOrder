//includes
#include "template.h"

using namespace AGK;

void app::loadAssets()
{
	agk::LoadImage(1, "media/sprites/loading.png");
	agk::CreateSprite(1, 1);
	agk::SetSpritePosition(1, 0, 0);
	agk::LoadImage(2, "media/sprites/office.png");
	agk::LoadImage(3, "media/sprites/window.png");
	agk::LoadImage(4, "media/sprites/phone.png");
	agk::LoadImage(5, "media/sprites/execorder.png");

	agk::DeleteSprite(1);
}

void app::gameScreenDraw()
{
	agk::SetSpritePosition(2, 0, 0);
	agk::SetSpritePosition(3, 16, 225);
	agk::SetSpritePosition(4, 575, 1050);
}

void app::newsFeedDraw(void)
{

}

void app::helpScreenDraw(void)
{

}