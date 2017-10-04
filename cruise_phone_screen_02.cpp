#include <iostream>
using namespace std;

class Task 
{
};

class Queue 
{
  public:
    int q_capacity;
    int q_size;
    queue<Task *> q_task;
    mutex q_mutex; // ?
    condition_variable cv;
  
    Queue(int capacity) : q_capacity(capacity), q_size(0)
    {
    }
  
    bool isFull()
    {
        return q_size == q_capacity;
    }
  
    bool isEmpty()
    {
        return q_size == 0;
    }
  
    int pushTask (Task *task)
    {
      LOCK();
      if (isFull()) {
        UNLOCK();
        return -1;
      }
      
      q_task.push(task);
      q_size++;
      
      UNLOCK();
      CV_SIGNAL(cv);
      return 0;  
    }
  
    Task * popTask ()
    {
      Task *front = nullptr;
      
      // cv_wait
      q_mutex.lock();
      while (isEmpty()) {
        CV_WAIT(cv, q_mutex); 
      }
      
      front = q_task.front();
      q_task.pop();
      q_mutex.unlock();
      return front;
    }
};

// To execute C++, please define "int main()"
int main() {
  int q_size = 5;
  queue<Task *> q_task;
  
  
  return 0;
}
