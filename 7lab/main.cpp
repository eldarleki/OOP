#include <iostream>
#include <memory>

#include "TNtree.h"
#include "figure.h"
#include "retrangle.h"
#include "rhombus.h"
#include "trapezium.h"
#include "TMassive.h"

#define MAX_ARRAY_SIZE 3

using namespace std;

Figure* CreateFigure(char type);
Figure* FindInTree(Figure *figure, BinTree<Array<shared_ptr<Figure>>> &tree);
void RemoveFromTree(Figure *figure, BinTree<Array<shared_ptr<Figure>>> &tree);

const size_t memory_page_size = 65536;
const size_t block_size = max({ sizeof(Retrangle), sizeof(Rhombus), sizeof(Trapezium) });

Allocator Figure::allocator = Allocator(memory_page_size, block_size);

int main() {
	BinTree<Array<shared_ptr<Figure>>> tree;
	
	int count = 0;
	Array<shared_ptr<Figure>> *array = new Array<shared_ptr<Figure>>(MAX_ARRAY_SIZE);

	tree.Insert(array);

	char command = 0;
	char fig_type = 0;

	while (1) {
		cout << "Enter a command <a/f/r/p/h/i>" << endl;
		cin >> command;
		if (cin.eof())
			break;
		if (command == 'a') {
			cout << "Enter a figure <1/2/3> to insert" << endl;
			cin >> fig_type;
			if (fig_type != '3' && fig_type != '2' && fig_type != '1')
				continue;
			if (count >= MAX_ARRAY_SIZE) {
				count = 0;
				array = new Array<shared_ptr<Figure>>(MAX_ARRAY_SIZE);
				(*array)[count] = shared_ptr<Figure>(CreateFigure(fig_type));
				tree.Insert(array);
				++count;
				continue;
			}
			(*array)[count] = shared_ptr<Figure>(CreateFigure(fig_type));
			++count;
		}
		else if (command == 'f') {
			cout << "Enter a figure <1/2/3> to find" << endl;
			cin >> fig_type;
			if (fig_type != '3' && fig_type != '2' && fig_type != '1')
				continue;
			Figure *temp_figure = CreateFigure(fig_type);

			temp_figure = FindInTree(temp_figure, tree);
			if (temp_figure != nullptr) {
				cout << "Found: " << endl;
				cout << *temp_figure << endl;
			}
			else {
				cout << "Nothing found" << endl;
			}
		}
		else if (command == 'p') {
			cout << "Current state of the tree: " << endl;
			tree.Print();
		}
		else if (command == 'e') {
			break;
		}
		else if (command == 'i') {
			cout << "inorder print: " << endl;
			for (auto el : tree)
				cout << *el << ' ';
			cout << endl;
		}
		else if (command == 'r') {
			cout << "Enter a figure <1/2/3> to find" << endl;
			cin >> fig_type;
			if (fig_type != '3' && fig_type != '2' && fig_type != '1')
				continue;
			Figure *temp_figure = CreateFigure(fig_type);
			RemoveFromTree(temp_figure, tree);
			cout << "Removed" << endl;
		}
		else if (command == '3') {
			cout <<
				R"(commands:
	a -- add,
	f -- find item,
	r -- remove tree item,
	p -- print tree,
	h -- help,
	i -- inorder print,
	e -- exit program.
figures:
	1 _ _ -- rectangle side1 side2,
	2 _ _ -- rhombus side height,
	3 _ _ _ -- trapezium side1 side2 height.)" << endl;
		}
	}
}

Figure* CreateFigure(char type) {
	Figure *fig = nullptr;
	if (type == '1')
		fig = new Retrangle(std::cin);
	else if (type == '2')
		fig = new Rhombus(std::cin);
	else if (type == '3')
		fig = new Trapezium(std::cin);
	return fig;
}

Figure* FindInTree(Figure *figure, BinTree<Array<shared_ptr<Figure>>> &tree) {
	auto cur_it = tree.begin();
	auto end_it = tree.end();
	for (; cur_it != end_it; ++cur_it) {
		auto &cur_array = **cur_it;
		auto size = cur_array.Size();
		decltype(size) i = 0;
		for (; i < size; ++i) {
			if (*cur_array[i] == *figure) {
				return cur_array[i].get();
			}
		}
	}
}

void RemoveFromTree(Figure *figure, BinTree<Array<shared_ptr<Figure>>> &tree) {
	auto cur_it = tree.begin();
	auto end_it = tree.end();
	for (; cur_it != end_it; ++cur_it) {
		auto &cur_array = **cur_it;
		auto size = cur_array.Size();
		decltype(size) i = 0;
		for (; i < size; ++i) {
			if (cur_array[i] && *cur_array[i] == *figure) {
				cur_array.Remove(&cur_array[i]);
				return;
			}
		}
	}
}
/*
void RemoveByCriteria(Figure *figure, BinTree<Array<shared_ptr<Figure>>> &tree) {
	auto cur_it = tree.begin();
	auto end_it = tree.end();
	for (; cur_it != end_it; ++cur_it) {
		auto &cur_array = **cur_it;
		auto size = cur_array.Size();
		decltype(size) i = 0;
		for (; i < size; ++i) {
			if (cur_array[i] && *cur_array[i] == *figure) {
				cur_array.Remove(&cur_array[i], Criteria cr&);
				return;
			}
		}
	}
}*/