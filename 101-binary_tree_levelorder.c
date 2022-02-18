#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to node of tree to measure
 * Return: retuns the height of tree or 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left, right;

if (tree == NULL)
{
return (0);
}
if (tree->left == NULL && tree->right == NULL)
{
return (0);
}
left = binary_tree_height(tree->left) + 1;
right = binary_tree_height(tree->right) + 1;

if (left > right)
{
return (left);
}
else
{
return (right);
}
}


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

/**
 * linked_node - this function makes a linked list from depth level and node
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: Nothing
 */

void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
link_t *new, *aux;

new = malloc(sizeof(link_t));
if (new == NULL)
{
return;
}
new->n = level;
new->node = tree;
if (*head == NULL)
{
new->next = NULL;
*head = new;
}
else
{
aux = *head;
while (aux->next != NULL)
{
aux = aux->next;
}
new->next = NULL;
aux->next = new;
}
}

/**
 * recursion - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: Nothing by default it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
size_t level = 0;

if (tree != NULL)
{
level = binary_tree_depth(tree);
linked_node(head, tree, level);
recursion(head, tree->left);
recursion(head, tree->right);
}
}
/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: root node
 * @func: function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
link_t *head, *aux;
size_t height = 0, count = 0;

if (!tree || !func)
{
return;
}
else
{
height = binary_tree_height(tree);
head = NULL;
recursion(&head, tree);
while (count <= height)
{
aux = head;
while (aux != NULL)
{
if (count == aux->n)
{
func(aux->node->n);
}
aux = aux->next;
}
count++;
}
while (head != NULL)
{
aux = head;
head = head->next;
free(aux);
}
}
}
