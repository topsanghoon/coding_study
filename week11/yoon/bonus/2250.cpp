#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct node {
    node* head = nullptr;
    node* left = nullptr;
    node* right = nullptr;
} node;

int current_idx = 0;
map<int, vector<int>> layer_to_indices;

void inorder(node* current, int layer) {
    if (current->left != nullptr)
        inorder(current->left, layer + 1);

    current_idx++;
    layer_to_indices[layer].push_back(current_idx);

    if (current->right != nullptr)
        inorder(current->right, layer + 1);
}

int return_root(int n, const vector<bool>& AmIRoot) {
    for (int i = 1; i <= n; i++) {
        if (AmIRoot[i]) return i;
    }
    return -1; // error
}

int main() {
    int n;
    cin >> n;

    vector<node*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new node;
    }

    vector<bool> AmIRoot(n + 1, true);
    for (int i = 1; i <= n; i++) {
        int me, left, right;
        cin >> me >> left >> right;

        if (left != -1) {
            nodes[me]->left = nodes[left];
            nodes[left]->head = nodes[me];
            AmIRoot[left] = false;
        }
        if (right != -1) {
            nodes[me]->right = nodes[right];
            nodes[right]->head = nodes[me];
            AmIRoot[right] = false;
        }
    }

    int root = return_root(n, AmIRoot);
    inorder(nodes[root], 1);

    int answer_layer = 0;
    int max_width = 0;
    for (const auto& [layer, vec] : layer_to_indices) {
        int width = vec.back() - vec.front() + 1;
        if (width > max_width) {
            max_width = width;
            answer_layer = layer;
        }
    }

    cout << answer_layer << " " << max_width;
    return 0;
}
