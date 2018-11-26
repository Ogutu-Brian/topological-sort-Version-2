#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
using namespace std;
class GraphList
{
public:
    GraphList(int number_vertices)
    {
        numVertices = number_vertices;
        headArray = new ListNode* [numVertices];

        int counter = 0;
        while(counter < numVertices)
        {
            headArray[counter] = new ListNode[numVertices];
            counter++;
        }
        counter = 0;
        while(counter < numVertices)
        {
            for(int a = 0; a < numVertices; a++)
            {
                headArray[counter][a].nodeValue = -1;
                headArray[counter][a].nextNode = nullptr;
            }
            counter++;
        }
    }

    ~GraphList()
    {
        for(int a = 0; a < numVertices; a++)
        {
            delete[] headArray[a];
        }
    }

    void addEdge(int x, int y)
    {
        ListNode *x_node = new ListNode;
        ListNode *y_node = new ListNode;

        x_node->nodeValue = x;
        y_node->nodeValue = y;

        x_node->nextNode = y_node;

    }

    bool hasEdge(int x,int y)
    {
        if(headArray[x][y].nextNode->nodeValue == y)
        {
            return true;
        }
        return false;
    }

    void printGraph()
    {
       int a = 0;
       while(a < numVertices)
       {
           cout<<a<<"--->";
           for(int m = 0; m < numVertices; m++)
           {
               if(hasEdge(a,m))
               {
                   cout<<m;
               }
               else
               {
                   cout<<"NULL";
               }
           }
           cout<<"\n";
       }

    }

private:
    int numEdges;
    int numVertices;
    struct ListNode
    {
        int nodeValue;
        ListNode * nextNode;
    };
    ListNode** headArray;
};
#endif // GRAPHLIST_H
