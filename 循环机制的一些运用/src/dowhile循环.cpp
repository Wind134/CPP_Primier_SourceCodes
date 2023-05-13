/* doWhile循环机制 */
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
    // repeatedly ask the user for a pair of numbers to sum
    string rsp;  // do...while是先do，然后while
    do {
        cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        cin  >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
             << " = " << val1 + val2 << "\n\n"
             << "More? Enter yes or no: ";
        cin  >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');

	cout << endl;

	return 0;
}
