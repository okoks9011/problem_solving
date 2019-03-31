#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintPostorder(const vector<int>& preorder,
                    const vector<int>& inorder) {
    if (preorder.empty())
        return;

    int root = preorder.front();
    int left_size = find(inorder.begin(), inorder.end(), root) - inorder.begin();

    PrintPostorder({preorder.begin()+1, preorder.begin()+1+left_size},
                   {inorder.begin(), inorder.begin()+left_size});
    PrintPostorder({preorder.begin()+left_size+1, preorder.end()},
                   {inorder.begin()+left_size+1, inorder.end()});
    cout << root << " ";
}

void Solve() {
    int n;
    cin >> n;

    vector<int> preorder(n);
    for (auto& p : preorder)
        cin >> p;

    vector<int> inorder(n);
    for (auto& p : inorder)
        cin >> p;

    PrintPostorder(preorder, inorder);
    cout << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
