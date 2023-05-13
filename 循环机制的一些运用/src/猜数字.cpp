/* 一个使用dowhile的例子 */
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	do {
		cout << "Guess a number between 0 and 9" << endl;
		unsigned i, mynum = 7;
		cin >> i;

		if (i == mynum) {
			cout << "Congrats you guessed right!" << endl;
			break;
		} else
			if (i < mynum)
				cout << "too low" << endl;
			else
				cout << "too high" << endl;

		if (i != mynum)
			if (i < mynum)
				cout << "too low" << endl;
			else
				cout << "too high" << endl;
		else {
			cout << "Congrats you guessed right!" << endl;
			break;
		}
	} while (true);

	return 0;
}
