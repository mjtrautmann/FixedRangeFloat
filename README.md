# FixedRangeFloat

FixedRangeFloat is a class that provides a reduced precision floating point storage type
with only 8 bit of storage capacity. It stores values in a fixed range using an 8 bit integer.
The given range is resolved with 252 points, including the inclusive end points, e.g. a range
of [0,1000] would roughly resolve to 0,4,8... The specific of steps ensures that the half point, quarter point and three quarter point are represented exactly. In a range of [0,1] for example, the numbers 0.25, 0.5 and 0.75 are stored exactly.

Since the performance of conversion from and to the type from standard floating points is extremely
important, there is a benchmark against the 16 bit floating point type from the half library:

This is the output from a run on a laptop, which shows comparable performance.
```
Run on (12 X 2496 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 1280 KiB (x6)
  L3 Unified 12288 KiB (x1)
-----------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
-----------------------------------------------------------------------
BM_FixedRangeFloatToDouble         3.39 ns        0.344 ns   1000000000
BM_HalfToDouble                    3.65 ns         1.20 ns   1000000000
BM_FixedRangeFloatFromDouble       1.94 ns        0.767 ns    896000000
BM_HalfFromDouble                  1.77 ns        0.654 ns   1338026667
```