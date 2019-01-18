#include <iostream>
#include <memory>

//#include "TNtree.h"
#include "figure.h"
#include "retrangle.h"
#include "rhombus.h"
#include "trapezium.h"
#include "TMassive.h"

#include <iostream>
#include <memory>
#include <vector>

#include "Sort.h"

using namespace std;

const size_t page_size = 65536;
const size_t obj_size = max({ sizeof(Retrangle), sizeof(Rhombus) , sizeof(Trapezium) });

Allocator Figure::allocator = Allocator(page_size, obj_size);

int main()
{
	size_t size = 0;

	cout << "How much figures do you want to sort?" << endl;
	cin >> size;

	Array<shared_ptr<Figure>> array(size);

	auto comparator = [](auto &f1, auto &f2) -> int {
		return *f1 == *f2 ? 0 : *f1 < *f2 ? -1 : 1; };

	auto gen_figure = [](char type) -> shared_ptr<Figure> {
		switch (type) {
		case '1':
			return shared_ptr<Figure>(new Retrangle(cin));
		case '2':
			return shared_ptr<Figure>(new Rhombus(cin));
		case '3':
			return shared_ptr<Figure>(new Trapezium(cin));
		default:
			return shared_ptr<Figure>(nullptr);
		}
	};

	char type;
	for (int i = 0; i < size; ++i) {
		cout << "Enter figure, please (1 _ _/2 _ _/3 _ _ _)" << endl;
		cin >> type;
		array[i] = gen_figure(type);
	}

	cout << "Entered figures: " << endl;
	for (auto el : array)
		cout << *el << ' ';
	cout << endl;

	quick_sort(array, 0, size - 1, comparator);

	cout << "Sorted: " << endl;
	for (auto el : array)
		cout << *el << ' ';
	cout << endl;

	system("read -p 'Press Enter to continue...' var");
    return 0;
}