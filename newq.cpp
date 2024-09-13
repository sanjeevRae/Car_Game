#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = { ' ','±','±',' ',
                   '±','±','±','±',
                   ' ','±','±',' ',
                   '±','±','±','±' };

int carPos;
int score = 0;
int speed = 0;
int lives = 3;
string name;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) {
        size = 20;
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < 17; j++) {
            gotoxy(0 + j, i); cout << "±";
            gotoxy(WIN_WIDTH - j, i); cout << "±";
        }
    }
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        gotoxy(SCREEN_WIDTH, i); cout << "±";
    }
}

void genEnemy(int ind) {
    enemyX[ind] = 17 + rand() % (33);
}

void drawEnemy(int ind) {
    if (enemyFlag[ind] == true) {
        gotoxy(enemyX[ind], enemyY[ind]);   cout << "****";
        gotoxy(enemyX[ind], enemyY[ind] + 1); cout << " ** ";
        gotoxy(enemyX[ind], enemyY[ind] + 2); cout << "****";
        gotoxy(enemyX[ind], enemyY[ind] + 3); cout << " ** ";
    }
}

void eraseEnemy(int ind) {
    if (enemyFlag[ind] == true) {
        gotoxy(enemyX[ind], enemyY[ind]);   cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 1); cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 2); cout << "    ";
        gotoxy(enemyX[ind], enemyY[ind] + 3); cout << "    ";
    }
}

void resetEnemy(int ind) {
    eraseEnemy(ind);
    enemyY[ind] = 1;
    genEnemy(ind);
}

void drawCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gotoxy(j + carPos, i + 22); cout << car[i][j];
        }
    }
}

void eraseCar() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gotoxy(j + carPos, i + 22); cout << " ";
        }
    }
}

int collision(int ind) {
    if (enemyY[ind] + 4 >= 23) {
        if (enemyX[ind] + 4 - 1 >= carPos && enemyX[ind] <= carPos + 4 - 1) {
            return 1;
        }
    }
    return 0;
}

void gameover() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    cout << endl;
    cout << "\t\t------------------------------" << endl;
    cout << "\t\t-------- GAME OVER -----------" << endl;
    cout << "\t\t------------------------------" << endl << endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "\t\tPlayer Name:  " << name << endl << endl;
    cout << "\t\t-------- You scored: " << score;
    cout << " -------" << endl << endl;
    cout << "\t\tRemaining Lives: " << lives << endl;  // Show remaining lives
    cout << "\t\tPress escape key to go back to menu.";
    getch();
    while (1) {
        char ch = getch();
        if (ch == 27) {
            break;
        }
    }
}

void updateScore() {
    gotoxy(WIN_WIDTH + 7, 5); cout << "Score: " << score << endl;
}

void updateLives() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    gotoxy(WIN_WIDTH + 7, 7); cout << "Lives: ";
    for (int i = 0; i < lives; i++) {
        cout << "❤️";  // Display a heart for each life
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void setvalue() {
    carPos = -1 + WIN_WIDTH / 2;
    score = 0;
    speed = 0;
    lives = 3;  // Initialize lives to 3
    enemyFlag[0] = 1;
    enemyFlag[1] = 0;
    enemyY[0] = enemyY[1] = 1;
}

void play() {
    setvalue();
    system("cls");
    drawBorder();
    updateScore();
    updateLives();  // Display lives initially
    genEnemy(0);
    genEnemy(1);

    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 'a' || ch == 'A') {
                if (carPos > 18)
                    carPos -= 8;
            }
            if (ch == 'd' || ch == 'D') {
                if (carPos < 50)
                    carPos += 8;
            }
            if (ch == 27) {
                break;
            }
        }

        drawCar();
        drawEnemy(0);
        drawEnemy(1);

        if (collision(0) == 1 || collision(1) == 1) {
            lives--;  // Decrease lives by 1
            updateLives();  // Update the lives display

            if (lives == 0) {  // If no lives are left, end the game
                gameover();
                return;
            } else {
                resetEnemy(0);
                resetEnemy(1);
            }
        }

        Sleep(50 - speed);
        eraseCar();
        eraseEnemy(0);
        eraseEnemy(1);

        if (enemyY[0] == 10)
            if (enemyFlag[1] == 0)
                enemyFlag[1] = 1;

        if (enemyFlag[0] == 1)
            enemyY[0] += 1;

        if (enemyFlag[1] == 1)
            enemyY[1] += 1;

        if (enemyY[0] > SCREEN_HEIGHT - 4) {
            resetEnemy(0);
            score++;
            updateScore();
        }
        if (enemyY[1] > SCREEN_HEIGHT - 4) {
            resetEnemy(1);
            score++;
            updateScore();
        }

        if (score == 5) {
            speed = 10;
        }
        if (score == 15) {
            speed = 20;
        }
        if (score == 25) {
            speed = 30;
        }
        if (score == 35) {
            speed = 35;
        }
        if (score == 45) {
            speed = 40;
        }
    }
}

int main() {
    setcursor(0, 0);
    srand((unsigned)time(NULL));

    do {
        system("cls");
        gotoxy(10, 5); cout << " -------------------------- ";
        gotoxy(10, 6); cout << " |        Car Game        | ";
        gotoxy(10, 7); cout << " -------------------------- ";
        gotoxy(10, 9); cout << "1. Start Game";
        gotoxy(10, 10); cout << "2. Quit";
        gotoxy(10, 11); cout << "Select option: ";
        char op = getche();

        if (op == '1') play();
        else if (op == '2') exit(0);

    } while (1);

    return 0;
}
