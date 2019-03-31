#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GenPostorder(const vector<int>& preorder,
                          const vector<int>& inorder) {
    if (preorder.size() <= 1)
        return preorder;

    int root = preorder.front();
    int left_size = find(inorder.begin(), inorder.end(), root) - inorder.begin();

    auto left = GenPostorder({preorder.begin()+1, preorder.begin()+1+left_size},
                              {inorder.begin(), inorder.begin()+left_size});
    auto right = GenPostorder({preorder.begin()+left_size+1, preorder.end()},
                               {inorder.begin()+left_size+1, inorder.end()});

    vector<int> result(left);
    result.insert(result.end(), right.begin(), right.end());
    result.emplace_back(root);

    return result;
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

    auto postorder = GenPostorder(preorder, inorder);
    for (auto& p : postorder)
        cout << p << " ";
    cout << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
