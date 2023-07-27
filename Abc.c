#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[100];
    char dob[12];
    char city[100];
} Record;

int calculate_age(const char* dob) {
    struct tm birth_date;
    strptime(dob, "%d-%b-%Y", &birth_date);

    time_t now;
    time(&now);
    struct tm* current_date = localtime(&now);

    int age = current_date->tm_year - birth_date.tm_year;
    if (current_date->tm_mon < birth_date.tm_mon || (current_date->tm_mon == birth_date.tm_mon && current_date->tm_mday < birth_date.tm_mday)) {
        age--;
    }
    return age;
}

void categorize_people(Record records[], int num_records, int age_groups_count[]) {
    for (int i = 0; i < num_records; i++) {
        int age = calculate_age(records[i].dob);
        if (age >= 0 && age <= 10) {
            age_groups_count[0]++;
        } else if (age >= 11 && age <= 20) {
            age_groups_count[1]++;
        } else if (age >= 21 && age <= 30) {
            age_groups_count[2]++;
        } else if (age >= 31 && age <= 40) {
            age_groups_count[3]++;
        } else if (age >= 41 && age <= 50) {
            age_groups_count[4]++;
        } else if (age >= 51 && age <= 60) {
            age_groups_count[5]++;
        } else if (age >= 61 && age <= 70) {
            age_groups_count[6]++;
        } else if (age >= 71 && age <= 80) {
            age_groups_count[7]++;
        } else if (age >= 81 && age <= 90) {
            age_groups_count[8]++;
        } else if (age >= 91 && age <= 100) {
            age_groups_count[9]++;
        }
    }
}

int main() {
    FILE *fp;
    char line[256];
    Record records[100];
    int num_records = 0;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,], %[^,], %[^\n]", records[num_records].name, records[num_records].dob, records[num_records].city);
        num_records++;
    }

    fclose(fp);

    int age_groups_count[10] = {0};
    categorize_people(records, num_records, age_groups_count);

    char* age_groups[] = {
        "0-10", "11-20", "21-30", "31-40", "41-50",
        "51-60", "61-70", "71-80", "81-90", "91-100"
    };

    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", age_groups[i], age_groups_count[i]);
        for (int j = 0; j < num_records; j++) {
            int age = calculate_age(records[j].dob);
            if ((age >= i * 10 && age < (i + 1) * 10) && age_groups_count[i] > 0) {
                printf("%s, %s, %s\n", records[j].name, records[j].dob, records[j].city);
                age_groups_count[i]--;
            }
        }
    }

    return 0;
}
