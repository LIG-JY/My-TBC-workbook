#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    // round-off errors 예시1, 이런 내용을 깊게 다루는 분야가 수치해석입니다.
    float a, b; 
    a = 1000.0f + 1.0f;
    b = a - 1000.0f;
    printf("%f\n", b);

    float A, B; 
    A = 1.0E20f + 1.0f;
    B = A - 1.0E20f;
    printf("%f\n", B);

    // round-off error2
    float c = 0.0f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    c = c + 0.01f;
    printf("%f", c);

    // overflow
    float max = 3.402823466e+38F;
    printf("%f\n", max);
    max = max * 100.0f;
    printf("%f\n", max);

    // underflow
    float min = 1.401298464e-45F;
    printf("%e\n", min); // %e: a floating point number in scientific notation
    min = min / 100.0f;
    printf("%e\n", min); // subnormal

    float t1 = asinf(1.0f);  // sin의 역함수에 1을 넣습니다.
    printf("%f\n", t1);

    float t2 = asinf(2.0f);  // sin의 역함수에 2을 넣습니다.
    printf("%f\n", t2); // Nan: Not a number
    
	return 0;
}
