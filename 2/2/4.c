#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement (int startAge,   //in months
                double initial, //initial savings in dollars
                retire_info working, //info about working
                retire_info retired) { //info about being retired
    double balance;
    int age_years;
    int age_months;
    int age;
    int i;

    age = startAge;
    for (i=0; i <= working.months; i++) {
        if (i == 0) {
            balance = initial;
        } else {
            balance += working.contribution + balance * working.rate_of_return / 12;
        }
        age_years = age / 12;
        age_months = age % 12;
        printf("Age %3d month %2d you have $%.2lf\n", age_years, age_months, balance);
        age++;
    }

    for (i=0; i < retired.months - 1; i++) {
        balance += retired.contribution + balance * retired.rate_of_return / 12;
        age_years = age / 12;
        age_months = age % 12;
        printf("Age %3d month %2d you have $%.2lf\n", age_years, age_months, balance);
        age++;
    }

}

int main () {
    retire_info working;
    retire_info retired;

    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045;

    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01;
    retirement(327, 21345, working, retired);

    return 0;
}
