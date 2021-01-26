// Copyright 2020 Shatskov12 <qweser2016@mail.ru>

#include <Cashe.hpp>

std::stringstream tester::StraightTest() {
  NameTest = "Straight";
  DurationTest.clear();
  [[maybe_unused]] int k;
  std::stringstream out;
  int j = 0;

  for (const int &size : BufsSize) {

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
    DurationTest.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(EndTime - StartTime).count()/Repeat);
    delete[] arr;
    out << tester::Print( j ,size , DurationTest[j-1] );

  }
  //for (const int &size : DurationTest){
  //  out << DurationTest[size] << std::endl;
  //}
  return out ;
}

std::stringstream tester::ReversTest() {
  NameTest = "Revers";
  DurationTest.clear();
  [[maybe_unused]] int k;
  std::stringstream out;
  int j = 0;

  for (const int &size : BufsSize) {
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
    DurationTest.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(EndTime - StartTime).count()/Repeat);
    delete[] arr;
    out << tester::Print( j ,size , DurationTest[j-1] );
  }

  return out;
}


std::stringstream tester::RandomTest() {
  NameTest = "Random";
  DurationTest.clear();
  [[maybe_unused]] int k;
  std::stringstream out;
  int j = 0;

  for(const int &size : BufsSize){

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
    DurationTest.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(EndTime - StartTime).count()/Repeat);
    delete[] arr;
    out << tester::Print( j ,size , DurationTest[j-1] );
  }

  return out;
}

//int tester::GetSizeBufs() { return BufsSize.size();}

std::string tester::Print(int a, int b, int d){
    std::stringstream ss;
    ss<< "investigation:\n"
      << "\ttravel_variant: " << NameTest << "\n"
      <<"experiments:\n"
      <<"- experiment:\n"
      <<"\tnumber"<<a<<"\n"
      <<"\tinput_data\n"
      <<"\t\tbuffer_size:"<<b<<"Kb"<<"\n"
      <<"\tresults:\n"
      <<"\t\tduration:"<<d<<" Nanoseconds"<<std::endl<<std::endl;
    return ss.str();
}

void tester::SetBufs() {
  BufsSize.push_back(CacheSize[0]/2);
  for (int i = CacheSize[0]; i < 3*CacheSize[2]/2; i *= 2){
    BufsSize.push_back(i);
  }
  BufsSize.push_back(3*CacheSize[2]/2);

}