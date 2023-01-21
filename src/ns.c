#include "../include/ns.h"

//hash function cuz i hate strings
unsigned int hash(const char* str)
{
    unsigned int x = strlen(str);
    for(int i = 0; i < strlen(str); i++)
    {
        x+=str[i] - str[i]*0.1f;
        x*=str[i]*i*3;
    }
    return x%4294967295*strlen(str);
}

Node* Node_new(const char* id)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->last = NULL;
    node->id = hash(id);
    return node;
}

void Node_free(Node* node)
{
    free(node->last);
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

Node* NodeList_find(NodeList* list, const char* id)
{
    if(list->size < 1)
    {
        fprintf(stderr, "NULL List\n");
        return NULL;
    }
    for(int i = 0; i < list->size; i++)
    {
        if(list->nodes[i].id == hash(id))
        {
            return &list->nodes[i];
        }
    }
    
    fprintf(stderr, "Couldn't find \"%s\"", id);
    return NULL;
}

void NodeList_free(NodeList* list)
{
    for(int i = 0; i < list->size; i++)
    {
        Node_free(&list->nodes[i]);
    }
}