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

void BFS(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << " ";
        if (q.front()->left != NULL)
            q.push(q.front()->left);
        if (q.front()->right != NULL)
            q.push(q.front()->right);
        q.pop();
    }
}

int main()
{
    node *root = build();
    BFS(root);
    cout << endl;

    return 0;
}

// 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 9 -1 -1 7 -1 -1