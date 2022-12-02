#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED
#include <iostream>
#include <iomanip>
using namespace std;
struct Node
{
    char label;
    int cost;
};
class MinHeap
{
    Node* heap; //an array of nodes
    int _size; //size of array
public:
    Node extractMin() //returns & removes the node with minimum cost
    {
        if (_size <= 0)
            return *heap;
        if (_size == 1)
        {
            _size--;
            return *heap;
        }
        Node root;
        root=heap[0];
        heap[0]=heap[_size--];
        minHeapify(0,_size);
        return root;
    }
    void buildMinHeap(Node arr[],int n)// allocates array then builds a min-heap from an array of struct Node with the given size
    {
        _size=n;
        heap = new Node[n];
        for(int i=0; i<n; i++)
        {
            heap[i].cost=arr[i].cost;
            heap[i].label=arr[i].label;
            minHeapify(i,n);
        }
    }
    void minHeapify(int i, int n)//restores the min-heap property for the “heap” array using the given index and size n
    {
        int l=2*i+1;
        int r=2*i+2;
        int minn=i;
        if(l<n&& heap[l].cost>heap[minn].cost)
            minn=l;
        if(r<n&&heap[r].cost>heap[minn].cost)
            minn=r;

        if(minn != i)
        {
            swap(heap[i],heap[minn]);
            minHeapify(minn,n);
        }
    }
    void decreaseKey(char label,int newCost)//decreases the node that has the given label to newCost
    {
        int index =label-'a';
        heap[index].cost = newCost;
        while (index != 0 && heap[parent(index)].cost > heap[index].cost)
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    int parent(int i)//returns the index of the parent of i
    {
        i=(i-1)/2;
        return i;
    }
    int getSize()//returns size of the heap
    {
        return _size;
    }
    bool inHeap(char ch)//checks if the node with the given label is in the heap
    {
        for(int i=0; i<_size; i++)
        {
            if(heap[i].label==ch)
                return true;
        }
        return false;
    }
     void print()
    {
        for(int i=0; i<_size; i++)
        {
                cout<<setw(3)<<heap[i].cost<<setw(3)<<heap[i].label<<endl;;
        }
    }
};
#endif // MINHEAP_H_INCLUDED
