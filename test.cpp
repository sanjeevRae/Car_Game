#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <ctime>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70 

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

class Car {
    char car[4][4] = { 
        ' ', 'T', 'T', ' ', 
        'O', '&', '&', 'O', 
        ' ', '&', '&', ' ', 
        'O', 'Y', 'Y', 'O' 
    };
protected:
    int carPos = WIN_WIDTH / 2;
public:
    void drawCar() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 4);
                gotoxy(j + carPos, i + 22);
                cout << car[i][j];
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
    }
    
    void eraseCar() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                gotoxy(j + carPos, i + 22);
                cout << " ";
            }
        }
    }
};

class Enemy {
protected:
    int enemyY[2];
    int enemyX[2];
    bool enemyFlag[2];
public:
    void drawEnemy(int ind) {
        if (enemyFlag[ind]) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 9);
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "****";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << " ** ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "****";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << " ** ";
        }
    }

    void genEnemy(int ind) {
        enemyX[ind] = 17 + rand() % (33);
        enemyY[ind] = 1; // Ensure enemies start from the top
        enemyFlag[ind] = true;
    }

    void eraseEnemy(int ind) {
        if (enemyFlag[ind]) {
            gotoxy(enemyX[ind], enemyY[ind]);
            cout << "    ";
            gotoxy(enemyX[ind], enemyY[ind] + 1);
            cout << "    ";
            gotoxy(enemyX[ind], enemyY[ind] + 2);
            cout << "    ";
            gotoxy(enemyX[ind], enemyY[ind] + 3);
            cout << "    ";
        }
    }

    void resetEnemy(int ind) {
        eraseEnemy(ind);
        genEnemy(ind);
    }
};

class HighScore {
protected:
    char Hname[20];
    int Hscore;
public:
    void displayHighScore() {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Current Highscore..\n\n";
        cout << "Name\tScore\n\n";
        SetConsoleTextAttribute(hConsole, 14);
        ifstream score("highscore.txt");
        score >> Hname >> Hscore;
        cout << Hname << "\t" << Hscore;
        score.close();
        getche();
    }
};

class Instruction {
public:
    void instructions() {
        system("cls");
        cout << "Instructions";
        cout << "\n----------------";
        cout << "\nAvoid Cars by moving left or right.";
        cout << "\n\nPress 'a' to move left";
        cout << "\nPress 'd' to move right";
        cout << "\nPress 'escape' to exit";
        cout << "\n\nPress any key to go back to menu";
        getch();
    }
};

class Game : protected Enemy, protected Car, protected HighScore {
    int score;
    int lives;
    char name[20];
    int speed;
public:
    void enterName() {
        system("cls");
        cout << "Enter your name: ";
        cin >> name;
    }

    void playMenu() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(WIN_WIDTH + 7, 2); cout << "Car Game";
        gotoxy(WIN_WIDTH + 6, 4); cout << "----------";
        gotoxy(WIN_WIDTH + 6, 11); cout << "----------";
        gotoxy(WIN_WIDTH + 7, 12); cout << "Control ";
        gotoxy(WIN_WIDTH + 7, 14); cout << "-------- ";
        gotoxy(WIN_WIDTH + 7, 15); cout << "-------- ";
        gotoxy(WIN_WIDTH + 2, 16); cout << "A Key - Left";
        gotoxy(WIN_WIDTH + 2, 17); cout << "D Key - Right"; 
        
        gotoxy(18, 4); cout << "Welcome " << name;
        gotoxy(18, 7); cout << "Press any key to Start..";
        getch();
        gotoxy(18, 4); cout << "                        ";
        gotoxy(18, 7); cout << "                        ";
        SetConsoleTextAttribute(hConsole, 7);
    }

    void setValue() {
        lives = 3;
        carPos = WIN_WIDTH / 2;
        score = 0;
        speed = 0;
        enemyFlag[0] = true;
        enemyFlag[1] = false;
        enemyY[0] = enemyY[1] = 1;
        genEnemy(0);
        genEnemy(1);
    }

    void drawBorder() {
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < 17; j++) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 10);
                gotoxy(j, i);
                cout << "1";
                gotoxy(WIN_WIDTH - j, i);
                cout << "1";
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 10);
            gotoxy(SCREEN_WIDTH, i);
            cout << "1";
            SetConsoleTextAttribute(hConsole, 7);
        }
    }

    int collision(int ind) {
        if (enemyY[ind] + 4 >= 23) {
            if (enemyX[ind] + 4 - carPos >= 0 && enemyX[ind] + 4 - carPos < 9) {
                return 1;
            }
        }
        return 0;
    }

    void gameOver() {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 4);
        cout << endl;
        cout << "\t\t------------------------------" << endl;
        cout << "\t\t-------- GAME OVER -----------" << endl;
        cout << "\t\t------------------------------" << endl << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\t\tPlayer Name:  " << name << endl << endl;
        cout << "\t\t-------- You scored: " << score << " -------" << endl << endl;
        checkHighScore(score);
        cout << "\t\tRemaining Lives: " << lives << endl;
        cout << "\t\tPress escape key to go back to menu.";
        getch();
        while (true) {
            char ch = getch();
            if (ch == 27) {
                break;
            }
        }
    }

    void updateScore() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(WIN_WIDTH + 7, 5); cout << "Score: " << score << endl;
    }

    void checkHighScore(int value) {
        int currentScore = value;
        ifstream check("highscore.txt");
        check >> Hname >> Hscore;
        if (currentScore > Hscore) {
            writeHighScore(currentScore);
            cout << "\t\tCongratulations " << name << endl << "\t\tNew High Score!!" << endl << endl;
        }
        check.close();
    }

    void writeHighScore(int score) {
        ofstream fp("highscore.txt");
        fp << name << " " << score;
        fp.close();
    }

    void updateLives() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(WIN_WIDTH + 7, 7); cout << "Lives: ";
        for (int i = 0; i < lives; i++) {
            cout << "❤️";
        }
        cout << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    void play() {
        enterName();
        setValue();
        system("cls");
        drawBorder();
        updateScore();
        playMenu();

        while (true) {
            if (_kbhit()) {
                char ch = _getch();
                switch (ch) {
                    case 'a':
                    case 'A':
                        if (carPos > 18) carPos -= 8;
                        break;
                    case 'd':
                    case 'D':
                        if (carPos < 50) carPos += 8;
                        break;
                }

                drawCar();
                drawEnemy(0);
                drawEnemy(1);

                if (collision(0) == 1 || collision(1) == 1) {
                    lives--;
                    updateLives();

                    if (lives == 0) {
                        gameOver();
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

                if (enemyY[0] == 10 && !enemyFlag[1]) enemyFlag[1] = true;
                if (enemyFlag[0]) enemyY[0]++;
                if (enemyFlag[1]) enemyY[1]++;

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

                if (score == 5) speed = 10;
                if (score == 15) speed = 20;
                if (score == 25) speed = 30;
                if (score == 35) speed = 35;
                if (score == 45) speed = 40;
            }
        }
    }
};

int main() {
    Car c;
    Enemy e;
    Instruction i;
    Game g;
    HighScore h;

    setcursor(0, 0);
    srand((unsigned)time(NULL));

    do {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(10, 5);
        cout << "==============================\n";
        gotoxy(10, 6);
        cout << "|         WELCOME TO         |\n";
        gotoxy(10, 7);
        cout << "==============================\n";
        gotoxy(10, 8);
        cout << "|                            |\n";
        gotoxy(10, 9);
        cout << "|          CAR GAME          |\n";
        gotoxy(10, 10);
        cout << "|    ____________________    |\n";
        gotoxy(10, 11);
        cout << "|                            |\n";
        gotoxy(10, 12);
        cout << "|      1. Start Game         |\n";
        gotoxy(10, 13);
        cout << "|      2. Instructions       |\n";
        gotoxy(10, 14);
        cout << "|      3. Highscore          |\n";
        gotoxy(10, 15);
        cout << "|      4. Exit               |\n";
        gotoxy(10, 16);
        cout << "|                            |\n";
        gotoxy(10, 17);
        cout << "==============================\n";
        gotoxy(10, 18);
        cout << "Select option: ";
        SetConsoleTextAttribute(hConsole, 7);
        char op = getche();

        switch (op) {
            case '1': g.play(); break;
            case '2': i.instructions(); break;
            case '3': h.displayHighScore(); break;
            case '4': exit(0); break;
            default: break;
        }

    } while (true);

    return 0;
}
