#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <iostream>
using namespace std;
class Graph
{
public:
    Graph(int number_vertices)
    {
        numVertices = number_vertices;
        vertexMatrix = new int* [numVertices];
        int i = 0;
        while(i < numVertices)
        {
            vertexMatrix[i] = new int[numVertices];
            i++;
        }

        i = 0;
        while(i < numVertices)
        {
            for(int j = 0; j < numVertices; j++){
                vertexMatrix[i][j] = 0;
            }
            i++;
        }
    }

    ~Graph()
    {
        for(int x = 0; x < numVertices; x++)
        {
            delete[] vertexMatrix[x];
        }
    }

    void addEdge(int x, int y){
        vertexMatrix[x][y] = 1;
    }

    void printGraph(){
        int a = 0;
        while(a < numVertices)
        {
            for(int j = 0; j < numVertices;j++)
            {
                cout<<vertexMatrix[a][j]<<" ";
            }
            cout<<"\n";
            a++;
        }
    }

    int getFirstVertex()
    {
        int a = 0;
        while(a < numVertices)
        {
            if(isFirstVertex(a))
            {
                return a;
            }
            a++;
        }
        return 0;
    }

    bool isFirstVertex(int vertex)
    {
        for(int a = 0; a < numVertices; a++)
        {
            if(isThereAnEdge(a,vertex))
            {
                return false;
            }
            else
            {
                for(int a = 0; a < numVertices; a++)
                {
                    vertexMatrix[a][vertex] = 1;
                }
            }
        }
        return true;
    }

    bool isThereAnEdge(int x, int y)
    {
        if(vertexMatrix[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    int numEdges;
    int numVertices;
    int ** vertexMatrix;
};
#endif // GRAPHMATRIX_H
