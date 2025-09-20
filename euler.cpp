1. Undirected Graph
Type	Conditions
Eulerian Circuit	- Graph is connected (ignoring isolated vertices)
- Every vertex has even degree
Eulerian Path	- Graph is connected
- Exactly 2 vertices have odd degree (start and end)

Observation:

0 odd-degree vertices → Eulerian Circuit exists.

2 odd-degree vertices → Eulerian Path exists but not circuit.

More than 2 odd-degree vertices → Neither path nor circuit exists.

2. Directed Graph
Type	Conditions
Eulerian Circuit	- Graph is strongly connected
- For every vertex: in-degree = out-degree
Eulerian Path	- Graph is weakly connected
- Exactly one vertex: out-degree = in-degree + 1 (start)
- Exactly one vertex: in-degree = out-degree + 1 (end)
- All other vertices: in-degree = out-degree

Observation:

Eulerian Circuit implies Eulerian Path exists.

More than 2 vertices violating degree condition → No Eulerian path/circuit.
