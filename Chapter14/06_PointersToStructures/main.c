#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names {
	char given[LEN];
	char family[LEN];
};

struct friend {
	struct names full_name;
	char mobile[LEN];
};

int main(void)
{
	struct friend my_friend[2] = {
		{{"Ariana", "Grande"}, "1234-1234"},
		{{"Taylor", "Swift"}, "8080-5555"},
	};

	struct friend* girl_Freind;
	girl_Freind = &my_friend[0];

	printf("size of struct freind is %zd\n", sizeof(struct friend));
	printf("address of pointer girl_Freind is %lld\n and member of member is %s\n",
		(long long)girl_Freind, girl_Freind->full_name.given);

	girl_Freind++;  // 포인터연산

	printf("address of pointer girl_Freind is %lld\n and member of member is %s\n",
		(long long)girl_Freind, (*girl_Freind).full_name.given);

	return 0;
}
