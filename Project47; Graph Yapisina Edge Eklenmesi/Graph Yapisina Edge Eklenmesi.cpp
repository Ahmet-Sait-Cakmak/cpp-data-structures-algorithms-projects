#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph {

private:

	map<int, vector<int>> adjList;

public:

	// Yeni bir dugum eklemek icin kullanilan metod:
	void addVertex(int vertex) {

		// Parametre olarak gelen vertex zaten varsa islem yapma, yoksa ekle
		if (adjList.find(vertex) == adjList.end()) {

			vector<int> neighbours; // Yeni bir komsu dugum listesi olusturuyoruz
			adjList[vertex] = neighbours; // Yeni dugumu yeni komsu listesi ile iliskilendiriyoruz
		}
	}

	// Yeni bir kenar (edge) eklemek icin kullanilan metod:
	void addEdge(int from, int to) {

		// 'from' ve 'to' dugumlerinin graph'ta bulunmama durumuna karsin ilk olarak 'from' ve 'to' dugumleri graph'a eklenir
		addVertex(from);
		addVertex(to);

		// 'from' dugumunun komsu listesine 'to' dugumunu ekleme:
		adjList[from].push_back(to);

		// 'to' dugumunun komsu listesine 'from' dugumunu ekleme:
		adjList[to].push_back(from);
	}
};

int main() {

	Graph g; // Graph sinifindan bir nesne olusturuyoruz

	g.addVertex(1); // 1 numarali dugumu ekliyoruz
	g.addVertex(2); // 2 numarali dugumu ekliyoruz
	g.addVertex(3); // 3 numarali dugumu ekliyoruz
	g.addVertex(4); // 4 numarali dugumu ekliyoruz
	g.addVertex(5); // 5 numarali dugumu ekliyoruz

	// Kenarlar (edges) ekliyoruz:
	g.addEdge(1, 2); // 1 ve 2 dugumleri arasinda bir kenar ekliyoruz
	g.addEdge(1, 3); // 1 ve 3 dugumleri arasinda bir kenar ekliyoruz
	g.addEdge(2, 4); // 2 ve 4 dugumleri arasinda bir kenar ekliyoruz
	g.addEdge(2, 5); // 2 ve 5 dugumleri arasinda bir kenar ekliyoruz
	g.addEdge(3, 5); // 3 ve 5 dugumleri arasinda bir kenar ekliyoruz
	g.addEdge(4, 5); // 4 ve 5 dugumleri arasinda bir kenar ekliyoruz

	return 0;
}