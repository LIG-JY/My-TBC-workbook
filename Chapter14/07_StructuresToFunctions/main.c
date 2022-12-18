#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
	char bank_name[FUNDLEN];
	double bank_saving;
	char fund_name[FUNDLEN];
	double fund_invest;
};

double sum(const struct fortune* client);

int main()
{
	struct fortune client_1 = {
		.bank_name = "Doichibank",
		.bank_saving = 50000.0,
		.fund_invest = 30000.0,
		.fund_name = "JP"
	};

	printf("Total:\t%.2lf\n", sum(&client_1));

	return 0;
}

double sum(const struct fortune* client)
{
	return client->bank_saving + client->fund_invest;
}
