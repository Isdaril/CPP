#include "stdafx.h"
#include <vector>

std::string printVector(std::vector<int> a);

class SortCalculator {
private:
	int operationCount;
public:
	SortCalculator();
	~SortCalculator();
	void refresh();
	int getCount();
	void tam(std::vector<int> & a, int noeud, int lim);
	void heapsort(std::vector<int> & a);
	std::vector<int> fuse(std::vector<int> a, std::vector<int> b);
	std::vector<int> fusionSort(std::vector<int> a);
	int part(std::vector<int> & a, int pivot, int premier, int dernier);
	void quickSort(std::vector<int> & a, int premier, int dernier);
};
