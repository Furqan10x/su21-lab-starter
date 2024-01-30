#include <stddef.h>
#include "ll_cycle.h"


//the function ll_has_cycle() to implement the following algorithm for checking if a singly- linked list has a cycle

int ll_has_cycle(node *head) {
    // Initialize pointers
    node *fast_ptr;
    node *slow_ptr;
    fast_ptr = head;
    slow_ptr = head;
    
    // No cycle if the list is empty or has only one node
    if (head == NULL) {
        return 0;
    }
    
    // Traverse the linked list with two pointers (fast and slow)
    while (fast_ptr != NULL && fast_ptr->next != NULL) 
    
    { 
        // Move pointers forward
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
        // we can also use for loop for advances fast_ptr by 2 heads. 
        
        // If fast pointer meets slow pointer, there is a cycle
        if (fast_ptr == slow_ptr) { 
            return 1; 
        }
        
    }
    
    // If the loop completes without fast pointer reaching NULL, there's no cycle
    return 0;
}


