#include <iostream>
#include <string>


using namespace std;


bool CheckExist(string s, const string& x, const string& y) {
    auto it = s.find(x);
    if (it == string::npos)
        return false;

    s[it] = 'X';
    s[it+1] = 'X';
    it = s.find(y);
    if (it == string::npos)
        return false;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (CheckExist(s, "AB", "BA") || CheckExist(s, "BA", "AB"))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
