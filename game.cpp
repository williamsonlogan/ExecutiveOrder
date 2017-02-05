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
	agk::LoadImage(6, "media/sprites/exec_small.png");
	agk::LoadImage(31, "media/sprites/Executive_Orders/execorder().png");
	agk::LoadImage(32, "media/sprites/Executive_Orders/execorder.png");
	agk::LoadImage(33, "media/sprites/Executive_Orders/execorder(1).png");
	agk::LoadImage(34, "media/sprites/Executive_Orders/execorder(2).png");
	agk::LoadImage(35, "media/sprites/Executive_Orders/execorder(3).png");
	agk::LoadImage(36, "media/sprites/Executive_Orders/execorder(4).png");
	agk::LoadImage(37, "media/sprites/Executive_Orders/execorder(5).png");
	agk::LoadImage(38, "media/sprites/Executive_Orders/execorder(6).png");
	agk::LoadImage(39, "media/sprites/Executive_Orders/execorder(7).png");
	agk::LoadImage(40, "media/sprites/Executive_Orders/execorder(8).png");
	agk::LoadImage(41, "media/sprites/Executive_Orders/execorder(9).png");
	agk::LoadImage(42, "media/sprites/Executive_Orders/execorder(10).png");
	agk::LoadImage(43, "media/sprites/Executive_Orders/execorder(11).png");
	agk::LoadImage(44, "media/sprites/Executive_Orders/execorder(12).png");
	agk::LoadImage(45, "media/sprites/Executive_Orders/execorder(13).png");
	agk::LoadImage(46, "media/sprites/Executive_Orders/execorder(14).png");
	agk::LoadImage(47, "media/sprites/Executive_Orders/execorder(15).png");
	agk::LoadImage(48, "media/sprites/Executive_Orders/execorder(16).png");
	agk::LoadImage(49, "media/sprites/Executive_Orders/execorder(17).png");
	agk::LoadImage(50, "media/sprites/Executive_Orders/execorder(18).png");
	agk::LoadImage(51, "media/sprites/Executive_Orders/execorder(19).png");
	agk::LoadImage(52, "media/sprites/Executive_Orders/execorder(20).png");
	agk::LoadImage(53, "media/sprites/Executive_Orders/execorder(21).png");
	agk::LoadImage(54, "media/sprites/Executive_Orders/execorder(22).png");
	agk::LoadImage(55, "media/sprites/Executive_Orders/execorder(23).png");
	agk::LoadImage(56, "media/sprites/Executive_Orders/execorder(24).png");
	agk::LoadImage(57, "media/sprites/Executive_Orders/execorder(25).png");
	agk::LoadImage(58, "media/sprites/Executive_Orders/execorder(26).png");
	agk::LoadImage(59, "media/sprites/Executive_Orders/execorder(27).png");
	agk::LoadImage(60, "media/sprites/Executive_Orders/execorder(28).png");
	agk::LoadImage(61, "media/sprites/Executive_Orders/execorder(29).png");
	agk::LoadImage(62, "media/sprites/Executive_Orders/execorder(30).png");

	//Loading Orders


	agk::DeleteSprite(1);
}

void app::gameScreenDraw()
{
	agk::SetSpritePosition(2, 0, 0);
	agk::SetSpritePosition(3, 16, 225);
	agk::SetSpritePosition(4, 575, 1050);
	agk::SetSpritePosition(6, 250, 1050);
}

void app::newsFeedDraw(void)
{

}

void app::helpScreenDraw(void)
{

}
