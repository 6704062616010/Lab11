#include <stdio.h>
#define NO_SCORE 5
#define N 10
typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;
void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);

int main() {
    Student std[N];
    float avg;
    FILE *fp;
    int i;
    for(i=0;i<N;i++){
        printf("\nStudent %d\n",i+1);
        readStudentData(&std[i]);
    }
    fp = fopen(".\\lab11\\no2\\std10.dat","wb");
    fwrite(std,sizeof(Student),N,fp);
    fclose(fp);

    fp = fopen(".\\lab11\\no2\\std10.dat","rb");
    fread(std,sizeof(Student),N,fp);
    fclose(fp);
    for(i=0;i<N;i++){
        printf("\n\n---------------------");
        findTotalScore(&std[i]);
        avg = findAverage(std[i]);
        printf("\nAverage score is %.2f",avg);
        findLessThanTen(std[i]);
    }
}
void readStudentData(Student *pStd) {
    int i;
    printf("\tName : ");
    scanf("%s", pStd->name);
    printf("\tSurname : ");
    scanf("%s", pStd->surname);
    for(i=0;i<NO_SCORE;i++){
        printf("\tScore %d : ",i+1);
        scanf("%d",&pStd->score[i]);
    }
}
void findTotalScore(Student *pStd) {
    int i;
    printf("\n%s %s got score ",pStd->name,pStd->surname);
    pStd->total = 0;
    for(i=0;i<NO_SCORE;i++){
        printf("%6d",pStd->score[i]);
        pStd->total += pStd->score[i];
    }
    printf("\nTotal score is %.2f",pStd->total);
}
float findAverage(Student s) {

    return s.total/NO_SCORE;
}
void findLessThanTen(Student s) {
    int i,count=0;
    printf("\nScore less than 10");
    for(i=0;i<NO_SCORE;i++){
        if(s.score[i] < 10){
            printf("\nTest no.%d - %d",i+1,s.score[i]);
            count++;
        }
    }
    if(count==0)
        printf(" -> None");
}