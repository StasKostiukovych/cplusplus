#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;


class Set{
public:
    char filename[30] = "numbers.bin";

    void cases(){
        char choice = '1';
        cout << "1 - Enter nums from keyboard\n"
                "2 - Read\n"
                "3 - Add one or many nums in set\n"
                "4 - Minimum element of set\n"
                "5 - Maximum element of set\n"
                "6 - is set empty?\n"
                "7 - is num in set?\n"
                "8 - delete num\n"
                "0 - exit\n\n";

        while (true) {



            cout << "Enter type of work: ";
            cin >> choice;



            if (choice == '1') {
                vector<int> in;
                in = input_set_via_terminal();
                if (write_data_into_set(in))
                    cout << "You successfully enter set: ";
                print_set(in);

            } else if (choice == '2') {
                vector<int> out;
                out = read_data_from_file();
                print_set(out);

            } else if (choice == '3') {
                vector<int> fileadd;
                fileadd = input_set_via_terminal();
                bool suc = add(fileadd);
                if (suc)
                    cout << "You successfully add!\n";
                print_set(read_data_from_file());

            } else if (choice == '4'){
                cout << "Min element: " << min_element() << endl;

            } else if (choice == '5') {
                cout << "Max element: " << max_element() << endl;

            } else if (choice == '6') {
                cout << "Set is "
                     << ( isEmptySet() ? "" : "not " )
                     << "empty\n";

            } else if (choice == '7'){

                int num;
                cout << "Enter num: ";
                cin >> num;

                cout << "Num is "
                     << ( (inSet(num)) ? "" : "not ")
                     << "in set\n";
            } else if (choice == '8'){

                int num;
                cout << "Enter num: ";
                cin >> num;

                if (deleteElementSet(num)){
                    cout << "Successfully deleted num \n";
                }

                else
                    cout << "No such element ";
            }

            else if (choice =='0'){
                cout << "Bye\n";
                break;
            }

            else
                cout << "Invalid response\n";

        }
    }



private:
    vector<int> input_set_via_terminal(){
        int n;
        int num;
        cout <<"\nEnter size of set: ";
        cin >> n;
        vector <int> in_set;


        for (int i(0); i<n; i++){
            cout << "el[" << i << "] = ";
            cin >> num;
            in_set.push_back(num);
        }
        return in_set;
    }

    void print_set(vector<int> nums){
        for (int i: nums){
            cout << i << ", ";
        }
        cout << endl;
    }


    bool write_data_into_set(vector<int> fnum) {

        ofstream out(filename, ios::binary);

        if(!out) {
            cout << "Cannot open file.";
            return false;
        }

        for (int num: fnum){
            out << " " << num;
        }

        out.close();
        return true;
    }


    vector<int> read_data_from_file(){

        vector<int> ret;
        ifstream in(filename, ios::binary);

        int current;
        while (in.good()) {
            in >> current;
            ret.emplace_back(current);
        }
        in.close();
        return ret;

    }


    bool add(vector<int> fileadd){
        vector<int> data_now;
        data_now = read_data_from_file();
        data_now.insert(data_now.end(), fileadd.begin(), fileadd.end());
        return write_data_into_set(data_now);
    }


    int min_element(){

        ifstream f(filename, ios::binary);

        int min, templ;
        f >> min;

        while (f.good()) {
            f >> templ;
            if (templ < min)
                min = templ;
        }
        f.close();

        return min;
    }

    int max_element(){

        ifstream f(filename, ios::binary);

        int max, templ;
        f >> max;

        while (f.good()) {
            f >> templ;
            if (templ > max)
                max = templ;
        }
        f.close();

        return max;

    }


    bool inSet(int num){
        ifstream f(filename, ios::binary);
        int templ;
        while (f.good()) {
            f >> templ;
            if (templ == num)
                return true;
        }
        return false;

    }

    bool isEmptySet(){
        ifstream in(filename, ios::binary);
        bool empty = ( in.get(), in.eof() );
        return empty;
    }

    bool deleteElementSet(int num){
        vector<int> data_now;
        data_now = read_data_from_file();

        if (!inSet(num))
            return false;


        for (int i(0); i < data_now.size(); i++){
            if (data_now[i] == num){
                data_now.erase(data_now.begin() + i);
                break;
            }
        }

        return write_data_into_set(data_now);

    }

};


int main() {
    Set s;
    s.cases();

    return 0;
}
