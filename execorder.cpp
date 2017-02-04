// Includes
#include "template.h"

// Namespace
using namespace AGK;


float playerX = 50.0f, playerY = 75.0f, speed = 1.5f, moveX = 0.0f, moveY = 0.0f;

app App;

void app::Begin(void)
{
	agk::SetDisplayAspect(720.0f/1280.0f);
	agk::SetClearColor(0,0,0);
	agk::SetBorderColor(0, 0, 0);
	agk::LoadImage(1, "media/sprites/ship1.png");
	agk::CreateSprite(1, 1);
	agk::SetSpriteScale(1, 1.0f, 1.0f);
}

int app::Loop(void)
{
	float joystickX = agk::GetJoystickX();
	float joystickY = agk::GetJoystickY();
	agk::SetSpritePosition(1, playerX, playerY);

	moveX = joystickX * speed;

	if (moveX > 0 || moveX < 0)
		playerX += moveX;

	moveY = joystickY * speed;

	if (moveY > 0 || moveY < 0)
		playerY += moveY;

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
