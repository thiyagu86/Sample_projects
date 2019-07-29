#include "CircularQueue.h"

using namespace std;

int main()
{
   Queue<unsigned int> objCircularQueue(4);
   objCircularQueue.Enqueue(1);

   cout << "Size of the objCircularQueue is: " << objCircularQueue.GetCapacity();
}
