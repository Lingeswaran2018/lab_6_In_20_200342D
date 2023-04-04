#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_SIZE 10000

class Stack {
  private:
    int stack_top;
    int stack_arr[MAX_SIZE];

  public:
    Stack() {
      stack_top = -1;
    }

    bool push(int x) {
      if (stack_top >= (MAX_SIZE - 1)) {
        cout << "Error: stack overflow error \n";
        return false;
      } else {
        stack_arr[++stack_top] = x;
        cout << x << " pushed the element to stack\n";
        return true;
      }
    }

    int pop() {
      if (stack_top < 0) {
        cout << "Error: stack underflow error \n";
        return 0;
      } else {
        int x = stack_arr[stack_top--];
        return x;
      }
    }

    bool is_empty() {
      return (stack_top < 0);
    }

    bool is_full() {
      return (stack_top >= (MAX_SIZE - 1));
    }

    int stack_top_value() {
      if (is_empty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return stack_arr[stack_top];
      }
    }

    void display() {
      if (is_empty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack: ";
        for (int i = stack_top; i >= 0; i--) {
          cout << stack_arr[i] << " ";
        }
        cout << endl;
      }
    }
};

int main() {
  auto start_time = high_resolution_clock::now();
  Stack my_stack;
  my_stack.push(8);
  my_stack.push(10);
  my_stack.push(5);
  my_stack.push(11);
  my_stack.push(15);
  my_stack.push(23);
  my_stack.push(6);
  my_stack.push(18);
  my_stack.push(20);
  my_stack.push(17);
  my_stack.display();
  cout << my_stack.pop() << " popped element from stack\n";
  cout << my_stack.pop() << " popped element from stack\n";
  cout << my_stack.pop() << " popped element from stack\n";
  cout << my_stack.pop() << " popped element from stack\n";
  cout << my_stack.pop() << " popped element from stack\n";
  my_stack.display();
  my_stack.push(4);
  my_stack.push(30);
  my_stack.push(3);
  my_stack.push(1);
  my_stack.display();    
  auto end_time = high_resolution_clock::now();
  auto execution_time = duration_cast<milliseconds>(end_time - start_time);
  cout << "Time taken for Execution : " << execution_time.count() << " ms" << endl;
  return 0;
}