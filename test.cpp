#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
#include <ctime>

using namespace std;

int main(){
  cout << "Game at " << ctime(&(chrono::system_clock::to_time_t(chrono::system_clock::now())));
  return 0;
}
