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

#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node or null
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
binary_tree_t *low, *high;
size_t first_d, second_d;
int res, i = 0;

if (first == NULL || second == NULL)
return (NULL);

first_d = binary_tree_depth(first);
second_d = binary_tree_depth(second);

res = (int)first_d - (int)second_d;
if (res >= 0)
{
low = (binary_tree_t *)first;
high = (binary_tree_t *)second;
} else if (res < 0)
{
low = (binary_tree_t *)second;
high = (binary_tree_t *)first;
res *= -1;
}

while (i < res)
{
low = low->parent;
i++;
}

while (high != NULL && low != NULL)
{
if (high->n == low->n)
return (high);
high = high->parent;
low = low->parent;
}
return (NULL);
}
