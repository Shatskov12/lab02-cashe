// Copyright 2020 Shatskov12 <qweser2016@mail.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <chrono>
#include <random>
#include <string>
#include <vector>


const int CacheSize[3]{128 , 512 , 3072};
const int Repeat = 1000;
const int ByteInInt = 4;
const int Step = 16;
const int ByteInKb = 1024;


std::string NameTest;
std::vector<int> BufsSize;
std::vector<int> DurationTest;
class tester {

 private:

 public:
  void StraightTest();
  void RandomTest();
  void ReversTest();
  void SetBufs();




};


#endif // INCLUDE_HEADER_HPP_
