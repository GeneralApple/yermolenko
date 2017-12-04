// Dijkstra algorithm. Searching for the shortest path between start point and all other points
#include<iostream> 
#include<curses.h>
#include<cstring>
 
#define M ( sizeof(nodes)/sizeof(nodes[ 0 ]) )
#define N ( sizeof(inf)/sizeof(inf[ 0 ]) )
 
//quasi-infinity (this number just has to be bigger than maximum path value)
#define INFINITY 10000
//start node
#define start_node 2

using namespace std;
 
//пункты
char nodes[ ][ 50 ]={ "A", "B", "C", "D", "E", "F" };
struct
{
    char points[ 2 ][ 50 ]; //from node to node
    int distance;           //distance (value of the lines)
    }inf[ ]={
    {{ "A", "B" }, 7 },
    {{ "B", "C" }, 4 },
    {{ "C", "D" }, 6 },
    {{ "D", "E" }, 5 },
    {{ "E", "A" }, 3 },
    {{ "A", "F" }, 4 },
    {{ "B", "F" }, 2 },
    {{ "C", "F" }, 4 },
    {{ "D", "F" }, 6 },
    {{ "E", "F" }, 5 },
    };
 
struct range
{
    char *point;    //node
    int distance;   //distance from the start node
    };
  
int main() 
{
int i, j, c, current_distance, q, p, real_p;
char *current_node=NULL;
 
range *xr=new range[ M ];
for( i=0; i<M; i++ )
{
    xr[ i ].point=NULL;
    xr[ i ].distance=INFINITY;
    }
//start node obviously has zero distance to itself
xr[ 0 ].distance=0;
xr[ 0 ].point=nodes[ start_node ];
 
for( i=0, c=0, p=1; i<M; i++ )
{
    current_node=xr[ i ].point;
 
    for( j=0, real_p=1; j<N; j++ )
    {
        current_distance=xr[ i ].distance;
        if( strcmp(inf[ j ].points[ 0 ], current_node)==0
        ||  strcmp(inf[ j ].points[ 1 ], current_node)==0 )
        {
            //checking if we examined this node earlier
            for( q=0; q<i; q++ )
                if( strcmp(inf[ j ].points[ 0 ], xr[ q ].point)==0
                ||  strcmp(inf[ j ].points[ 1 ], xr[ q ].point)==0 )
                    break;
            if( q<i )
                continue;
 
           //-----------------------------
           //checking what nodes are neighbours to the current node
           for( q=0; q<2; q++ )
              if( strcmp(inf[ j ].points[ q ], current_node)!=0 )
                  break;
 
           //i is the current node
           //p - quantity of the neighbours (visited already)
           //real_p is the neighbour of current node (which is being checked now)
           //j is the current line (arc)
  
           for( c=0; c<p; c++ )
               if( strcmp(xr[ c ].point, inf[ j ].points[ q ])==0 )
                   break;
           if( c<p )
               real_p=c; //this node was visited
           else
           {   //пункт не посещался
               xr[ p ].point=inf[ j ].points[ q ]; //remembering the node
               real_p=p; //commiting the new data about that node
               ++p;
               }
  
           current_distance+=inf[ j ].distance;
           if( current_distance<xr[ real_p ].distance )
               //remembering the distance
               xr[ real_p ].distance=current_distance;
              }
          }
      }
  
cout << endl << "---------------------" << endl
     << "Beeline from " << xr[ 0 ].point << endl;
for( q=1; q<p; q++ )
    cout << "to: " << xr[ q ].point << " = " << xr[ q ].distance << endl; //the result is shown
delete [] xr; //clearing the memory
//getch();
return 0; 
}
