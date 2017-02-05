// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

int freshLoad = 1, showOrder = 1;


void app::Begin(void)
{
	agk::SetVirtualResolution(720, 1280);
	agk::SetClearColor(235, 186, 109);
	agk::SetBorderColor(0, 0, 0);
	app::loadAssets();

	stack <Order> executive_orders;
	FILE *orders_file;
   orders_file = fopen("orders.csv", "r");
	queue_all_orders(orders_file, executive_orders);

}

int app::Loop(void)
{

	//agk::Print(agk::ScreenFPS());

	app::gameScreenDraw();

	//Local Vars
	int currentGameScreen = 0;

	//Prints FPS
	agk::Print(agk::ScreenFPS());

	//Draw Function Calls
	switch (currentGameScreen)
	{
	case 0:
		if (freshLoad == 1)
		{
			agk::CreateSprite(2, 2);
			agk::CreateSprite(3, 3);
			agk::CreateSprite(4, 4);

			freshLoad = 0;
		}

		if (agk::GetRawKeyPressed(32))
		{
			agk::CreateSprite(5, 5);
			if (showOrder == 1)
			{
				showOrder = 0;
				agk::DeleteSprite(5);
			}
			else
			{
				showOrder = 1;
			}
		}

		app::gameScreenDraw();

		if (showOrder == 1)
		{
			agk::SetSpritePosition(5, 40, 100);
		}



		break;
	case 1:
		app::helpScreenDraw();



		break;
	case 2:
		app::newsFeedDraw();



		break;
	default:
		break;
	}

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
