Task - 5: Write a program that help us find the shortest path between any two buildings or point of interests in the Northeastern University campus. Utilize the Dijkstra’s Algorithm to implement the program.

To carry out this task, do the following:
1. Using any drawing software (e.g., Visio), design an undirected graph using the campus map available at: https://www.northeastern.edu/campusmap/printable/campusmap15.pdf
2. Only consider the area of the campus that is located inside Huntington Avenue, Ruggles Street, Massachusetts Avenue, and the Orange Line railroad.
3. The vertices in the graph represent the centroid of the buildings and points of interests as indicated in the map. You can also add vertices to represent some roads intersections (if needed).
4. The edges in your graph represent the roads between the vertices. The weight of an edge is determined by the distance between its two vertices. These distances can be measured utilizing Google map as explained in: https://support.google.com/maps/answer/1628031
5. Only add edges to the vertex’s direct neighbors on the map (i.e., do not include nonessential edges).
6. Create a text file to store your graph data, which includes: the number of vertices followed by the data of the graph edges. For each edge, provide its <vertex1>  <vertex2> <distance>
7. Write your C++ program so that it starts by reading the graph text file you created in the previous step and then implement this graph using either an adjacency‐list or an adjacency‐matrix.
8. When it runs, your program will read from a user the start and end points (using numbers to refer to these points as shown in the campus map). The program will then use Dijkstra’s algorithm to provide the user with the shortest path between these two points.
9. Verify your program shortest path results with the corresponding results given by Google maps for the “walking” directions.