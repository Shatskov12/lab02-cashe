// Copyright 2020 Shatskov12 <qweser2016@mail.ru>

#include <Cashe.hpp>

void tester::StraightTest() {
  NameTest = "Straight";
  DurationTest.clear();
  [[maybe_unused]] int k;

  for (const int &size : BufsSize) {
    int *arr = new int[size / ByteInInt];

    for (int i = 0; i < size / ByteInInt; i += Step) {
      k = arr[i];
    }
    auto StartTime = std::chrono::steady_clock::now();
    for ( int iteration = 0; iteration < Repeat; ++iteration ){
      for (int i = 0; i < size / ByteInInt; i += Step ){
        k = arr[i];
      }
    }
    auto EndTime = std::chrono::steady_clock::now();
    DurationTest.push_back(std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime).count()/Repeat);
    delete[] arr;
  }
}

void tester::ReversTest() {
  NameTest = "Revers";
  DurationTest.clear();
  [[maybe_unused]] int k;

  for (const int &size : BufsSize) {
    int *arr = new int[size / ByteInInt];

    for (int i = 0; i < size / ByteInInt; i += Step) {
      k = arr[i];
    }
    auto StartTime = std::chrono::steady_clock::now();
    for ( int iteration = 0; iteration < Repeat; ++iteration ){
      for (int i = size/ByteInInt-1; i>0; i -= Step ){
        k = arr[i];
      }
    }
    auto EndTime = std::chrono::steady_clock::now();
    DurationTest.push_back(std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime).count()/Repeat);
    delete[] arr;
  }

}

void tester::RandomTest() {
  NameTest = "Random";
  DurationTest.clear();
  [[maybe_unused]] int k;

  for(const int &size : BufsSize){
    int *arr = new int[size / ByteInInt];
    std::vector<int> IndexRandomBufs:
    for (int i = 0; i < size / ByteInInt; i += Step) {
      IndexRandomBufs.push_back(i);
      k = arr[i];
    }

    std::shuffle(IndexRandomBufs.begin() , IndexRandomBufs.end() , std::default_random_engine{});

    auto StartTime = std::chrono::steady_clock::now();
    for ( int iteration = 0; iteration < Repeat; ++iteration ){
      for (int index : IndexRandomBufs){
        k = arr[index];
      }
    }
    auto EndTime = std::chrono::steady_clock::now();
    DurationTest.push_back(std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime).count()/Repeat);
    delete[] arr;

  }

}