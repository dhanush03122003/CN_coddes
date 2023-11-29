#include <iostream>
#include <string>

using namespace std;

string bitStuffing(string data) {
    string stuffedData = "01111110";  // Start delimiter
    int count = 0;

    for (char bit : data) {
        stuffedData += bit;

        if (bit == '1') {
            count = count + 1;
        } else {
            count = 0;
        }

        if (count == 5) {
            stuffedData += '0';
            count = 0;
        }
    }

    stuffedData += "01111110";  // End delimiter
    return stuffedData;
}

string bitUnstuffing(string stuffedData) {
    string data = "";
    int count = 0;

    stuffedData = stuffedData.substr(8, stuffedData.length() - 16);

    for (char bit : stuffedData) {
        data += bit;

        if (bit == '1') {
            count = count + 1;
        } else {
            count = 0;
        }

        if (count == 5) {
            count = 0;
        }
    }

    return data;
}

int main() {
    string originalData = "01111111111011111110";
    string stuffedData = bitStuffing(originalData);
    string unstuffedData = bitUnstuffing(stuffedData);

    cout << "Original Data: " << originalData << endl;
    cout << "Stuffed Data: " << stuffedData << endl;
    cout << "Unstuffed Data: " << unstuffedData << endl;

    return 0;
}
