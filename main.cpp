#include <iostream>                                 //الاء اسامة محمد شوقي-20207013-sg2
#include "MinHeap.h"
#include "WeightedGraph.h"
#include <fstream>
#include <iomanip>
#include<climits>
using namespace std;

int main()
{
    WeightedGraph wg;
    ifstream ifile("graph.txt");
    wg.loadGraphFromFile(ifile);
    wg.print();
    cout<<endl;
    char* p;
    p = new char[wg.getNVertices()];
    Node* n;
    n=new Node[wg.getNVertices()];
    wg.dijkstra('g',p,n);
    cout<<endl<<"Node\tCost\tPrevious";
    for(int i=0; i<wg.getNVertices(); i++)
    {
        cout<<endl<<n[i].label<<"\t"<<n[i].cost<<"\t"<<p[i];
    }
    cout<<endl;
    ifile.close();
    return 0;
}
