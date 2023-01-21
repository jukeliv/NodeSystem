#ifndef NODE_SYSTEM_H
#define NODE_SYSTEM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef ui_t
    #define ui_t unsigned int
#endif

typedef struct _Node Node;

struct _Node
{
    ui_t tag;
    float amp, freq;
    struct _Node* last;
};

typedef struct _Node Node;

struct _NodeList
{
    size_t heap_size;
    size_t size;
    Node* nodes;
};

typedef struct _NodeList NodeList;

Node* Node_new(const char* tag);
void Node_free(Node* node);

void NodeList_init(NodeList* list);
void NodeList_add(NodeList* list, Node* node);
Node* NodeList_find(NodeList* list, const char* tag);
void NodeList_free(NodeList* list);

#endif //NODE_SYSTEM_H