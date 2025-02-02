
#include "detection2d.pb.h"
#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

void test_async() {
  std::atomic_bool is_stop_{false};
  auto foo_lambda = [&is_stop_]() {
    while (!is_stop_) {
      for (int i = 0; i < 100; ++i) {
        std::cout << "foo " << i << std::endl;
      }
    }
  };
  std::future<void> task_future_ = std::async(foo_lambda);

  {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    is_stop_ = true;
    task_future_.get();
  }
}

void test_proto() { ::test::Detection2D proto; }

int main() {
  std::cout << "Hello" << std::endl;

  test_async();

  test_proto();

  return 0;
}
