#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL)
        return q;
    q->head = NULL;
    q->tail = q->head;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (q == NULL)
        return;
    list_ele_t *curr;
    list_ele_t *prev = NULL;
    curr = q->head;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        if (prev->value)
            free(prev->value);
        free(prev);
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    if (s == NULL || q == NULL)
        goto error_exit;
    int size = strlen(s);
    newh = (list_ele_t *) malloc(sizeof(list_ele_t));
    if (newh == NULL)
        goto error_exit;
    newh->value = (char *) malloc(size + 1);
    if (!newh->value) {
        free(newh);
        goto error_exit;
    }
    memset(newh->value, 0, size);
    strncpy(newh->value, s, size);
    newh->value[size] = 0;
    newh->next = q->head;
    q->head = newh;
    q->size++;
    if (q->tail == NULL)
        q->tail = newh;
    return true;
error_exit:
    return false;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt;
    if (s == NULL || q == NULL)
        goto error_exit;
    int size = strlen(s);
    newt = (list_ele_t *) malloc(sizeof(list_ele_t));
    if (newt == NULL)
        goto error_exit;
    newt->value = (char *) malloc(size + 1);
    if (!newt->value) {
        free(newt);
        goto error_exit;
    }
    memset(newt->value, 0, size);
    strncpy(newt->value, s, size);
    newt->value[size] = 0;
    newt->next = NULL;
    q->tail->next = newt;
    q->tail = newt;
    q->size++;
    if (q->head == NULL)
        q->head = newt;
    return true;
error_exit:
    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (q == NULL || q->size == 0)
        return false;
    list_ele_t *curr = q->head;
    if (sp && curr->value) {
        strncpy(sp, curr->value, bufsize - 1);
        q->head = q->head->next;
        free(curr->value);
        free(curr);
        q->size--;
        return true;
    }
    return false;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q)
        return q->size;
    return 0;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    list_ele_t *prev = NULL;
    list_ele_t *temp = NULL;
    list_ele_t *curr;
    if (q == NULL)
        return;
    if (q->size == 1)
        return;
    curr = q->head;
    q->tail = q->head;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    q->head = prev;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
