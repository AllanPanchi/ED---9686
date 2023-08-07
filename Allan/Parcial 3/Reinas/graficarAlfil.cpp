/*#include <graphics.h>
#include <math.h>
#include <conio.h>

void drawChessBoard(int x, int y, int width, int height)
{
   int i, j;
   for(i = x; i < x + width; i += width / 8)
   {
      for(j = y; j < y + height; j += height / 8)
      {
         if((i + j) % (2 * (width / 8)) == 0)
         {
            setfillstyle(SOLID_FILL, WHITE);
         }
         else
         {
            setfillstyle(SOLID_FILL, BLACK);
         }
         floodfill(i + width / 16, j + height / 16, WHITE);
      }
   }
}

void drawBishop(int x, int y, int width, int height)
{
   int r = width / 4;
   float theta;

   for(theta = 0; theta <= 360; theta += 0.01)
   {
      int x1 = r * cos(theta) + x + width / 2;
      int y1 = r * sin(theta) + y + height / 2;
      putpixel(x1, y1, WHITE);
   }
}

int main()
{
   	int gd = DETECT, gm;
   	initgraph(&gd, &gm, "");
   	int x = 50, y = 50, width = 400, height = 400;
  	setfillstyle(SOLID_FILL, 6);
  	fillellipse(100,100, 5, 10);
   	fillellipse(100,120, 10, 15);
   	bar(90,135,110,150);
   	getch();
   	closegraph();
   	return 0;
}

