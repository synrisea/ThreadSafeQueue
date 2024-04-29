#include "ThreadSafeQ.h"

ThreadSafeQ::ThreadSafeQ(std::deque<int> dQ) : rawQ(dQ) {}

int& ThreadSafeQ::retrieveAndDelete()
{
	int frontVal = 0;

	m.lock();

	if (!rawQ.empty())
	{
		frontVal = rawQ.front();
		rawQ.pop();
	}

	m.unlock();

	return frontVal;
}

void ThreadSafeQ::push(int val)
{
	m.lock();
	rawQ.push(val);
	m.unlock();
}

void ThreadSafeQ::printQueue()
{
	m.lock();
	std::queue<int> rawQCopy = rawQ;

	while (!rawQCopy.empty())
	{
		std::cout << rawQCopy.front() << " ";
		rawQCopy.pop();
	}

	m.unlock();
}