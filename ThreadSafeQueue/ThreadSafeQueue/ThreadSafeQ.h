#pragma once

#include <iostream>
#include <queue>
#include <mutex>
#include <deque>

class ThreadSafeQ
{
private:
	std::queue<int> rawQ;
	std::mutex m;
public:

	ThreadSafeQ(std::deque<int> dQ);

	int& retrieveAndDelete();

	void push(int val);

	void printQueue();
};