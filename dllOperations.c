#include "monty.h"

/**
 * print_stack - prints a doubly linked list
 * @h: the head of the list
 *
 * Return: the number of nodes
 */
size_t print_stack(stack_t *h)
{
	const stack_t *p = h;
	size_t count = 0;

	if (h == NULL)
		return (0);
	for (; p != NULL; p = p->next)
	{
		printf("%d\n", p->n);
		count++;
	}
	return (count);
}

/**
 * free_stack - frees a stack_t list
 * @head: the head of the list
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
		free(head);
	else
	{
		free_stack(head->next);
		free(head);
	}
}

/**
 * delete_node_at_index - deletes the node at index of a stack_t list
 * @head: the head of the stack_t list
 * @index: the index to be deleted
 *
 * Return: 1 if successful, -1 upon failure
 */
int delete_node_at_index(stack_t **head, unsigned int index)
{
	stack_t *p, *prv, *del;
	unsigned int i, count = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	for (p = *head; p != NULL; p = p->next)
		count++;
	if (index >= count)
		return (-1);
	if (index == 0)
	{
		del = *head;
		*head = del->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		p = *head;
		for (i = 0; i + 1 < index; i++) /* go to the node right before index */
			p = p->next;
		prv = p;
		del = p->next;
		prv->next = del->next;
		if (del->next != NULL)
			(del->next)->prev = prv;
	}
	free(del);
	return (1);
}


/**
 * add_node - adds a new node at the beginning of a stack_t list
 * @head: the head of the list
 * @n: the int element of the node
 *
 * Return: the address of the new element, or NULL upon failure
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		free_entire_arr(argv);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * add_node_end - adds a new node to the end of a listint_t list
 * @head: the head of the listint_t list
 * @n: the value of the new node's property
 *
 * Return: a pointer to the new node, or NULL upon failure
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new, *p = *head;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		free_entire_arr(argv);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (p != NULL)
		while (p->next != NULL)
			p = p->next;
	new->n = n;
	new->next = NULL;
	new->prev = p;
	if (*head == NULL)
		*head = new;
	else
		p->next = new;
	return (new);
}

/**
 * insert_node_at_index - inserts a new node at index idx
 * @h: the head of the stack_t list
 * @idx: the index where the new node is to be inserted
 * @n: the data to be assigned to the new node
 *
 * Return: the address of the new node, or NULL upon failure
 */
stack_t *insert_node_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *p = *h, *t, *new;
	unsigned int i = 0, count = 0;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_node(h, n));
	for (; p != NULL; p = p->next)
		count++;
	if (idx > count)
		return (NULL);
	if (idx == count)
		return (add_node_end(h, n));
	for (p = *h; i < idx - 1; i++)
		p = p->next;
	t = p->next;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		free_entire_arr(argv);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = t;
	t->prev = new;
	new->prev = p;
	p->next = new;
	return (new);
}
