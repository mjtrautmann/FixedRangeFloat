# FixedRangeFloat

FixedRangeFloat is a class that provides a reduced precision floating point storage type
with only 8 bit of storage capacity. It stores values in a fixed range using an 8 bit integer.
The given range is resolved with 255 points, including the inclusive end points, e.g. a range
of [0,1000] would roughly resolve to 0,4,8...