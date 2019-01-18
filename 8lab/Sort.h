#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#endif 

#include <mutex>
#include <thread>
#include <functional>
#include "TMassive.h"

template<typename T, typename P>
void quick_sort_parallel(Array<T> &arr, size_t start, size_t finish, P predicate);
template<typename T, typename P>
void quick_sort(Array<T> &arr, size_t start, size_t finish, P predicate);
template<typename T, typename P>
bool is_sorted(const Array<T> &arr, P predicate);

template<typename T, typename P>
void quick_sort(Array<T> &arr, size_t start, size_t finish, P predicate) {
	T pivot = arr[(start + finish) / 2 + 1];
	size_t left = start;
	size_t right = finish;

	while (left <= right) {
		while (predicate(arr[left], pivot) < 0)
			++left;
		while (predicate(arr[right], pivot) > 0)
			--right;
		if (left <= right) {
			if (left != right) {
				auto temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
			++left;
			--right;
		}
	}
	
	if (start < right)	
		quick_sort(arr, start, right, predicate);
	if (finish > left)	
		quick_sort(arr, left, finish, predicate);
}

template<typename T, typename P>
void quick_sort_parallel(Array<T> &arr, size_t start, size_t finish, P predicate) {
	T pivot = arr[(start + finish) / 2 + 1];
	size_t left = start;
	size_t right = finish;

	static std::mutex mut;
	static int threads_available = hardware_concurrency() - 1;

	bool is_left_threaded = false;
	bool is_right_threaded = false;

	while (left <= right) {
		while (predicate(arr[left], pivot) < 0)
			++left;
		while (predicate(arr[right], pivot) > 0)
			--right;
		if (left <= right) {
			if (left != right) {
				auto temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
			++left;	
			--right;
		}
	}
	std::thread left_thread;
	std::thread right_thread;
	
	if (start < right) {	
		mut.lock();
		if (threads_available > 0) {
			left_thread = std::thread(quick_sort_parallel<T>, std::ref(arr), start, right, predicate);
			is_left_threaded = true;
			--threads_available;
			mut.unlock();
		}
		else {
			mut.unlock();
			quick_sort(arr, start, right);
		}
	};
	if (finish > left) {	
		mut.lock();
		if (threads_available > 0) {
			right_thread = std::thread(quick_sort_parallel<T>, std::ref(arr), left, finish, predicate);
			is_right_threaded = true;
			--threads_available;
			mut.unlock();
		}
		else {
			mut.unlock();
			quick_sort(arr, left, finish);
		}
	}
	if (is_left_threaded) {
		left_thread.join();
		mut.lock();
		++threads_available;
		mut.unlock();
	}
	if (is_right_threaded) {
		right_thread.join();
		mut.lock();
		++threads_available;
		mut.unlock();
	}
}

template<typename T, typename P>
bool is_sorted(const Array<T> &arr, P predicate) {
	auto size = arr.Size();
	for (decltype(size) i = 1; i < size; ++i)
		if (predicate(arr[i - 1] > arr[i]) > 0)
			return false;
	return true;
}