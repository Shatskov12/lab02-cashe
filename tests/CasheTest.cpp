// Copyright 2020 Shatskov12 <qweser2016@mail.ru>

#include <gtest/gtest.h>

#include "iostream"
#include "Cashe.hpp"

TEST(Example, EmptyTest) {
  tester test;
  test.SetBufs();
  test.StraightTest();
  std::cout << test;
  test.ReversTest();
  //std::cout << test;
  test.RandomTest();
  //std::cout << test;
}