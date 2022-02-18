#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: The depth or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth_L = 0, depth_R = 0;

if (tree == NULL)
return (0);

if (tree->parent)
{
depth_L = binary_tree_depth(tree->parent) + 1;
depth_R = binary_tree_depth(tree->parent) + 1;
}

if (depth_R >= depth_L)
return (depth_R);
else
return (depth_L);
}
