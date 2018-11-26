#include <iostream>
#include <graphmatrix.h>
#include <graphlist.h>
#include <fstream>
#include <list>
#include <stack.h>
#include <algorithm>

using namespace std;

int main()
{
    int numVertices;
    ifstream myFile;
    string fileName;
    list<int> sortedList;
    list<int> unsortedList;
    Stack<int> stack;
    bool gotFirstVertex = false;
    int a,b;

    cout<<"Enter the name of your file that contains the graph vertices:";
    cin>>fileName;

    try
    {
        myFile.open(fileName);
    }
    catch(const exception& e)
    {
        cout<<"The file name that you entered does not exist"<<endl;
        return 0;
    }

    myFile>>numVertices;
    Graph graph(numVertices);
    GraphList graphList(numVertices);

    while(myFile >> a >> b)
    {
        graph.addEdge(a,b);
        graphList.addEdge(a,b);
    }
    myFile.close();

    graph.printGraph();
    graphList.printGraph();

    cout<<"\nNow topologically sorting graph.\n";

    for(int j = 0; j < numVertices; j++)
    {
        unsortedList.push_back(j);
    }
    for(int i = 0; i < numVertices; i++)
    {
        int first;
        first = graph.getFirstVertex();
        if(first == -1)
        {
            cout<<"\nAh shooty pooty. This graph has a cycle"<<endl;
            cout<<"\nThis graph can't be topologically sorted because it is not a DAG\n"<<endl;
            return 0;
        }
        sortedList.push_back(first);
    }
    cout<<"\nThe graph vertices topologically sorted are:";
    reverse(sortedList.begin(),sortedList.end());
    for(int value: sortedList)
    {
        stack.push(value);
    }
    while(!stack.isEmpty())
    {
        int poppedItem;
        stack.pop(poppedItem);
        cout<<poppedItem<<" ";
    }
    cout<<"\n"<<endl;
    return 0;
}
