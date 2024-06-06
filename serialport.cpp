#include <iostream>
#include <string>

using namespace std;

class serial {
public:
    int bitrate;
    string prity;
    int databit;
    float stop;
    string portcom;

    void serial_def();
    void serial_set();
    void serial_get();
};

void serial::serial_def() {
    bitrate = 9600;
    prity = "None";
    databit = 8;
    stop = 1;
    portcom = "CPM2";
}

void serial::serial_get() {
    cout << "bitrate = " << bitrate << endl;
    cout << "parity = " << prity << endl;
    cout << "databit = " << databit << endl;
    cout << "stop bit = " << stop << endl;
    cout << "port = " << portcom << endl;
}

void serial::serial_set() {
    cout << "Please enter the name of the port (COM1~COM8): ";
    cin >> portcom;
    cout << "Please enter the bit rate value (4800, 6800, 9600, 115200): ";
    cin >> bitrate;
    cout << "Please enter the stop bit value (1 or 1.5): ";
    cin >> stop;
    cout << "Please enter the parity value (None, Odd, Even, Space): ";
    cin >> prity;
    cout << "Please enter the data bit (2, 4, 6, 8): ";
    cin >> databit;

    if (portcom == "COM1" || portcom == "COM2" || portcom == "COM3" || portcom == "COM4" ||
        portcom == "COM5" || portcom == "COM6" || portcom == "COM7" || portcom == "COM8") {
        cout << "Port COM is valid." << endl;
    } else {
        cout << "Port COM is not valid." << endl;
    }

    if (bitrate == 4800 || bitrate == 9600 || bitrate == 15200) {
        cout << "Bit rate is valid." << endl;
    } else {
        cout << "Bit rate is not valid." << endl;
    }

    if (stop == 1 || stop == 1.5 || stop == 2) {
        cout << "Stop bit is valid." << endl;
    } else {
        cout << "Stop bit is not valid." << endl;
    }

    if (prity == "None" || prity == "none" || prity == "Even" || prity == "even" ||
        prity == "Odd" || prity == "odd" || prity == "Space" || prity == "space") {
        cout << "Parity is valid." << endl;
    } else {
        cout << "Parity is not valid." << endl;
    }

    if (databit == 2 || databit == 4 || databit == 6 || databit == 8) {
        cout << "Data bit is valid." << endl;
    } else {
        cout << "Data bit is not valid." << endl;
    }
}

int main() {
    serial Mohammad;
    Mohammad.serial_def();
    Mohammad.serial_get();
    Mohammad.serial_set();

    return 0;
}
