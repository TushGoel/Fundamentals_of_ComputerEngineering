/* 
Name: Tushar Goel
NUID: 001356901
*/
/* Program for implementing the Dijkstra's shortest path algorithm using priority queue in STL */

#include<bits/stdc++.h> 

using namespace std; 
# define INF 0x3f3f3f3f
// 100000 0x3f3f3f3f

typedef pair<int, int> iPair; // iPair for representing integer pair
int source; // Source vertex from where the user wants to find shortest path
int destination; // Destination vertex to where the user wants to find shortest path
// Create a vector for distances and initializes all distances as infinite (INF) 
vector<int> dist(240, INF);

/* 
The class Dijkastras will implement Dijkstra's shortest path algorithm using priority queue on adjacency list 
*/

class Dijkastras 
{
	int V; // Total number of vertices considered
	list< pair<int, int> > *adj; // For a weighted graph to store vertices and weight for every edge 

	public:
		Dijkastras(int V); // Constructor 
		void addEdge(int u, int v, int w); // function to add an edge to the graph
		void shortestPath(); // find the shortest path from the user entered source to destination using Dijkstra's algorithm and priority queue on adjacency list
	    void input_func(); // takes input of the source vertex and destination vertex from the user
	    void output_func(); // Print shortest distances in metres from the user entered source to destination
}; 

// Allocates memory for the adjacency list 
Dijkastras::Dijkastras(int V) 
{
	this->V = V; 
	adj = new list<iPair> [V]; 
} 

// function to add an edge to the graph
void Dijkastras::addEdge(int u, int v, int w) 
{
	// u--> vertex-1, v--> vertex-2, w--> weight of the edge 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

// takes input of the source vertex and destination vertex from the user
void Dijkastras::input_func()
{
	string s;
	string d;

	cout << "Enter the source vertice--> ";
	cin >> s;

	cout << "Enter the destination vertice--> ";
	cin >> d;

	cout << "Entered Data: " << endl;
	cout << "Source vertex--> "<< s << endl;
	cout << "Destination vertex--> " << d << endl;

	if (s=="23A")
	{
		s="231";
	}

	if(d=="23A")
	{
		d="231";
	}
	
	if (s=="23B")
	{
		s="232";
	}

	if(d=="23B")
	{
		d="232";
	}
	
	if (s=="23C")
	{
		s="233";
	}

	if(d=="23C")
	{
		d="233";
	}
	
	if (s=="23D")
	{
		s="234";

	}
	if(d=="23D")
	{
		d="234";
	}
	
	if (s=="23E")
	{
		s="235";
	}

	if(d=="23E")
	{
		d="235";
	}
	
	if (s=="23F")
	{
		s="236";
	}

	if(d=="23F")
	{
		d="236";
	}
	
	if (s=="23G")
	{
		s="237";

	}
	    
	if(d=="23G")
	{
		d="237";
	}
	
	source=stoi(s);
	destination=stoi(d);

	cout << "Source stored for processing --> " << source <<endl;
	cout << "Destination stored for processing --> " << destination <<endl;

}

// Find the shortest path from the user entered 'source' to 'destination' using Dijkstra's algorithm and priority queue on adjacency list
void Dijkastras::shortestPath() 
{
	// Creating the priority queue to store vertices that are being preprocessed.
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	// Insert source itself in priority queue and initializes its distance as 0. 
	pq.push(make_pair(0, source)); 
	dist[source] = 0; 

	/* Checking till the priority queue that has been created becomes empty */
	while (!pq.empty()) 
	{
		/* The first vertex in pair is the minimum distance vertex, 
		   extracting it from the priority queue. */
		/* vertex label is stored in second of pair for keeping the vertices of the sorted distance */
		int u = pq.top().second; 
		pq.pop(); 

		// 'i' works as an interator to access all the adjacent vertices of a vertex 
		list< pair<int, int> >::iterator i;

		// Get the vertex and weight of current adjacent vertex of u.
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{
			int v = (*i).first; 
			int weight = (*i).second; 

			// If there is available short path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{
				// Updating the distance of v 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	}
}

// Print shortest distances in metres from the user entered source to destination
void Dijkastras::output_func()
{
	if(dist[destination]>=INF)
	{
		cout << "No valid path exists between " << source << " and " << destination << endl;
	}

	else
	{
		cout << "Distance from Source to destination is: " << dist[destination] << " metres"<<endl; 
	}
}

// Driver program to test methods of Dijkastras class 
int main() 
{
	string weight; // variable to store weight of the edge while reading from the .txt file
    string v1, v2; // variables to store the vertices of the graph while reading from the .txt file
  
    Dijkastras g(240); // Allocates memory for the adjacency list to the constructor
    
    // Procedure for reading the data column by column from the .txt file
    ifstream infile;   
  	
  	infile.open("graph_data_Dijkstras_Tushar_Goel.txt");

    if(infile.fail()) // checks to see if file opened or not 
    { 
      cout << "error" << endl; 
      return 1;// no point of continuing if the file didn't open.
    } 

    while(!infile.eof()) // reads the data till the end of the file
    {
    	infile >> v1; // read first column from .txt file i.e. vertex-1 
        infile >> v2; // read second column from .txt file i.e. vertex-2
        infile >> weight; // read third column from .txt file i.e. edge weight
         
        //cout << stoi(v1) << " " << stoi(v2)<< " " << stoi(weight)<< endl;
         
        // Converting string values into integer format
        int u=stoi(v1);
        int v=stoi(v2);
        int d=stoi(weight);
        
        // Calling the addEdge function to add an edge to the graph
        g.addEdge(u,v,d );        
    } 

  	infile.close();

  	/* After creating the graph, 
  	asking user for inputting the source vertex and destination vertex for which he/she wants to calculate the shortest path */
  	g.input_func();
  	
	/* Calling the shortestPath function from the user entered 'source' to 'destination' 
	using Dijkstra's algorithm and priority queue on adjacency list */
	g.shortestPath();

	// Calling the output_func to display the shortest distances in metres from the user entered source to destination
	g.output_func();

	return 0; 
} 
