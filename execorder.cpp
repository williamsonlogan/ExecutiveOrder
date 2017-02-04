// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	agk::SetDisplayAspect(720.0f/1280.0f);
	agk::SetClearColor(235, 186, 109);
	agk::SetBorderColor(0, 0, 0);
	//agk::LoadImage(1, "media/sprites/ship1.png");
	//agk::CreateSprite(1, 1);
	//agk::SetSpriteScale(1, 1.0f, 1.0f);
}

int app::Loop(void)
{
	if (agk::GetRawKeyPressed(27))
	{
		app::End();
	}

	agk::Print( agk::ScreenFPS() );
	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{
	exit(0);
}
