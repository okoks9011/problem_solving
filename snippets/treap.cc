#include <memory>
#include <random>
#include <utility>

using namespace std;

typedef int KeyType;

struct Node {
    KeyType key = -1;

    int priority = 0;
    int size = 1;

    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(KeyType k) : key(k) {
        random_device rd;
        mt19937 gen(rd());
        priority = gen();
    }

    void SetLeft(shared_ptr<Node> new_left) {
        left = new_left;
        UpdateSize();
    }

    void SetRight(shared_ptr<Node> new_right) {
        right = new_right;
        UpdateSize();
    }

    void UpdateSize() {
        size = 1;
        if (left)
            size += left->size;
        if (right)
            size += right->size;
    }
};


typedef pair<shared_ptr<Node>, shared_ptr<Node>> NodePair;

NodePair Split(shared_ptr<Node> root, KeyType key) {
    if (!root)
        return {};

    if (root->key < key) {
        auto right_split = Split(root->right, key);
        root->SetRight(right_split.first);
        return {root, right_split.second};
    } else {  // root->key >= key
        auto left_split = Split(root->left, key);
        root->SetLeft(left_split.second);
        return {left_split.first, root};
    }
}

shared_ptr<Node> Insert(shared_ptr<Node> root, shared_ptr<Node> node) {
    if (!root)
        return node;

    if (node->priority <= root->priority) {
        if (node->key < root->key)
            root->SetLeft(Insert(root->left, node));
        else  // root->key >= node->key
            root->SetRight(Insert(root->right, node));
        return root;
    }

    auto split = Split(root, node->key);
    node->SetLeft(split.first);
    node->SetRight(split.second);
    return node;
}

shared_ptr<Node> Merge(shared_ptr<Node> a_node, shared_ptr<Node> b_node) {
    if (!a_node)
        return b_node;
    if (!b_node)
        return a_node;

    if (a_node->priority <= b_node->priority) {
        auto left = Merge(a_node, b_node->left);
        b_node->SetLeft(left);
        return b_node;
    } else {
        auto right = Merge(a_node->right, b_node);
        a_node->SetRight(right);
        return a_node;
    }
}

shared_ptr<Node> Erase(shared_ptr<Node> root, KeyType key) {
    if (!root)
        return {};

    if (root->key == key)
        return Merge(root->left, root->right);

    if (root->key < key) {
        auto right = Erase(root->right, key);
        root->SetRight(right);
    } else {  // root->key > key
        auto left = Erase(root->left, key);
        root->SetLeft(left);
    }
    return root;
}
