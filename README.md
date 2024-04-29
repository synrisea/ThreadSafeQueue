## Thread Safety
The `ThreadSafeQ` class uses a mutex (`std::mutex m`) to ensure that operations on the queue are thread-safe. This prevents data races when multiple threads access the queue simultaneously. When accessing or modifying the queue, always use the provided methods to maintain thread safety.

## Class Definition

```cpp
#include <deque>
#include <queue>
#include <mutex>

class ThreadSafeQ
{
public:
    ThreadSafeQ(std::deque<int> dQ);

    int& retrieveAndDelete();
    void push(int val);
    void printQueue();

private:
    std::queue<int> rawQ;
    std::mutex m;
};
```

## Constructor
- **ThreadSafeQ(std::deque<int> dQ)**: Constructs the `ThreadSafeQ` class with an initial deque of integers.

## Methods
- **int& retrieveAndDelete()**: Retrieves the front value from the queue and removes it. If the queue is empty, it returns `0`. This operation is thread-safe due to the use of a mutex.

- **void push(int val)**: Pushes an integer value onto the queue. This operation is also thread-safe due to the mutex.

- **void printQueue()**: Prints the contents of the queue from front to back. This method creates a copy of the underlying queue to avoid affecting the actual queue while printing. This ensures thread safety.
