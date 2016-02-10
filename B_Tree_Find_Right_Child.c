#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int iData;
    struct Node *psLeft;
    struct Node *psRight;
};

typedef struct Node Node;

void GetNewNode(Node **psNewNode, int iData)
{
    *psNewNode = (Node *) malloc(sizeof(Node));
    (*psNewNode)->psLeft = NULL;
    (*psNewNode)->psRight = NULL;
    (*psNewNode)->iData = iData;
}

void AddLeftNode(Node *psRoot, int iData)
{
    Node *psNewNode = NULL;
    
    GetNewNode(&psNewNode, iData);
    psRoot->psLeft = psNewNode;
}

void AddRightNode(Node *psRoot, int iData)
{
    Node *psNewNode = NULL;
    
    GetNewNode(&psNewNode, iData);
    psRoot->psRight = psNewNode;
}


void GetRightChild(Node *psRoot, int iData)
{
    if (psRoot)
    {
        if (psRoot->iData == iData)
        {
            if (psRoot->psRight)
            {
                printf("Given Node: [%d]  Right Child: [%d]\n",
                        iData,
                        psRoot->psRight->iData);
            }
            else
            {
               printf("Given Node: [%d]  Right Child: [NULL]\n",
                        iData);
            }
        }
        else
        {
            // Check for left child
            if (psRoot->psLeft)
            {
                GetRightChild(psRoot->psLeft, iData);
            }
        
            // Check for Right child
            if (psRoot->psRight)
            {
                GetRightChild(psRoot->psRight, iData);
            }
        }
    }
    
}


int main()
{
    int iRetVal = 0;
    Node *psRoot = NULL;
    
    GetNewNode(&psRoot, 10);
    AddLeftNode(psRoot,5);
    AddRightNode(psRoot,15);
    AddLeftNode(psRoot->psLeft,3);
    AddRightNode(psRoot->psLeft->psLeft,4);
    AddLeftNode(psRoot->psRight,13);
    AddRightNode(psRoot->psRight->psLeft,14);
    AddRightNode(psRoot->psRight,20);
    AddRightNode(psRoot->psRight->psRight,25);
    AddLeftNode(psRoot->psRight->psRight->psRight,22);
    
    GetRightChild(psRoot,20);

    return iRetVal;
}