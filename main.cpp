#include <iostream>

using namespace std;


class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};


Node* newNode(int data)
{
    Node* root = new Node(data);
    root->left = NULL;
    root->right = NULL;

    return(root);
}

Node* insert(Node * root, int data) {

  if(root == NULL)
    root = new Node(data);
  else if(data <= root->data)
    root->left = insert(root->left,data);
  else
    root->right = insert(root->right, data);

  return root;
}

void printTree (Node* root)
{
  if (root == NULL)
    return;


  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right);

}

int main()
{
  Node *root = newNode(1);

  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root = insert(root, 7);
  printTree (root);
    return 0;
}
