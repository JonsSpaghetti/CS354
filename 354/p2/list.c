#include <stdio.h>
#include <stdlib.h>

#define MAX_INTS 1000
#define LENGTH(array) (sizeof(array)/sizeof(*array))

/* A node in the linked list */
struct node {
    int data;
    struct node *next;
};

struct node* create_list(int intarray[], int len);

struct node* add_item_at_start(struct node *head, int data);

int search_array(int integers[], int numints, int element);

int search_list(struct node *head, int element);

struct node* create_sorted_list(struct node *head);

struct node* add_item_sorted(struct node *head, int data);

int copy_list_to_array(struct node *head, int *array);

void print_list(struct node *head);

void print_array(int integers[], int len);

void test_create_list();

int main(int argc, char *argv[])
{
    //test_create_list(); //TEST LINE FOR CREATE_LIST

    /* Open a file for reading */
    char *fileNam = argv[1];
    FILE *file;
    if ((file = fopen(fileNam, "r+")) == NULL){
        printf("File does not exist!\n");
        exit(1);
    }

    /* Read the numbers from the file, into an array */
    //MAYBE try doing this without using realloc - read the file first, get number of lines
    //then create the array.
    int intArray[MAX_INTS];
    char buff[100];
    int arrayLength = 0;
    while(fgets(buff, 100, file)){
        intArray[arrayLength] = strtol(buff, NULL, 10);
        arrayLength++;
    }

    /* Print the array */
    print_array(intArray, arrayLength);

    /* Create a linked list with the integers from the array */
    struct node *linkedList = create_list(intArray, arrayLength); 
    
    /* Print the linked list */
    print_list(linkedList); 

    /* Repeatedly prompt the user for a number to be searched.
    *  Search the array for the number and print out the result as shown in the specs.
    *  Search the linked list for the number and print out the result as shown in the specs.
    *  Stop prompting when the user enters 'q' (just the character q without the single quotes).
    */
    int search = 1;
    do {
        int searchNum;
        printf("Enter an element to be searched in the list and array: ");
        if(scanf("%d", &searchNum) == 0){
            char input;
            scanf("%c", &input);
            if(input == 'q'){
                search = 0;
            }
            else {
                break;
            }
        }
        else{
            int searchResult = search_array(intArray, arrayLength, searchNum);
            if (searchResult > -1){
                printf("Element %d found in the array at index %d.\n\n", searchNum, searchResult);
            }
            else{
                printf("Element %d not found in the array.\n\n", searchNum);
            }
            searchResult = search_list(linkedList, searchNum);
            if(searchResult > -1){
                printf("Element %d found in the linked list at index %d.\n\n", searchNum, searchResult);
            }
            else{
                printf("Element %d not found in the linked  list.\n\n", searchNum);
            }
        }
    } while(search);

    /* Create a sorted list(in ascending order) from the unsorted list */
    struct node *sortedList = create_sorted_list(linkedList);

    /* Print the sorted list */
    //print_list(sortedList);

    /* Copy the sorted list to an array with the same sorted order */

    /* Print out the sorted array */    

    /* Print the original linked list again */

    /* Print the original array again */


    /* Open a file for writing */

    /* Write the sorted array to a file named "sorted_numbers.txt" */

    /* Print out the number of integers written to the file */

}

struct node* create_list(int intarray[], int len)
{
    struct node *head = malloc(sizeof(struct node));
    if (head == NULL){
        exit(1);
    }
    head = add_item_at_start(NULL, intarray[0]);
    int i = 1;
    do{
         head = add_item_at_start(head, intarray[i]); 
         i++;
    } while(i < len);
    return head;
}


struct node* add_item_at_start(struct node *head, int data)
{
    struct node *newHead = malloc(sizeof(struct node));
    if (newHead == NULL){
        exit(1);
    }
    newHead -> data = data;
    if(head != NULL) {
        newHead -> next = head;
    }
    else{
        newHead -> next = NULL;
    }
    return newHead;
}

int search_list(struct node *head, int element)
{
    int count = 0;
    do {
        if(head -> data == element){
            return count;
        }
        else{
            head = head -> next;
            count++;
        }
    }
    while(head != NULL);
    return -1;
}

int search_array(int integers[], int numints, int element)
{
    for(int i = 0; i < numints; i++){
        if (integers[i] == element){
            return i;
        }
    }
    return -1;
}

int copy_list_to_array(struct node *head, int *array)
{
    /* TODO: Complete this function */
}

struct node* create_sorted_list(struct node *head)
{
    struct node *sortedList = malloc(sizeof(struct node));
    if (sortedList == NULL){
        exit(1);
    }
    sortedList -> data = 0;
    sortedList -> next = NULL;
    do {
        sortedList = add_item_sorted(sortedList, head -> data);
        head = head -> next;
    }
    while(head);
    return sortedList;
}

struct node* add_item_sorted(struct node *sorted_head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    struct node *prevNode = malloc(sizeof(struct node));
    struct node *currNode = malloc(sizeof(struct node));
    if(newNode == NULL || prevNode == NULL || currNode == NULL){
        exit(1);
    }
    newNode -> data = data;
    newNode -> next = NULL;
    currNode = sorted_head;
    do {
        if(currNode -> data < newNode -> data){
            newNode -> next = currNode;
            prevNode -> next = newNode;
            break;
        }
        else{
            prevNode = currNode;
            currNode = currNode -> next;
        }
    }
    while(currNode -> next == NULL);
    currNode -> next = newNode;
    return sorted_head;
}

void print_list(struct node *head)
{
    if (head == NULL) {
        printf("Linked List is Empty.\n");
    } else {
        struct node *temp = head;
        printf("head->");
        while (temp != NULL) {
            printf("|%d|->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void print_array(int integers[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("| %d ", integers[i]);
    }
    printf("|\n");
}

void test_create_list(){
    int array[] = { 1, 2, 3, 4, 5 };
    struct node* test = create_list(array, LENGTH(array));
    print_array(array, LENGTH(array));
}
