//
// Created by ggggg on 2017/3/10.
//

#include <cstdio>
#include <cstdlib>
#define Error(Str) FatalError(Str)
#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1);