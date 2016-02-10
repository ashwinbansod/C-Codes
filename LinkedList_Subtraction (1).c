#include <stdio.h>


struct Node
{
    int iData;
    struct Node* sNextNode;
};

typedef struct Node Node;

/*********** Function Declaration *********************************************/
Node*  Substract(Node *psFirst, Node *psSecond);

Node*  Add(Node *psFirst, Node *psSecond);

/******************Main Function **********************************************/
int main()
{
    struct Node* sNewNode;
    struct Node* sPrevNode = NULL;
    struct Node* sFirstHead = NULL;
    struct Node* sSecondHead = NULL;
    char cInputchar = 'y';
    
    printf("First number\n");
    while (cInputchar == 'y')
    {
        printf("Enter single Digit : ");
        sNewNode = (Node *) malloc(sizeof(Node));
        sFirstHead = sNewNode;

        
        scanf("%d", &sNewNode->iData);
        if (sPrevNode == NULL)
        {
            sNewNode->sNextNode = NULL;
        }
        else
        {
            sNewNode->sNextNode = sPrevNode;
        }
        sPrevNode = sNewNode;
        
        printf("Do you want to continue ? (y/n)");
        scanf("%c",&cInputchar);
        scanf("%c",&cInputchar);
    }
    
    
    cInputchar = 'y';
    sPrevNode = NULL;
    printf("\nSecond number\n");
    while (cInputchar == 'y')
    {
        printf("Enter single Digit : ");
        sNewNode = (Node *) malloc(sizeof(Node));
        sSecondHead = sNewNode;

        
        scanf("%d", &sNewNode->iData);
        if (sPrevNode == NULL)
        {
            sNewNode->sNextNode = NULL;
        }
        else
        {
            sNewNode->sNextNode = sPrevNode;
        }
        sPrevNode = sNewNode;
        
        printf("Do you want to continue ? (y/n)");
        scanf("%c",&cInputchar);
        scanf("%c",&cInputchar);
    }  
    
    
    sNewNode= sFirstHead;
    printf("\n First Number (Reverse) : ");
    while (sNewNode != NULL)
    {
        printf("-->%d",sNewNode->iData);
        sNewNode = sNewNode->sNextNode;
    }
    
    sNewNode= sSecondHead;
    printf("\n Second Number (Reverse): ");
    while (sNewNode != NULL)
    {
        printf("-->%d",sNewNode->iData);
        sNewNode = sNewNode->sNextNode;
    }
    
    printf("\n\n");
    /*
    sNewNode = Substract(sFirstHead,sSecondHead);

    printf("\n Subtraction (Reverse): ");
    while (sNewNode != NULL)
    {
        printf("-->%d",sNewNode->iData);
        sNewNode = sNewNode->sNextNode;
    }
    
    printf("\n\n");
    */
    sNewNode = Add(sFirstHead,sSecondHead);

    printf("\n Add (Reverse): ");
    while (sNewNode != NULL)
    {
        printf("-->%d",sNewNode->iData);
        sNewNode = sNewNode->sNextNode;
    }
    
    printf("\n\n");    
    return 0;
}

/*********** Function Definition **********************************************/
// This fuction substracts second linked list from first
// Assumption: First Linked list is greater than second.
Node*  Substract(Node *psFirst, Node *psSecond)
{
    int iCarryBit = 0;
    Node *psResult = psFirst;
    

    while (psFirst != NULL)
    {
        if (psSecond != NULL)
        {
            if (iCarryBit == 1)
            {
                psSecond->iData += 1;
                iCarryBit = 0;
            }
            if (psFirst->iData < psSecond->iData)
            {
                iCarryBit = 1;
                psFirst->iData = (psFirst->iData + 10) - psSecond->iData;
            }
            else
            {
                psFirst->iData = psFirst->iData - psSecond->iData;
            }
            
            psSecond = psSecond->sNextNode;
        }
        else
        {
            if (iCarryBit == 1)
            {
                psFirst->iData = psFirst->iData - 1;
                iCarryBit = 0;
            }
        }
        
        psFirst = psFirst->sNextNode;
    }
    
    return psResult;
}

// This fuction Adds two linked lists 
Node*  Add(Node *psFirst, Node *psSecond)
{
    int iCarryBit = 0;
    Node *psResult = psFirst;
    Node *psNewNode;

    while (psFirst != NULL)
    {
        if (psSecond != NULL)
        {
            if (iCarryBit == 1)
            {
                psSecond->iData += 1;
                iCarryBit = 0;
            }
            if ((psFirst->iData + psSecond->iData) > 9)
            {
                iCarryBit = 1;
                psFirst->iData = (psFirst->iData + psSecond->iData) - 10;
            }
            else
            {
                psFirst->iData = psFirst->iData + psSecond->iData;
            }
            
            psSecond = psSecond->sNextNode;
        }
        else
        {
            if (iCarryBit == 1)
            {
                if ((psFirst->iData + 1) > 9)
                {
                    if (psFirst->sNextNode == NULL)
                    {
                        psNewNode = (Node *) malloc(sizeof(Node));
                        psFirst->iData = (psFirst->iData + 1) - 10;
                        psNewNode->iData = 1;
                        psFirst->sNextNode = psNewNode;
                        psNewNode->sNextNode = NULL;
                    }
                }
                else
                {
                    psFirst->iData = psFirst->iData + 1;
                }
                iCarryBit = 0;
            }
        }
        
        psFirst = psFirst->sNextNode;
    }
    
    return psResult;
}
