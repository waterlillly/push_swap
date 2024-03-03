#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoubleLinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to initialize a double-linked list
void initializeList(struct DoubleLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to append a node to the double-linked list
void append(struct DoubleLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Example usage:
int main() {
    struct DoubleLinkedList stackB;
    initializeList(&stackB);

    append(&stackB, 1);
    append(&stackB, 2);
    // ... continue appending values as needed

    // Now stackB is a double-linked list with elements pushed onto it.

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoubleLinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to initialize a double-linked list
void initializeList(struct DoubleLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to append a node to the double-linked list
void append(struct DoubleLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to push values from Stack A to Stack B
void pushFromAToB(struct DoubleLinkedList* stackA, struct DoubleLinkedList* stackB) {
    if (stackB->head == NULL && stackA->head != NULL) {
        // Move elements from A to B until A is empty
        while (stackA->head != NULL) {
            int data = stackA->head->data;
            append(stackB, data);

            // Pop the element from A
            struct Node* temp = stackA->head;
            stackA->head = stackA->head->next;
            free(temp);
        }
    }
}

// Example usage:
int main() {
    struct DoubleLinkedList stackA, stackB;
    initializeList(&stackA);
    initializeList(&stackB);

    append(&stackA, 1);
    append(&stackA, 2);
    // ... continue appending values to stackA as needed

    pushFromAToB(&stackA, &stackB);

    // Now stackB contains elements from stackA

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoubleLinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to initialize a double-linked list
void initializeList(struct DoubleLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to append a node to the double-linked list
void append(struct DoubleLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to push values from dynamic array to Stack B
void pushFromArrayToB(int* arrayA, int sizeA, struct DoubleLinkedList* stackB) {
    if (stackB->head == NULL && sizeA > 0) {
        for (int i = 0; i < sizeA; i++) {
            append(stackB, arrayA[i]);
        }
    }
}

// Example usage:
int main() {
    int arrayA[] = {1, 2, 3, 4}; // Replace this with your dynamic array
    int sizeA = sizeof(arrayA) / sizeof(arrayA[0]);

    struct DoubleLinkedList stackB;
    initializeList(&stackB);

    pushFromArrayToB(arrayA, sizeA, &stackB);

    // Now stackB contains elements from arrayA

    return 0;
}
