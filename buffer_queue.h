/**
 * @file buffer_queue.h
 *
 * @brief Buffer queue implementation
 *
 *
 */
#ifndef __BUFFER_QUEUE_H__
#define __BUFFER_QUEUE_H__


#include <stdio.h>
#include <stdlib.h>

struct buffer_queue {
    void **buffers;
    int head;
    int tail;
    int size;
};

typedef struct buffer_queue buffer_queue_t;

void init_buffer_queue(buffer_queue_t *queue, int size);
void free_buffer_queue(buffer_queue_t *queue);
void enqueue_buffer(buffer_queue_t *queue, void *buffer);
void *dequeue_buffer(buffer_queue_t *queue);
#endif //__BUFFER_QUEUE_H__
