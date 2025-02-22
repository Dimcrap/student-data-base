/*
                                new researchsssss

Student class: Attributes such as student ID, name, major,
               and GPA, along ******with methods to access and modify them*****.
               
Database class: Manages a collection of Student objects, providing functionalities for adding,
deleting, searching, and displaying student records.

File Handling:Load data from a file at the start of the program, populating the Database.

Save data to a file before the program exits, ensuring data persistence.

Implement functions to read and
 write student data to a file, using a suitable format (e.g., CSV or a custom format).

User interface:
A menu-driven interface for user interaction.

Options to add a new student, delete an existing student,
 search for a student by ID or name, display all students, and exit the program.
*/

#include <iostream>
//#include <C:\programming\reviving files\C++\exersise p\student data base\declerations.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>


std::string Id_creator();
void mainscreen();
void print_all();
void record_modifier();
void search_print();
void add_delete_s();
int id_exist(std::string I_D );

struct student{
     std::string Firstname;
     std::string Lastname;
     std::string Id;
     std::string records;//this must contain some other details like gpa(grade point avrage)
     
};

int student_numbers=11;


int main(){
     srand(time(0));
     /* requiered objects must be creted for *deleting student*,*adding detials*,editing student 
     */
     std::ostringstream text;
     std::ofstream file_o("data.txt",std::ios::app);
     
    
     // std::cout<<"hello there";//<<std::endl;
    mainscreen();
}



std::string id_creator(){

std::string alphabet="QWERTYUIOPASDFGHJKLZXCVBNM";
std::string numbers="0123456789";     
std::string ID;

int index_n=rand() %26;

for (int i=0;i<3;i++){
     ID+=alphabet[index_n];
     index_n=rand() %26;
};

index_n=rand()%10;

for(int i=0;i<6;i++){
     ID+=numbers[index_n];
     index_n=rand()%10;  
};

return ID;


};


void print_all(){

};

void mainscreen(){
     int input;
   std::cout<<"\n\n\n\t\t\t\t\t student  database\n";
   std::cout<<"\n\t\t\t\t\t 1.Reavling all sudents datas\n\t\t\t\t\t 2.Modify students records \n\t\t\t\t\t 3.Search and view Records\n\t\t\t\t\t 4.add and delete a student\n\t\t\t\t\t 5.Exits";
   std::cout<<"\n\t\t\t\t\t Choose options:[1/2/3/4/5]\n\t\t\t\t\t";
   std::cin>>input;
   switch(input){
   case 1:
   print_all(); 
   std::cout<<"record reciver";
   case 2:
   record_modifier();
    std::cout<<"modifier";
   case 3:
   search_print();
    //std::cout<<"deleter";
   case 4:
    std::cout<<"add and delete student";
    add_delete_s();
    case 5:
    std::cout<<"exit";
                                                     //save the data before exit
    exit(0);
   }
}

void record_modifier(){

};

void search_print(){
    std::cout<<"student finder";
    


};

void add_delete_s(){
     std::cout<<"\t\t\t\t\t<<adding deleting page>>\n\n";
     std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
     int input1;

     std::cout<<"1-adding a student.\n2-deleting a student file\n";
     std::cin>>input1;
     while(input1<1||input1>3){
          std::cout<<strerror(22)<<"\n1-adding a student.\n2-deleting a student file\n3-go to leading screen\n";
          std::cin>>input1;
          if(input1==3){
               mainscreen();
          }
     
     };
     
     if(input1==1){
     std::cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');
          student_numbers++;
          std::string fname,lname,id,gpa,major;
          std::cout<<"\nenter students first name:";
          getline(std::cin,fname);
          std::cout<<"\nenter students lastname:";
          getline(std::cin,lname);
         id=id_creator();                                              
         while(id_exist(id)==1){
          id=id_creator();                                              
         } 
         std::cout<<"\nenter students GPA:";
          getline(std::cin,gpa);
          std::cout<<"\nenter studentss major:";
          getline(std::cin,major);
          
          //*****declaring and sving to the base */
          std::ofstream to_add_file;
          to_add_file.open("data.txt",std::ios::out|std::ios::app);
          to_add_file<<"\nFirstname"<<student_numbers<<":"<<fname;
          to_add_file<<"\nLastname"<<student_numbers<<":"<<lname;
          to_add_file<<"\nid"<<student_numbers<<":"<<id;
          to_add_file<<"\ngpa"<<student_numbers<<":"<<gpa;
          to_add_file<<"\nmajor"<<student_numbers<<":"<<major;
          
     }else if(input1==2){

     };

};

int id_exist(std::string I_D){

     std::map <std::string ,std::string> configuration;
     std::ifstream infile;
     std::string line;
     
     infile.open("data.txt");

     if(!infile){
          std::cout<<"error accured!";
          exit(1);
     };

     size_t pos;
     int st=0;
     while(infile.good()){
          getline(infile,line);
          pos=line.find(I_D);
          if(pos!=std::string::npos){

               return 1;
               st=1;
          }
     }
     if(st==0){

          return 0;
     }
     
}

/*
     APP FEATURES:
-Find individual student records by last name and first name.
-Print the entire student registry sorted alphabetically by last name, major, or GPA.
-Save student records to a specified file destination.
-Efficient sorting using merge sort algorithm.
-Flexible file destination selection.
-Error handling for invalid input.
-Future plans include adding more advanced features like calculating average GPA, class ranking, and university ranking.
*/
/*
         column needs:
             student id  firstname lastname email(optional) department(need more scarpng ) 
             major   Gpa

*/

/*

 majors:
 healthcare administration -----psychology-----journalism------electrical engineering---
 criminal justice-------human services------economic--------social sciences----biochemisty-----

 */