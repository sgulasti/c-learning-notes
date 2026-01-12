#include <stdio.h>

#define MAX 50

struct Student {
    int id;
    float grade;
};

void addStudents(struct Student s[], int *count) {
    int n;
    printf("Kac ogrenci eklemek istiyorsunuz? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Ogrenci ID: ");
        scanf("%d", &s[*count].id);

        printf("Not: ");
        scanf("%f", &s[*count].grade);

        (*count)++;
    }
}

void listStudents(struct Student s[], int count) {
    printf("\n--- Ogrenci Listesi ---\n");
    for(int i = 0; i < count; i++) {
        printf("ID: %d | Not: %.2f\n", s[i].id, s[i].grade);
    }
}

float calculateAverage(struct Student s[], int count) {
    float sum = 0;
    for(int i = 0; i < count; i++) {
        sum += s[i].grade;
    }
    return sum / count;
}

void findTopStudent(struct Student s[], int count) {
    int index = 0;
    for(int i = 1; i < count; i++) {
        if(s[i].grade > s[index].grade)
            index = i;
    }

    printf("\nEn basarili ogrenci:\n");
    printf("ID: %d | Not: %.2f\n", s[index].id, s[index].grade);
}

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ogrenci Ekle\n");
        printf("2. Ogrencileri Listele\n");
        printf("3. Ortalama Hesapla\n");
        printf("4. En Basarili Ogrenciyi Bul\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudents(students, &count);
                break;
            case 2:
                listStudents(students, count);
                break;
            case 3:
                printf("Sinif Ortalamasi: %.2f\n", calculateAverage(students, count));
                break;
            case 4:
                findTopStudent(students, count);
                break;
            case 0:
                printf("Cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim!\n");
        }
    } while(choice != 0);

    return 0;
}
