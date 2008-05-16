#ifndef __DOJO_UNIT_H__
#define __DOJO_UNIT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char boolean;

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef throw_error
#define throw_error(MSG) do{__increase_error_count();fprintf(stderr,"ERROR in file \"%s\", line %d: %s\n", __FILE__, __LINE__, MSG);return;}while(0)
#endif

#ifndef assert_true
#define assert_true(MSG,A) if(!A)throw_error(MSG)
#endif

#ifndef assert_false
#define assert_false(MSG,A) if(A)throw_error(MSG)
#endif

#ifndef pending
#define pending() do{__increase_pending_count();fprintf(stderr,"Pending test in file \"%s\", near line %d.\n", __FILE__, __LINE__ - 1);return;}while(0)
#endif

#ifndef assert_same
#define assert_same(MSG,A,B) assert_true(MSG,__assert_equals(&A,&B,sizeof A, sizeof B))
#endif

#ifndef assert_equals
#define assert_equals(MSG,A,B,COMP) assert_true(MSG,__assert_equals_cmp(A,B,COMP))
#endif

#ifndef assert_not_same
#define assert_not_same(MSG,A,B) assert_false(MSG,__assert_equals(&A,&B,sizeof A, sizeof B))
#endif

#ifndef assert_not_equals
#define assert_not_equals(MSG,A,B,COMP) assert_false(MSG,__assert_equals_cmp(A,B,COMP))
#endif

#ifndef assert_null
#define assert_null(MSG,A) if(A!=NULL)throw_error(MSG)
#endif

#ifndef assert_not_null
#define assert_not_null(MSG,A) if(A==NULL)throw_error(MSG)
#endif

boolean __assert_equals(const void*, const void*, const int, const int);
boolean __assert_equals_cmp(void*, void*, const int *(func)(void*, void*));
void __increase_error_count();
void __increase_pending_count();
int print_summary(int);
#endif /* __DOJO_UNIT_H__ */