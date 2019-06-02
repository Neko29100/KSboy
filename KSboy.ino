#include <Arduboy2.h>
 
#include "Images.h"

enum class GameState : uint8_t
{
	TitleScreen,
	Gameplay,
  EndScreen,
};

Arduboy2 arduboy;
GameState gameState = GameState::EndScreen;
int Gover = 2;
int Height = 0;
int planety = 256;
int playerx = 23;
int playery = 90;
int boosterxL = 34;
int boosterxR = 20;
int boosteryL = 95;
int boosteryR = 95;
int var = 0;
int Delay = 200;
int backgroundy;
int base_y = 97;


// int16_t is the same as int on the Arduboy,
// but int isn't the same size on all platforms,
// while int16_t and uint16_t are
uint16_t playerX = 0;
uint16_t playerY = 0;
uint16_t boosterX = 0;
uint16_t boosterY = 0;

// The 'void' in the brackets means 'this function takes no arguments'
// If you don't know what functions and arguments are,
// you need to read more tutorials - they're crucial to writing manageable games

void setup()
{
	arduboy.begin();
 
  arduboy.clear();
}

void loop()
{
	// This stops the Arduboy trying to draw before it's ready
	if(!arduboy.nextFrame())
	return;

	// This updates the button state
	arduboy.pollButtons();

	// Do different things depending on the current game state
	switch(gameState)
	{
	case GameState::TitleScreen:
		updateTitleScreen();
		break;
	case GameState::Gameplay:
		renderGameplay();
		break;
      case GameState::EndScreen:
    renderEndScreen();
    break;
	}

	// This clears the screen
	arduboy.clear();

	// Do different things depending on the current game state
	switch(gameState)
	{
	case GameState::TitleScreen:
		renderTitleScreen();
		break;
	case GameState::Gameplay:
		renderGameplay();
		break;
      case GameState::EndScreen:
    renderEndScreen();
    break;
	}

	// This displays the screen
	arduboy.display();
}

void updateTitleScreen()
{
  arduboy.clear();
	// If A is pressed, move to Gameplay state
	if(arduboy.justPressed(A_BUTTON))
	{
		gameState = GameState::Gameplay;
	}
}


void renderTitleScreen()
{
	// You don't need to specify the colour, it defaults to 'BLACK',
	// which means 'draw the image normally'
	// Using 'WHITE' inverts the image
	arduboy.drawBitmap(0, 0, Start, 128, 63);
}
void renderEndScreen()
{
  arduboy.drawBitmap(0, 0, GOver, 128, 64);
    
  // If A is pressed, move to Gameplay state
  if(arduboy.justPressed(A_BUTTON))
  {
    gameState = GameState::TitleScreen;
  }
}

void renderGameplay()
{
	if(arduboy.pressed(A_BUTTON))
	{  

		
		for (int i = 0; i <= 7000; i++)
		{    
		  var++;
      Delay--;
      planety++;
      
			if(playery > 50)
			{
				playery --;
				boosteryR--;
				boosteryL--;
			}
		if ( Height <= 100 ) {
    	Height++;
		}
    if (Height >= 100 ) {
    Height + 2;
   
   }
      if (Height >= 250 ) {
    Height + 3;
   
   }
   
		if (Height > 150 & boosteryL > 19 )
     {
    gameState = GameState::EndScreen;
     }
     


			if (Height > 100 & Height < 150  )
			{
        arduboy.drawBitmap(40,15,Detach, 10, 43, BLACK );
        
				if(arduboy.pressed(A_BUTTON))
				{
						boosterxL++;
						boosterxR--;
           
						boosteryL++;
						boosteryR++;
				}
			}



			arduboy.drawBitmap(0,29, HEIGHT2, 9, 35, BLACK);
			arduboy.setCursor(0, 20);
			arduboy.print(Height);
			arduboy.display();

			for( int backgroundx = 0; backgroundx < 128; backgroundx = backgroundx + 8 )
			{
				for( int backgroundy = 0; backgroundy < 64; backgroundy = backgroundy + 8 )
				{
					arduboy.drawBitmap( backgroundx, backgroundy, background, 8, 8);
				}
			}

			delay(100);

			arduboy.drawBitmap(planety,20, Planet, 43, 17, BLACK);
			arduboy.drawBitmap(playery,playerx, player, 43, 17, BLACK);
			arduboy.drawBitmap(boosteryL,boosterxL, boosterL, 32, 9, BLACK);
			arduboy.drawBitmap(boosteryR,boosterxR, boosterR, 32, 9, BLACK);
			if(var < 40)
			{
				arduboy.drawBitmap(97,15, base2, 32, 32, BLACK);
			}

			if(var > 40)
			{
				arduboy.drawBitmap(base_y,15, base1, 32, 32, BLACK);
				base_y++;
			}

			arduboy.display();
		}
	}
}
