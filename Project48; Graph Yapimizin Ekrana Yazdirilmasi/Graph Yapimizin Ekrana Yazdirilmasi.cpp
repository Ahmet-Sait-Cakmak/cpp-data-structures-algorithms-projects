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

	// Graph'i ekrana yazdirmak icin kullanilan metod:
	void printGraph() {

		for (auto const& pair : adjList) { // Her bir dugum ve komsu listesi icin dongu

			int vertex = pair.first; // Dugum numarasini aliyoruz

			vector<int> neighbours = pair.second; // Komsu dugum listesini aliyoruz

			cout << "Dugum " << vertex << " komsulari: "; // Dugum numarasini ekrana yazdiriyoruz

			for (int neighbour : neighbours) { // Komsu dugumleri icin dongu

				cout << neighbour << " "; // Komsu dugumleri ekrana yazdiriyoruz
			}

			cout << endl; // Yeni satira geciyoruz
		}
	}

	/*

	void printGraph() metodunun alternatif bir versiyonu:

	void printGraph() {

		int number_of_vertices = adjList.size(); // Graph'taki dugum sayisini aliyoruz

		for (int i = 0; i < number_of_vertices; i++) { // Dugum sayisi kadar dongu

			int vertex = i;

			auto it = adjList.begin(); // Iterator'u graph'in basina ayarliyoruz

			advance(it, vertex); // Iterator'u vertex'in degeri kadar ilerletiyoruz

			vector<int> &neighbours = it->second; // Komsu dugum listesini aliyoruz

			cout << "Adjacencies of vertex " << it->first << ": ";

			for (int j = 0; j < neighbours.size(); j++) { // Komsu dugumleri icin dongu

				cout << neighbours[j] << " "; // Komsu dugumleri ekrana yazdiriyoruz
			}

			cout << endl;
		}
	}

	*/
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

	cout << "Graph'in baslangictaki hali:" << endl << endl;

	g.printGraph();

	return 0;
}