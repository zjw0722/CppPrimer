  // <Copyright liaoqb>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

const int N = 25;

class Snake {
public:
	Snake();
	~Snake();
	bool isD() { return isDead; }
	void print();
	void run(char c);
	void gameOver();

private:
	static void init();
	void move(int x, int y);
	void putFood();

	struct snake {
	    int x, y;
		snake* next;
	};
	snake* head, *tail;

	static char map[N][N];
	bool isDead;
};

char Snake::map[N][N] = { ' ' };

Snake::Snake() {
    init();
	putFood();
	isDead = false;

	for (int i = 1; i < 10; ++i) {
		if (i == 1) {
		    head = tail = new snake;
			head -> x = 1;
			head -> y = i;
			head -> next = NULL;
			map[head -> x][head -> y] = 'X';
		}
		else {
		    snake* temp = new snake;
			temp -> next = NULL;
			temp -> x = 1;
			temp -> y = i;
			tail -> next = temp;
			tail = temp;
			map[tail -> x][tail -> y] = 'X';
		}
	}
	map[tail -> x][tail -> y] = 'H';
}

void Snake::init() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i > 0 && i < N - 1 && j > 0 && j < N - 1)
				map[i][j] = ' ';
			else
				map[i][j] = '*';
		}
	}
}

void Snake::putFood() {
	int x, y;
	srand(static_cast<int>(time(NULL)));

	do {
	    x = rand() % N;
		y = rand() % N;
	} while (map[x][y] != ' ');

	map[x][y] = 'o';
}

void Snake::gameOver() {
    cout << "Sorry<^_^>!!!\nGame Over!!!\nGood luck next time!!!\n";
}

void Snake::print() {
	cout << "Snake Game!!!Good Luck!!!\n";

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
		    cout << map[i][j];
		}
		cout << endl;
	}
}

void Snake::run(char c) {
	switch (c) {
	case 'a':
		move(0, -1);
		break;

	case 'd':
		move(0, 1);
		break;

	case 's':
		move(1, 0);
		break;

	case 'w':
		move(-1, 0);
		break;
	}
}

void Snake::move(int x, int y) {
    if (map[tail -> x + x][tail -> y + y] == '*' ||
		map[tail -> x + x][tail -> y + y] == 'X') {
	    isDead = true;
		return;
	}

	else {
	    snake* temp = new snake;
		temp -> x = tail -> x + x;
		temp -> y = tail -> y + y;
		temp -> next = NULL;

		if (map[temp -> x][temp -> y] == ' ') {
			snake* t = head;
		    map[head -> x][head -> y] = ' ';
			head = head -> next;
			delete t;
		}

		else {
		    putFood();
		}

		map[tail -> x][tail -> y] = 'X';
		map[temp -> x][temp -> y] = 'H';
		tail -> next = temp;
		tail = temp;
	}
}

Snake::~Snake() {
	while (head != NULL) {
	    snake* temp = head;
		head = head -> next;
		delete temp;
	}
}

int main() {
	Snake s;
	s.print();
    char direction = 'd';

	while (1) {
		while (!kbhit()) {
		    s.run(direction);

	        system("cls");
		    s.print();
		    Sleep(200);

		    if (s.isD())
			    break;
	    }

		if (s.isD())
			break;

		direction = getch();
	}
	s.gameOver();

	return 0;
}