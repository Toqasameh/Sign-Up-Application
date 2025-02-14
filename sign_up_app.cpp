#include <iostream>
#include <array>
#include <string>
using namespace std;

/************************************************ */
                //    Enums
/************************************************ */
enum class Option{
    addRecord=1,
    fetchRecord=2,
    quit=3
};

/************************************************ */
               // initial values
/************************************************ */

constexpr int INITIAL_VALUE=0;
constexpr int TOTAL_RECORDS=100;
static int record_count=0;
Option DEFAULT_OPTION= Option::addRecord;

/************************************************ */
          // functions
/************************************************ */

void to_string(Option i){

  switch (i){
   
   case Option::addRecord :
   cout <<"1-Add Record \n";
   break;

   case Option::fetchRecord :
   cout <<"2-Fetch Record \n" ;
   break;

   case Option::quit :
   cout <<"3-Quit \n" ;
   break;
  }
 

}

Option select_option(){
    Option opt=DEFAULT_OPTION;
    cin>>opt; 
   return opt;
  
  }

/***********  cin operator overloadig **************** */
istream& operator >> (istream& input_stream , Option &result){

    int int_option;
    input_stream>>int_option; // takes integer value
   // convert intger value ----> to option enum;
    result= static_cast<Option> (int_option); 
   return input_stream;
}


/************************************************ */
 //               classes
/************************************************ */

class Menu{

public :
 array<Option,3>options
 {Option::addRecord ,Option::fetchRecord, Option::quit };

 void show(){
    cout <<"Please select an option \n";
     for(Option i : options ){
        to_string(i);
   }
}
};

class Record {

public :
string name;
int age;

};


/************************************************ */
//        functions
/************************************************ */
 /* glopal array decleration*/ 
array<Record,TOTAL_RECORDS>records;

void addRecord(string name,int age){
 records[record_count]={name,age};
 record_count++;
cout<<"user record added successfully\n";
cout<<"**************************************\n";

}

void fetchRecord(int id){

   cout<<"User Name : "<<records[id].name<<"\n";
   cout<<" Age: "<<records[id].age<<"\n";
   cout<<"**************************************\n";
}

 /****************** main program *****************************/
int main(){
 
    Menu new_menue;
    string name;
    int age=INITIAL_VALUE;
    int ID=INITIAL_VALUE;
   
    while (true){

    new_menue.show();
    Option opt = select_option ();

    switch(opt){

    case Option::addRecord :
    cout<<"please Enter user name and age\n";
    cin>>name>>age;
    addRecord(name,age);
    break;

    case Option::fetchRecord :
    cout<<"please Enter user ID \n";
    cin>>ID;
    fetchRecord(ID);
    break;
    case Option::quit :
         return 0;
    break;

    }
    }
}
