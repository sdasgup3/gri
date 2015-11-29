#include<iostream>
using namespace std;


int main ()
{
  
  //int v=1000, e=6000;
  int v=500, e=1000;
  srand(time(NULL));


  for(int i = 0; i < v; i++) {
    cout << i << "\n";
  }

  for(int i = 0; i < e; i++) {
    int start = rand() % v;
    int end   = rand() % v;
    float weight = rand()%200;
    cout << start << " " << end << " " << weight <<  "\n";
  }

}
