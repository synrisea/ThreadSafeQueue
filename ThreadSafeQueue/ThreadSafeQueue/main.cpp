#include "ThreadSafeQ.h"

int main()
{
	std::deque<int> dQ{ 2,3,56 };

	ThreadSafeQ Q(dQ);

	std::thread popThread(&ThreadSafeQ::retrieveAndDelete, &Q);
	popThread.join();

	std::thread pushThread1(&ThreadSafeQ::push, &Q, 6);
	if (pushThread1.joinable())
	{
		pushThread1.join();
	}

	std::thread pushThread2(&ThreadSafeQ::push, &Q, 3);
	if (pushThread2.joinable())
	{
		pushThread2.join();
	}

	std::cout << "Your queue : ";
	Q.printQueue();

	return 0;
}