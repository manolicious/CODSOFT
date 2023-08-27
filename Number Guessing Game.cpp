#include<iostream> 
#include <time.h>
#include <cstdlib>

using namespace std;
void game() {
	int attempt=1;
	int _num = 0;
	srand(time(0));
	_num=(rand() % 10) + 1;
	int _input = 0;
	while (1) {
		cout << "Guess The Number\n";
		cin >> _input;
		if (_input < _num) {
			cout << "Low"<<endl;
			attempt++;
		}
		else if (_input > _num) {
			cout << "High"<<endl;
			attempt++;
		}
		else
		{
			cout<<"You guessed the correct number in "<<attempt<<" attempts!!"<<endl;
			break;
		}
	}
}
int main() {
	game();
	return 0;
}

