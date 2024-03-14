#include<iostream>
#include<string.h>
#include<sqlite3.h>
#include <fstream>
#include<conio.h>
#include<iomanip>
#include <cstring>
#include<HashTable.h>

using namespace std;

void connection();
void Insert();
void retrieve();
void Delete();
void Update();
sqlite3 *db;
sqlite3_stmt *stmt;
int sqlit3_step;
int rc, roll;

string query;

string TId, TName,TDept, TQual, TGender, TExp,TAge, TPhone, TSalary,TYearInSchool;

// YUN VANNWT (LINE 26 TO 250 )
struct Teacher {

    string TeacherId;
    string TeacherName;
    string TeacherDept, TeacherQual;
    string TeacherGender, TeacherExp;
    string TeacherAge, TeacherPhone, TeacherSalary, TeacherYearInSchool;


    int key;

    Teacher* left, *right;

    Teacher* next;
};

Teacher* newTeacher(int key)
{
    Teacher* teacher = new Teacher;
    teacher->key = key;
    teacher->left = teacher->right = NULL;
    return (teacher);
}

Teacher* Head = new Teacher();

bool Check(string y){ //

    if (Head == NULL)
        return false;

    Teacher* k = new Teacher;
    k = Head;


    while (k != NULL) {
        if (k->TeacherId == y)
            return true;
        k = k->next;
    }

    return false;
}


void Insert_Teacher(string TeacherName, string TeacherDept, string TeacherGender, string TeacherExp, string TeacherQual,
                    string TeacherId, string TeacherAge ,string TeacherPhone, string TeacherSalary, string TeacherYearInSchool){


    if (Check(TeacherId)) {
        cout << "Teacher with this "
             << "record Already Exists\n";

        return;
    }


    Teacher* k = new Teacher();
    k->TeacherId = TeacherId;
    k->TeacherName = TeacherName;
    k->TeacherGender = TeacherGender;
    k->TeacherDept = TeacherDept;
    k->TeacherAge = TeacherAge;
    k->TeacherPhone = TeacherPhone;
    k->TeacherSalary = TeacherSalary;
    k->TeacherYearInSchool = TeacherYearInSchool;
    k->TeacherExp = TeacherExp;
    k->TeacherQual = TeacherQual;

    k->next = NULL;


    if (Head == NULL
        || (Head->TeacherId >= k->TeacherId)) {
        k->next = Head;
        Head = k;
    }


    else {
        Teacher* b = Head;
        while (b->next != NULL
               && b->next->TeacherId < k->TeacherId) {
            b = b->next;
        }
        k->next = b->next;
        b->next = k;
    }

    cout << "RECORD INSERTED SUCCESFULLY\n";
}

void Search_Teacher(string TeacherId)
{

    if (!Head) {
        cout << "NO SUCH RECORD AVAILABLE\n";
        return;
    }


    else {
        Teacher* p = Head;
        while (p) {
            if (p->TeacherId == TeacherId) {
                cout << "Name: ";
                cout << p->TeacherName << endl;
                cout << "ID: ";
                cout << p->TeacherId << endl;
                cout << "Gender: ";
                cout << p->TeacherGender << endl;
                cout << "Department: ";
                cout << p->TeacherDept << endl;
                cout <<"Age: ";
                cout << p->TeacherAge <<endl;
                cout <<"Phone number: ";
                cout << p->TeacherPhone<<endl;
                cout << "Salary: ";
                cout << p->TeacherSalary << endl;
                cout << "Experience: ";
                cout << p->TeacherExp << endl;
                cout << "Year In School: ";
                cout << p->TeacherYearInSchool << endl;
                cout << "Quality: ";
                cout << p->TeacherQual << endl;
                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "NO SUCH RECORD AVAILABLE" << endl;
    }
}


int Delete_Teacher(string TeacherId)
{
    Teacher* t = Head;
    Teacher* p = NULL;


    if (t != NULL && t->TeacherId == TeacherId) {
        Head = t->next;
        delete t;

        cout << "Deleted teacher Successfully\n";
        return 0;
    }


    while (t != NULL && t->TeacherId != TeacherId) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "ID does not Exist " << endl;
        return -1;
        p->next = t->next;

        delete t;

        return 0;
    }
}


void Show_Teacher()
{
    Teacher* i = Head;
    if (i == NULL) {
        cout << "No Record Available " << endl;
    }
    else {
        cout << "\n========================================================================================================================\n";
        cout << left << setw(7) << "NAME";
        cout << setw(7) << "ID";
        cout << setw(10) << "GENDER";
        cout << setw(15) << "DEPARTMENT";
        cout << setw(7) << "AGE";
        cout << setw(7) << "PHONE";
        cout << setw(10) << "SALARY";
        cout << setw(15) << "EXPERIENCE";
        cout << setw(25) << "QUALITY_OF_STUDYING";
        cout << setw(7) << "YEAR_IN_SCHOOL" << endl;
        cout << "\n========================================================================================================================\n";
        cout << "\n========================================================================================================================\n";

        while (i != NULL) {
            cout << "\n" << left;
            cout << setw(7) << i->TeacherName ;
            cout << setw(7) << i->TeacherId;
            cout << setw(10) << i->TeacherGender;
            cout << setw(15) << i->TeacherDept;
            cout << setw(7) << i->TeacherAge;
            cout << setw(7) << i->TeacherPhone;
            cout << setw(10) << i->TeacherSalary;
            cout << setw(15) << i->TeacherExp;
            cout <<setw(25) << i->TeacherQual;
            cout << setw(7) << i->TeacherYearInSchool << endl;

            i = i->next;
        }
        cout << "\n========================================================================================================================\n";
    }
}
void Edit_Teacher(string TeacherId){
    if (!Head) {
        cout << "NO SUCH RECORD AVAILABLE\n";
        return;
    }
     else {
        Teacher* p = Head;
        while (p) {
        if (strcmp, p->TeacherId == TeacherId) {
        cout << "Edit teacher successfully. " << endl;
                return;
            }
            p = p->next;
        }

     }
}


// TRY CHI ENG(252 TO 507)
struct Student {

    string Id;
    string Name;
    string Dept;
    string Gender;
    string Room;
    int Age, Phone;
    float Fee;
    float Math, Physic, Chemistry, Computer, English, France, Tp;
    int key;

    Student* left, *right;

    Student* next;
};

Student* newStudent(int key)
{
    Student* student = new Student;
    student->key = key;
    student->left = student->right = NULL;
    return (student);
}


int Sum(Student* root)
{
    if (root == NULL)
        return 0;
    return (root->key + Sum(root->left) + Sum(root->right));
}



Student* head = new Student();


bool check(string x)
{

    if (head == NULL)
        return false;

    Student* t = new Student;
    t = head;


    while (t != NULL) {
        if (t->Id == x)
            return true;
        t = t->next;
    }

    return false;
}


void Insert_Student(string Id, string Name, string Dept, string Gender, string Room,
                        int Age,int Phone, float Fee, float Math, float Physic, float Chemistry,
                        float Computer, float English, float France, float Tp){


    if (check(Id)) {
        cout << "Student with this "
             << "record Already Exists\n";

        return;
    }


    Student* t = new Student();
    t->Id = Id;
    t->Name = Name;
    t->Gender = Gender;
    t->Dept = Dept;
    t->Room = Room;
    t->Age = Age;
    t->Phone = Phone;
    t->Fee = Fee;
    t->Math = Math;
    t->Physic = Physic;
    t->Chemistry = Chemistry;
    t->Computer = Computer;
    t->English = English;
    t->France = France;
    t->Tp = Tp;

    t->next = NULL;


    if (head == NULL
        || (head->Id >= t->Id)) {
        t->next = head;
        head = t;
    }


    else {
        Student* c = head;
        while (c->next != NULL
               && c->next->Id < t->Id) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << "RECORD INSERTED "
         << "SUCCESFULLY\n";
}


void Search_Student(string Id)
{

    if (!head) {
        cout << "NO SUCH RECORD "
             << "AVAILABLE\n";
        return;
    }


    else {
        Student* p = head;
        while (p) {
            if (p->Id == Id) {
                cout << "Name: ";
                cout << p->Name << endl;
                cout << "ID: ";
                cout << p->Id << endl;
                cout << "Gender: ";
                cout << p->Gender << endl;
                cout << "Department: ";
                cout << p->Dept << endl;
                cout <<"Numbers room: ";
                cout << p->Room <<endl;
                cout <<"Age: ";
                cout << p->Age <<endl;
                cout <<"Phone number: ";
                cout << p->Phone<<endl;
                cout << "Annual fee: ";
                cout << p->Fee << endl;
                cout << "Math: ";
                cout << p->Math << endl;
                cout << "Physic: ";
                cout << p->Physic << endl;
                cout << "Chemistr: ";
                cout << p->Chemistry << endl;
                cout << "Computer: ";
                cout << p->Computer << endl;
                cout << "English: ";
                cout << p->English << endl;
                cout << "France: ";
                cout << p->France << endl;
                cout << "TP: ";
                cout << p->Tp << endl;
                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "NO SUCH RECORD "
                 << "AVAILABLE" << endl;
    }
}


int Delete_Student(string Id)
{
    Student* t = head;
    Student* p = NULL;


    if (t != NULL
        && t->Id == Id) {
        head = t->next;
        delete t;

        cout << "Deleted students "
             << "Successfully\n";
        return 0;
    }


    while (t != NULL && t->Id != Id) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "ID does not Exist " << endl;
        return -1;
        p->next = t->next;

        delete t;
        cout << " DELETE INFORMATION OF STUDENT  "
             << "SUCCESSFULLY" << endl;

        return 0;
    }
}


void Show_Student()
{
    Student* p = head;
    if (p == NULL) {
        cout << "No Record "
             << "Available " << endl;
    }
    else {
        cout <<"\n======================================================================================================\n";
        cout<<left<<setw(7)<<"NAME"
        <<setw(7)<<"ID"
        <<setw(7)<<"GENDER"
        <<setw(7)<<"DEP"
        <<setw(7)<<"ROOM"
        <<setw(7)<<"AGE"
        <<setw(7)<<"PHONE"
        <<setw(7)<< "FEE"
        <<setw(7)<<"MATH"
        <<setw(7)<<"PHY"
        <<setw(7)<<"CHE"
        <<setw(7)<<"COMP"
        <<setw(7)<<"ENG"
        <<setw(7)<<"FRA"
        <<setw(7)<<"TP" << endl;
    cout <<"\n===========================================================================================================\n";
    cout <<"\n===========================================================================================================\n";
        // Until p is not NULL
        while (p != NULL) {
            cout <<"\n"<<left
            <<setw(7)<<p->Name
            <<setw(7)<< p->Id
            <<setw(7)<< p->Gender
            <<setw(7) << p->Dept
            <<setw(7) << p->Room
            <<setw(7)<< p->Age
            <<setw(7) << p->Phone
            <<setw(7)<< p->Fee
            <<setw(7)<< p->Math
            <<setw(7)<< p->Physic
            <<setw(7)<< p->Chemistry
            <<setw(7)<< p->Computer
            <<setw(7) << p->English
            <<setw(7) << p->France
            <<setw(7)<< p->Tp << endl;

            p = p->next;
        }
          cout << "\n========================================================================================================\n";
    }
}
// SIN UDORM(LINE 507 TO 621)
class Books{
	private:
		int code;
		string name;
		string depatment;

	public:
		Books(){
			code =0;
			name ="N/A";
			depatment ="N/A";
		}
		int getCode(){
			return code;
		}
		void setName(string n){
			name=n;
		}
		void setDepatment(string d){
			depatment=d;
		}

		void input(){
			cout<<"=====Input===="<<endl;
			cout<<"Input Code: "; cin>>code;
			cout<<"Input Name of Book: ";cin>>name;
			cout<<"Input Kinds of Book: ";cin>>depatment;
		}
		void output(){
			cout<<"====Output===="<<endl;
			cout<<code<<"  "<<name<<" "<<depatment<<endl;
		}

};
int search(Books books[5000],int n){
	int scode,b=0;
	int index=-1;
	cout<<"Input Code to Search: "; cin>>scode;
	for(int i=0; i<n; i++){
		if(books[i].getCode()==scode)
		{
			b=1;
			books[1].output();
			index=i;
			break;
		}
	}
	if(b==0) cout<<"Search not found\n";
	return index;
}
struct StudentL{

 string name;
 StudentL *next;

};
struct Queue{

 int n;
 StudentL *rear_, *front_;

};
Queue *createEmptyQueue(){
    Queue *q;
    q = new Queue;
    q->n = 0;
    q->front_ = NULL;
    q->rear_ = NULL;

    return q;
}
void enqueue(Queue *q, string newName){

    StudentL *s;
    s = new StudentL;
    s->name = newName;
    s->next = NULL;

    if(q->n ==0){
        q->front_ = s;
        q->rear_ =s;
        q->n = q->n + 1;
    }
    else{
        q->rear_ ->next =s;
        q->rear_ =s;
        q->n = q->n + 1;
    }
}
void dequeue(Queue *q){

    if(q->n ==0){
        cout<<"Can not delete! Queue is empty! Underflow!\n";

    }
    else{
        StudentL *t;
        t =q->front_;
        q->front_ =q->front_ ->next;
        cout<<"\t Deleted "<<t->name<<"\n";
        delete t;
        q->n = q->n -1;
    }
}
void displayQueue(Queue *q){
    StudentL *s;
    s = q->front_;

    while(s!=NULL){
        cout<<s->name<<" ";
        s = s->next;
    }
    cout<<"\n";
}
//SET SOPHY (LINE 622 TO 819)
class Librar {
    private:
    int BID;
    char BName[20];
    char BkAuthor[50];
    int BcellNo;
    char date[10];

  public:
    void getData ();
    void showData ();
    int getBookId (){
        return BID;
}
};
void Librar::getData ()
{
    cout << "\n\n........Enter Book Details......\n";
    cout << "Enter Book ID : ";
    cin >> BID;

    cout << "Enter Book Name : ";
    cin.ignore ();
    cin.getline (BName, 20);
    cout << "Enter Book Author : ";
    cin.ignore ();
    cin.getline (BkAuthor, 50);
    cout << "Enter Book Location cell #: ";
    cin >> BcellNo;
    cout << "Enter Book borrowed date MM/DD/YYYY: ";
    cin >> date;
    cout << endl;
}

void Librar::showData ()
{
    cout << "\n\n.......Book Details......\n";
    cout << "Book ID : " << BID << endl;
    cout << "Book Name : " << BName << endl;
    cout << "Book Author : " << BkAuthor << endl;
    cout << "Book Location cell #: " << BcellNo << endl;
    cout << "Book borrowed Date: " << date << endl;
    cout << endl;
}

void AddBook ()
{
    Librar b;
    fstream wdf;
    wdf.open ("Bookitc.txt",  ios::app);
    b.getData ();
    wdf.write ((char *) &b, sizeof (b));
    wdf.close ();
    cout << "\n\nBook Successfully Saved....\n";
}

void DisplayBook ()
{
     Librar b;
    fstream rdf;
    rdf.open ("Bookitc.txt", ios::in );
    while (rdf.read ((char *) &b, sizeof (b))) {
        b.showData ();
    }
    rdf.close ();
  cout << "\n\nData Reading from File Successfully Done....\n";
}

void SearchBook ()
{
     Librar b;
    int n, boo = 0;
    ifstream rdf;
    rdf.open ("Bookitc.txt", ios::in );
    cout << "Enter Book ID you want to search : ";
    cin >> n;

    while (rdf.read ((char *) &b, sizeof (b))) {
        if (n == b.getBookId ()) {
            cout << "The details of Book ID " << n << " are:\n";
            b.showData ();
            boo++;
        }
    }
    rdf.close ();
    if (boo == 0)
        cout << "The Book Id " << n << " not found....\n\n";
    cout << "\n\nData Reading from File Successfully Done....\n";
}

void DeleteBook ()
{    Librar b;
    int n, boo = 0, result;

    fstream wdf, ofs, rdf;

    rdf.open ("Bookitc.txt", ios::in );
    wdf.open ("TemporayBook.txt",  ios::out|ios::binary );
    ofs.open ("BinBook.txt", ios::out | ios::app );

    cout << "Enter Book ID you want to move to Trash : ";
    cin >> n;

    while (rdf.read ((char *) &b, sizeof (b))) {
        if (n == b.getBookId ()) {
            cout << "The Following Book ID " << n <<
                " has been moved to Bin:\n";
            b.showData ();
            ofs.write ((char *) &b, sizeof (b));
            boo++;
        } else {
            wdf.write ((char *) &b, sizeof (b));
        }
    }
    wdf.close ();
    ofs.close ();
    rdf.close ();
    if (boo == 0)
        cout << "The Book ID " << n << " not found....\n\n";
    remove ("Bookitc.txt");
    result = rename ("tempBook.txt", "Bookitc.txt");
    cout << result;
}

void BinOfBook ()
{    Librar b;
    fstream rdf;
    rdf.open ("TrashBook.txt", ios::app );
    while (rdf.read ((char *) &b, sizeof (b))) {
        b.showData ();
    }
    rdf.close ();
    cout << "\n\nData Reading from Bin File Successfully Done....\n";
}

void UpdateBook ()
{    Librar b;
    int n, boo = 0, position;
    fstream rwf;

    rwf.open ("Bookitc.txt", ios::in | ios::out );

    cout << "Enter Book ID  to edit : ";
    cin >> n;

    while (rwf.read ((char *) &b, sizeof (b))) {
        position = rwf.tellg ();
        if (n == b.getBookId ()) {
            cout << "The Following Book ID " << n <<
                " will be edit :\n";
            b.showData ();
            cout << "\n\n Enter the New Details....\n";
            b.getData ();
            const __int64 Z = position - static_cast < __int64 > (sizeof (b));
            rwf.seekg (Z);
            rwf.seekg(position-sizeof(b));
            rwf.write ((char *) &b, sizeof (b));
            boo++;
        }
    }
    rwf.close ();

    if (boo == 0)
        cout << "The Book ID " << n << " not found....\n\n";
}

struct StaffTable{

    string room[100];
int x =100, top =- 1;
void push ( string table ) {
if ( top >= x-1)
cout << " Have limited :" << endl;
else {
top++;
room [top] = table;
}
}
void pop() {
if ( top <= -1)
cout << " Don't have tables " << endl;
else {
cout << " Table took out the room "<< room[top] << endl;
top--;
}
}
void show() {
if ( top >= 0) {
cout << " Room has table such as : " ;
for ( int i =top; i >= 0; i--)
cout << room[i] << " ";
cout << endl;
} else
cout << " Room is empty table ";


}
};
//TRY CHI ENG (LINE 819 TO 1018)
struct Staff{
public:
    string ID;
    string Name;
    string Gender;
    string Phone;
    int Age;
    Staff *next;
};

Staff *start_ptr = NULL;
Staff *current;
int choice = 0;

void insert(){
    Staff *temp;
    Staff *temp2;


    temp = new Staff;
    cout << "Enter name of staff: ";
    cin >> temp->Name;
    cout << "Enter ID of staff: ";
    cin >> temp->ID;
    cout << "Enter gender of staff: ";
    cin >> temp->Gender;
    cout << "Enter age of staff: ";
    cin >> temp->Age;
    cout << "Enter phone number of staff: ";
    cin >> temp->Phone;

    temp->next=NULL;


    if(start_ptr==NULL){
        start_ptr=temp;
        current=start_ptr;
    }
    else{
        temp2=start_ptr;

        while(temp2->next != NULL){
            temp2 = temp2->next;

        }
        temp2 -> next = temp;
    }
}
Staff* HEAD = new Staff();
void Search_Staff(string ID)
{

    if (!HEAD) {
        cout << "NO SUCH RECORD "
             << "AVAILABLE\n";
        return;
    }


    else {
    cout << "Enter ID of staff to search: ";
    cin >> ID;
        Staff* p = HEAD;
        while (p) {
            if (p->ID == ID) {
                cout << "Name: ";
                cout << p->Name << endl;
                cout << "ID: ";
                cout << p->ID << endl;
                cout << "Gender: ";
                cout << p->Gender << endl;
                cout <<"Age: ";
                cout << p->Age <<endl;
                cout <<"Phone number: ";

                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "NO SUCH RECORD AVAILABLE" << endl;
    }
}

void Show_Staff(){
    Staff *temp;
    temp = start_ptr;
    cout << endl << endl;
    if(temp == NULL)
        cout << "THE LIST IS EMPTY. " << endl;
    else{
        while(temp != NULL){
            cout << endl << "NAME\t\tID\t\tGENDER\t\tAGE\t\tPHONE" << endl;
            cout << temp->Name << "\t\t" << temp->ID << "\t" << temp->Gender << "\t\t" << temp->Age << "\t\t" << temp->Phone << endl;
            temp=temp->next;
        }
    }
}
class HashTable
{

public:
    int Hash(const std::string&);
  static const int tableSize = 100;
  Staff* listofStaff[tableSize];
  HashTable();
  ~HashTable();
  void Insert(std::string ID, std::string name);
  void Retrieve(std::string ID);
};
HashTable::HashTable()
{
  for (int i = 0; i < tableSize; i++)
  {
    listofStaff[i] = new Staff;
    listofStaff[i]->Name = " ";
    listofStaff[i]->ID = " ";
    listofStaff[i]->next = NULL;
  }
}
HashTable::~HashTable()
{
  for (int i = 0; i < tableSize; i++)
  {
    delete listofStaff[i];
  }
}
void HashTable::Insert(std::string ID, std::string name)
{
  int location = Hash(ID);

  if (listofStaff[location]->ID == "")
  {
    listofStaff[location]->ID= ID;
    listofStaff[location]->Name = name;
  }
  else
  {
    Staff* ptr = listofStaff[location];
    Staff* newStaff = new Staff;
    newStaff->Name = name;
    newStaff->ID = ID;
    newStaff->next = NULL;

    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = newStaff;
  }

}
void HashTable::Retrieve(std::string ID)
{
  int location = Hash(ID);
  bool foundStaff;
  std::string Name;

  Staff* ptr = listofStaff[location];
  while (ptr != NULL)
  {
    if (ptr-> ID == ID);
    {
      foundStaff = true;
      Name = ptr->Name;
    }
    ptr = ptr->next;
  }

  if (foundStaff  == true)
  {
    std::cout << "------------------------------\n";
    std::cout << " Name of Employee: " << Name << std::endl;
    std::cout << "------------------------------\n";
  }
  else
  {
    foundStaff = false;
    std::cout << "---------------------------------\n";
    std::cout << " No Employee exist with that ID" << std::endl;
    std::cout << "----------------------------------\n";
  }

}
int HashTable::Hash(const std::string& key)
{
  int hashVal = 0;
  for (int i = 0; i < key.length(); i++)
  {
    hashVal = int( 37 * hashVal + key[i]);
  }
  hashVal %= tableSize;

  if (hashVal < 0)
    hashVal += tableSize;

  return hashVal;

}
//PHOUEK SOREYA(LINE 1019 TO 1060 )
void SortDataStaff(){
  const int numNames = 5;
    char name [numNames][20];
    char Last_Name[numNames][20];
    char Sure_Name [1][20];

    cout << "\tPlease enter 5 Staff names to be sorted:\n";
    cout << "\tEnter your full name:" << "\n\n";

    for (int i=0; i<numNames; ++i)
        gets(name[i]);

    cout<< "\n";
    cout<<"***Confirm check***"<<"\n\n";

    for (int i=0; i<numNames; ++i)
        cout << (name[i])<<"\n";

    cout<< "\n***Check Completed***"<< "\n\n";
    cout<< "Press ENTER to continue:";
    cin.get();

      for(int a=1; a<=numNames; a++)
      {
        for(int b=numNames-1; b>=a; b--)
        {

          if(name[b-1] [0] > name[b][0])
          {
            strcpy(Sure_Name [1],name[b-1]);
            strcpy(name[b-1], name[b]);
            strcpy(name[b], Sure_Name[1]);
          }
        }
      }
    cout << "\nHere the name sort by Alphabetical order:" << "\n\n";
    for (int i = 0; i < numNames; i++)
        cout << name[i] << "\n";


}

// Driver code
int main()
{
  //YUN VANNET(LINE 1067 TO 2017 )
    head = NULL;
    Head = NULL;
    Books books[5000];
	int n, op, i,j;

    string name, department, gender;
    int age,phone;
    char username[20];
    char password[20];
    int choice;
    float fee;
    string id,room;
    float math, physic, chemistry, computer, english, france, tp;

    float sum, average;

    string teachername, teacherdepartment, teacherqualification, teacherid;
    string teacherage, teacherexperience, teachernumberofyearinschool, teachersalary;
    string teachergender, teacherphone;

    cout << "\t\t\tYOU MUST ENTER THE USERNAME AND PASSWORD TO LOGIN THE PROGRAM............." << endl << endl;
    cout<<"\t\t\t ENTER USERNAME = ";
    cin>>username;
    cout<<"\t\t\t ENTER PASSWORD = ";
    cin>>password;
    cout << endl;

    while(true){

       if(strcmp(username, "GTR2")== 0 && strcmp(password, "100")== 0 ){
          cout<<"\t\t\t\t\tYOUR LOGIN IS SUCCESS!.......... " << endl;
          cout<<"\t\t\t================================================" << endl;
          cout<<"\t\t\t\tWELCOME TO SCHOOL MANAGERMENT SYSTEM!........... " << endl;
          cout<<"\t\t\t================================================" << endl;

            //Menu of School Management
            cout << "1. Teacher information. " << endl;
            cout << "2. Student information. " << endl;
            cout << "3. Teacher information on Sqlite. " << endl;
            cout << "4. Library for Students . " << endl;
            cout << "5. Library for Staffs . " << endl;
            cout << "6. Staff in the school. " << endl;
            cout << "7. Exit. " << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            cout << endl << endl;

            if (choice == 1){
            while (true){
                cout << "\n\t\tWelcome to Teacher Information. "<<endl<<endl;
                cout << "Press the number to " << endl;
                cout << "1. Add a new teacher. " << endl;
                cout << "2. Search a teacher. " << endl;
                cout << "3. Show all teacher. " << endl;
                cout << "4. Edit teacher. " << endl;
                cout << "5. Delete a teacher. " << endl;
                cout << "6. Exit. " << endl << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cout << endl << endl;

            if (choice == 1){
                cout << "1. Enter the name of teacher: ";
                cin.clear(); cin.ignore();
                getline(cin, teachername);
                cout << "2. Enter ID of teacher: ";
                cin >> teacherid;
                cout << "3. Enter age of teacher: ";
                cin >> teacherage;
                cout << "4. Enter gender of teacher: ";
                cin >> teachergender;
                cout << "5. Enter department which teacher teach: ";
                cin >> teacherdepartment;
                cout << "6. Enter qualification of teaching of teacher: ";
                cin >> teacherqualification;
                cout << "7. Enter teacher experience in the school: ";
                cin >> teacherexperience;
                cout << "8. Enter teacher number of year in school: ";
                cin >> teachernumberofyearinschool;
                cout << "9. Enter teacher salary($): ";
                cin >> teachersalary;
                cout << "10. Enter teacher phone number: ";
                cin >> teacherphone;

                Insert_Teacher(teachername, teacherdepartment, teachergender, teacherexperience, teacherqualification,
                               teacherid, teacherage, teacherphone, teachersalary, teachernumberofyearinschool);

            }
            else if (choice == 2){
                cout << "Enter ID of teacher you want to search: ";
                cin >> teacherid;
                cout << endl;
                cout << "Here are the information of teacher you searched. " << endl << endl;
                Search_Teacher(teacherid);
            }
            else if (choice == 3){
                cout << "Here are the summary information of teacher. " << endl << endl;
                Show_Teacher();
            }

            else if (choice == 4){

                    cout << "Enter teacher ID to edit: ";
                    cin >> teacherid;
                    cout << endl;
                    cout << "Here are the new information of teacher: " << endl;
                    cout << "1. Enter the name of teacher: ";
                    cin.clear(); cin.ignore();
                    getline(cin, teachername);
                    cout << "2. Enter ID of teacher: ";
                    cin >> teacherid;
                    cout << "3. Enter age of teacher: ";
                    cin >> teacherage;
                    cout << "4. Enter gender of teacher: ";
                    cin >> teachergender;
                    cout << "5. Enter department which teacher teach: ";
                    cin >> teacherdepartment;
                    cout << "6. Enter qualification of teaching of teacher: ";
                    cin >> teacherqualification;
                    cout << "7. Enter teacher experience in the school: ";
                    cin >> teacherexperience;
                    cout << "8. Enter teacher number of year in school: ";
                    cin >> teachernumberofyearinschool;
                    cout << "9. Enter teacher salary($): ";
                    cin >> teachersalary;
                    cout << "10. Enter teacher phone number: ";
                    cin >> teacherphone;

                    Edit_Teacher(teacherid);

            }
            else if (choice == 5){
                cout << "Enter ID of teacher you want to delete: ";
                cin >> teacherid;
                Delete_Teacher(teacherid);
            }

            else if (choice == 6){
                cout << "program exited. " << endl;
                exit(0);
            }
            else {
                    cout << "YOUR CHOICE IS NOT CORRECT PLEASE TRY AGAIN"<<endl;

        }
            }
       }

       //TRY CHI ENG (LINE 1218 TO  1285)

            if(choice == 2){
            while (true) {
                cout<<"\n\t\tWelcome to Student Information. "<<endl;
                cout<<"Press the number to"<<endl;
                cout<<"1. Add a new student."<<endl;
                cout<<"2. Search a student."<<endl;
                cout<<"3. Show a student."<<endl;
                cout<<"4. Show Average and result of examation of student. "<<endl;
                cout<<"5. Delete a students."<<endl;
                cout<<"6. Exit."<<endl<<endl;

                cout << "Enter your Choice: ";

                // Enter Your Choice
                cin >> choice;
                cout << endl;

                if (choice == 1) {
                    cout << "1. Enter Name of Student: ";
                    cin.clear(); cin.ignore();
                    getline(cin, name);
                    cout << "2. Enter ID of Student: ";
                    cin >> id;
                    cout << "3. Enter gender of student: ";
                    cin >> gender;
                    cout << "4. Enter Department of Student: ";
                    cin >> department;
                    cout << "5. Enter Math score of student: ";
                    cin >> math;
                    cout << "6. Enter Physic score of student: ";
                    cin >> physic;
                    cout << "7. Enter Chemistry score of student: ";
                    cin >> chemistry;
                    cout << "8. Enter Computer score of student: ";
                    cin >> computer;
                    cout << "9. Enter English score of student: ";
                    cin >> english;
                    cout << "10. Enter France score of student: ";
                    cin >> france;
                    cout << "11. Enter TP score of student: ";
                    cin >> tp;
                    cout << "12. Enter the class of student: ";
                    cin >> room;
                    cout << "13. Enter age of student: ";
                    cin >> age;
                    cout << "14. Enter phone number of student: ";
                    cin >> phone;
                    cout << "15. Enter the annual fee student needs to pay in 1 year: ";
                    cin >> fee;
                    Insert_Student(id, name, department, gender, room, age, phone,
                                       fee, math, physic, chemistry, computer, english, france, tp);
                }

                else if (choice == 2) {
                    cout << "Enter ID of student you want to Search: ";
                    cin >> id;
                    cout << endl;
                    cout << "Here are the information of student you searched. " << endl << endl;
                    Search_Student(id);
                }

                else if (choice == 3){
                cout << "Here are the summary information of student. " << endl << endl;
                    Show_Student();
                }

               // SIN UDORM (LINE 1286 TO 1332)
                else if (choice == 4){
                Student* root = newStudent(math);
                    root->left = newStudent(physic);
                    root->right = newStudent(chemistry);
                    root->left->left = newStudent(computer);
                    root->left->right = newStudent(english);
                    root->right->left = newStudent(france);
                    root->right->right = newStudent(tp);

                 sum =Sum(root);

                average =sum/7;
                cout << endl;
                cout << "Here are the Summation and Average of student. " << endl << endl;
                cout << "Summation of all the score = " << sum << endl;
                cout << "Average of students = "<<average<<endl<<endl;

                if(average >= 50){

                    cout <<"Student pass the exam. "<<endl;
                }
                else{
                cout<<"Student fail the exam."<<endl;

                }
                }

                else if (choice == 5) {
                    cout << "Enter ID of Student you want to delete: ";
                    cin >> id;
                    Delete_Student(id);
                }

                else if (choice == 6) {
                cout << "program exited. " << endl;
                    exit(0);

                }

                else {
                    cout << "YOUR CHOICE IS NOT CORRECT PLEASE TRY AGAIN"<<endl;

        }
        }
        }

        // SET SOPHY (LINE 1333 TO 1369 )

        if(choice==3){
            cout<<"welcome to Teacher Infomation \n";
             // call connection function
    while(true){
    connection();
    int menu;
    cout<<"\n----------------------------------------\n";
    cout<<"Press[1] To insert :\n";
    cout<<"Press[2] To read :\n";
    cout<<"Press[3] To delete :\n";
    cout<<"Press[4] To Update :\n";
    cout<<"Press[5] To exit :\n";
    cout<<"\n----------------------------------------\n";
    cin>>menu;
    getchar();
    if(menu==1){
         Insert();

    }else if(menu==2){
         retrieve();

    }else if(menu==3){
         Delete();

    }else if(menu==4){
        Update();

    }
    else if(menu == 5){
        cout<<" Close program!..\n";
                return 0;
    }else
        {
    cout<<"Ivalid command \n";
    }


        }
        }
     // SIN  UDORM (LINE 1370 TO 1472 )

    if(choice==4){


	do{
		cout<<"1. Input"<<endl;
		cout<<"2. Output"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Update"<<endl;
		cout<<"5. Sort"<<endl;
		cout<<"Choose One(1-5): ";
		cin>>op;
		switch(op){
			case 1:{
				cout<<"Input Number of Array: "; cin>>n;
				for(i=0;i<n;i++){
					books[i].input();
				}
				break;
			}
			case 2: {
				for(i=0;i<n;i++){
					books[i].output();

				}
				break;
			}
			case 3:{
				int index=search(books,n);
				if(index==-1)
				cout<<"Error Search\n";
				else
				cout<<" ";
				break;
			}
			case 4: {
				string nname, ndepatment;
				double nsalary;
				int index=search(books,n);
				if(index==-1)
				cout<<"Error search\n";
				else
				cout<<"Input Name of Book: ";cin>>nname;
                cout<<"Input Kinds of Book: ";cin>>ndepatment;

				books[index].setName(nname);
				books[index].setDepatment(ndepatment);

				cout<<"Update Completed...!";
				break;
			}
			case 5: {
				Books tbooks;
				for(i=0;i<n;i++){
					for(j=i+1;j<n;j++){
						if(books[i].getCode()>books[j].getCode()){
							tbooks=books[i];
							books[i]=books[j];
							books[j]=tbooks;
						}
					}
				}
			}
				break;
			}
			cout<<"\nPress Enter to Continue...!"<<endl;
		}while(getch()==13);
		 string name1;
		 string name2;
		 string name3;
		 string date1;
		 string date2;
		 string date3;
		 int num1;
		 int num2;
		 int num3;

    cout<<"Enter Student's Name borrow is  "; cin>>name1;
    cout<<"Enter Date borrow book:"; cin>>date1;
    cout<<"Enter Number of Books: "; cin>>num1;
    cout<<"Enter Student's Name borrow is : "; cin>>name2;
    cout<<"Enter Date borrow book:"; cin>>date2;
    cout<<"Enter Number of Books: "; cin>>num2;
    cout<<"Enter Student's Name borrow is : "; cin>>name3;
    cout<<"Enter Date borrow book:"; cin>>date3;
    cout<<"Enter Number of Books: "; cin>>num3;

    Queue *q1;
    q1 = createEmptyQueue();

    enqueue(q1, name1);
    enqueue(q1, name2);
    enqueue(q1, name3);
    displayQueue(q1);

    dequeue(q1);

    displayQueue(q1);
		return 0;

    }

    // SET SOPHY(LINE 1474 TO 1630)
    if(choice==5){
        int ch;
    do {

        cout << "............WELCOME TO LIBRARY ITC............\n "
                "..............MANAGEMENT SYSTEM..............\n";
        cout <<"===============================================\n";

        cout<<"...........Book for Staff..............\n\n";

        cout << "1. Add a Book\n";
        cout << "2. View all Books\n";
        cout << "3. Search a Book \n";
        cout << "4. Delete a Book \n";
        cout << "5. View of Deleted Books\n";
        cout << "6. Edit a Book\n";
        cout << "7. Exit from Program\n";
        cout << "Enter choice : ";
        cin >> ch;

        switch (ch) {
        case 1:
            AddBook ();
            break;
        case 2:
            DisplayBook ();
            break;
        case 3:
            SearchBook ();
            break;
        case 4:
            DeleteBook ();
            break;
        case 5:
            BinOfBook ();
            break;
        case 6:
            UpdateBook ();
            break;
        case 7:
            cout<<"Close program !\n";
            return 0;
        }
    } while (1);
    }
    if(choice==6){

          StaffTable t;
int chioce;
string table;

    cout<<" Preparing Table in room in oder!...........\n\n";
    cout << "1.Put table in room :" << endl;
    cout << "2.Take table out the room " << endl;
    cout << "3.Show table  " << endl;
    cout<<"\n\n";
    cout<<"Welcome to Staff information.........\n\n";
    cout << "4.Staff information  " << endl;
    cout << "5.Exit program " << endl;
    do {
    cout << " Please enter choice: " << endl;
    cin >> chioce;
    switch ( chioce ) {
    case 1: {
    cout << " Insert table name : " << endl;
    cin >> table;
    t.push ( table );
    main();
    break;
    }
    case 2: {
    t.pop();
    main();
    break;
    }
    case 3: {
    t.show();
    main();
    break;
    }
    case 4: {
     int choice;

    string result;
    string staff_name;
    string ID;
    string staff_gender;
    int Delete_Staff;
    int staff_age;
    string staff_phone;

     while(true){
    cout << "***** PLEASE ENTER YOUR CHOICE *****" << endl << endl;
    cout<<"1.Add a new Employee:"<<endl;
    cout<<"2.Search an Employee:"<<endl;
    cout<<"3.Show  information of Employee::"<<endl;
    cout<<"4.Delete an Employee: "<<endl;
    cout<<"5.Sort Employee's data : "<<endl;
    cout<<"6.Exit program:"<<endl;

    cout<<"Enter choice: ";
    cin>>choice;
            if(choice == 1){
                insert();
            }

            else if(choice == 2){

                Search_Staff(ID);
            }
            else if( choice == 3){
                    cout << "***** Staff summary information ***** " << endl;
                    Show_Staff();

            }
            else if(choice == 4){
                cout << "Enter ID of employee to delete: ";
                cin >> ID;
                HashTable(ID);

            }
            else if(choice == 5){
                SortDataStaff();


            }else if(choice==6)


                {
           cout<<"Program close !.......\n";
                exit(0);
            }
            else{
                cout << "YOUR CHOICE IS NOT CORRECT, PLEASE TRY AGAIN.\n ";
            }
    }
        break;
        }

        case 5:{
        cout << " Exit " << endl;
        break;
        }
        default: {
        cout << " Invalid Choice " << endl;
        }
        }
        }while ( chioce != 4);
        return 0;

    }
    else if(choice==7){
       cout<<"Close program!...\n";
       return 0;
    }

        }
     else{
        cout<<"\t\t\t\tYOUR LOGIN IS NOT SUCCESS!"<<endl<<endl;
        cout<<"\t\t\t\tPLEASE TRY AGAIN LATER!"<<endl<<endl;

    }
    }
    return 0;

}

//SET SOPHY (LINE 1640 1826)

void connection(){

    if(sqlite3_open("TeacherInfo.db", &db)==SQLITE_OK)
       rc=sqlite3_prepare_v2(db, "CREATE TABLE TeacherInfo(TName CHAR  NULL, TId CHAR  NULL,TDept CHAR  NULL ,\
                             TQual CHAR  NULL, TGender CHAR  NULL,TExp CHAR  NULL,TAge CHAR  NULL, TPhone CHAR  NULL,\
                              TSalary CHAR  NULL, TYearInSchool CHAR  NUL);",-1, &stmt,NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(rc != SQLITE_OK){
        cout<<"error :"<<sqlite3_errmsg(db)<<"\n";
    }else{
        cout<<"Table created successfully \n";
    }

}
void Insert(){

     cout << "1. Enter the name of teacher: ";
                getline(cin, TName);
                cout << "2. Enter ID of teacher: ";
                getline(cin, TId);
                cout << "3. Enter age of teacher: ";
                getline(cin, TAge);
                cout << "4. Enter gender of teacher: ";
                getline(cin, TGender);
                cout << "5. Enter department which teacher teach: ";
                getline(cin, TDept);
                cout << "6. Enter qualification of teaching of teacher: ";
                getline(cin, TQual);
                cout << "7. Enter teacher experience in the school: ";
                 getline(cin, TExp);
                cout << "8. Enter teacher number of year in school: ";
                getline(cin, TYearInSchool);
                cout << "9. Enter teacher salary: ";
                getline(cin, TSalary);
                cout << "10. Enter teacher phone number: ";
                getline(cin, TPhone);

    query = " INSERT INTO TeacherInfo(TName, TId, TDept, TQual, TGender,TExp, TAge,\
            TPhone,TSalary,TYearInSchool ) VALUES(?,?,?,?,?,?,?,?,?,?); ";


     rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
     sqlite3_bind_text(stmt,1 ,TName.c_str(), TName.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,2 ,TId.c_str(), TId.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,3 ,TDept.c_str(), TDept.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,4 ,TQual.c_str(), TQual.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,5 ,TGender.c_str(), TGender.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,6 ,TExp.c_str(), TExp.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,7 ,TAge.c_str(), TAge.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,8 ,TPhone.c_str(), TPhone.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,9 ,TSalary.c_str(), TSalary.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,10 ,TYearInSchool.c_str(), TYearInSchool.length(), SQLITE_TRANSIENT );

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(rc != SQLITE_OK){
        cout<<"error"<<sqlite3_errmsg(db)<<"\n";
    }else{
        cout<<"Data inserted successfully\n";
    }
}
void retrieve(){

     query = "SELECT rowid, *FROM TeacherInfo ";
     rc = sqlite3_prepare_v2(db,query.c_str(), -1, &stmt, NULL);

     if(rc != SQLITE_OK){

        cout<<"error :"<<sqlite3_errmsg(db)<<"\n";

     }else{
         cout<<
"\n-------------------------------------------------------------------\n";

         cout<<"\n"<<left
         <<setw(15)<<"rowId"
         <<setw(15)<<"Name"
         <<setw(15)<<"Id"
         <<setw(10)<<"Dept"
         <<setw(10)<<"Qual"
         <<setw(10)<<"Gender"
         <<setw(10)<<"Exp"
         <<setw(10)<<"Age"
         <<setw(10)<<"Phone"
         <<setw(10)<<"Salary"
         <<setw(10)<<"YearInSchool";
       cout<<
"\n===================================================================================================================================\n";
         while((rc=sqlite3_step(stmt)==SQLITE_ROW)){

            cout<<"\n"<<left<<setw(15)<<sqlite3_column_text(stmt, 0)
            <<setw(15)<<sqlite3_column_text(stmt, 1)
            <<setw(10)<<sqlite3_column_text(stmt, 2)
            <<setw(10)<<sqlite3_column_text(stmt, 3)
            <<setw(10)<<sqlite3_column_text(stmt, 4)
            <<setw(10)<<sqlite3_column_text(stmt, 5)
            <<setw(15)<<sqlite3_column_text(stmt, 6)
            <<setw(10)<<sqlite3_column_text(stmt, 7)
            <<setw(15)<<sqlite3_column_text(stmt, 8)
            <<setw(15)<<sqlite3_column_text(stmt, 9)
            <<setw(15)<<sqlite3_column_text(stmt, 10) <<"\n";


         }
 cout<<
"\n===================================================================================================================================\n";
     }
     }
     void Delete(){
        string rowid;
          cout<<"\n Which record you want to delete?";
          cout<<"\n Input ID :"; getline(cin, rowid);
          getchar();

          query = "DELETE FROM TeacherInfo WHERE rowid =?";
          rc = sqlite3_prepare_v2(db, query.c_str(),-1, &stmt, NULL);
          sqlite3_bind_text(stmt,1 ,rowid.c_str(), rowid.length(), SQLITE_TRANSIENT );
          sqlite3_step(stmt);
          sqlite3_finalize(stmt);
          if(rc==SQLITE_OK){

            cout<<"\n Data delete successfully!";

          }else{
           cout<<"\n Failed :"<<sqlite3_errmsg(db);
          }
     }
void Update(){
     string rowid;
     cout<<"\n Input  id to update :";
     getline(cin, rowid);
      cout << "1. Enter the name of teacher: ";
                getline(cin, TName);
                cout << "2. Enter ID of teacher: ";
                getline(cin, TId);
                cout << "3. Enter age of teacher: ";
                getline(cin, TAge);
                cout << "4. Enter gender of teacher: ";
                getline(cin, TGender);
                cout << "5. Enter department which teacher teach: ";
                getline(cin, TDept);
                cout << "6. Enter qualification of teaching of teacher: ";
                getline(cin, TQual);
                cout << "7. Enter teacher experience in the school: ";
                 getline(cin, TExp);
                cout << "8. Enter teacher number of year in school: ";
                getline(cin, TYearInSchool);
                cout << "9. Enter teacher salary: ";
                getline(cin, TSalary);
                cout << "10. Enter teacher phone number: ";
                getline(cin, TPhone);


     query = "UPDATE TeacherInfo SET TName= ?,TId=?,TDept=?,TQual=?,TGender=?,TExp=?,TAge=?,TPhone=?,TSalary=?,TYearInSchool=? WHERE rowid=?;";
     rc = sqlite3_prepare_v2(db, query.c_str(),-1,&stmt, NULL);

     sqlite3_bind_text(stmt,1 ,TName.c_str(), TName.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,2 ,TId.c_str(), TId.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,3 ,TDept.c_str(), TDept.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,4 ,TQual.c_str(), TQual.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,5 ,TGender.c_str(), TGender.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,6 ,TExp.c_str(), TExp.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,7 ,TAge.c_str(), TAge.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,8 ,TPhone.c_str(), TPhone.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,9 ,TSalary.c_str(), TSalary.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,10 ,TYearInSchool.c_str(), TYearInSchool.length(), SQLITE_TRANSIENT );
     sqlite3_bind_text(stmt,11 ,rowid.c_str(), rowid.length(), SQLITE_TRANSIENT );


     sqlite3_step(stmt);
     sqlite3_finalize(stmt);

     if (rc != SQLITE_OK ){


        cout<<"\n Failed "<<sqlite3_errmsg(db)<<"\n";
     }
     else{
        cout<<"\n Data update seccessfully ";

     }

}

