#include <iostream>
using namespace std;

struct Student
{
    string id;
    string name;
    double gpa;
    Student(){}
    Student(string id,string name,double gpa){
        this->gpa = gpa;
        this->id = id;
        this->name = name;
    }
};

class StudentList{
    private:
     Student* list;
     int capacity;
     int size;

     public:
     StudentList(int capacity){
        this->capacity = capacity;
        size = 0;
        list = new Student[capacity];
     }

    private:
     void resize(){
        capacity*=2;
        Student* newList = new Student[capacity];
        for (int i =0;i<size;i++){
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
     }

    public:
     void addStudent(string id,string name,double gpa){
        Student s(id,name,gpa);
        if(size==capacity){
            resize();
        }
        list[size] = s;
        size++;
     }

     void insertStudent(int index,string id,string name,double gpa){
        Student s(id,name,gpa);
        if(index<0 || index>size){
            cout << "Invalid Index!"<< endl;
            return;
        }
        if(size==capacity){
            resize();
        }
        for (int i = size;i>index;i--){
            list[i] = list[i-1];
        }
        list[index] = s;
        size++;
     }
    void removeStudent(string id){
    int index = -1;
    for(int i = 0;i<size;i++){
        if(list[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "Student not Fund!" << endl;
        return;
    }
    
        for(int i = index;i<size-1;i++){
            list[i] = list[i+1];
        }
        size--;
    
}

void updateGpa(string id,double newgpa){
    int index = -1;
    for(int i = 0;i<size;i++){
        if(list[i].id == id){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "Student not Found!" << endl;
        return;
    }
        list[index].gpa = newgpa;
        cout << "GPA of "<< list[index].name << " updated Successfully!" <<endl;
    
}


void displayList(){
    if(size==0){
        cout << "List is Empty!"<< endl;
        return;
    }
    else{
        for (int i = 0;i< size;i++){
            cout << "[ Student ID: " << list[i].id <<", Name: "<< list[i].name
            << ", GPA: " << list[i].gpa << " ]" << endl; 
        }
    }
}

void highestGPA(){
    if(size==0){
        cout << "List is Empty!"<< endl;
        return;
    }
    else {
        int highIndex = 0;
        for(int i = 1;i<size;i++){
            if(list[highIndex].gpa<list[i].gpa){
                highIndex = i;
            }
        }
        cout << "Student having High GPA amoung all is :" << endl; 
        cout << "[ Student ID: " << list[highIndex].id <<", Name: "<< list[highIndex].name
            << ", GPA: " << list[highIndex].gpa << " ]" << endl; 
    }
}
     
};




int main(){

    StudentList list(5);
    list.addStudent("SP25-BSE-063","Hafiz Ahmad Husnain",3.83);
    list.addStudent("SP25-BSE-024","Ali Adress",3.88);
    list.addStudent("SP25-BSE-044","Usama Saeed",3.76);
    list.addStudent("SP25-BSE-045","Awais Aslam",3.56);
    list.addStudent("SP25-BSE-050","Abdur Rehman",3.80);
    list.displayList();
    cout << "____________________________________" << endl;
    cout << "After Manipulation: "<< endl;

    list.insertStudent(0,"SP25-BSE-019","Sharjeel Saleem",3.5);

    list.removeStudent("SP25-BSE-050");

    list.updateGpa("SP25-BSE-019",3.6);

    cout << "____--Student List--____"<<endl;
    list.displayList();
    cout << "____________________________________" << endl;

    list.highestGPA();
    return 0;
}