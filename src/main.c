#include "../include/ns.h"

int main(void)
{
    NodeList list;
    NodeList_init(&list);
    
    NodeList_add(&list, Node_new("root"));
    NodeList_add(&list, Node_new("another"));

    Node* root = NodeList_find(&list, "root");
    if(!root)
    {
        return -1;
    }
    root->amp = 10;
    root->freq = 5;

    Node* another = NodeList_find(&list, "another");
    if(!another)
    {
        return -2;
    }
    another->amp=3;
    another->freq=5;
    
    NodeList_free(&list);
    
    Node* output = Node_new("output");
    
    Node_free(output);

    for(int i = 0; i < list.size; i++)
    {
        output->amp += list.nodes[i].amp;
        output->freq += list.nodes[i].freq;
    }
    printf("(amp: %f, freq: %f)\n", output->amp, output->freq);

    getchar();

    return 0;
}