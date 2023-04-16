#include "ball.h"
void Ball::drawBall()
{
   DrawCircle(xCoord, yCoord, ballRadius, ballColor);
}
void Ball::update()
{   
    xCoord += xSpeed;
    yCoord += ySpeed;

    //ball collisions
    if(yCoord + ballRadius >= GetScreenHeight() || yCoord - ballRadius <= 0)
    {
        ySpeed *= -1;
    }

    //bot wins
    if(xCoord + ballRadius >= GetScreenWidth())
    {
        BeginDrawing();
        DrawText("Computer Scored!", 290, 200, 70, WHITE); //display only for 1 second
        cpuScore++;
        EndDrawing();
        sleep(1); // program paused for 1 second
        resetBall();
    }

    //player wins
    if(xCoord - ballRadius <= 0)
    {
        BeginDrawing();
        DrawText("Player Scored!", 320, 200, 70, WHITE); //display only for 1 second
        playerScore++;
        EndDrawing();
        sleep(1); // program paused for 1 second
        resetBall();
    }
}

void Ball::resetBall()
{
    xCoord = GetScreenWidth() / 2;
    yCoord = GetScreenHeight() / 2;

    int speed_choices[2] = {-1, 1};
    xSpeed *= speed_choices[GetRandomValue(0, 1)];
    ySpeed *= speed_choices[GetRandomValue(0,1)];
}
void Ball::setColor(const Color newColor)
{
    ballColor = newColor;
}