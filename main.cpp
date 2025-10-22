#include <iostream>
#include <cmath>
using namespace std;

// Electric Field Class
class Electric_Field {
private:
    double *E; // [0] = Ex, [1] = Ey, [2] = Ez
public:
    // Default constructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};
    }

    // Constructor with components
    Electric_Field(double Ex, double Ey, double Ez) {
        E = new double[3]{Ex, Ey, Ez};
    }

    // Destructor
    ~Electric_Field() {
        delete[] E;
    }

    // Setters
    void setEx(double Ex) { E[0] = Ex; }
    void setEy(double Ey) { E[1] = Ey; }
    void setEz(double Ez) { E[2] = Ez; }

    // Getters
    double getEx() const { return E[0]; }
    double getEy() const { return E[1]; }
    double getEz() const { return E[2]; }

    // Magnitude
    double calculateMagnitude() const {
        return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
    }

    // Inner product (E · E)
    double calculateInnerProduct() const {
        return E[0]*E[0] + E[1]*E[1] + E[2]*E[2];
    }
};

// Magnetic Field Class
class Magnetic_Field {
private:
    double *B; // [0] = Bx, [1] = By, [2] = Bz
public:
    // Default constructor
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0};
    }

    // Constructor with components
    Magnetic_Field(double Bx, double By, double Bz) {
        B = new double[3]{Bx, By, Bz};
    }

    // Destructor
    ~Magnetic_Field() {
        delete[] B;
    }

    // Setters
    void setBx(double Bx) { B[0] = Bx; }
    void setBy(double By) { B[1] = By; }
    void setBz(double Bz) { B[2] = Bz; }

    // Getters
    double getBx() const { return B[0]; }
    double getBy() const { return B[1]; }
    double getBz() const { return B[2]; }

    // Magnitude
    double calculateMagnitude() const {
        return sqrt(B[0]*B[0] + B[1]*B[1] + B[2]*B[2]);
    }

    // Unit vector
    void printUnitVector() const {
        double mag = calculateMagnitude();
        if (mag == 0) {
            cout << "Magnetic field vector is zero; no unit vector.\n";
            return;
        }
        cout << "Magnetic field unit vector: ("
             << B[0]/mag << ", "
             << B[1]/mag << ", "
             << B[2]/mag << ")\n";
    }
};

int main() {
    // Electric Fields
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);

    E_default.setEx(50.0);
    E_default.setEy(30.0);
    E_default.setEz(10.0);

    cout << "Electric Field Magnitudes:\n";
    cout << "E_default: " << E_default.calculateMagnitude() << endl;
    cout << "E_components: " << E_components.calculateMagnitude() << endl;

    cout << "\nElectric Field Inner Product (E·E): "
         << E_components.calculateInnerProduct() << endl;

    // Magnetic Fields
    Magnetic_Field B_default;
    Magnetic_Field B_components(5.0, 2.0, 1.0);

    B_default.setBx(1.0);
    B_default.setBy(2.0);
    B_default.setBz(3.0);

    cout << "\nMagnetic Field Magnitudes:\n";
    cout << "B_default: " << B_default.calculateMagnitude() << endl;
    cout << "B_components: " << B_components.calculateMagnitude() << endl;

    cout << "\n";
    B_components.printUnitVector();

    return 0;
}
