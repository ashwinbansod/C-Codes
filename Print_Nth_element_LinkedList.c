#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int iData;
    struct Node *psNext;
};

typedef struct Node Node;

void AddNode(Node **psHead, int iData)
{
    Node *psNewNode = NULL;
    
    psNewNode = (Node *) malloc(sizeof(Node));
    
    psNewNode->psNext = *psHead;
    psNewNode->iData = iData;
    
    *psHead = psNewNode;
}

void PrintList(Node *psHead)
{
    while (psHead != NULL)
    {
        printf("%d ",psHead->iData);
        psHead = psHead->psNext;
    }
    printf("\n");
}

void GetListLength(Node *psHead, int *piLength)
{
    while (psHead != NULL)
    {
        (*piLength)++;
        psHead = psHead->psNext;
    }
}

void GetElement(Node *psHead, int iElemintNumber, int *piData)
{
    int iCounter = 0;
    
    while (psHead != NULL)
    {
        iCounter++;
        
        if (iCounter == iElemintNumber)
        {
            *piData = psHead->iData;
        }
        psHead = psHead->psNext;
    }
}

int PrintNthElementfromLast(Node *psHead, int iLength, int iElementNumber)
{
    int iRetVal = 0;
    int iData = 0;
    
    if (iLength < iElementNumber)
    {
        printf("Invalid element Number :[%d]. Length of list is [%d]\n",
                iElementNumber,
                iLength);
        
        iRetVal = 1;
    }
    else
    {
        GetElement(psHead, iElementNumber, &iData);
        
        printf("\nElement from Last No.: %d   Data: %d\n", 
                iElementNumber, 
                iData);
    }
    
    return iRetVal;
}

int PrintNthElementfromFirst(Node *psHead, int iLength, int iElementNumber)
{
    int iRetVal = 0;
    int iData = 0;
    
    if (iLength < iElementNumber)
    {
        printf("Invalid element Number :[%d]. Length of list is [%d]\n",
                iElementNumber,
                iLength);
        
        iRetVal = 1;
    }
    else
    {
        GetElement(psHead, (iLength - iElementNumber + 1), &iData);
        
        printf("\nElement from First No.: %d   Data: %d\n", 
                iElementNumber, 
                iData);
    }
    
    return iRetVal;
}

int main()
{
    int iRetVal = 0;
    Node *psHeadNode = NULL;
    int iLength = 0;
    
    AddNode(&psHeadNode, 1);
    AddNode(&psHeadNode, 2);
    AddNode(&psHeadNode, 3);
    AddNode(&psHeadNode, 4);
    AddNode(&psHeadNode, 5);
    AddNode(&psHeadNode, 6);

    PrintList(psHeadNode);
    
    GetListLength(psHeadNode, &iLength);
    
    printf("Length: [%d]\n",iLength);
    
    iRetVal = PrintNthElementfromFirst(psHeadNode, iLength, 1);
    iRetVal = PrintNthElementfromLast(psHeadNode, iLength, 1);

    return iRetVal;
}

