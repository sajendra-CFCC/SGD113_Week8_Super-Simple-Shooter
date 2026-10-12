#include "raylib.h"
#include "raymath.h"

int main() {
	int screenWidth = 800;
	int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "Super Awesome Game");
	SetTargetFPS(60);

	while( WindowShouldClose() == false ) { //begin main repeating game loop
		//check for inputs
		
		//update state
		

		//do your drawing    
		BeginDrawing(); 
		
		ClearBackground(BLACK);
		DrawText("Some text drawn on screen (HUD)", 10, 20, 20, LIGHTGRAY);
		DrawText("And we will add a second line", 10, 40, 20, BLUE);
		
        // 1. Base Face
        DrawCircle(400, 300, 150, YELLOW);          // Main face background
        DrawCircleLines(400, 300, 150, BLACK);     // Face outline

        // 2. Eyes
        DrawCircle(340, 240, 16, BLACK);           // Left eye
        DrawCircle(460, 240, 16, BLACK);           // Right eye
        
        // 3. Smiling Mouth (Overlaying Shapes)
        // A large black circle forms the bottom curve of the smile
        DrawCircle(400, 340, 60, BLACK);
        // A slightly higher yellow circle blocks out the top half to create a crescent smile
        DrawCircle(400, 325, 60, YELLOW);
        
        // Nose made of lines (Triangle)
        DrawLine(400, 280, 385, 315, BLACK); // Left slope
        DrawLine(400, 280, 415, 315, BLACK); // Right slope
        DrawLine(385, 315, 415, 315, BLACK); // Bottom base
        
		EndDrawing();
	
	} // end main loop

	CloseWindow();
	return 0;
}


