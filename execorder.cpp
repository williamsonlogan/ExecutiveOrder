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
	stack <Order> executive_orders;
	FILE *orders_file = fopen("orders.csv", "r");
	queue_all_orders(orders_file, executive_orders);
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
