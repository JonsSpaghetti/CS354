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
    int *intArray; //has to be pointer because we don't want to statically define array size.
    int arrayLength = 0; //store array length because we don't have intArray[].
    while(!feof(file)) {
        int *tmp = realloc(intArray, (arrayLength + 1) * sizeof *intArray);
        //printf("alloc = %lu\n", (arrayLength + 1) * sizeof *intArray);
        if(!tmp){
            printf("Could not resize array, exiting.");
            exit(1);
        }
        else{
            intArray = tmp;
        }
        int input = fscanf(file, "%d\n", intArray + arrayLength);
        //printf("Val = %d and index = %d\n", *(intArray + arrayLength), arrayLength);
        arrayLength++;
    }

    /* Print the array */
    //printf("Length = %d\n", arrayLength);
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

    /* Create a sorted list(in ascending order) from the unsorted list */

    /* Print the sorted list */

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
    /* TODO: Complete this function */
}

int search_array(int integers[], int numints, int element)
{
    /* TODO: Complete this function */
}

int copy_list_to_array(struct node *head, int *array)
{
    /* TODO: Complete this function */
}

struct node* create_sorted_list(struct node *head)
{
    /* TODO: Complete this function */
}

struct node* add_item_sorted(struct node *sorted_head, int data)
{
    /* TODO: Complete this function */
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
