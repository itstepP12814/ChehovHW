#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
class GameBandit {
private:
	char *reelSymbol;
	int reelLength;
public:
	GameBandit();
	~GameBandit();
	void move();
	void show();
	char isWin();
};

GameBandit :: GameBandit() {
	reelLength = 4;
	reelSymbol = new char[reelLength];
	reelSymbol[0] = '@';
	reelSymbol[1] = '$';
	reelSymbol[2] = '#';
	reelSymbol[3] = '&';
}

void GameBandit :: show() {
	cout << reelSymbol[0] << " ";
}

void GameBandit :: move() {
	int ran = rand() % 20;
	int num = 0;
	while(num < ran) {
		int temp = reelSymbol[0];
		for(int i = 1; i < reelLength; i++) {
			reelSymbol[i - 1] = reelSymbol[i];
		}
		reelSymbol[reelLength - 1] = temp;
		num++;
	}
}

char GameBandit :: isWin() {
	return reelSymbol[0];
}

GameBandit :: ~GameBandit() {
	delete [] reelSymbol;
}

int main() {
	int go_on = 1;
	GameBandit x;
	GameBandit y;
	GameBandit z;
	cout << "There are four symbols: @, $, # and &.\n\n";
	x.show();
	y.show();
	z.show();
	cout << "\n\n";
	int money = 1000;
	while(go_on) {
		int bet;
		if(money > 0) {
			cout << "Your money: " << money << "$" << endl;
			cout << "Enter your bet:\n";
			cin >> bet;
			while(bet > money) {
				cout << "It's too big bet! Your money is " << money << "! Enter other bet!\n";
				cin >> bet;
			}
			cout << "Let's play! Push any button to start!\n";
			system("pause");
			system("cls");
			srand(time(NULL));
			x.move();
			y.move();
			z.move();
			x.show();
			y.show();
			z.show();
			cout << "\n\n";
			if(x.isWin() == y.isWin() && y.isWin() == z.isWin()) {
				cout << "You've won!\n" << bet << "$" << endl;
				cout << "Your money: " << money + bet << "$" << endl;
				money += bet;
			}
			else {
				cout << "Sorry... You've lost " << bet << "$" << endl;
				cout << "Your money: " << money - bet << "$" << endl;
				money -= bet;
			}
			cout << "Continue? (1 - yes, 0 - no)\n";
			cin >> go_on;
			while(go_on < 0 || go_on > 1) {
				cout << "Wrong digit! Enter 1 (yes) or 0 (no):\n";
				cin >> go_on;
			}
			system("cls");
		}
		else {
			cout << "Sorry! You have no money! The game is over!\n";
			go_on = 0;
		}
	}
	return 0;
}
