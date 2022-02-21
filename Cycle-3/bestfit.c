// C++ implementation of program
// for best fit algorithm for memory
// management using linked list
 
#include <bits/stdc++.h>
using namespace std;
 
// Two global counters
int g = 0, k = 0;
 
// Structure for free list
struct free {
    int tag;
    int size;
    struct free* next;
}* free_head = NULL, *prev_free = NULL;
 
// Structure for allocated list
struct alloc {
    int block_id;
    int tag;
    int size;
    struct alloc* next;
}* alloc_head = NULL, *prev_alloc = NULL;
 
// Function to create free
// list with given sizes
void create_free(int c)
{
    struct free* p = (struct free*)
        malloc(sizeof(struct free));
    p->size = c;
    p->tag = g;
    p->next = NULL;
    if (free_head == NULL)
        free_head = p;
    else
        prev_free->next = p;
    prev_free = p;
    g++;
}
 
// Function to print free list which
// prints free blocks of given sizes
void print_free()
{
    struct free* p = free_head;
    cout << "Tag\tSize\n";
    while (p != NULL) {
        cout << p->tag << "\t"
             << p->size << "\n";
        p = p->next;
    }
}
 
// Function to print allocated list which
// prints allocated blocks and their block ids
void print_alloc()
{
    struct alloc* p = alloc_head;
    cout << "Tag\tBlock ID\tSize\n";
    while (p != NULL) {
        cout << p->tag << "\t  " << p->block_id
             << "\t\t" << p->size << "\n";
        p = p->next;
    }
}
 
// Function to allocate memory to
// blocks as per Best fit algorithm
void create_alloc(int c)
{
    // create node for process of given size
    struct alloc* q = (struct alloc*)
        malloc(sizeof(struct alloc));
    q->size = c;
    q->tag = k;
    q->next = NULL;
    struct free* p = free_head;
 
    // Temporary node r of free
    // type to find the best and
    // most suitable free node to
    // allocate space
    struct free* r = (struct free*)
        malloc(sizeof(struct free));
    r->size = 99999;
 
    // Loop to find best choice
    while (p != NULL) {
        if (q->size <= p->size) {
            if (p->size < r->size)
                r = p;
        }
        p = p->next;
    }
 
    // Node found to allocate
    // space from
    if (r->size != 99999) {
        // Adding node to allocated list
        q->block_id = r->tag;
        r->size -= q->size;
        if (alloc_head == NULL)
            alloc_head = q;
        else {
            prev_alloc = alloc_head;
            while (prev_alloc->next != NULL)
                prev_alloc = prev_alloc->next;
            prev_alloc->next = q;
        }
        k++;
    }
 
    // Node with size not found
    else
        cout << "Block with size "
             << c << " can't be allocated\n";
}
 
// Function to delete node from
// allocated list to free some space
void delete_alloc(int t)
{
    // Standard delete function
    // of a linked list node
    struct alloc *p = alloc_head, *q = NULL;
 
    // First, find the node according
    while (p != NULL)
    // to given tag id
    {
        if (p->tag == t)
            break;
        q = p;
        p = p->next;
    }
    if (p == NULL)
        cout << "Tag ID doesn't exist\n";
    else if (p == alloc_head)
        alloc_head = alloc_head->next;
    else
        q->next = p->next;
    struct free* temp = free_head;
    while (temp != NULL) {
        if (temp->tag == p->block_id) {
            temp->size += p->size;
            break;
        }
        temp = temp->next;
    }
}
 
// Driver Code
int main()
{
    int blockSize[] = { 100, 500, 200 };
    int processSize[] = { 95, 417, 112, 426 };
    int m = sizeof(blockSize)
            / sizeof(blockSize[0]);
    int n = sizeof(processSize)
            / sizeof(processSize[0]);
 
    for (int i = 0; i < m; i++)
        create_free(blockSize[i]);
 
    for (int i = 0; i < n; i++)
        create_alloc(processSize[i]);
 
    print_alloc();
 
    // block of tag id 1 deleted
    // to free space for block of size 426
    delete_alloc(1);
 
    create_alloc(426);
    cout << "After deleting block"
         << " with tag id 1.\n";
    print_alloc();
}
