// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

int freshLoad = 1, showOrder = 0, iSprite = 0, execLoc = 100, execApprov = 0, execClicked = 0;
int money = 50, happy = 50, military = 50, foreign = 50;
Order current_order;

stack <Order> executive_orders;
FILE *orders_file = fopen("orders.csv", "r");


void app::Begin(void)
{
	agk::SetVirtualResolution(720, 1280);
	agk::SetClearColor(235, 186, 109);
	agk::SetBorderColor(0, 0, 0);
	app::loadAssets();

	queue_all_orders(orders_file, executive_orders);
	agk::Print(executive_orders.size());

}

int app::Loop(void)
{
	//agk::Print(executive_orders.size());
	//agk::Print(showOrder);
	//agk::Print((int)floor(agk::GetPointerX()));
	//agk::Print(iSprite);
	agk::PrintC("$: ");
	agk::Print(money);
	agk::PrintC(":): ");
	agk::Print(happy);
	agk::PrintC("^: ");
	agk::Print(military);
	agk::PrintC("[=]: ");
	agk::Print(foreign);

	app::gameScreenDraw();

	//Local Vars
	int currentGameScreen = 0;

	//Prints FPS
	//agk::Print(agk::ScreenFPS());

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
			agk::CreateSprite(7, 7);
			agk::AddSpriteAnimationFrame(7, agk::LoadImage("media/sprites/sun/sun1.png"));
			agk::AddSpriteAnimationFrame(7, agk::LoadImage("media/sprites/sun/sun2.png"));
			agk::AddSpriteAnimationFrame(7, agk::LoadImage("media/sprites/sun/sun3.png"));
			agk::AddSpriteAnimationFrame(7, agk::LoadImage("media/sprites/sun/sun4.png"));
			agk::PlaySprite(7, .25f, 1, 1, 4);
			agk::CreateSprite(8, 8);
			agk::AddSpriteAnimationFrame(8, agk::LoadImage("media/sprites/person/person().png"));
			agk::AddSpriteAnimationFrame(8, agk::LoadImage("media/sprites/person/person(1).png"));
			agk::AddSpriteAnimationFrame(8, agk::LoadImage("media/sprites/person/person(2).png"));
			agk::AddSpriteAnimationFrame(8, agk::LoadImage("media/sprites/person/person(3).png"));
			agk::AddSpriteAnimationFrame(8, agk::LoadImage("media/sprites/person/person(4).png"));
			agk::PlaySprite(8, 2, 1, 1, 5);
			agk::CreateSprite(9, 8);
			agk::AddSpriteAnimationFrame(9, agk::LoadImage("media/sprites/person/person().png"));
			agk::AddSpriteAnimationFrame(9, agk::LoadImage("media/sprites/person/person(1).png"));
			agk::AddSpriteAnimationFrame(9, agk::LoadImage("media/sprites/person/person(2).png"));
			agk::AddSpriteAnimationFrame(9, agk::LoadImage("media/sprites/person/person(3).png"));
			agk::AddSpriteAnimationFrame(9, agk::LoadImage("media/sprites/person/person(4).png"));
			agk::PlaySprite(9, 2, 1, 1, 5);
			agk::CreateSprite(10, 8);
			agk::AddSpriteAnimationFrame(10, agk::LoadImage("media/sprites/person/person().png"));
			agk::AddSpriteAnimationFrame(10, agk::LoadImage("media/sprites/person/person(1).png"));
			agk::AddSpriteAnimationFrame(10, agk::LoadImage("media/sprites/person/person(2).png"));
			agk::AddSpriteAnimationFrame(10, agk::LoadImage("media/sprites/person/person(3).png"));
			agk::AddSpriteAnimationFrame(10, agk::LoadImage("media/sprites/person/person(4).png"));
			agk::PlaySprite(10, 2, 1, 1, 5);

			freshLoad = 0;
		}

		if (agk::GetPointerPressed())
		{
			iSprite = agk::GetSpriteHit(agk::GetPointerX(), agk::GetPointerY());
		}

		if (showOrder == 0 && iSprite == 6)
		{
			current_order = Exec(executive_orders);
			int tag = current_order.image_tag;
			agk::CreateSprite(5, tag);
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
				update_stats(execApprov, &money, &happy, &military, &foreign,
					current_order);
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

		if (happy < 35)
		{

		}
		else if (happy > 75)
		{

		}
		else
		{

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
