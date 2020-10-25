#include <iostream>
#include <string>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    cout << 3 << endl;
    cout << "L 2" << endl;
    cout << "R 2" << endl;
    cout << "R " << 2 * s.size() - 1 << endl;
}
