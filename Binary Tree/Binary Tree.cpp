#include <iostream>
#include "Node.h"
#include "BinaryTree.h"
#include <vector>

using namespace std;

BinaryTree::BinaryTree() {
    root = NULL;
}

void BinaryTree::insert(int element) {
    Node* newNode = new Node;
    newNode->value = element;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }

    else {
        vector<Node*> nodes;
        nodes.push_back(root);
        while (nodes.size() > 0)
        {
            Node* temp = nodes.front();
            nodes.erase(nodes.begin());
            if (temp->left == NULL)
            {
                temp->left = newNode;
                break;
            }
            else
            {
                nodes.push_back(temp->left);
            }
            if (temp->right == NULL) {
                temp->right = newNode;
                break;
            }
            else {
                nodes.push_back(temp->right);
            }
        }
    }
}

void BinaryTree::remove(int element) {
    vector<Node*> stack;
    vector<Node*> queue;
    Node* ptr;
    queue.push_back(root);
    while (queue.size() > 0) {
        ptr = queue.front();
        queue.erase(queue.begin());
        stack.push_back(ptr);
        if (ptr->left != NULL)
        {
            queue.push_back(ptr->left);
        }
        if (ptr->right != NULL) {
            queue.push_back(ptr->right);
        }
    }

    int pos = -1;
    for (int i = 0; i < stack.size(); ++i) {
        if (stack.at(i)->value == element)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "element does not exist in the tree" << "\n";
        return;
    }

    int last = stack.size();
    int parent = last / 2;

    stack.at(pos)->value = stack.at(last - 1)->value;
    Node* parentNode = stack.at(parent - 1);
    Node* nodeDelete = stack.at(last - 1);
    stack.pop_back();

    if (last%2 == 0)
    {
        parentNode->left = NULL;
    }
    else {
        parentNode->right = NULL;
    }
    delete nodeDelete;
    cout << "The element was deleted from the tree" << "\n";
}

int BinaryTree::peek() {
    if (isEmpty())
    {
        return NULL;
    }
    return root->value;
}

void BinaryTree::preOrderTraversal(Node* parent) {
    if (parent == NULL)
    {
        cout << "Tree is empty" << "\n";
        return;
    }

    else
    {
        cout << parent->value << " ";
        preOrderTraversal(parent->left);
        preOrderTraversal(parent->right);
    }
}

void BinaryTree::inOrderTraversal(Node* parent) {
    if (parent == NULL)
    {
        return;
    }

    else
    {
        inOrderTraversal(parent->left);
        cout << parent->value << " ";
        inOrderTraversal(parent->right);
    }
}

void BinaryTree::postOrderTraversal(Node* parent) {
    if (parent == NULL)
    {
        return;
    }
    else
    {
        postOrderTraversal(parent->left);
        postOrderTraversal(parent->right);
        cout << parent->value << " ";
    }
}

void BinaryTree::levelOrderTraversal() {
    vector<Node* > queue;
    if (root == NULL)
    {
        return;
    }

    queue.push_back(root);
    while (queue.size() > 0)
    {
        Node* ptr = queue.front();
        queue.erase(queue.begin());
        cout << ptr->value << " ";
        if (ptr->left != NULL)
            queue.push_back(ptr->left);
        if (ptr->right != NULL)
            queue.push_back(ptr->right);
    }
}


bool BinaryTree::search(int element) {
    vector<Node*> nodes;
    nodes.push_back(root);
    Node* ptr;
    while (nodes.size() > 0) {
        ptr = nodes.front();
        nodes.erase(nodes.begin());
        if (ptr->value == element)
        {
            return true;
        }
        if (ptr->left!=NULL)
        {
            nodes.push_back(ptr->left);
        }
        if (ptr->right != NULL) {
            nodes.push_back(ptr->right);
        }
    }
    return false;
}


void BinaryTree::postOrderDelete(Node* parent) {
    if (parent == NULL)
    {
        return;
    }
    else
    {
        postOrderDelete(parent->left);
        parent->left = NULL;
        postOrderDelete(parent->right);
        parent->right = NULL;
        delete parent;
    }
}

bool BinaryTree::isEmpty() {
    return root == NULL;
}

BinaryTree::~BinaryTree() {
    postOrderDelete(root);
    root = NULL;
}