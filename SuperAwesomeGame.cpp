#include "raylib.h"
#include "raymath.h"

#include <iostream>

int main() {
	int screenWidth = 800;
	int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "Super Awesome Game");
	SetTargetFPS(60);

	const int ENEMY_START_SPEED = 4;
	const int ENEMY_WIDTH = 100;
	const int ENEMY_HEIGHT = 50;
	const Color ENEMY_COLOR = RED;

	const Vector2 SHOOT_POS{ screenWidth / 2, screenHeight - 100 };
	const int BULLET_SIZE{ 10 };
	const Color BULLET_COLOR = WHITE;
	const int BULLET_SPEED = 10;
	
	Rectangle enemy{ screenWidth / 2, 0, ENEMY_WIDTH, ENEMY_HEIGHT };
	int enemySpeed = -ENEMY_START_SPEED;

	Vector2 bullet_pos = SHOOT_POS;
	int bullet_current_speed = 0;

	while( WindowShouldClose() == false ) { //begin main repeating game loop
		//check for inputs
		if (IsKeyPressed(KEY_SPACE)) {
			bullet_pos = SHOOT_POS;
			bullet_current_speed = -BULLET_SPEED;
		}
		
		//update state
		enemy.x += enemySpeed;
		if (enemy.x < 0 || enemy.x > screenWidth) { //gone off the left of the screen
			enemySpeed *= -1;
		}

		bullet_pos.y += bullet_current_speed;

		if (CheckCollisionCircleRec(bullet_pos, BULLET_SIZE, enemy)) {
			std::cout << "HIT!!\n";
			enemy.x = 0;
			enemySpeed = ENEMY_START_SPEED;
		}

		//do your drawing    
		BeginDrawing(); 
		
		ClearBackground(BLACK);
		DrawRectangleRec(enemy, ENEMY_COLOR);

		if(bullet_current_speed != 0) {
			DrawCircleV(bullet_pos, BULLET_SIZE, BULLET_COLOR);
		}
        
		EndDrawing();
	
	} // end main loop

	CloseWindow();
	return 0;
}


