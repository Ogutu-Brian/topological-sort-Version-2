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
        ListNode *y_node = new ListNode;
        y_node->nodeValue = y;

        headArray[x][y].nodeValue = x;
        headArray[x][y].nextNode = y_node;

    }

    bool hasEdge(int x,int y)
    {
        if(headArray[x][y].nodeValue != -1)
        {
            return true;
        }
        return false;
    }

    void printGraph()
    {
        int a = 0;
        cout<<"\nAdjacency List:"<<endl;

        while(a < numVertices)
        {
            cout<<a;
            for(int m = 0; m < numVertices; m++)
            {
                if(hasEdge(a,m))
                {
                    cout<<"--->"<<m;
                }
            }
            cout<<"--->NULL";
            cout<<endl;
            a++;
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
