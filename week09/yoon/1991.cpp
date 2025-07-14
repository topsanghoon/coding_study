#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    char name;
    int right;
    int left;
};

vector<Node> tree;

void CRL(int cur){
    if(cur == -1) return;
    cout << tree[cur].name;
    CRL(tree[cur].left);
    CRL(tree[cur].right);
}

void RCL(int cur){
    if(cur == -1) return;
    RCL(tree[cur].left);
    cout << tree[cur].name;
    RCL(tree[cur].right);
}

void RLC(int cur){
    if(cur == -1) return;
    RLC(tree[cur].left);
    RLC(tree[cur].right);
    cout << tree[cur].name;
}

int main()
{

    int n;
    cin >> n;

    tree.resize(n);

    for (int i = 0; i < n; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        int p = parent - 'A';
        tree[p].name = parent;
        tree[p].left = (left == '.' ? -1 : left - 'A');
        tree[p].right = (right == '.' ? -1 : right - 'A');
    }

    CRL(0);
    cout << "\n";
    RCL(0);
    cout << "\n";
    RLC(0);

    return 0;
}
