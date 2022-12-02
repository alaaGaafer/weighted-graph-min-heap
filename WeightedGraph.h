#ifndef WEIGHTEDGRAPH_H_INCLUDED
#define WEIGHTEDGRAPH_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>
#include<climits>
using namespace std;
class WeightedGraph
{
    int** g;
    int nVertices;
    int nEdges;
public:

    int getNVertices()//returns the number of vertices
    {
        return nVertices;
    }
    int getWeight(char v1,char v2)//returns weight of the edge connecting the given vertices
    {
        return g[v1-'a'][v2-'a'];
    }
    int* returnNeighbors(int v)// returns the indices of the neighbors of the vertex v as an int array
    {
        int count=numNeighbors(v);
        int *arr=new int[count];
        count=0;
        for(int i=0; i<nVertices; i++)
        {
            if(g[v][i]!=0)
            {
                arr[count]=i;
                count++;
            }
        }
        return arr;
    }

    int numNeighbors(int v)//returns the number of neighbors of the vertex v
    {
        int coun=0;
        for(int i=0 ; i<nVertices; i++)
        {
            if (g[v][i]!=0)
            {
                coun++;
            }
        }
        return coun;
    }
    void loadGraphFromFile(ifstream& ifile)
    {
        char v1,v2;
        int w;
        ifile>>nVertices;
        ifile>>nEdges;
        g=new int *[nVertices];
        for(int i=0; i<nVertices; i++)
            g[i]=new int [nVertices];
        for(int i=0; i<nVertices; i++)
            for(int j=0; j<nVertices; j++)
                g[i][j]=0;
        for(int i=0; i<nEdges; i++)
        {
            ifile>>v1;
            ifile>>v2;
            ifile>>w;
            g[v1-'a'][v2-'a']=w;
        }

    }
    void print()
    {
        for(int i=0; i<nVertices; i++)
        {
            char ch=97+i;
            cout<<setw(3)<<ch;
        }
        for(int i=0; i<nVertices; i++)
        {
            char ch=97+i;
            cout<<endl;
            cout<<ch;
            for(int j=0; j<nVertices; j++)
                cout<<setw(3)<<g[i][j];
        }
    }

    int minimumDist(Node dist[], bool Tset[])       //returns the index of the minimum node
    {
        int min=INT_MAX,index;

        for(int i=0; i<nVertices; i++)
        {
            if(Tset[i]==false && dist[i].cost<=min)
            {
                min=dist[i].cost;
                index=i;
            }
        }
        return index;
    }
    void dijkstra(char startVertex, char* prev, Node distances[])//find the shortest path from the start vertex to all other vertices, by filling the prev array and the distances array
    {
        int stV=startVertex-'a';
        bool Tset[nVertices];
        for(int i = 0; i<nVertices; i++)
        {
            distances[i].cost=INT_MAX;                 //initializing all the nodes' costs to infinity
            distances[i].label=(i+'a');                //naming the labels
            Tset[i] = false;                           //marking all the vertices as unvisited
        }

        distances[stV].cost=0;                        //making the cost of the start vertex =0 and marking it as a parent for itself
        prev[stV]=stV+'a';

        for(int i = 0; i<nVertices; i++)
        {
            int m=minimumDist(distances,Tset);
            Tset[m]=true;                            //marking the vertex as visited
            for(int j = 0; j<nVertices; j++)
            {
                if(!Tset[j] && g[m][j] && distances[m].cost!=INT_MAX && distances[m].cost+g[m][j]<distances[j].cost)
                {
                    distances[j].cost=(distances[m].cost+g[m][j]);
                    prev[j]=m+'a';
                }

            }
        }
        MinHeap h;
        h.buildMinHeap(distances,nVertices);

    }
};

#endif // WEIGHTEDGRAPH_H_INCLUDED
