// Copyright 2020 Shatskov12 <qweser2016@mail.ru>

#include <Cashe.hpp>

void tester::StraightTest() {
  NameTest = "Straight";
  DurationTest.clear();
  [[maybe_unused]] int k;

  for (const int &size : BufsSize) {
    int j = 0;
    ++j;
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
    Print( j ,size , DurationTest[j-1] );
  }

}

void tester::ReversTest() {
  NameTest = "Revers";
  DurationTest.clear();
  [[maybe_unused]] int k;

  for (const int &size : BufsSize) {
    int j = 0;
    ++j;
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
    Print( j , size , DurationTest[j-1] );
  }

}


void tester::RandomTest() {
  NameTest = "Random";
  DurationTest.clear();
  [[maybe_unused]] int k;

  for(const int &size : BufsSize){
    int j = 0;
    ++j;
    int *arr = new int[size / ByteInInt];
    std::vector<int> IndexRandomBufs;
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
    Print( j , size , DurationTest[j-1]);
  }

}

int tester::GetSizeBufs() { return BufsSize.size();}

std::stringstream tester::Print(int a, int b, int d){
    std::stringstream ss;
    ss<< "investigation:\n"
      << "\ttravel_variant: " << NameTest << "\n"
      <<"experiments:"
      <<"- experiment:"
      <<"\tnumber"<<a
      <<"\tinput_data"
      <<"\t\tbuffer_size:"<<b
      <<"\tresults:"
      <<"\t\tduration:"<<d;
    return ss;
}

void tester::SetBufs() {
  BufsSize.push_back(CacheSize[0]/2);
  for (int i = CacheSize[0]; i < 3*CacheSize[2]/2; i *= 2){
    BufsSize.push_back(i);
  }
  BufsSize.push_back(3*CacheSize[0]/2);

}