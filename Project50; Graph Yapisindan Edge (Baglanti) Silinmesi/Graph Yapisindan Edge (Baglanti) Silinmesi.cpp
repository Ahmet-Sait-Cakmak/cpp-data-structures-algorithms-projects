#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph {

private:

	map<int, vector<int>> adjList;

public:

	// Graph'a yeni bir dugum eklemek icin kullanilan metod:
	void addVertex(int vertex) {

		// Graph'a parametre olarak gelen vertex zaten varsa islem yapma, yoksa ekle
		if (adjList.find(vertex) == adjList.end()) {

			vector<int> neighbours; // Yeni bir komsu dugum listesi olusturuyoruz
			adjList[vertex] = neighbours; // Yeni dugumu yeni komsu listesi ile iliskilendiriyoruz
		}
	}

	// Graph'a yeni bir kenar (edge) eklemek icin kullanilan metod:
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

	// Graph'tan bir dugumu silmek icin kullanilan metod:
	void removeVertex(int vertex) {

		// Once silinmek istenen dugum/vertex/node graph'ta var mi diye kontrol edilmelidir:
		if (adjList.find(vertex) != adjList.end()) {

			adjList.erase(vertex); // Dugum graph'tan silinir

			// Bagli dugumlerdeki ilgili kenarlar/edges silinir:
			for (map<int, vector<int>>::iterator it = adjList.begin(); it != adjList.end(); it++) {

				vector<int>& neighbours = it->second; // Mevcut dugumun komsu dugum listesini aliyoruz

				// Komsu dugum listesini kontrol ederek silinmek istenen dugumun numarasini bulup silme islemini gerceklestiriyoruz:
				vector<int>::iterator neighbour_it = neighbours.begin(); // Iterator'a komsu dugum listesinin basinin adresini atiyoruz

				while (neighbour_it != neighbours.end()) {

					if (*neighbour_it == vertex) {

						neighbour_it = neighbours.erase(neighbour_it); // Silinmek istenen dugumu komsu dugum listesinden siliyoruz ve iterator'u guncelliyoruz
					}
					else {

						neighbour_it++; // Silinmek istenen dugumun numarasini bulamadik, iterator'u bir sonraki komsu dugume ilerletiyoruz
					}
				}
			}
		}
	}

	// Graph'tan bir kenari (edge) silmek icin kullanilan metod:
	void removeEdge(int from, int to) {

		// Once 'from' ve 'to' dugumleri graph'ta var mi diye kontrol edilmelidir:
		if (adjList.find(from) != adjList.end() && adjList.find(to) != adjList.end()) {

			vector<int>& neighbours_of_from = adjList[from]; // 'from' dugumunun komsu dugum listesini aliyoruz

			// 'from' dugumunun komsu dugum listesini kontrol ederek 'to' dugumunu bulup silme islemini gerceklestiriyoruz:
			for (int i = 0; i < neighbours_of_from.size(); i++) {

				if (neighbours_of_from[i] == to) {

					neighbours_of_from.erase(neighbours_of_from.begin() + i); // 'to' dugumunu 'from' dugumunun komsu dugum listesinden siliyoruz

					break; // 'to' dugumunu bulduk ve sildik, donguden cikiyoruz
				}
			}

			vector<int>& neighbours_of_to = adjList[to]; // 'to' dugumunun komsu dugum listesini aliyoruz

			// 'to' dugumunun komsu dugum listesini kontrol ederek 'from' dugumunu bulup silme islemini gerceklestiriyoruz:
			for (int i = 0; i < neighbours_of_to.size(); i++) {

				if (neighbours_of_to[i] == from) {

					neighbours_of_to.erase(neighbours_of_to.begin() + i); // 'from' dugumunu 'to' dugumunun komsu dugum listesinden siliyoruz

					break; // 'from' dugumunu bulduk ve sildik, donguden cikiyoruz
				}
			}
		}
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

	cout << "Graph'in baslangictaki hali:" << endl << endl;

	g.printGraph();

	g.removeVertex(1); // 1 numarali dugumu siliyoruz

	cout << "\n\n1. vertex silindikten sonra graph'in hali:" << endl << endl;

	g.printGraph();

	g.removeEdge(2, 4); // 2. vertex ve 4. vertex arasindaki kenari siliyoruz

	cout << "\n\n2. vertex ve 4. vertex arasindaki edge (kenar)silindikten sonra graph'in hali:" << endl << endl;

	g.printGraph();

	return 0;
}