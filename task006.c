#include <stdio.h>
#include <string.h>
typedef struct {
    float basic;
    float bonus;
    float deduction;
} Salary;
typedef struct {
    int id;
    char name[30];
    Salary salary;
} Employee;
float calculateNetSalary(Employee e) {
    return e.salary.basic + e.salary.bonus - e.salary.deduction;
}
void displayEmployee(Employee e) {
    printf("\nEmployee ID: %d\n", e.id);
    printf("Name       : %s\n", e.name);
    printf("Basic Pay  : %.2f\n", e.salary.basic);
    printf("Bonus      : %.2f\n", e.salary.bonus);
    printf("Deduction  : %.2f\n", e.salary.deduction);
    printf("Net Salary : %.2f\n", calculateNetSalary(e));
}
int main() {
    int n;
    int i;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar(); 
    Employee employees[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].id);
        getchar(); 
        printf("Name: ");
        fgets(employees[i].name, 30, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';
        printf("Basic Pay: ");
        scanf("%f", &employees[i].salary.basic);
        printf("Bonus: ");
        scanf("%f", &employees[i].salary.bonus);
        printf("Deduction: ");
        scanf("%f", &employees[i].salary.deduction);
    }
    printf("\n====== Employee Salary Details ======\n");
    for (i = 0; i < n; i++) {
        displayEmployee(employees[i]);
    }
    return 0;
}

