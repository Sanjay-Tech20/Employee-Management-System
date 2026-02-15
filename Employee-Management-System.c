// Employee-Management-System
#include <stdio.h>
#include <string.h>
# define MAX_Employees 50
    struct Employee
    {
        int id;
        char name[50];
        float salary;
        char gender;
        char designation[50];
    };

        struct Employee employee[MAX_Employees];
        int count=0;

    void addEmployee();
    void deleteEmployee();
    void displayEmployees();
    void file_se_data_load();
    void data_saving();
    
int main() {
    file_se_data_load();
    int choice;
    while(1){
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
   

    if(choice==1){ 
        addEmployee();
    }
    else if(choice==2){
        displayEmployees();
    }
    else if(choice==3){
            deleteEmployee();
    }
    else if(choice==4){
       printf("Existing Program...\n");
       data_saving();
       break;
    }
    else{
        printf("Please Enter the Valid Choice.........\n");
    }
    }

    return 0;
}
 void addEmployee(){
    if(count<MAX_Employees){
      printf("Enter ID :: ");
    scanf("%d",&employee[count].id);
    getchar();

    printf("Enter Name :: ");
    fgets(employee[count].name,50,stdin);
    employee[count].name[strcspn(employee[count].name,"\n")]='\0';

    printf("Enter Salary :: ");
    scanf("%f",&employee[count].salary);

    printf("Enter Gender (M/F) :: ");
    scanf(" %c",&employee[count].gender);
    getchar();
    
    printf("Enter Designation :: ");
    fgets(employee[count].designation,50,stdin);
    employee[count].designation[strcspn(employee[count].designation,"\n")]='\0';

    count++;
    printf("Employee Added Successfuly \n");
    }
    else{
        printf("System Full..!");
    }
 }

  void displayEmployees(){
         if(count==0){
            printf("No Employees to Display.\n");
        }
        else{
            for(int i=0; i<count ; i++){
                printf("\n Employee %d\n",i+1);
                printf("ID : %d\n",employee[i].id);
                printf("Name : %s\n",employee[i].name);
                printf("Salary : %.2f\n",employee[i].salary);
                printf("Gender : %c\n",employee[i].gender);
                printf("Designation : %s\n",employee[i].designation);
            }
        }
  }
  void deleteEmployee(){
     int delete_ID, found=0;

            printf("Enter Employee ID that you want to Delete :: ");
            scanf("%d",&delete_ID);

            for(int i=0;i<count;i++){
                if(employee[i].id==delete_ID){
                    found=1;

                    for(int j=i;j<count-1;j++){
                        employee[j] = employee[j+1];
                    }
                    count--;
                    printf("Employee Delete Successfully\n");
                    break;
                }  
            }
            if(found==0){
                    printf("Employee with this ID not Found");
                }
  }
  void file_se_data_load(){
    FILE *ptr = fopen("employeess_data.txt","r");

    if(ptr==NULL){
        return;
    }
    while(fscanf(ptr,"%d %[^\n] %f %c %[^\n]",
    &employee[count].id,
    &employee[count].name,
    &employee[count].salary,
    &employee[count].gender,
    &employee[count].designation) != EOF){
    count++;
    }
    fclose(ptr);
  }
  void data_saving(){
    FILE *ptr = fopen("employeess_data.txt","w");
    if(ptr==NULL){
        printf("File Nahi Ban saki !");
        return;
    }
    for(int i=0;i<count;i++){
        fprintf(ptr,"%d\n%s\n%f\n%c\n%s\n",
        employee[i].id,
        employee[i].name,
        employee[i].salary,
        employee[i].gender,
        employee[i].designation);
    }
    fclose(ptr);
    printf("Data Saved Successfully");
  }