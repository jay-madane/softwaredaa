#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 100
#define DATE_FORMAT_LEN 12

typedef struct {
    char name[MAX_NAME_LEN];
    char dob[DATE_FORMAT_LEN];
    char city[MAX_NAME_LEN];
} Record;

typedef struct {
    int lower;
    int upper;
    int count;
} AgeGroup;

int calculateAge(const char* dob) {
    int day, month, year;
    sscanf(dob, "%d-%*3s-%d", &day, &year);
    year -= 1900;
    month = (int)(dob[4] - 'A' + 1);
    return 2023 - year - (month * 30 + day > 212);
}

int main() {
    FILE* file;
    char line[MAX_NAME_LEN * 3 + DATE_FORMAT_LEN + 3]; // For storing each line (record) from the file
    Record records[MAX_RECORDS];
    AgeGroup ageGroups[] = {
        {0, 10, 0},
        {11, 20, 0},
        {21, 30, 0},
        {31, 40, 0},
        {41, 50, 0},
        {51, 60, 0},
        {61, 70, 0},
        {71, 80, 0},
        {81, 90, 0},
        {91, 100, 0},
    };

    int numRecords = 0;

    file = fopen("records.txt", "r");
    if (!file) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read the records from the file and calculate the age
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,], %[^,], %[^\n]", records[numRecords].name, records[numRecords].dob, records[numRecords].city);
        int age = calculateAge(records[numRecords].dob);

        // Update the count for the appropriate age group
        for (int i = 0; i < sizeof(ageGroups) / sizeof(ageGroups[0]); i++) {
            if (age >= ageGroups[i].lower && age <= ageGroups[i].upper) {
                ageGroups[i].count++;
                break;
            }
        }

        numRecords++;
    }

    fclose(file);

    // Sort the age groups based on count in descending order
    for (int i = 0; i < sizeof(ageGroups) / sizeof(ageGroups[0]) - 1; i++) {
        for (int j = i + 1; j < sizeof(ageGroups) / sizeof(ageGroups[0]); j++) {
            if (ageGroups[i].count < ageGroups[j].count) {
                AgeGroup temp = ageGroups[i];
                ageGroups[i] = ageGroups[j];
                ageGroups[j] = temp;
            }
        }
    }

    // Print the output
    printf("Age Categorization Program\n\n");
    printf("Category %d-%d - Count %d\n", ageGroups[0].lower, ageGroups[0].upper, ageGroups[0].count);

    for (int i = 0; i < numRecords; i++) {
        int age = calculateAge(records[i].dob);
        if (age >= ageGroups[0].lower && age <= ageGroups[0].upper) {
            printf("%s, %s, %s\n", records[i].name, records[i].dob, records[i].city);
        }
    }

    for (int i = 1; i < sizeof(ageGroups) / sizeof(ageGroups[0]); i++) {
        printf("\nCategory %d-%d - Count %d\n", ageGroups[i].lower, ageGroups[i].upper, ageGroups[i].count);

        for (int j = 0; j < numRecords; j++) {
            int age = calculateAge(records[j].dob);
            if (age >= ageGroups[i].lower && age <= ageGroups[i].upper) {
                printf("%s, %s, %s\n", records[j].name, records[j].dob, records[j].city);
            }
        }
    }

    return 0;
}
