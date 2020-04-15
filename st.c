#include <stdio.h>
#define MAX_NAME_LEN 20
typedef struct _Student Student;

struct _Student
{
	char name[MAX_NAME_LEN+1];
	int age;
	int num;
};

void store_students();
void search_student();

int main() {
	store_students();
	search_student();
	return 0;
}


void store_students()
{
	Student base[4] = {
		{"hong gil dong", 20, 3}, {"gang gam chan", 30, 4},
		{"kim yu sin", 70, 1}, {"lee sun sin", 35, 2}
	};


	FILE *fp = fopen("students.dat", "wb");
	fwrite(base, sizeof(Student), 4, fp);
	fclose(fp);

}


void search_student() {
	FILE *fp = fopen("students.dat", "rb");
	fseek(fp, 0, SEEK_END);
	int mcnt = ftell(fp) / sizeof(Student);

	rewind(fp);
	
	int nth = 0;
	printf("num(1~%d): ", mcnt);
	scanf("%d", &nth);

	if ((nth <= 0) || (nth > mcnt)) {
		printf("select another number \n");
		return;
	}

	fseek(fp, (nth -1) * sizeof(Student), SEEK_SET);
	Student student;
	fread(&student, sizeof(Student), 1, fp);
	fclose(fp);

	printf("Name: %s Number: %d Age: %d \n", student.name, student.num, student.age);
}
