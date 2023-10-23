/**
 * @file buffer_queue.c
 *
 * @brief Buffer queue implementation
 *
 *
 */

#include "buffer_queue.h"
void init_buffer_queue(buffer_queue_t *queue, int size)
{
    queue->size = size;
    queue->head = 0;
    queue->tail = 0;
    queue->buffers = malloc(sizeof(queue->buffers)*size);
    return;
}
void free_buffer_queue(buffer_queue_t *queue)
{
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    if (queue->buffers)
        free(queue->buffers);
    return;

}
void enqueue_buffer(buffer_queue_t *queue, void *buffer)
{
    if ((queue->tail + 1) % queue->size == queue->head)
    {
        printf("Buffer queue full\n");
        queue->head = (queue->head + 1) % queue->size;
    }
    queue->buffers[queue->tail] = buffer;
    queue->tail = (queue->tail + 1) % queue->size;
}

void *dequeue_buffer(buffer_queue_t *queue)
{
    void *buffer = NULL;
    if (queue->tail != queue->head)
    {
        buffer = queue->buffers[queue->head];
        queue->buffers[queue->head] = NULL;
        queue->head = (queue->head + 1) % queue->size;
    }
    else
    {
        printf("Buffer queue is empty\n");
    }
    return buffer;
}

