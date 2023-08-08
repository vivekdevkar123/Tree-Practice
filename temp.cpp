#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = build();
    root->right = build();

    return root;
}

int max_level = INT_MIN;

void solve(node *root, int curr)
{
    if (root == NULL)
        return;
    if (max_level < curr)
    {
        cout << root->data << " ";
        max_level = curr;
    }
    solve(root->right, curr + 1);
    solve(root->left, curr + 1);
}

int main()
{
    node *root = build();
    cout << endl;
    solve(root, 0);
    return 0;
}

// 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 9 -1 -1 7 -1 -1