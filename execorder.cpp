// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution(720, 1280);
	agk::SetClearColor(235, 186, 109);
	agk::SetBorderColor(0, 0, 0);
	app::loadAssets();
}

int app::Loop(void)
{
	//agk::Print(agk::ScreenFPS());

	app::gameScreenDraw();

	if (agk::GetRawKeyPressed(27))
	{
		app::End();
	}

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{
	exit(0);
}
