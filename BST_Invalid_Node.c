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

/*
void PrintTree(Node *psRoot)
{
    printf("Root: [%d]  Left")
}
*/

void PrintLeftBoundry(Node *psRoot)
{
    if (psRoot->psLeft)
    {
        printf("%d ",psRoot->iData);
        PrintLeftBoundry(psRoot->psLeft);
    }
    else if (psRoot->psRight)
    {
        printf("%d ",psRoot->iData);
        PrintLeftBoundry(psRoot->psRight);
    }
}

void PrintRightBoundry(Node *psRoot)
{
    if (psRoot->psRight)
    {
        printf("%d ",psRoot->iData);
        PrintLeftBoundry(psRoot->psRight);
    }
    else if (psRoot->psLeft)
    {
        printf("%d ",psRoot->iData);
        PrintLeftBoundry(psRoot->psLeft);
    }
}

void PrintLeaves(Node *psRoot)
{
    if (psRoot)
    {
        PrintLeaves(psRoot->psLeft);
        
        if ((psRoot->psLeft == NULL) && (psRoot->psRight == NULL))
        {
            printf("%d ", psRoot->iData);
        }
        
        PrintLeaves(psRoot->psRight);
    }
}

void CheckNode(Node *psRoot)
{
    if (psRoot)
    {
        
        
        // Check Left Child
        if (psRoot->psLeft)
        {
            if (psRoot->psLeft->iData >= psRoot->iData)
            {
                printf("Invalid Left Child Found: [%d] Root: [%d]\n", 
                        psRoot->psLeft->iData,
                        psRoot->iData);
            }
            else
            {
                CheckNode(psRoot->psLeft);
            }
        }

        // Check Right child
        if (psRoot->psRight)
        {
            if (psRoot->psRight->iData <= psRoot->iData)
            {
                printf("Invalid Right Child Found: [%d] Root: [%d]\n", 
                        psRoot->psRight->iData,
                        psRoot->iData);
            }
            else
            {
                CheckNode(psRoot->psRight);
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
    AddRightNode(psRoot->psRight->psRight->psRight,2);
    
    CheckNode(psRoot);

    return iRetVal;
}