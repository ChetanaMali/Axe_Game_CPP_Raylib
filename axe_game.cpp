#include "raylib.h"
int main()
{
    //window initialization
    int width = 600;
    int height = 400;
    InitWindow(width, height, "Chetana's Window");

    //Variables to draw a Circle
     int radius = 25;
     int circle_x = width/2;
     int circle_y = height - radius;
     int l_circle_x = circle_x - radius;
     int r_circle_x = circle_x + radius;
     int u_circle_y = circle_y - radius;
     int b_circle_y = circle_y + radius;

    //Variables to draw a Rectangle
    int axePos_x = 300; //
    int axePos_y = 0;
    int rectWidth = 50;
    int rectheight = 50;
    int direction = 7;
    int l_axe_x = axePos_x;
    int r_axe_x = axePos_x + rectWidth;
    int u_axe_y = axePos_y;
    int b_axe_y = axePos_y + rectheight;
    
    // here we set the collision for axe
    bool collision_with_axe = ((l_axe_x <= r_circle_x) && 
                                (r_axe_x >= l_circle_x) && 
                                (u_axe_y <= b_circle_y) && 
                                (b_axe_y >= u_circle_y));

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
      
        if(collision_with_axe){
            DrawText("Game Over!", width/2, height/2, 25, RED);
        }
        else{
            // GAME LOGIC START
            //update the edges
            l_circle_x = circle_x - radius;
            r_circle_x = circle_x + radius;
            u_circle_y = circle_y - radius;
            b_circle_y = circle_y + radius;

             l_axe_x = axePos_x;
             r_axe_x = axePos_x + rectWidth;
             u_axe_y = axePos_y;
             b_axe_y = axePos_y + rectheight;

             //update the collision_with_axe
             collision_with_axe = ((l_axe_x <= r_circle_x) && 
                                (r_axe_x >= l_circle_x) && 
                                (u_axe_y <= b_circle_y) && 
                                (b_axe_y >= u_circle_y));

            //  LOGIC FOR DRAW CIRCLE sand Rectangles AND AVOID PASS THROUGH THE EDGES OF WINDOW WITH ANOY DIMENTIONS
            DrawCircle(circle_x, circle_y, radius, BLUE);
            DrawRectangle(axePos_x, axePos_y, rectWidth, rectheight, RED);

            axePos_y +=  direction;

            // if(axePos_y > height || axePos_y < 0){
            //     direction = -direction;
            // }
             if(axePos_y > height){
                axePos_x = GetRandomValue(0, width - rectWidth/2);
                axePos_y = 0;
                DrawRectangle(axePos_x, axePos_y, rectWidth, rectheight, RED);
            }

            
            // Player movement with WSAD also checking the circle edge to not go out of the window 
            if(IsKeyDown(KEY_A) && circle_x > radius){
                circle_x = circle_x - 5;
            }
            if(IsKeyDown(KEY_D) && circle_x < width - radius){
                circle_x = circle_x + 5;
            }
            if (IsKeyDown(KEY_W) && circle_y > radius)
            {
                circle_y = circle_y - 5;
            }
            if(IsKeyDown(KEY_S) && circle_y < height - radius){
                circle_y = circle_y + 5;
            }

           //GAME LOGIC END
        }
        
        EndDrawing();
    }
    
}