#include <stdio.h>
#include <stdint.h> // stdint.h를 inlcude 하면 _t 붙은 자료형 사용 가능 also included in inttypes.h
#include <inttypes.h> // printf에서 stdint.h에서 이름 바꾼 자료형의 변수를 사용할 때 적절한 format specifier을 찾기 어렵기 때문에 사용

/* inttypes.h에는 이미 stdint.h가 이미 include되어 있기 때문에 굳이 2번째 줄 코드는 필요없다.  */

int main()
{
	int i;
    int32_t i32; // 32 bit fixed interger
    int_least8_t i8; // 적어도 8 bit를 가진 자료형
    int_fast8_t f8; // fastest minimum 8bit 중에서 가장 빠르다.
    intmax_t imax; // biggest signed int, signed int중에서 가장 메모리를 많이 차지하는 것
    uintmax_t uimax; // unsigned int 중에서 가장 메모리를 많이 차지하는 것

    i32 = 1004;

    printf("me32 = %d\n", i32);
    printf("me32 = %" "d" "\n", i32);
    printf("me32 = %" PRId32 "\n", i32);
    /* PRId32 : inttypes.h의 메크로 */


	return 0;
}
