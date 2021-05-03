#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>



struct date {
	int year;
	int month;
	int day;
};

struct person
{
	int code_department;
	char* last_name;
	struct date date_of_hiring;
	double salary;
};



void staff_list_printer(struct person arr[], int size);
void person_search(struct person arr[], int size, char lastnamt[]);
void salary_sorter(struct person arr[], int size, double criterion);
struct person* array_reduser(struct person arr[], int);

int main(void) {
	int counter;
	int new_size = 0;
	struct person staff[] = {
		2, "Cartman", {1990, 8, 13}, 14000.5,
		1, "Griffin", {2000, 2, 1}, 9230.2,
		2, "Sanches", {2005, 12, 1}, 25100.0,
		3, "Simpson", {2001, 1, 7}, 110330.0,
		4, "Meeseeks", {2006, 2, 28}, 3000.68,
		2, "Summer", {1980, 6, 1}, 34256.21,
		1, "Goldenfold", {1995, 3, 12}, 6000.02,
		3, "Flanders", {1999,4, 17}, 4826.3,
		2, "Viegum", {2002, 5, 17}, 34500.0,
		1, "Dorian", {2003, 8, 15}, 1000.02
	};


	int size = sizeof(staff) / sizeof(staff[0]);

	staff_list_printer(staff, size);

	person_search(staff, size, "Goldenfold");

	salary_sorter(staff, size, 12000.00);

	for (counter = 0; counter < size; counter++) {
		if (staff[counter].salary > 12000.00) {
			new_size++;
		}
	}
	staff_list_printer(staff, size);

	struct person* new_array = array_reduser(staff, new_size);


	staff_list_printer(new_array, new_size);

	return 0;
}



void staff_list_printer(struct person svar[], int size) {
	int cntr;
	for (cntr = 0; cntr < size; cntr++) {
		printf("Lastname: %s\tDepartment:%d\tDate of hiring: %d.%d.%d\tSalary:%7.2f\n", svar[cntr].last_name, svar[cntr].code_department,
			svar[cntr].date_of_hiring.day, svar[cntr].date_of_hiring.month, svar[cntr].date_of_hiring.year, svar[cntr].salary);
	}
	printf("\n\n");
}


void person_search(struct person arr[], int size, char lastname[]) {
	int cntr;
	int is_person = 0;
	for (cntr = 0; cntr < size; cntr++) {
		if (0 == strcmp(arr[cntr].last_name, lastname)) {
			printf("Lastname: %s\tDepartment:%d\tDate of hiring: %d.%d.%d\tSlary:%7.2f\n\n\n", arr[cntr].last_name, arr[cntr].code_department,
				arr[cntr].date_of_hiring.day, arr[cntr].date_of_hiring.month, arr[cntr].date_of_hiring.year, arr[cntr].salary);
			is_person++;
		}
	}
	if (0 == is_person) {
		printf("Sorry, employee wasn't found\n\n");
	}
}

void salary_sorter(struct person arr[], int size, double criterion) {
	int j;
	int z;
	for (int i = 0; i < 2; i++) {
		for (j = 0; j < size; j++) {
			if (arr[j].salary < criterion) {
				for (z = j; z < (size - 1); z++) {
					int temp_department = arr[z].code_department;
					char* temp_lastname = arr[z].last_name;
					struct date temp_dt = { arr[z].date_of_hiring.year, arr[z].date_of_hiring.month, arr[z].date_of_hiring.day };
					double temp_salary = arr[z].salary;

					arr[z].code_department = arr[z + 1].code_department;
					arr[z].last_name = arr[z + 1].last_name;
					arr[z].date_of_hiring.year = arr[z + 1].date_of_hiring.year;
					arr[z].date_of_hiring.month = arr[z + 1].date_of_hiring.month;
					arr[z].date_of_hiring.day = arr[z + 1].date_of_hiring.day;
					arr[z].salary = arr[z + 1].salary;

					arr[z + 1].code_department = temp_department;
					arr[z + 1].last_name = temp_lastname;
					arr[z + 1].date_of_hiring.year = temp_dt.year;
					arr[z + 1].date_of_hiring.month = temp_dt.month;
					arr[z + 1].date_of_hiring.day = temp_dt.day;
					arr[z + 1].salary = temp_salary;
				}
			}
		}
	}
}


struct person* array_reduser(struct person arr[], int new_size) {
	int i;
	struct person* new_array = (struct person*)calloc(new_size, sizeof(struct person));
	for (i = 0; i <= new_size; i++) {
		(new_array + i)->code_department = arr[i].code_department;
		(new_array + i)->last_name = arr[i].last_name;
		(new_array + i)->date_of_hiring.year = arr[i].date_of_hiring.year;
		(new_array + i)->date_of_hiring.month = arr[i].date_of_hiring.month;
		(new_array + i)->date_of_hiring.day = arr[i].date_of_hiring.day;
		(new_array + i)->salary = arr[i].salary;
	}
	return new_array;
}