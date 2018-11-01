#include<stdio.h>
#include<stdlib.h>

#define N 10

struct node {
	int info;
	struct node *next;
};

struct list {
	struct node *head;
};

void print_list(struct list *lst)
{
	struct node *walk = lst->head;
	printf("[");
	if (walk) {
		do {
			printf("%d, ", walk->info);
			walk = walk->next;
		} while (walk);
		printf("\b\b");
	}
	puts("]");
}

int remove_node(struct list *lst, int entry)
{
	struct node **indirect = &lst->head;
	while (*indirect && (*indirect)->info != entry) {
		indirect = &(*indirect)->next;
	}
	if (*indirect) {
		*indirect = (*indirect)->next;
		return 1;
	}
	return 0;
}

int main(void)
{
	struct node nodes[N];
	struct list lst = { nodes };

	nodes[N - 1].info = N - 1;
	nodes[N - 1].next = NULL;

	for (int i = 0; i < N - 1; i++) {
		nodes[i].info = i;
		nodes[i].next = nodes + i + 1;
	}
	print_list(&lst);

	for (int i = 0; i < N; i++) {
		printf("\nRemovendo valor %d\n", i);
		int ok = remove_node(&lst, i);
		if (!ok) {
			printf("Valor %d não removido.\n", i);
		} else {
			print_list(&lst);
		}
	}
	return 0;
}
