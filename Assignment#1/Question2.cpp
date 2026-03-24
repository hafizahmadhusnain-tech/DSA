#include <iostream>
using namespace std;

struct Patient
{
    int id;
    string name;
    string diease;
    Patient* next;
    Patient(int id,string name,string diease){
        this->id = id;
        this->name = name;
        this->diease = diease;
        next = NULL;
    }
};

class PatientList{
    Patient* head;
    public:
    PatientList(){
        head = NULL;
    }

    void addPatient(int id,string name,string disease){
        Patient* newPatient = new Patient(id,name,disease);
        if(head==NULL){
            head = newPatient;
            cout << "Patient with ID " << id << " added successfully!"<< endl;
            return;
        }
        else{
            Patient* temp = head;
            while(temp->next !=NULL){
                temp = temp->next;
            }
            temp->next = newPatient;
                cout << "Patient with ID " << id << " added successfully!"<< endl;
        }
    }

    void EmergencyCase(int id,string name,string disease){
        Patient* newPatient = new Patient(id,name,disease);
        if(head==NULL){
            head = newPatient;
            cout << "Patient with ID " << id << " added successfully!"<< endl;
            return;
        }
        else{
            Patient* temp = head;
            newPatient->next = temp;
            head = newPatient;
                cout << "Patient with ID " << id << " added successfully!"<< endl;
        }
    }
    void deletePatient(int id){
        if(head==NULL){
            cout << "List is Empty!"<< endl;
            return;
        }
        else if(head->next== NULL){
            head==NULL;
            cout << "Patient with ID " << id << " deleted successfully!"<< endl;
            return;
        }
        else{
        Patient* temp = head;
        
        while(temp->next!=NULL){
            if(temp->next->id == id){
                Patient* save = temp->next->next;
                temp->next = NULL;
                temp->next = save;
                cout << "Patient with ID " << id << " deleted successfully!"<< endl;
                return;
            }
            temp = temp->next;
        }
    }
    }

    void searchPatient(int id){
        if(head==NULL){
            cout << "List is Empty!"<< endl;
            return;
        }else{
        Patient* temp = head;
        
        while(temp!=NULL){
            if(temp->id == id){
                cout << "[ Name: " + temp->name << ", ID: " << temp->id
                << ", Disease: " + temp->diease + " ]\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not Found!\n";
    }
}

void displayList(){
    if(head==NULL){
            cout << "List is Empty!"<< endl;
            return;
        }else{
        Patient* temp = head;
        
        while(temp!=NULL){
            
                cout << "[ Name: " + temp->name << ", ID: " << temp->id
                << ", Disease: " + temp->diease + " ] -->";
                temp = temp->next;
        }
        cout << " NULL";
            
        }
}


};


int main(){

    PatientList pl;
    pl.addPatient(2,"ali","fever");
    pl.addPatient(3,"ahmed","cough");
    pl.EmergencyCase(5,"Danish Ali","Psycho");
    cout << "---__Patient Search__--- \n";
    pl.searchPatient(5);
    cout << "---__Patient Delete__--- \n";
    pl.deletePatient(3);
    cout << "---__Patient List__--- \n";
    pl.displayList();

    return 0;
}