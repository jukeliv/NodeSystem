#include "../include/ns.h"

Node* Node_new(const char* tag)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->last = NULL;
    strcpy(node->tag, tag);
    return node;
}

void Node_free(Node* node)
{
    free(node->tag);
}

void NodeList_init(NodeList* list)
{
    list->heap_size = 1;
    list->size = 0;
    
    list->nodes = (Node*) malloc(sizeof(Node));
}

void NodeList_add(NodeList* list, Node* node)
{
    while (list->size >= list->heap_size) {
        list->heap_size *= 2;
        list->nodes = (Node*)realloc(list->nodes, sizeof(Node) * list->heap_size);
    }

    list->nodes[list->size++] = *node;
    
    if(list->size>2)
    {
        list->nodes[list->size-1].last = &list->nodes[list->size-2];
    }
}

Node* NodeList_find(NodeList* list, const char* tag)
{
    if(list->size < 1)
    {
        fprintf(stderr, "NULL List\n");
        return NULL;
    }
    for(int i = 0; i < list->size; i++)
    {
        if(!strcmp(list->nodes[i].tag, tag))
        {
            return &list->nodes[i];
        }
    }
    
    fprintf(stderr, "Couldn't find \"%s\"", tag);
    return NULL;
}