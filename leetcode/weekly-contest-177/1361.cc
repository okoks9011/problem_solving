#include <vector>
#include <unordered_set>
#include <algorithm>


using namespace std;


class Solution {
  public:
    bool visit(int cur, const vector<int>& leftChild, const vector<int>& rightChild,
               vector<char>* visited_ptr) {
        if (cur == -1)
            return true;

        auto& visited = *visited_ptr;
        if (visited[cur])
            return false;
        visited[cur] = true;

        if (!visit(leftChild[cur], leftChild, rightChild, visited_ptr) ||
            !visit(rightChild[cur], leftChild, rightChild, visited_ptr))
            return false;
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> candi;
        for (int i = 0; i < n; ++i)
            candi.emplace(i);

        for (int i = 0; i < n; ++i) {
            candi.erase(leftChild[i]);
            candi.erase(rightChild[i]);
        }

        if (candi.size() != 1)
            return false;

        int root = *candi.begin();
        vector<char> visited(n);

        if (!visit(root, leftChild, rightChild, &visited))
            return false;
        return visited.end() == find(visited.begin(), visited.end(), false);
    }
};
