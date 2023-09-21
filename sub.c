#include "monty.h"

/**
 * f_sub -  A function that subtracts the top element of
 * the stack from the second top element
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int sum;
	int nodes;

	tmp = *head;

	for (nodes = 0; tmp != NULL; nodes++)
	{
		tmp = tmp->next;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = tmp->next->n - tmp->n;
	tmp->next->n = sum;
	*head = tmp->next;
	free(tmp);
}
