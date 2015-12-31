#ifndef TESTER_H
#define TESTER_H 1

#include <stdio.h>

extern char *suite_name;
extern int test_count;
extern int error_count;

typedef void (*test_case_fnc)(void *data);
#define ASSERT(e) ({ int _e = (e); ++test_count; if(_e) { printf("."); } else { fprintf(stderr, "("#e" "__FILE__" line %d failed!)\n", __LINE__); ++error_count; } _e = _e; })
#define ASSERT_OR_RETURN(e) ({ if(!ASSERT(e)) return; })

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

void add_test_case(char *name, test_case_fnc fnc, void *data);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
