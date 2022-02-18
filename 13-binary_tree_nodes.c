#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 0 when tree is NULL or a recursive function call
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
if (tree != NULL && (tree->left != NULL || tree->right != NULL))
{
return (binary_tree_nodes(tree->left) + 1 +
binary_tree_nodes(tree->right));
}
return (0);
}
