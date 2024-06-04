// #pragma once
#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <iostream>
#include <queue>
#include <stdexcept>
#include <algorithm>
#include <utility>

template <typename K, typename D>
class AVL
{
public:
    AVL();

    const D &find(const K &key);
    void insert(const K &key, const D &data);
    const D &remove(const K &key);

    /* return the bool type whether there is the item for the key or not */
    bool contains(const K &key);

private:
    class TreeNode
    {
    public:
        const K &key;
        const D &data;
        TreeNode *left;
        TreeNode *right;
        int height;
        TreeNode(const K &key, const D &data);
    };

    TreeNode *root_;

    TreeNode*& _find(const K& key, TreeNode*& cur) const;
    const D& _remove(TreeNode *&node);
    void _find_and_insert(const K& key, const D& data, TreeNode*& cur);
    const D& _find_and_remove(const K& key, TreeNode*& cur);
    const D& _iopRemove(TreeNode*& targetNode);
    const D& _iopRemove(TreeNode*& targetNode, TreeNode*& iopAncestor, bool isInitialCall);
    TreeNode*& _swap_nodes(TreeNode*& node1, TreeNode*& node2);
    void _updateHeight(TreeNode*& cur);
    void _ensureBalance(TreeNode*& cur);

    void _rotateLeft(TreeNode*& cur);
    void _rotateRight(TreeNode*& cur);
    void _rotateRightLeft(TreeNode*& cur);
    void _rotateLeftRight(TreeNode*& cur);

    int _get_height(TreeNode *&node) const
    {
        if (!node)
        {
            // A non-existent node has a height of 1
            return -1;
        }
        else
        {
            // We assume that an existing node already has an updated height
            return node->height;
        }
    }

    // _get_balance_factor: A helper function for safely calculating the balance
    // factor of the node that is passed as the argument.
    int _get_balance_factor(TreeNode *&node) const
    {
        if (!node)
        {
            // A non-existent node has a balance factor of 0
            return 0;
        }
        else
        {
            // Calculate the balance factor safely and return it.
            return _get_height(node->right) - _get_height(node->left);
        }
    }

public:
    bool empty() const { return !root_; }

    void clear_tree()
    {
        while (root_)
            remove(root_->key);
    }

    ~AVL() { clear_tree(); }

public:
    // Prints the tree vertically without any fancy formatting in the margin.
    // For debugging purposes.
    void printVertical() const;

public:
    // printInOrder: Print the tree contents to std::cout using an in-order
    // traversal. The "_printInOrder" version is for internal use by the
    // public wrapper function "printInOrder".
    void printInOrder() const;

private:
    void _printInOrder(TreeNode *node) const;

public:
    // More debugging functions to help check the AVL tree properties.
    // These are not meant to be fast and they are optional components.
    // I haven't fully commented how they work but the implementations
    // are in AVL-extra.hpp.
    bool runDebuggingChecks();

private:
    bool _debugHeightCheck(TreeNode *cur);
    bool _debugBalanceCheck(TreeNode *cur);
    bool _debugOrderCheck(TreeNode *cur);

    // This constant controls whether debugging checks will be run after
    // insertions and removals. Note that this makes the data structure run
    // below its intended theoretical speed.
    //   Also, here's an obscure syntax note:
    // It's possible to give this an initial value here because it's a
    // compile-time constant (constexpr) and of bool type, and it's static
    // (shared for the whole class), and it's a templated class. That is
    // pretty specific... You can't do this for all member variables of all
    // types. In newer versions of C++, C++17 and later, there are more
    // flexible and consistent ways to define constants like this for the
    // whole class. This version of the example has been written with C++14
    // compatibility in mind.
    static constexpr bool ENABLE_DEBUGGING_CHECKS = true;
};

#endif//_AVL_TREE_H_