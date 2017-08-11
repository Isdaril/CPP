// ConsoleApplication2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
#include <random>

#include "Sort.h"
//using namespace std;

std::string printVector(std::vector<int> a) {
	std::string result;
	for (int i = 0; i < int(a.size()); i++) {
		result += std::to_string(a[i]) + ' ';
	}
	result += '\n';
	return result;
}

int generateRandomNumber(int begin, int end) {
	std::random_device rd;
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr = std::uniform_int_distribution<>(begin, end);
	return distr(eng);
}

SortCalculator::SortCalculator() {
	refresh();
	std::cout << "Creating Sorter..." << '\n';
}

SortCalculator::~SortCalculator() {
	std::cout << "Deleting Sorter..." << '\n';
}

void SortCalculator::refresh() {
	operationCount = 0;
}

int SortCalculator::getCount() {
	return operationCount;
}

void SortCalculator::tam(std::vector<int> & a, int noeud, int lim) {
	int k, j;
	k = noeud+1;
	j = 2 * k;
	while (j <= lim+1) {
		operationCount+=2;
		if ((j < lim+1) && (a[j-1] < a[j])) {
			j += 1;
		}
		operationCount++;
		if (a[k-1] < a[j-1]) {
			std::swap(a[j - 1], a[k - 1]);
			k = j;
			j = 2 * k;
		}
		else {
			break;
		}
	}
}

void SortCalculator::heapsort(std::vector<int> & a) {
	int i, lim, n;
	n = int(a.size());
	lim = int(floor(n / 2));
	for (i = lim - 1; i >= 0; i--) {
		this->tam(a, i, n);
	}
	for (i = n-1; i >= 1; i--) {
		std::swap(a[0], a[i]);
		this->tam(a, 0, i-1);
	}
}

std::vector<int> SortCalculator::fuse(std::vector<int> a, std::vector<int> b) {
	std::vector<int> result;
	while((! a.empty()) || (! b.empty())) {
		if (a.empty()) {
			result.push_back(b.front());
			b.erase(b.begin());
		}
		else if (b.empty()) {
			result.push_back(a.front());
			a.erase(a.begin());
		} else {
			operationCount++;
			if (a.front() <= b.front()) {
				result.push_back(a.front());
				a.erase(a.begin());
			}
			else {
				result.push_back(b.front());
				b.erase(b.begin());
			}
			
		}		
	}

	return result;
}

std::vector<int> SortCalculator::fusionSort(std::vector<int> a) {
	std::vector<int> result = a;
	int n = int(a.size());
	if (n == 1) {
		return result;
	}
	else {
		int half = int(ceil(n / 2));
		std::vector<int> a1 (a.begin(), a.begin() + half);
		std::vector<int> a2 (a.begin() + half, a.end());
		result = fuse(fusionSort(a1), fusionSort(a2));
		return result;
	}
}

int SortCalculator::part(std::vector<int> & a, int pivot, int first, int last) {
	int posPiv,i;
	std::swap(a[pivot], a[last]);
	posPiv = first;
	for (i = first; i < last ; i++) {
		operationCount++;
		if (a[i] < a[last]) {
			std::swap(a[i], a[posPiv]);
			posPiv ++;
		}
	}
	std::swap(a[posPiv], a[last]);
	return posPiv;
}



void SortCalculator::quickSort(std::vector<int> & a, int first, int last) {
	if (first < last) {
		int pivot = generateRandomNumber(first, last);
		pivot = part(a, pivot, first, last);
		quickSort(a, first, pivot - 1);
		quickSort(a, pivot + 1, last);
	}

}


