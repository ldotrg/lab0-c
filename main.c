#include "queue.h"
int main(int argc, char const *argv[])
{
    queue_t *q = q_new();
    q_insert_head(q, "lunlun");
    return 0;
}
