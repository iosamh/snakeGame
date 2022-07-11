#include <iostream>
#include <time.h>
#include <string>

int main() {

	int n,t,counter = 0;
	std::string b;



	std::cout << "Enter the number" << std::endl;
	std::cin >> n;

	int i = 0;
	t = n;
	while (t > 0) {
		i++;
		if (t > 1) {
			t /= 2;
		}
		else {
			break;
		}
	}
	
	std::cout << i << " bit" << std::endl;

	
	t = n;

	for (; i > 0; i--) {

		if (t - pow(2, i - 1) >= 0) {
			t = t - pow(2, i - 1);
			b += "1";
			std::cout << "1";
		}
		else if ((t - pow(2, i - 1) == 2)&&(i ==2)) {
			std::cout << "1";
			b += "1";
			continue;
		}
		else if ((t - pow(2, i - 1) == 1) && (i == 1)) {
			std::cout << "1";
			b += "1";
			continue;
		}
		else {
			counter++; 
			b += "0";
			std::cout << "0";
		}
	}

	std::cout << std::endl << "zeros number :" << counter << std::endl;
		
	int maxG = 0, counterG = 0;
	bool last1 = false;
	//std::cout << b << std::endl;


	i = b.length();
	while (i>0) {
		if (b[i-1] == '0') {
			if (last1) {
				counterG++;
			}
		}
		else if (b[i-1] == '1') {
			last1 = true;
			if (maxG < counterG) {
				maxG = counterG;
			}
			counterG = 0;
		}
		i--;
	}
	std::cout << "gaps length: " << maxG << std::endl;






		/*

		if (t % 2 == 0) {
			counter++;
		}

		if (t >= 0) {
			counter++;
		}

		//t = t - pow(2, i);
		//t = n - t;
	}


	for (int  i = 0; n!=0; i++)
	{

	}

	*/


	
}

















/*#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;


void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
}
void Draw() {
	system("cls");



	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	} cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			if (j == 0) {
				cout << "#";
			}

			if (i == y && j == x) {
				cout << "0";
			}
			else if (i == fruitY && j == fruitX) {
				cout << "f";
			}
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print) {
					cout << " ";
				}
			}


			if (j == width - 1) {
				cout << "#";
			}

		}
		cout << endl;
	}


	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}cout << endl;

	cout << "Score:" << score;

}
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT; break;
		case 'd':
			dir = RIGHT; break;
		case 'w':
			dir = UP; break;
		case 's':
			dir = DOWN; break;

		case 'x':
			gameOver = true; break;


		}
	}
}
void Logic() {

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}



	switch (dir) {
	case LEFT:
		--x; break;
	case RIGHT:
		++x; break;
	case UP:
		--y; break;
	case DOWN:
		++y; break;
	}

	if ((y == -1 || y == height) || (x == -1 || x == width)) {
		gameOver = true;
	}

	if ((x == fruitX) && (y == fruitY)) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}


}



int main() {
	Setup();

	while (!gameOver) {

		Draw();
		Input();
		Logic();
		Sleep(40);


	}

	return 0;
}
*/