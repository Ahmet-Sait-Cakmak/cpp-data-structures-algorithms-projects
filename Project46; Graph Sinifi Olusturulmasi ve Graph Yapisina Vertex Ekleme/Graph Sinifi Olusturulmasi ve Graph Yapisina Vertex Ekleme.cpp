#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph {

private:

	map<int, vector<int>> adjList;

public:

	// Yeni bir dugum eklemek icin kullanilan metod
	void addVertex(int vertex) {

		// Parametre olarak gelen vertex zaten varsa islem yapma, yoksa ekle
		if (adjList.find(vertex) == adjList.end()) {

			vector<int> neighbours; // Yeni bir komsu dugum listesi olusturuyoruz
			adjList[vertex] = neighbours; // Yeni dugumu yeni komsu listesi ile iliskilendiriyoruz
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

	return 0;
}