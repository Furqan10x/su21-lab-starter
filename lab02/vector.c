#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

/* Define the structure for the vector */
struct vector_t {
    size_t size;
    int *data;
};

/* Function to handle memory allocation failures */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Function to create a new vector */
vector_t *vector_new() {
    /* Declare a pointer to hold the new vector */
    vector_t *retval;
    
    /* Allocate memory for the vector structure */
    retval = (vector_t*)malloc(1*sizeof(vector_t));

    /* Check if memory allocation was successful */
    if (retval == NULL) {
        allocation_failed();
    }

    /* Initialize the size of the vector to 1 */
    retval->size = 1;

    /* Allocate memory for the vector's data array */
    retval->data = (int*)malloc(1*sizeof(int));

    /* Check if memory allocation was successful */
    if (retval->data == NULL) {
        /* Free memory allocated for the vector structure */
        free(retval);
        allocation_failed();
    }

    /* Initialize the single component of the vector to 0 */
    retval->data[0] = 0;

    /* Return the newly created vector */
    return retval;
}

/* Function to get the value at a specified location in the vector */
int vector_get(vector_t *v, size_t loc) {
    /* Check if the vector pointer is NULL */
    if (v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* Check if the specified location is out of bounds */
   /* if (loc >= v->size) {
        fprintf(stderr, "vector_get: index out of bounds.\n");
        abort();
    } */

    /* Return the value at the specified location */
    return v->data[loc];
}

/* Function to delete a vector and free its memory */
void vector_delete(vector_t *v) {
    /* Check if the vector pointer is NULL */
    if (v == NULL) {
        return;
    }

    /* Free the memory allocated for the vector's data array */
    free(v->data);

    /* Free the memory allocated for the vector structure */
    free(v);
}

/* Function to set a value at a specified location in the vector */
void vector_set(vector_t *v, size_t loc, int value) {
    /* Check if the vector pointer is NULL */
    if (v == NULL) {
        fprintf(stderr, "vector_set: passed a NULL vector.\n");
        abort();
    }

    /* Check if the specified location is greater than or equal to the vector's size */
    if (loc >= v->size) {
        /* Resize the vector to accommodate the specified location */
        size_t new_capacity = loc + 1;
        int *new_data = realloc(v->data, new_capacity * sizeof(int));

        /* Check if memory reallocation was successful */
        if (new_data == NULL) {
            allocation_failed();
        }

        }

    /* Set the value at the specified location in the vector */
    v->data[loc] = value;
    
}

