// #include<iostream>
// #include<conio.h>
// #include<fstream>
// #include<dos.h> 
// #include <windows.h>
// #include <time.h>

// #define SCREEN_WIDTH 90
// #define SCREEN_HEIGHT 26
// #define WIN_WIDTH 70 
// using namespace std; 

// HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
// COORD CursorPosition;

// void gotoxy(int x, int y){
// 	CursorPosition.X = x;
// 	CursorPosition.Y = y;
// 	SetConsoleCursorPosition(console, CursorPosition);
// }
// void setcursor(bool visible, DWORD size) {
// 	if(size == 0)
// 		size = 20;	
	
// 	CONSOLE_CURSOR_INFO lpCursor;	
// 	lpCursor.bVisible = visible;
// 	lpCursor.dwSize = size;
// 	SetConsoleCursorInfo(console,&lpCursor);
// }

// class car
// {
// 	char car[4][4] = { ' ','T','T',' ', 
// 						'O','&','&','O', 
// 						' ','&','&',' ',
// 						'O','Y','Y','O' }; 
// 	protected:
// 		int carPos = WIN_WIDTH/2;
		
// 	public:
// 		void drawCar(){
// 			for(int i=0; i<4; i++)
// 			{
// 				for(int j=0; j<4; j++)
// 				{
// 					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 					SetConsoleTextAttribute(hConsole, 4);
// 					gotoxy(j+carPos, i+22); cout<<car[i][j];
// 					SetConsoleTextAttribute(hConsole, 7);
// 				}		
// 			}
// 		}
// 		void eraseCar(){
// 			for(int i=0; i<4; i++){
// 				for(int j=0; j<4; j++){
// 					gotoxy(j+carPos, i+22); cout<<" ";
// 				}
// 			}
// 		}
// };

// class enemy
// {
// 	protected:
// 		int enemyY[3];
// 		int enemyX[3];
// 		int enemyFlag[3];
		
// 	public:
// 		void drawEnemy(int ind){
// 			if( enemyFlag[ind] == true ){
// 				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 				SetConsoleTextAttribute(hConsole, 9);
// 				gotoxy(enemyX[ind], enemyY[ind]);   cout<<"****";  
// 				gotoxy(enemyX[ind], enemyY[ind]+1); cout<<" ** "; 
// 				gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"****"; 
// 				gotoxy(enemyX[ind], enemyY[ind]+3); cout<<" ** ";  
		
// 			} 
// 		}
		
// 		void genEnemy(int ind){
// 			enemyX[ind] = 17 + rand()%(33);  
// 		}
		
// 		void eraseEnemy(int ind){
// 			if( enemyFlag[ind] == true ){
// 				gotoxy(enemyX[ind], enemyY[ind]); cout<<"    ";  
// 				gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"    "; 
// 				gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"    "; 
// 				gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"    "; 
// 			} 
// 		}
		
// 		void resetEnemy(int ind){
// 			eraseEnemy(ind);
// 			enemyY[ind] = 1;
// 			genEnemy(ind);
// 		}
// };
// class highscore
// {
// 	protected:
// 		char Hname[20];
// 		int Hscore;	
// 	public:
// 		void displayhighscore(){
// 			system("cls");
// 			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 			SetConsoleTextAttribute(hConsole, 14);
// 			cout<<"Current Highscore.."<<endl<<endl;
// 			cout<<"Name"<<"\t"<<"Score"<<endl<<endl;
// 			SetConsoleTextAttribute(hConsole, 14);
// 			ifstream score("highscore.txt");
// 			score>>Hname>>Hscore;
// 			cout<<Hname<<"\t"<<Hscore;
// 			score.close();
// 			getche();
// 		}
		
// };
// class instruction
// {
	
	
// 	public:
// 		void instructions(){
	
// 			system("cls");
// 			cout<<"Instructions";
// 			cout<<"\n----------------";
// 			cout<<"\n Avoid Cars by moving left or right. ";
// 			cout<<"\n\n Press 'a' to move left";
// 			cout<<"\n Press 'd' to move right";
// 			cout<<"\n Press 'escape' to exit";
// 			cout<<"\n\nPress any key to go back to menu";
// 			getch();
// 		}
		
		
		
// };


// class game : protected enemy, protected car, protected highscore
// {
// 	int score;
// 	char name[20];
// 	int speed;
	
// 	public:
		
// 		void entername(){
// 			system ("cls");
// 			cout<<"Enter your name: ",
// 			cin>>name;
// 		}

// 		void playmenu(){
// 			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 			SetConsoleTextAttribute(hConsole, 14);
// 			gotoxy(WIN_WIDTH + 7, 2);cout<<"Car Game";
// 			gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
// 			gotoxy(WIN_WIDTH + 6, 11);cout<<"----------";
// 			gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
// 			gotoxy(WIN_WIDTH + 7, 14);cout<<"-------- ";
// 			gotoxy(WIN_WIDTH + 7, 15);cout<<"-------- ";
// 			gotoxy(WIN_WIDTH + 2, 16);cout<<" A Key - Left";
// 			gotoxy(WIN_WIDTH + 2, 17);cout<<" D Key - Right"; 
			
// 			gotoxy(18, 4);cout<<"Welcome "<<name;
// 			gotoxy(18, 7);cout<<"Press any key to Start..";getch();
// 			gotoxy(18, 4);cout<<"                        ";
// 			gotoxy(18, 7);cout<<"                        ";
// 			SetConsoleTextAttribute(hConsole, 7);
// 		}
		
// 		void setvalue(){	
// 			carPos = -1 + WIN_WIDTH/2;
// 			score = 0;	
// 			speed = 0;
// 			enemyFlag[0] = 1;
// 			enemyFlag[1] = 0;
// 			enemyY[0] = enemyY[1] = 1;
// 		}
				
// 		void drawBorder(){  
// 			for(int i=0; i<SCREEN_HEIGHT; i++){
// 				for(int j=0; j<17; j++){
// 					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 					SetConsoleTextAttribute(hConsole, 10);
// 					gotoxy(0+j,i); cout<<"1";
// 					gotoxy(WIN_WIDTH-j,i); cout<<"1";
// 					SetConsoleTextAttribute(hConsole, 7);
// 				}
// 			} 
// 			for(int i=0; i<SCREEN_HEIGHT; i++){
// 				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 				SetConsoleTextAttribute(hConsole, 10);
// 				gotoxy(SCREEN_WIDTH,i); cout<<"1";
// 				SetConsoleTextAttribute(hConsole, 7);
// 			} 
// 		} 
		
// 		int collision(int ind){
// 			if( enemyY[ind]+4 >= 23 ){
// 				if( enemyX[ind] + 4 - carPos >= 0 && enemyX[ind] + 4 - carPos < 9  ){
// 					return 1;
// 				}
// 			}
// 			return 0;
// 		}
		
// 		void gameover(){
// 			system("cls");
// 			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 			SetConsoleTextAttribute(hConsole, 4);
// 			cout<<endl;
// 			cout<<"\t\t------------------------------"<<endl;
// 			cout<<"\t\t-------- GAME OVER -----------"<<endl;
	
// 			cout<<"\t\t------------------------------"<<endl<<endl;
// 			SetConsoleTextAttribute(hConsole, 7);
// 			cout<<"\t\tPlayer Name:  "<<name<<endl<<endl;
// 			cout<<"\t\t-------- You scored: "<<score;
// 			cout<<" -------"<<endl<<endl;
// 			checkHscore(score);
// 			cout<<"\t\tPress escape key to go back to menu.";
// 			getch();
// 			while(1){
// 				char ch = getch();
// 				if( ch==27){
// 					break;
// 				}
// 			}
// 		}
// 		void updateScore(){
// 			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 			SetConsoleTextAttribute(hConsole, 14);
// 			gotoxy(WIN_WIDTH + 7, 5);cout<<"Score: "<<score<<endl;
// 		}
// 		void checkHscore(int value){
// 			int score=value;
// 			ifstream check("highscore.txt");
// 			check>>Hname>>Hscore;
// 			if(score>Hscore){
// 				writeHighScore(score);
// 				cout<<"\t\tCongratulations "<< name <<endl<<" \t\tNew High Score!!"<<endl<<endl;
// 			}
// 			check.close();
// 		}
// 		void writeHighScore(int score) {
// 		    FILE *fp;
// 		    fp = fopen("highscore.txt", "w");
// 		    fprintf(fp, "%s %d",name,score);
// 		    fclose(fp);
// 		}

// 		void play(){
// 			entername();
// 			setvalue();  
// 			system("cls"); 
// 			drawBorder(); 
// 			updateScore();
// 			genEnemy(0);
// 			genEnemy(1);
// 			playmenu();
				
// 			while(1){
// 				if(kbhit()){
// 					char ch = getch();
// 					if( ch=='a' || ch=='A' ){
// 						if( carPos > 18 )
// 							carPos -= 8;
// 					}
// 					if( ch=='d' || ch=='D' ){
// 						if( carPos < 50 )
// 							carPos += 8;
// 					}

// 					if(ch==27){
// 						break;
// 					}
// 				} 
				
// 				drawCar(); 
// 				drawEnemy(0); 
// 				drawEnemy(1); 
				
// 				if( collision(0) == 1  ){
// 					gameover();
// 					return;
// 				}
// 				if( collision(1) == 1  ){
// 					gameover();
// 					return;
// 				}  
// 				Sleep(50 - speed);
// 				eraseCar();
// 				eraseEnemy(0);
// 				eraseEnemy(1);
				
// 				if( enemyY[0] == 10 )
// 					if( enemyFlag[1] == 0 )
// 						enemyFlag[1] = 1;
				
// 				if( enemyFlag[0] == 1 )
// 					enemyY[0] += 1;
				
// 				if( enemyFlag[1] == 1 )
// 					enemyY[1] += 1;
				 
// 				if( enemyY[0] > SCREEN_HEIGHT-4 ){
// 					resetEnemy(0);
// 					score++;
// 					updateScore();
// 				}
// 				if( enemyY[1] > SCREEN_HEIGHT-4 ){
// 					resetEnemy(1);
// 					score++;
// 					updateScore();
// 				}
				
// 				if(score == 0){
// 					speed=1;
// 				}
// 				if(score == 5){
// 					speed=10;
// 				}
// 				if(score == 15){
// 					speed=20;
// 				}
// 				if(score == 25){
// 					speed=30;
// 				}
// 				if(score == 35){
// 					speed=35;
// 				}
// 				if(score == 45){
// 					speed=40;
// 				}
// 			}
// 		}
	
			
		
// };



// int main()
// {
// 	car c;
// 	enemy e;
// 	instruction i;
// 	game g;
// 	highscore h;
	
// 	setcursor(0,0); 
// 	srand( (unsigned)time(NULL)); 
	 
// 	do{
// 		system("cls");
// 		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 		SetConsoleTextAttribute(hConsole, 14);
// 		gotoxy(10,5);  cout << "==============================\n";
// 	    gotoxy(10,6);  cout << "|         WELCOME TO         |\n";
// 	    gotoxy(10,7);  cout << "==============================\n";
// 	    gotoxy(10,8);  cout << "|                            |\n";
// 	    gotoxy(10,9);  cout << "|          CAR GAME          |\n";
// 	    gotoxy(10,10); cout << "|    ____________________    |\n";
// 	    gotoxy(10,11); cout << "|                            |\n";
// 	    gotoxy(10,12); cout << "|      1. Start Game         |\n";
// 	    gotoxy(10,13); cout << "|      2. Instructions       |\n";
// 	    gotoxy(10,14); cout << "|      3. Highscore          |\n";
// 	    gotoxy(10,15); cout << "|      3. Exit               |\n";
// 	    gotoxy(10,16); cout << "|                            |\n";
// 	    gotoxy(10,17); cout << "==============================\n";
// 		gotoxy(10,18); cout<<"Select option: ";
// 		SetConsoleTextAttribute(hConsole, 7);
// 		char op = getche();
		
// 		if( op=='1')g.play() ;
// 		else if( op=='2') i.instructions();
// 		else if( op=='3') h.displayhighscore();
// 		else if( op=='4') exit(0);
		
// 	}while(1);
	
// 	return 0;
// }


#include <iostream>
#include <conio.h>
#include <fstream>
#include <dos.h>
#include <windows.h>
#include <time.h>

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
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

class car {
    char car[4][4] = { ' ',  'A',  ' ',
                       'O', '|', '|', 'O',
                       ' ', '|', '|', ' ',
                       'O', '[', ']', 'O' };
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

class enemy {
protected:
    int enemyY[3];
    int enemyX[3];
    int enemyFlag[3];
public:
    void drawEnemy(int ind) {
        if (enemyFlag[ind] == true) {
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
    }

    void eraseEnemy(int ind) {
        if (enemyFlag[ind] == true) {
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
        enemyY[ind] = 1;
        genEnemy(ind);
    }
};

class highscore {
protected:
    char Hname[20];
    int Hscore;
public:
    void displayhighscore() {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Current Highscore.." << endl << endl;
        cout << "Name" << "\t" << "Score" << endl << endl;
        SetConsoleTextAttribute(hConsole, 14);
        ifstream score("highscore.txt");
        score >> Hname >> Hscore;
        cout << Hname << "\t" << Hscore;
        score.close();
        getche();
    }
};

class instruction {
public:
    void instructions() {
        system("cls");
        cout << "hi";
        cout << "\n----------------";
        cout << "\n Avoid Cars by moving left or right. ";
        cout << "\n\n Press 'a' to move left";
        cout << "\n Press 'd' to move right";
        cout << "\n Press 'escape' to exit";
        cout << "\n\nPress any key to go back to menu";
        getch();
    }
};

class game : protected enemy, protected car, protected highscore {
    int score;
    char name[20];
    int speed;
    int lives;  

public:
    void entername() {
        system("cls");
        cout << "Enter your name: ";
        cin >> name;
    }

    void playmenu() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(WIN_WIDTH + 7, 2);
        cout << "Car Game";
        gotoxy(WIN_WIDTH + 6, 4);
        cout << "----------";
        gotoxy(WIN_WIDTH + 6, 11);
        cout << "----------";
        gotoxy(WIN_WIDTH + 7, 12);
        cout << "Control ";
        gotoxy(WIN_WIDTH + 7, 14);
        cout << "-------- ";
        gotoxy(WIN_WIDTH + 7, 15);
        cout << "-------- ";
        gotoxy(WIN_WIDTH + 2, 16);
        cout << " A Key - Left";
        gotoxy(WIN_WIDTH + 2, 17);
        cout << " D Key - Right";

        gotoxy(18, 4);
        cout << "Welcome " << name;
        gotoxy(18, 7);
        cout << "Press any key to Start..";
        getch();
        gotoxy(18, 4);
        cout << "                        ";
        gotoxy(18, 7);
        cout << "                        ";
        SetConsoleTextAttribute(hConsole, 7);
    }

    void setvalue() {
        carPos = -1 + WIN_WIDTH / 2;
        score = 0;
        speed = 0;
        lives = 3;  
        enemyFlag[0] = 1;
        enemyFlag[1] = 0;
        enemyY[0] = enemyY[1] = 1;
    }

    void drawBorder() {
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < 17; j++) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 10);
                gotoxy(0 + j, i);
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
        checkHscore(score);
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
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(WIN_WIDTH + 7, 5);
        cout << "Score: " << score << endl;
    }

    void updateLives() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12); //live lai red color set garay
        gotoxy(WIN_WIDTH + 7, 6);
        cout << "Lives: " << lives << endl;
    }

    void checkHscore(int score) {
        ifstream check("highscore.txt");
        int hscore;
        char hname[20];
        check >> hname >> hscore;
        if (score > hscore) {
            check.close();
            writeHighScore(score);
            system("cls");
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 10);
            cout << "Current Highscore" << endl << endl;
            cout << "Name: " << name << endl;
            cout << "Score: " << score << endl << endl;
            cout << " \t\tNew High Score!!" << endl << endl;
        }
        check.close();
    }

    void writeHighScore(int score) {
        FILE* fp;
        fp = fopen("highscore.txt", "w");
        fprintf(fp, "%s %d", name, score);
        fclose(fp);
    }

    void play() {
        entername();
        setvalue();
        system("cls");
        drawBorder();
        updateScore();
        updateLives();
        genEnemy(0);
        genEnemy(1);
        playmenu();

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
                lives--;
                if (lives <= 0) {
                    gameover();
                    return;
                }
                
                resetEnemy(0);
                resetEnemy(1);
                updateLives();
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


            if (score == 0) {
                speed = 5;
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
};

int main() {
    car c;
    enemy e;
    instruction i;
    game g;
    highscore h;

    setcursor(0, 0);
    srand((unsigned)time(NULL));

    do {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(10, 5);
        cout << "==============================" << endl;
        gotoxy(10, 6);
        cout << "|         WELCOME TO         |" << endl;
        gotoxy(10, 7);
        cout << "==============================" << endl;
        gotoxy(10, 8);
        cout << "|                            |" << endl;
        gotoxy(10, 9);
        cout << "|          CAR GAME          |" << endl;
        gotoxy(10, 10);
        cout << "|    ____________________    |" << endl;
        gotoxy(10, 11);
        cout << "|                            |" << endl;
        gotoxy(10, 12);
        cout << "|      1. Start Game         |" << endl;
        gotoxy(10, 13);
        cout << "|      2. Instruction     |" << endl;
        gotoxy(10, 14);
        cout << "|      3. Highscore          |" << endl;
        gotoxy(10, 15);
        cout << "|      4. Exit               |" << endl;
        gotoxy(10, 16);
        cout << "|                            |" << endl;
        gotoxy(10, 17);
        cout << "==============================" << endl;
        gotoxy(10, 18);
        cout << "Select option: ";
        SetConsoleTextAttribute(hConsole, 7);
        char op = getche();

        if (op == '1')
            g.play();
        else if (op == '2')
            i.instructions();
        else if (op == '3')
            h.displayhighscore();
        else if (op == '4')
            exit(0);

    } while (1);

    return 0;
}

