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
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <cstring>
#include <limits>
#include <thread>
#include <chrono>
#include <vector>

std::string id_creator();
void mainscreen();
void print_all();
void record_modifier();
void search_print();
void add_delete_s();
int id_exist(std::string I_D );
void dossier_swaper(std::string firststudentN,std::string secondstudentN);
std::string student_number(const std::string & filename,std::string ID);
std::map <std::string,std::string> studentdatadonor(std::string studentN);
void loopingfile(std::vector<std::string>& all_lines,std::string field,std::string subjnumber,std::string content);
void deletelastS();
int readStudentNums();
void saveStudentNums(int count);

int student_numbers=readStudentNums();

struct student{
     std::string Firstname;
     std::string Lastname;
     std::string Id;
     std::string records;//this must contain some other details like gpa(grade point avrage)
     
};






int main(){
    
     //std::map<std::string,std::string> testmap=studentdatadonor("0");
     //std::cout<<testmap["Firstname0"];
     mainscreen();
    //std::cout<<"name";

     return 0;
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


std::cout<<"this function isn't ready";
return "";
};


void print_all(){

std::map <std::string,std::string> configuration;
std::ifstream fileobj("data.txt");
std::string line;

while(getline(fileobj,line)){
     std::string key;
     std::string value;
          std::stringstream myss(line);
          getline(myss,key,':');
          myss>>std::ws;
          getline(myss,value);

          configuration[key]=value;
     };
     for(int i=0;i<11;i++){
          std::cout<<"\nFIRSTNAME:"<<configuration["Firstname"+std::to_string(i)]<<"\nLASTNAME:"<<configuration["Lastname"+std::to_string(i)];
          std::cout<<"\nID:"<<configuration["id"+std::to_string(i)]<<"\nGPA:"<<configuration["gpa"+std::to_string(i)]<<"\nMAJOR:"<<configuration["major"+std::to_string(i)];
          std::cout<<std::endl;
     }
     fileobj.close();
     mainscreen();

};

void mainscreen(){
    int input; 
     
     std::cout<<"\n\n\n\t\t\t\t\t\t student  database\n";
   std::cout<<"\n\t\t\t\t\t 1.Reavling all sudents datas\n\t\t\t\t\t 2.Modify students records \n\t\t\t\t\t 3.Search and view Records\n\t\t\t\t\t 4.add and delete a student\n\t\t\t\t\t 5.Exits";
   std::cout<<"\n\t\t\t\t\t Choose options:[1/2/3/4/5]\n\t\t\t\t\t";
   std::cin>>input;
   while (input<1||input>5){
     std::cout<<"\n\n"<<strerror(3)<<"\n";
     std::cout<<"\n\t\t\t\t\t 1.Reavling all sudents datas\n\t\t\t\t\t 2.Modify students records \n\t\t\t\t\t 3.Search and view Records\n\t\t\t\t\t 4.add and delete a student\n\t\t\t\t\t 5.Exits";
     std::cout<<"\n\t\t\t\t\t Choose options:[1/2/3/4/5]\n\t\t\t\t\t";
     std::cin>>input;
}
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
   //std::this_thread::sleep_for(std::chrono::milliseconds(700));
   exit(0);
}
}

void record_modifier(){
     
     std::cout<<"\t\t\t\t<<student modifying file page>>";
     std::string fname,lname,g_pa,magor;
     std::string ID;
     std::cin.ignore();
     std::cout<<"\n enter sudents ID for modifying:";
     getline(std::cin,ID);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     int catcher=id_exist(ID);
     
     while(id_exist(ID)!=1){
          std::cout<<strerror(22)<<std::endl;
          std::cout<<"enter a valid ID(enter 1 to go to leading screen):";
          getline(std::cin,ID);
          if(ID=="1"){
               mainscreen();
               break;
          }
     };
     
     std::string Snumber=student_number("data.txt",ID);
    
   //reading every lines from file    
      
     std::ifstream ifs_obj("data.txt");
     ;
     if(!ifs_obj){
          std::cout<<"\n error loading files!";
          mainscreen();
     };
     
     std::vector <std::string> lines;
     std::string line;
          while(std::getline(ifs_obj,line)){
               lines.push_back(line);
          }
     ifs_obj.close();

    int inp_choice;

    std::cout<<"choose what part you want to modify:\n1.First name\n2.Last name\n3.GPA\n4.Major\n5.-save and go to Mainscrean\n";
    std::cin>>inp_choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(1){

     while(inp_choice<1||inp_choice>5){
     std::cout<<strerror(22)<<"\nenter a valid number\nchoose what part you want to modify:\n1.First name\n2.Last name\n3.GPA\n4.Major\n5.-save and go to Mainscrean\n";
          std::cin>>inp_choice;
     };
     

    if(inp_choice==1){ 
     std::string newfirstname;
     std::cout<<"\n\t\t\t enter your new firstname:";
     std::getline(std::cin,newfirstname);
      
     if(newfirstname=="" || newfirstname==" "){
              std::cout<<"error accured!";
              mainscreen();
          };
          
     loopingfile( lines,"Firstname", Snumber, newfirstname);
        
     };
    if(inp_choice==2){ 
        std::string newlastname;
     std::cout<<"\n\t\t\t enter a new lastname:";
     std::getline(std::cin,newlastname);
     if(newlastname=="" || newlastname==" "){
              std::cout<<"error accured!";
              mainscreen();
          };
    
     loopingfile( lines,"Lastname", Snumber, newlastname);
      
     };
    if(inp_choice==3){
       std::string newgpa;
     std::cout<<"\n\t\t\t enter a new gpa:";
     std::getline(std::cin,newgpa);
     if(newgpa=="" || newgpa==" "){
              std::cout<<"error accured!";
              mainscreen();
          };
    
     loopingfile( lines,"gpa", Snumber, newgpa);
      
     };
    if(inp_choice==4){
      std::string newmajor;
     std::cout<<"\n\t\t\t enter a new major:";
     std::getline(std::cin,newmajor);
     if(newmajor=="" || newmajor==" "){
              std::cout<<"error accured!";
              mainscreen();
          };
    

     loopingfile( lines,"major", Snumber, newmajor);
      
    
};
    if(inp_choice==5){
          std::ofstream outfile("data.txt");
         for(const auto &line :lines){
          outfile<<line<<"\n";
         };
         outfile.close();
          std::cout<<"data editing complited";
          mainscreen();
     }


     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"edited!\nchoose what part you want to modify:\n1.First name\n2.Last name\n3.GPA\n4.Major\n5.-save and go to Mainscrean\n";
    std::cin>>inp_choice;

};
}

void search_print(){
     
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string ID;
    std::cout<<"\t\t\t\t\tstudent finder\nenter student ID:";
    getline(std::cin,ID);

    while(id_exist(ID)!=1){
     std::cout<<strerror(22)<<std::endl;
    std::cout<<"enter a valid ID(enter 1 to go to leading screen):";
    getline(std::cin,ID);
    

    if(ID=="1"){
    mainscreen();
    break;
    }
    }   
    
    std::string student_num=student_number("data.txt",ID);

std::map<std::string,std::string> configuration;
std::ifstream the_file("data.txt");
std::string line;    

while(getline(the_file,line)){
std::string key,value;
std::stringstream ss(line);
getline(ss,key,':');
ss>>std::ws;
getline(ss,value);
configuration[key]=value;
};
std::cout<<"firstname:"<<configuration["Firstname"+student_num];
std::cout<<"\nlastname:"<<configuration["Lastname"+student_num];
std::cout<<"\nId:"<<ID;
std::cout<<"\nGPA:"<<configuration["gpa"+student_num];
std::cout<<"\nMajor:"<<configuration["major"+student_num];
std::cout<<"\n  Enter to go mainscreen ..."<<std::endl;
//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
std::cin.get();
mainscreen();
};

void add_delete_s(){
     
     std::cout<<"\t\t\t\t\t<<adding deleting page>>\n\n";
     std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
     
     int input1;

     std::cout<<"1-adding a student.\n2-deleting a student file\n";
     std::cin>>input1;
     while(input1<1||input1>3||std::cin.fail()){
          std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
          std::cout<<strerror(22)<<"\n1-adding a student.\n2-deleting a student file\n3-go to leading screen\n";
          std::cin>>input1;
          if(input1==3){
               mainscreen();
          }
     
     };
     
     if(input1==1){
     std::cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');
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
          
          //*****declaring and sving to the base 
          std::ofstream to_add_file;
          to_add_file.open("data.txt",std::ios::out|std::ios::app);
          to_add_file<<"\nFirstname"<<student_numbers<<":"<<fname;
          to_add_file<<"\nLastname"<<student_numbers<<":"<<lname;
          to_add_file<<"\nid"<<student_numbers<<":"<<id;
          to_add_file<<"\ngpa"<<student_numbers<<":"<<gpa;
          to_add_file<<"\nmajor"<<student_numbers<<":"<<major<<"\n\n";

          to_add_file.close();
          student_numbers++;
          saveStudentNums(student_numbers);
          std::cout<<"student added susccesfuly"; 
          mainscreen();

     }else if(input1==2){
          
          std::cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');
          std::string   s_id;
          std::cout<<"\n\t\t\t enter the student ID:";
          std::cin>>s_id;
          while(id_exist(s_id)!=1){
               std::cout<<"Unvalid id!\n enter a valid Id (enter 1 to mainscrean):";
               getline(std::cin,s_id); 
               if(s_id=="1")   mainscreen();
          };

          std::string studentnumber=student_number("data.txt",s_id);
          if(std::stoi(studentnumber)==student_numbers-1){

          deletelastS();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
               std::cout<<"\nstudent profile deleted\n  Enter to go mainscreen ..."<<std::endl;
               std::cin.get();
               mainscreen();
          
          }else{

               std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
               //swap the target student with the last student
               dossier_swaper(studentnumber,(std::to_string(student_numbers-1)));
               //delete the last student that would be the terget
                deletelastS(); 
               std::cout<<"\nstudent profile deleted\n  Enter to go mainscreen ..."<<std::endl;
               std::cin.get();
               mainscreen();
          };


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
               st=1;
          };
     };
     if(st==0){
          return 0;
     }else{
          return 1;
     };

//std::cout<<"this function isn't ready";    
return 0;
};

std::string student_number(const std::string & filename,std::string ID){

std::ifstream ifs_file_obj(filename);
std::string all_lines;
std::string snumber="";
std::string line;

if(!ifs_file_obj.is_open()){
   std::cout<<"error finding file.\n";
    mainscreen();
};

while(getline(ifs_file_obj,all_lines)){
     if(all_lines.find(ID) != std::string::npos){
        ifs_file_obj.close();
         line=all_lines;
     };
     
     
     };
     
     ifs_file_obj.close();
     
     for(int i=2;line[i]!=':';i++){
          snumber=snumber+line[i];
     };
     
     return snumber;
    

};



void dossier_swaper(std::string firststudentN,std::string secondstudentN){
     std::map <std::string,std::string> firstst=studentdatadonor(firststudentN);
     std::map <std::string,std::string> secondst=studentdatadonor(secondstudentN);
   
     //read all lines from file 
     std::ifstream inFile("data.txt");
     std::vector <std::string> lines;
     std::string line;
          while(std::getline(inFile,line)){
               lines.push_back(line);
          }
          inFile.close();

          for(auto& line:lines){
               if(line.find("Firstname"+firststudentN+":")==0){
                    line="Firstname"+firststudentN+":"+secondst["Firstname"+secondstudentN];
               }
               else if(line.find("Firstname"+secondstudentN+":")==0){
                    line="Firstname"+secondstudentN+":"+firstst["Firstname"+firststudentN];
               }
                else if(line.find("Lastname"+firststudentN+":")==0){
                    line="Lastname"+firststudentN+":"+secondst["Lastname"+secondstudentN];
               }
               else if(line.find("Lastname"+secondstudentN+":")==0){
                    line="Lastname"+secondstudentN+":"+firstst["Lastname"+firststudentN];
               }
               else if(line.find("id"+firststudentN+":")==0){
                    line="id"+firststudentN+":"+secondst["id"+secondstudentN];
               }
               else if(line.find("id"+secondstudentN+":")==0){
                    line="id"+secondstudentN+":"+firstst["id"+firststudentN];
               }
               else if(line.find("gpa"+firststudentN+":")==0){
                    line="gpa"+firststudentN+":"+secondst["gpa"+secondstudentN];
               }
               else if(line.find("gpa"+secondstudentN+":")==0){
                    line="gpa"+secondstudentN+":"+firstst["gpa"+firststudentN];
               }
              else if(line.find("major"+firststudentN+":")==0){
                    line="major"+firststudentN+":"+secondst["major"+secondstudentN];
               }
             else if(line.find("major"+secondstudentN+":")==0){
                    line="major"+secondstudentN+":"+firstst["major"+firststudentN];
               }

          }

          //write all the modified lines to the file
          std::ofstream outfile("data.txt");
          for(const auto& line : lines){
          outfile<<line<<"\n";
          }
          outfile.close();
};


std::map <std::string,std::string> studentdatadonor(std::string studentN){
     std::map <std::string,std::string> result;
     std::map <std::string,std::string> configuration;
     std::ifstream file("data.txt");
     std::string line;


     while(getline(file,line)){
          std::string key;
          std::string value;
          std::stringstream ss(line);
          getline(ss,key,':');
          ss>>std::ws;
          getline(ss,value);
     
          configuration[key]=value;
     }
     file.close();
     result["Firstname"+studentN]=configuration["Firstname"+studentN];
     result["Lastname"+studentN]=configuration["Lastname"+studentN];
     result["id"+studentN]=configuration["id"+studentN];
     result["gpa"+studentN]=configuration["gpa"+studentN];
     result["major"+studentN]=configuration["major"+studentN];

     return result;

};


void loopingfile(std::vector<std::string>& all_lines,std::string field,std::string subjnumber,std::string content){

     for(auto & line:all_lines){
         if(line.find(field+subjnumber+":")==0){
          line=field+subjnumber+":"+content;
         }; 
     };
}

void deletelastS(){
     std::ifstream infile("data.txt");
     std::vector<std::string> all_lines;
     std::string line;
     while(std::getline(infile,line)){
          all_lines.push_back(line);
     }
     infile.close();

     if(all_lines.size()>=7){
          all_lines.resize(all_lines.size()-7);
     };
     std::ofstream outfile("data.txt");
     for(const auto & line:all_lines){
          outfile<<line<<"\n";
     }
     outfile.close();
     student_numbers--;
     saveStudentNums(student_numbers);

}


int readStudentNums(){
     std::ifstream inFile("Pstudentnumbers.dat");
     int value =0;
     if(inFile){
          inFile >>value;
     }
     return value;
}

void saveStudentNums(int count){
     std::ofstream outfile("Pstudentnumbers.dat");
     if(outfile){
          outfile<<count;
     };

};


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





 // *********record modifier deteils: 
 /*
std::map <std::string,std::string> config;
std::ifstream Rfile("data.txt");
std::string if_lines;

    while(getline(Rfile,if_lines)){ //it will loop through every line
    std::string key;
    std::string value;
    std::stringstream ss(if_lines);
    getline(ss,key,':');
    ss>>std::ws;
    getline(ss,value);

    config[key]=value; //storing them
    };
      R_file.close();
*/