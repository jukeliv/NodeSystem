#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _Node Node;

struct _Node
{
    unsigned int id;
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

Node* Node_new(const char* id);
void Node_free(Node* node);
void NodeList_init(NodeList* list);
void NodeList_add(NodeList* list, Node* node);
Node* NodeList_find(NodeList* list, const char* id);
void NodeList_free(NodeList* list);