#include <stdio.h>
#include <Windows.h>
void gotoxy(int x, int y)
{
    COORD pos = { x*2 , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setColor(short backgroundColor, short textColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backgroundColor << 4) + textColor);
}
void cursorHide()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void drawVerticalLine()
{

}
void drawHorizantalLine()
{

}
int main()
{
    cursorHide();
    int myX = 0, myY = 0;
    printf("*");
    while (1)
    {
        char movement = getch();
        if (movement == 'w')
            myY--;
        else if (movement == 's')
            myY++;
        else if (movement == 'a')
            myX--;
        else if (movement == 'd')
            myX++;

        system("cls");
        gotoxy(myX, myY);
        printf("*");
    }
    
}