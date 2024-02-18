#include <iostream>
#include <vector>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Function to create a new node with given data
Node *newNode(int data)
{
    Node *temp = new Node; // Allocate new node
    temp->data = data;     // Set the data
    temp->next = NULL;     // Next pointer set to NULL
    return temp;           // Return the new node
}

// Function to remove duplicates from the linked list
void removeDuplicates(Node *start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    // Outer loop for each element in the list
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        // Inner loop to compare the element with the rest of the list
        while (ptr2->next != NULL)
        {
            // If duplicate is found
            if (ptr1->data == ptr2->next->data)
            {
                // Remove the duplicate
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete dup; // Free memory of the duplicate node
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

// Function to print the elements of the linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    vector<int> inputs; // Vector to store user inputs
    int num;
    cout << "Enter integers (Enter -1 to end): " << endl;

    // Reading integers until -1 is entered
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        inputs.push_back(num);
    }

    Node *start = NULL;   // Start pointer for the linked list
    Node *current = NULL; // Pointer to keep track of the current node

    // Creating linked list from the vector of inputs
    for (int value : inputs)
    {
        if (start == NULL)
        {
            start = newNode(value);
            current = start;
        }
        else
        {
            current->next = newNode(value);
            current = current->next;
        }
    }

    cout << "Linked list before removing duplicates: " << endl;
    printList(start);
    removeDuplicates(start); // Remove duplicates from the list
    cout << "\nLinked list after removing duplicates: " << endl;
    printList(start);

    // Freeing memory used by the linked list
    Node *temp;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
    return 0;
}