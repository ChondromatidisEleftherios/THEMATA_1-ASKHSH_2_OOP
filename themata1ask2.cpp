#include <iostream>
#include <string>
using namespace std;

class vehicle {
protected:
    int registration_number;
    string owner_name;
    int cc;

public:
    vehicle(int a, string &n, int c) {
        registration_number = a;
        owner_name = n;
        cc = c;
    }
    virtual double traffic_tax() = 0;
};

class car : public vehicle {
private:
    int number_of_doors;

public:
    car(int a, string &n, int c, int nu) : vehicle(a, n, c) { //Στις παραγόμενες κλάσεις θα βάζω πάντα "ονομακλασης (ολες οι παραμετροι) : αρχικηκλαση (παραμετροι που ηταν και στην αρχικη κλαση) { μεταβλητη νεας κλασης=παραμετρος}"  //
        number_of_doors = nu;
    }
    double traffic_tax() {
        double syn = 0.0;
        int x = 0;
        if (cc <= 1000) {
            syn = 140;
            return syn;
        } else if (cc >= 1001) {
            syn = 140 + ((cc - 1000) / 100) * 10;
            while (!((int)syn % 10 == 0)) // ΟΤΑΝ ΚΑΝΩ MOD ΚΑΝΩ INT ΤΗ ΜΕΤΑΒΛΗΤΗ ΠΡΩΤΑ//
            {
                syn = syn - 1;
            }
            return syn;
        }
    }

    friend ostream &operator<<(ostream &os, const car &obj) {
        os << obj.registration_number << obj.owner_name << obj.cc << obj.number_of_doors;
        return os;
    }
};

class truck : public vehicle {
private:
    double max_weight;

public:
    truck(int a, string &n, int c, int mx) : vehicle(a, n, c) {
        max_weight = mx;
    }
    double traffic_tax() {
        double syn = 0.0;
        if (max_weight <= 3000.0) {
            syn = 300;
            return syn;
        } else if ((max_weight > 3000.0) && (max_weight <= 6000.0)) {
            syn = 400;
            return syn;
        } else if (max_weight > 6000.0) {
            syn = 600;
            return syn;
        }
    }
    friend ostream &operator<<(ostream &os, const truck &obj) {
        os << obj.registration_number << obj.owner_name << obj.cc << obj.max_weight;
        return os;
    }
};

double total_tax(vehicle *v[5]) {  //Σαν τύπο βάζω αυτό που όρισα και στη main και επίσης Βαζω θέσεις πίνακα σε συνάρτηση//
    int y = 0;
    double total = 0.0;
    while (y < 5) {
        total = v[y]->traffic_tax() + total;
        y = y + 1;
    }
    return total;
}

int main(void) {
    int x = 0, choice = 0, rnu = 0, kybika = 0, port = 0;
    double var = 0.0, ap = 0.0;
    string ow;
    vehicle *pin[5];
    while (x < 5) {
        cout << "Car (1) or truck (2)" << endl;
        cin >> choice;
        if (choice == 1) {
            cin >> rnu;
            cin >> ow;
            cin >> kybika;
            cin >> port;
            pin[x] = new car(rnu, ow, kybika, port);
        } else if (choice == 2) {
            cin >> rnu;
            cin >> ow;
            cin >> kybika;
            cin >> var;
            pin[x] = new truck(rnu, ow, kybika, var);
        }
        x = x + 1;
    }
    ap = total_tax(pin);
    cout << "Synolo: " << endl;
    cout << ap << endl;
    cout << endl
         << endl;
    x = 0;
    while (x < 5) {
        delete pin[x];
        x = x + 1;
    }
    return 0;
}
