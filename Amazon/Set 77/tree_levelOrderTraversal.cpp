#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <climits>
#include <set>

using namespace std;

typedef long long int ll;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* createNode (int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int height(struct node* node) {
    if (node == NULL) {
        return 0;
    }
    return max(height(node->left), height(node->right)) + 1;
}

void printGivenLevel(struct node* root, int level) {
    if (root == NULL) {
        return 0;
    }
    if (level <= 1) {
        cout << root->data << " ";
    }
    printGivenLevel(root->left, level - 1);
    printGivenLevel(root->right, level - 1);
}

void printLevelOrder(struct node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}
 
int main () {
	struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printLevelOrder(root);
    cout << endl;
    return 0;
}
