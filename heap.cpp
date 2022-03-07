// heap.cpp
// Madhav Rai

#include "heap.h"
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using namespace std;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  if (length==0) 
  {
    length = 1;
    return;
  }


  int i = length;

  int swap = 0;

  

  int temp = 0;

  length = length + 1;

  int sib = 0;
  
  while(i!=0)
  {
    swap = (i-1)/2;
    if(swap==0)
    {
      sib = 0;
    }
    else if(swap%2==1)
    {
      sib = swap + 1;
      
    }
    else
    {
      sib = swap - 1;
    }

      
    if((value >= vdata.at(swap)) && (value>=vdata.at(sib)))
    {
      return;
    }

    if(vdata.at(sib)>vdata.at(swap))
    {
      swap = sib;
    }
    
    temp = vdata.at(swap);

    vdata.at(swap) = value;

    vdata.at(i) = temp;

    i = swap;
    
      
      
  }

  

}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){


  if (length == 0) return ;

  if(length==1)
  {
    vdata.pop_back();
    length = 0;
    return;
  }
  if (length == 2)
  {
    int y = vdata.at(1);
    vdata.at(0) = y;
    length = 1;
    vdata.pop_back();
    return;
  }


  int const init = vdata.at(length - 1);
  vdata.at(0) = init;
  int i = 0;

  length = length - 1;
  int swap;
  int temp;
  vdata.pop_back();

  while(2*i + 1< length)
  {
    swap = 2*i + 1;
    if(2*i + 2 < length)
    {
      
      if (init <= vdata.at(2*i + 2)&& init <= vdata.at(2*i + 1))
      {
        return;
      }

      if (vdata.at(2*i + 2) < vdata.at(2*i + 1))
      {
        swap = swap + 1;
      }
      
      
      
      
    }
    else
    {
      if (init < vdata.at(swap))
      {
        return;
      }
    }
    temp = vdata.at(swap);
    vdata.at(i) = temp;
    vdata.at(swap) = init;
    i = swap;
  }
  



  
  /*
  while(i*2 + 1 < length)
  {
    if(i==0)
    {
      
      if (min(vdata.at(i*2+1),vdata.at(2*i + 2)) == vdata.at(i*2+1)) swap = 2*i + 1;
      else  swap = 2*i + 2;
  
      temp = vdata.at(swap);
  
      vdata.at(swap) = init;
  
      vdata.at(i) = temp;
  
      i = swap;
    }
    else if(i%2==1)
    {
      swap = i*2 + 1;
      if(i*2 + 2 < length)
      {
        if (min(vdata.at(i*2+1),vdata.at(2*i + 2)) == vdata.at(i*2+1)) swap = 2*i + 1;
        else  swap = 2*i + 2;

        if(i*2 + 3 < length)
        {
          if(vdata.at(i*2+3)<vdata.at(swap))
          {
            swap  = i*2 + 3;
          }
          
        }
        if(i*2 + 4< length)
        {
          if(vdata.at(i*2+4)<vdata.at(swap))
          {
            swap = i*2 + 4;
          }
        }

        
      }
      temp = vdata.at(swap);
    
      vdata.at(swap) = init;
    
      vdata.at(i) = temp;
    
      i = swap;
      
      
    }
    else
    {
      swap = i*2 + 1;
      vector<int> inds;
      int wmax = vdata.at(swap);
      if(i*2 + 2< length)
      {
        inds.push_back(i*2 + 2);
      }
      inds.push_back(i*2 + 1);
      inds.push_back(i*2);
      inds.push_back(i*2-1);
      for(int j = 0 ; j<inds.size() ; j++)
        {
          if(vdata.at(inds.at(j))<wmax)
          {
            swap = inds.at(j);
            wmax = vdata.at(inds.at(j));
          }
          
        }
      temp = vdata.at(swap);
    
      vdata.at(swap) = init;
    
      vdata.at(i) = temp;
    
      i = swap;
      
      
      
    }
  }
  if(i%2==0&&2*i<length)
  {
    if(vdata.at(2*i-1)<vdata.at(2*i))
    {
      int temp = vdata.at(2*i - 1);
      vdata.at(2*i-1) = init;
      vdata.at(i) = temp;
      i = 2*i - 1;
    }
    
  }
  temp = vdata.at(length - 1);

  vdata.at(length - 1) = init;

  vdata.at(i) = temp;
  vdata.pop_back();

  length = length - 1;
  */
  return;
  

}

// Returns the minimum element in the heap
int Heap::top(){
  if (length==0) 
  {
    return 0;
    }

  

  return vdata.at(0);
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return length==0;
}
    