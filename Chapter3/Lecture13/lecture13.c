#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("%u\n", sizeof(_Bool)); 
    /* 
        1 byte, 최소 단위인 1바이트를 배정받습니다. 불리언 타입은 실제로는 1비트만 필요합니다. 나머지 7비트는 낭비가되네요?
        byte가 메모리에서 주소를 배정받을 수 있는 최소단위 입니다.
        이 나머지 7비트를 사용하는 방법을 비트연산에서 배우게 됩니다.
     */
	printf("%zu\n", sizeof(_Bool));  // 1 byte, use %zu for size_t type

    _Bool b1; // 최근에 추가된 Bool type
    b1 = 0; // False
    b1 = 1; // True

    printf("%d\n", b1 ); // printf에서는 format specifier을 그냥 %d로 하면 됩니다.

    // stdbool.h 라는 header가 추가되었습니다. 이 헤더를 Inlcude하면 아래처럼 선언할 수 있습니다.
    bool b2, b3;
    b2 = true;
    b3 = false; // 컴퓨터는 false가 아니면 true라고 인식합니다.

    printf("%d %d\n", b2, b3);

	return 0;
}
