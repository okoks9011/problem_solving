#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>

using namespace std;

struct Circle {
    int x = 0;
    int y = 0;
    int r = 0;
    Circle() = default;
    Circle(int xi, int yi, int ri) : x(xi), y(yi), r(ri) {}
    bool operator<(const Circle& other) const {
        return r < other.r;
    }
};

ostream& operator<<(ostream& os, const Circle& c) {
    os << "x: " << c.x << " y: " << c.y << " r: " << c.r;
    return os;
}

struct TreeNode {
    Circle c;
    vector<shared_ptr<TreeNode>> children;
    TreeNode(Circle ci) : c(ci) {}
};

bool IsCovering(Circle c1, Circle c2) {
    if (c2.r >= c1.r)
        return false;

    int x_diff = c1.x - c2.x;
    int y_diff = c1.y - c2.y;
    double dis = sqrt(x_diff*x_diff + y_diff*y_diff);
    return (dis+c2.r) < c1.r;
}

void InsertNode(shared_ptr<TreeNode> cur, Circle c) {
    for (auto& child : cur->children) {
        if (IsCovering(child->c, c)) {
            InsertNode(child, c);
            return;
        }
    }
    cur->children.emplace_back(make_shared<TreeNode>(c));
}

void PrintNode(shared_ptr<TreeNode> cur) {
    cout << cur->c << endl;
    cout << "child of " << cur->c << endl;
    for (auto& child : cur->children)
        PrintNode(child);
    cout << "child of " << cur->c << " end" << endl;
}

int CalHeight(shared_ptr<TreeNode> cur, int* max_path_ptr) {
    vector<int> child_heights;
    for (auto& child : cur->children)
        child_heights.emplace_back(CalHeight(child, max_path_ptr)+1);

    child_heights.emplace_back(0);
    sort(child_heights.rbegin(), child_heights.rend());

    if (child_heights.size() >= 2) {
        auto& max_path = *max_path_ptr;
        max_path = max(max_path, child_heights[0]+child_heights[1]);
    }

    return child_heights[0];
}

void Solve() {
    int n;
    cin >> n;

    vector<Circle> circles(n);
    for (auto& c : circles) {
        int xi, yi, ri;
        cin >> xi >> yi >> ri;
        c.x = xi;
        c.y = yi;
        c.r = ri;
    }

    sort(circles.rbegin(), circles.rend());

    auto head = make_shared<TreeNode>(circles.front());
    for (int i = 1; i < n; ++i)
        InsertNode(head, circles[i]);

    int result = 0;
    CalHeight(head, &result);
    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
