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
    // Same as before
    // ...
}

void categorize_people(Record records[], int num_records, int age_groups_count[]) {
    // Same as before
    // ...
}

void print_category(const char* category, Record records[], int num_records) {
    printf("Category %s-Count %d\n", category, num_records);
    for (int i = 0; i < num_records; i++) {
        printf("%s, %s, %s\n", records[i].name, records[i].dob, records[i].city);
    }
    printf("\n");
}

int main() {
    // Same as before
    // ...
    
    char* age_groups[] = {
        "0-10", "11-20", "21-30", "31-40", "41-50",
        "51-60", "61-70", "71-80", "81-90", "91-100"
    };

    for (int i = 0; i < 10; i++) {
        if (age_groups_count[i] > 0) {
            print_category(age_groups[i], records, age_groups_count[i]);
        }
    }

    return 0;
}
