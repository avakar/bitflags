# bitflags

Tiny header-only library providing bitwise operators for enums in C++11.

## Getting started

Import the operators from namespace `avakar::bitflags` and
add an enumerator called `none` to your flag-like enum.

```cpp
#include <avakar/bitflags.h>
using namespace avakar::bitflags;

enum myflags {
    none,
    flag1 = (1<<0),
    flag2 = (1<<1),
    flag3 = (1<<2),
};
```

Now you can use bitwise operators on your enum.

```cpp
myflags fl = flag1 | flag2;
```
