#include <iostream>
#include <list>
#include <cstring>
#include <string>

using namespace std;

struct Node
{
    char data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, char new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

bool isPalindrome(struct Node* left)
{
    if (left == NULL)
        return true;
    struct Node* right = left;
    while (right->next != NULL)
        right = right->next;
    while (left != right)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    string word;
    struct Node* head = NULL;
    cout << "Enter your word: ";
    cin >> word;
    int len = word.length();
    for (int i = 0; i < len; i++)
        push(&head, word[i]);
    if (isPalindrome(head))
        cout << "It is Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}