#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <sstream>


using namespace std;


bool fib_to_file(fstream &file){

    if (!file){
        return false;
    }

    int n;
    cout << "enter n: ";
    cin >> n;

    int f1=1, f2=1;
    file << f1 << " ";
    while (f2 < n){
        file << f2 << " ";
        f2 += f1;
        f1 = f2-f1;
    }
    return true;
}


bool is_prime(int n){

    for (int i(2); i <= n/2; i++)
        if (n % i == 0){
            return false;
        }
    return true;
}

bool prime_fib_to_file(fstream &file){
    if (!file){
        return false;
    }

    int n;
    cout << "enter n: ";
    cin >> n;

    int f1=1, f2=1;
    file << f1 << " ";
    while (f2 < n){
        if (is_prime(f2))
            file << f2 << " ";
        f2 += f1;
        f1 = f2-f1;
    }
    return true;
}


void task1_a(){
    fstream file_to_write("fib.txt", ios::out);
    cout << fib_to_file(file_to_write);
    file_to_write.close();
}

void task1_b(){
    fstream file_to_write("fib_prime.txt", ios::out);
    cout << prime_fib_to_file(file_to_write);
    file_to_write.close();
}


class Date{

public:

    struct mydate{
        int day;
        int month;
        int year;
    };

    mydate date;

    void SetDateNums(){

        cout << "\nEnter day: ";
        cin >> date.day;

        cout <<"Enter month: ";
        cin >> date.month;

        cout << "Enter year: ";
        cin >> date.year;

        if (!valid(date)){
            cout << "Something incorrect, pls try again!";
            SetDateNums();
        } else
            cout << "_________________________________________";

    }

    void SetDateStr(){

        unsigned long sep_pos[2];

        int j = 0;
        string test;

        cout << "Enter date like d-m-y or d:m:y or d/m/y: \n";
        getline (std::cin,test);

        for (unsigned long i(0); test[i] != '\0'; i++){
            if ((test[i] == '-')||(test[i] == '/')||(test[i] == ':')) {
                if (j == 2) {
                    cout << "Something incorrect, pls try again!";
                } else {
                    sep_pos[j] = i;

                }
                j += 1;
            }
        }

        // days
        string day = test.substr(0, sep_pos[0]);
        istringstream d (day);
        d >> date.day;

        // months
        string month = test.substr(sep_pos[0] + 1, sep_pos[1]);
        istringstream m (month);
        m >> date.month;

        // years
        string year = test.substr(test.size() - 4);
        istringstream y (year);
        y >> date.year;

        if (!valid(date)) {
            cout << "Something incorrect, pls try again!";
            SetDateStr();
        } else
            cout << "_________________________________________";

    }

    void SetDateCurrent(){

        time_t theTime = time(nullptr);
        struct tm *aTime = localtime(&theTime);

        date.day = aTime->tm_mday;
        date.month = aTime->tm_mon + 1;
        date.year = aTime->tm_year + 1900;

        cout << "_________________________________________";

    }


    void PrintDate(){
        cout << "\nDay: " << date.day <<
        "\nMonth: " << date.month << "\nYear: " << date.year;
    }

private:

    bool valid(mydate &date){

        // this func will check the given date is valid or not
        // if the date is not valid then it will return the value false

        if (date.year < 0) return false;
        if (date.month >12 || date.month <1) return false;
        if (date.day >31 || date.day <1) return false;
        if ((date.day ==31 &&
             ( date.month == 2 || date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) ))
            return false;
        if ( date.day ==30 && date.month == 2) return false;

        if (!(((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0))){
            if (date.day ==29 && date.month ==2) return false;
        };

        return true;
    }

};



class Students{
public:

    /*
    This csv file contains table of information about students like this:

    1,Іваненко Іван, 6, 85
    2,Симоненко Петро, 3, 76

     */
    string data = "f.csv";

    struct student_t{
        int id_;
        char fullname_[100];
        int course_;
        int point_;
    };



    void RecordAll(){
        // copy all info from csv to binary
        CsvToBinary(-1); // -1 because id only real nums
    }

    void ShowFile(){
        cout << "id | Fullname | Course | Point\n";
        ReadBinary();
    }

    void Change(){
        cout << "Enter Record to change:";
        int l;
        cin >> l;
        CsvToBinary(l);
        ShowFile();
    }


private:
    int LenCsv(){
        int rows=0;
        ifstream file(data);
        string line;
        while (getline(file, line)) {
            rows++;
        }
        return rows;
    }


    void Change(student_t & s){
        cout << "Enter new Fullname: ";
        cin >> s.fullname_;
        cout << "Enter new Course: ";
        cin >> s.course_;
        cout << "Enter new Point: ";
        cin >> s.point_;
    }

    void CsvToBinary(int k) {
        ifstream ip(data);
        if (!ip.is_open()) cout << "ERROR: File Open\n";

        int last_id = 0;
        string id;
        string fullname;
        string course;
        string points;

        int len = 0;
        len = LenCsv();
        student_t students_array[len];

        int indx = 0;

        student_t templ_stud;

        while (ip.good()){

            getline(ip, id, ',');
            getline(ip, fullname, ',');
            getline(ip, course, ',');
            getline(ip, points, '\n');

            stringstream i (id);
            i >> templ_stud.id_;

            for (int i = 0; i < sizeof(fullname); i++){
                templ_stud.fullname_[i] = fullname[i];
            }

            stringstream c (course);
            c >> templ_stud.course_;

            stringstream p (points);
            p >> templ_stud.point_;

            if (templ_stud.id_ == k){
                Change(templ_stud);
            }

            students_array[indx] = templ_stud;
            indx +=1;
        }
        ip.close();

        ofstream output_file("students.data", ios::binary);
        output_file.write((char*)&students_array, sizeof(students_array));
        output_file.close();
    }


    void ReadBinary(){

        // Reading from it
        ifstream input_file("students.data", ios::binary);
        int len = 0;
        len = LenCsv();
        student_t master[len];
        input_file.read((char*)&master, sizeof(master));
        for (int idx = 0; idx < len; idx++)
        {
            cout << "Record #" << idx << endl;
            cout << "Name: " << master[idx].fullname_ << endl;
            cout << "Course: " << master[idx].course_ << endl;
            cout << "Point: " << master[idx].point_ <<endl;
            cout << "-----------------\n";

        }

        input_file.close();
    }
};



int main() {

    cout << "task 1" << endl << "a)";
    task1_a();
    cout << endl << "b)";
    task1_b();

    cout << "task 2" << endl;
    Students s;
    s.RecordAll();
    s.ShowFile();
    s.Change();

    cout << "task 3" << endl;
    Date d;

    //d.SetDateStr();
    //d.SetDateCurrent();
    d.SetDateNums();
    d.PrintDate();

    return 0;
}
