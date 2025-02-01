
#include <future>
#include <iostream>

void foo() {
  for (int i = 0; i < 100; ++i) {
    std::cout << "foo " << i << std::endl;
  }
}

int main() {
  std::cout << "Hello" << std::endl;
  std::future<void> task_future_ = std::async(&foo);
  task_future_.get();
  return 0;
}
