/* 
Name: Tushar Goel
NUID: 001356901
*/
/* Program for implementing the Adjacency List by reading data column-wise from the .txt file */

#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <iostream>
#include <fstream>
#include <stdexcept>
 
using namespace std;
 
int main()
{
  int vertices=46; // Total nuber of vertices in the graph
  int edges=129; // Total number of possible paths or edges in the graph 
  int weight; // variable to store weight of the edge while reading from the .txt file
  string v1, v2; // variables to store the vertices of the graph while reading from the .txt file
      
  // unordered map list pair is used to create adjacency list consisting of pair of destination vertex and edge weight from the source vertex
  unordered_map< string, list< pair<string, int> > > adjacencyList(vertices + 1); 
  
  // Procedure for reading the data column by column from the .txt file
  ifstream infile;   

  infile.open("graph_data_Tushar_Goel.txt");
  
  if(infile.fail()) // checks to see if file opened or not 
  {
    cout << "error" << endl; 
    return 1; // no point of continuing if the file didn't open.
  }

  while(!infile.eof()) // reads the data till the end of the file
  {
    for (int i = 1; i <= edges; ++i) 
    {
      infile >> v1; // read first column from .txt file i.e. vertex-1
      infile >> v2; // read second column from .txt file i.e. vertex-2
      infile >> weight; // read third column from .txt file i.e. edge weight

      // Adding Edge to the Graph for creating adjacency list
      adjacencyList[v1].push_back(make_pair(v2, weight));
    }
        
  } 

  infile.close(); 
     
    
  // Procedure for printing Adjacency List in the readable format for output window (or terminal)
  cout << endl << "The Adjacency List-" << endl;
  for (auto& value : adjacencyList) 
  {
    string vertex = value.first;
    list< pair<string, int> > adjacentVertices = value.second;
    list< pair<string, int> >::iterator itr = adjacentVertices.begin();
         
    cout << "adjacencyList [ " << vertex << " ]"; // Representation:- source vertex in Square brackets/Box braclets.

    while (itr != adjacentVertices.end()) 
    {
      // Representation:- destination vertex after arrow from source and edge weight in  Round brackets/Parentheses
      cout << " -> " << (*itr).first << " ( " << (*itr).second << " )";
      ++itr;
    }
         
    cout << endl;
  }
     
  return 0;
}