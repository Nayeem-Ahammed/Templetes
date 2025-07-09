## Debugging File
- [download](https://github.com/Nayeem-Ahammed/Templetes/blob/main/Debuggin_headerfile.cpp) here.

- in your program , just add this after `main()`
```
#ifndef ONLINE_JUDGE
#include "NAYEEM.cpp"
#else
#define dbg(...)
#endif
```

### use: 
`dbg(__)`
* You can dbg :
  - any single data
  - pair, tuple
  - vector, pair of vector, vector of vector
  - set, unorsered_set
  - map, unordered_map
  - multimap, multiset

- Also, you can use together multimples.

*@nayeem_ahammed*
