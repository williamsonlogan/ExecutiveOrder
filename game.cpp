//includes
#include "template.h"

using namespace AGK;

void app::loadAssets()
{
	agk::LoadImage(1, "media/sprites/loading.png");
	agk::CreateSprite(1, 1);
	agk::SetSpritePosition(1, 0, 0);
	agk::LoadImage(2, "media/sprites/officetemp.png");

	agk::DeleteSprite(1);
}

void app::gameScreenDraw(void)
{
	agk::CreateSprite(2, 2);
	agk::SetSpritePosition(2, 0, 0);
}

void newsFeedDraw(void);
void helpScreenDraw(void);