#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef struct _node //������� �����
{
	int tn;
	int n;

	struct _node* next;
} node;

typedef struct {  //����
	node* head;

} Stack;

Stack* CreateStack() {  //�������� c����
	Stack* temp;
	temp = (Stack*)malloc(sizeof(Stack));

	temp->head = NULL;

	return temp;
}

void Push(Stack* stack, int number, int TreeNumber) //������� ��������� � ����
{
	if (stack->head == NULL) {
		node* temp;
		temp = (node*)malloc(sizeof(node));

		temp->n = number;
		temp->tn = TreeNumber;
		temp->next = NULL;
		stack->head = temp;
	}
	else {
		node* temp;
		temp = (node*)malloc(sizeof(node));

		temp->n = number;
		temp->tn = TreeNumber;
		temp->next = stack->head;
		stack->head = temp;
	}
}

void Delete(Stack* stack)//�������� ��������� �����
{
	if (stack->head == NULL) {
		printf("Empty stack ");
		return;
	}
	else {
		node* temp;
		temp = (node*)malloc(sizeof(node));
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
}

int ShowTreeNumber(Stack* stack)//�������� ������ ������ �� �����
{
	if (stack->head == NULL) {
		printf("Empty stack ");
		return 0;
	}
	else {
		return stack->head->tn;
	}
}

int ShowNumber(Stack* stack) //�������� �������� �� �����
{
	if (stack->head == NULL) {
		printf("Empty stack ");
		return 0;
	}
	else {
		return stack->head->n;
	}
}

typedef struct _tnode { //���� ������
	int n;

	struct _tnode* left;
	struct _tnode* right;
} tnode;

tnode* AddNode(int number, tnode* tree) {//���������� ��������� � ������
	if (tree == NULL) {
		tree = (tnode*)malloc(sizeof(tnode));
		tree->n = number;
		tree->left = NULL;
		tree->right = NULL;
	}
	else {
		if (number < tree->n) {
			tree->left = AddNode(number, tree->left);
		}
		else {
			tree->right = AddNode(number, tree->right);
		}
	}
	return(tree);
}

void Summa(tnode* node, int* s) { //����� �������� � ������
	if (node == NULL) {
		return;
	}
	*s = *s + node->n;
	Summa(node->left, s);
	Summa(node->right, s);

}

int main()
{
	srand(time(NULL));
	int size, TreeNumber, number, answer, sum, elem, sizestackofelemnts, a[100], b[100];
	Stack* elements = CreateStack();
	Stack* stack = CreateStack(); //�������� �����
	answer = 0;
	TreeNumber = 1;
	sizestackofelemnts = rand() % 100;
	for (int y = 0; y < sizestackofelemnts; y++) {
		elem = rand() % 100;
		a[y] = elem;
	}
	size = rand() % 50;
	for (int i = 0; i < sizestackofelemnts; i++) {
		printf("\nNumbers of trees being processed: %d ", a[i]);
		Push(elements, a[i], TreeNumber); //��������� �������� � ����
		printf("\n");
		sum = 0;
		for (int j = 0; j < size; j++) {
			if (j == 0)
				printf("The number to be pushed into the stack: ");
			number = rand() % 100;
			sum = sum + number;
			printf("%d ", number);
			Push(stack, number, TreeNumber); //��������� �������� � ����
		}
		b[i] = sum;
	}

	tnode* root[10000];
	for (int i = 0; i < TreeNumber; i++) {
		root[i] = NULL;
	}

	for (int j = 0; j < sizestackofelemnts; j++) {
		for (int i = 0; i < size; i++) {      //��������� �������
			root[ShowTreeNumber(stack) - 1] = AddNode(ShowNumber(stack), root[ShowTreeNumber(stack) - 1]);
			Delete(stack);
		}
	}

	for (int j = 0; j < sizestackofelemnts; j++) {
		printf("\n\nThe sum of the elements of %d tree = %d", a[j], b[j]);
	}

	_getch();
	return 0;
}