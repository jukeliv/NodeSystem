#include "../include/ns.h"

int main(void)
{
    NodeList list;
    NodeList_init(&list);
    
    //it works when you call it once but not when you do it twice?
    NodeList_add(&list, Node_new("root"));
    NodeList_add(&list, Node_new("lol"));

    printf("epic");
    Node* root = NodeList_find(&list, "root");
    if(!root)
    {
        return -1;
    }
    Node* another = NodeList_find(&list, "lol");
    if(!another)
    {
        return -2;
    }
    another->amp=3;
    another->freq=5;
    
    Node* output = Node_new("output");

    for(int i = 0; i < list.size; i++)
    {
        output->amp += list.nodes[i].amp;
        output->freq += list.nodes[i].freq;
    }
    printf("(%f, %f)\n", output->amp, output->freq);
    return 0;
}