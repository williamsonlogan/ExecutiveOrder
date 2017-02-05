// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

int freshLoad = 1, showOrder = 0, iSprite = 0, execLoc = 100, execApprov = 0, execClicked = 0;


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
	//agk::Print(showOrder);
	//agk::Print((int)floor(agk::GetPointerX()));
	//agk::Print(iSprite);

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
			agk::CreateSprite(6, 6);

			freshLoad = 0;
		}

		if (agk::GetPointerPressed())
		{
			iSprite = agk::GetSpriteHit(agk::GetPointerX(), agk::GetPointerY());
		}

		if (showOrder == 0 && iSprite == 6)
		{
			agk::CreateSprite(5, 5);
			agk::SetSpritePosition(5, 40, 100);
			showOrder = 1;
		}

		app::gameScreenDraw();

		if (showOrder == 1)
		{
			//if(iSprite == 0)
			//	agk::SetSpritePosition(5, 40, 100);

			if (agk::GetPointerPressed())
			{
				iSprite = agk::GetSpriteHit(agk::GetPointerX(), agk::GetPointerY());
				if (iSprite == 5)
				{
					execClicked = 1;
					
				}
			}

			if (execClicked)
			{
				execLoc = (int)(floor(agk::GetPointerX()));
				agk::SetSpritePosition(5, agk::GetPointerX() - 350, 100);
			}
			else
			{
				agk::SetSpritePosition(5, 40, 100);
			}

			if (execLoc > 750)
			{
				execApprov = 1;
				agk::DeleteSprite(5);
				execLoc = 100;
				showOrder = 0;
			}
			if (execLoc < 25)
			{
				execApprov = 0;
				agk::DeleteSprite(5);
				execLoc = 100;
				showOrder = 0;
			}
		}

		if (agk::GetPointerReleased()) //Mouse Released Sets all to 0
		{
			iSprite = 0;
			execClicked = 0;
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
