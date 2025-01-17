#include <benchmark/benchmark.h>
#include <half.hpp>
#include "FixedRangeFloat.h"
#include <vector>
#include <random>

namespace {
  constexpr double kLower = 0.;
  constexpr double kUpper = 1.;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(0.0, 1.0);
  volatile double input = dis(gen);
}

static void BM_FixedRangeFloatToDouble(benchmark::State& state) {
  FixedRangeFloat<0., 1.> number;
  number = input;
  
  double sum = 0;
  for (auto _ : state) {
    sum += static_cast<double>(number);
    benchmark::DoNotOptimize(sum);
  }
}

static void BM_HalfToDouble(benchmark::State& state) {
  half_float::half number;
  number = input;
  
  double sum = 0;
  for (auto _ : state) {
    sum += static_cast<double>(number);
    benchmark::DoNotOptimize(sum);
  }
}


static void BM_FixedRangeFloatFromDouble(benchmark::State& state) {
  FixedRangeFloat<0., 1.> number;
  
  for (auto _ : state) {
    number = input;
    benchmark::DoNotOptimize(number);
  }
}

static void BM_HalfFromDouble(benchmark::State& state) {
  half_float::half number;
  
  for (auto _ : state) {
    number = input;
    benchmark::DoNotOptimize(number);
  }
}

BENCHMARK(BM_FixedRangeFloatToDouble);
BENCHMARK(BM_HalfToDouble);
BENCHMARK(BM_FixedRangeFloatFromDouble);
BENCHMARK(BM_HalfFromDouble);
BENCHMARK_MAIN();