#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

/**
 * a binary tree is full if and only if every node has either zero or two children.
 * a binary tree is perfect if and only if all interior nodes have two children 
 * and leaves are at the same level.
 * a binary tree is complete if and only if the tree is perfect up until the last level 
 * and all leaf nodes on the last level are pushed to the left.
 */
#include <iostream>
#include <queue>

template<typename T>
class BST
{
private:
    class Node
    {
    public:
        T data;
        Node* left;
        Node* right;
        Node(T data)
        : data(data), left(nullptr), right(nullptr)
        {}
    };
    Node* root_ = nullptr;

public:
    /** find a node matching the value in a recursive way */
    Node* find(T value) { return _find(root_, value); }
    Node* min() { return _min(root_); }
    Node* max() { return _max(root_); }
    Node* successor(Node* x)
    {
        if (x->right)
            return _min(x->right);
        return x->right;
    }

    Node* predecessor(Node* x)
    {
        if (x->left)
            return _max(x->left);
        return x->left;
    }

    void insert(T value)
    {
        if (!root_)
            root_ = new Node{value};
        else
            _insert(root_, value);
    }
    void remove(T value)
    {
        root_ = _remove(root_, value);
    }

    void clear()
    {
        _clear(root_);
    }

    // Traversals
    void preorder(Node* cur)
    {
        if (!cur)
            return;
        std::cout << cur->data << std::endl;
        preorder(cur->left);
        preorder(cur->right);
    }
    void inorder(Node* cur)
    {
        if (!cur)
            return;
        inorder(cur->left);
        std::cout << cur->data << std::endl;
        inorder(cur->right);
    }
    void postorder(Node* cur)
    {
        if (!cur)
            return;
        postorder(cur->left);
        postorder(cur->right);
        std::cout << cur->data << std::endl;
    }
    void level()
    {
        std::queue<Node*> q;
        q.push(root_);
        while (!(q.empty()))
        {
            size_t size = q.size();
            for (size_t i = 0; i < size; i++)
            {
                std::cout << " | ";
                Node* cur = q.front();
                std::cout << cur->data << " | ";
                q.pop();
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            std::cout << std::endl;
        }
    }


private:
    Node* _find(Node* cur, T value)
    {
        if (!cur || cur->data == value)
            return cur;
        else if (cur->data < value)
            return _find(cur->left, value);
        else
            return _find(cur->right, value);
    }
    // in an iterative way to find a target node
    Node* _find_loop(Node* cur, T value)
    {
        while (cur != nullptr && cur->data != value)
        {
            if (cur->data < value)
                cur = cur ->left;
            else
                cur = cur ->right;
        }
        return cur;
    }

    Node* _min(Node* cur)
    {
        while (!cur)
            cur = cur->left;
        return cur;
        
        // recursive
        // if (!cur)
        //     return cur->data;
        // else
        //     return _min(cur->left);
    }

    Node* _max(Node* cur)
    {
        while (!cur)
            cur = cur->right;
        return cur;

        // recursive
        // if (!cur)
        //     return cur->data;
        // else
        //     return _min(cur->right);
    }

    void _insert(Node* cur, T value)
    {
        if (value < cur->data)
        {
            if (!cur->left)
                cur->left = new Node{value};
            else
                _insert(cur->left, value);
        }
        else
        {
            if (!cur->right)
                cur->right = new Node{value};
            else
                _insert(cur->right, value);
        }
    }

    Node* _remove(Node* cur, T value)
    {
        if (!cur)
            return nullptr;
        if (value < cur->data)
        {
            cur->left = _remove(cur->left, value);
        }
        else if (value > cur->data)
        {
            cur->right = _remove(cur->right, value);
        }
        else
        {
            if (!cur->left)
            {
                Node* tmp = cur->right;
                delete cur;
                return tmp;
            }
            if (!cur->right)
            {
                Node* tmp = cur->left;
                delete cur;
                return tmp;
            }
            Node* succNode = successor(cur);
            cur->data = succNode->data;

            cur->right = _remove(cur->right, succNode->data);
        }
        return cur;
    }

    void _clear(Node* cur)
    {
        if (!cur)
            return;
        _clear(cur->left);
        _clear(cur->right);
        delete cur;
    }

};

#endif//_BINARY_SEARCH_TREE_H_