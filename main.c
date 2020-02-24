#include "queue.h"
int main(int argc, char const *argv[])
{
    queue_t *q = q_new();
    q_insert_head(q, "5");
    q_insert_head(q, "6");
    // q_insert_head(q, "7");
    // q_insert_head(q, "8");
    // q_insert_head(q, "9");
    // q_insert_head(q, "10");
    q_sort(q);
    return 0;
}
