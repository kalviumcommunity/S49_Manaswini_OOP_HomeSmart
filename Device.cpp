#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

class Device{
protected:
    string deviceName;
    string typeOfConnectivity;
    int versionYear;
    bool isOn;
public:
    //Constructor.
    Device(string deviceName, string typeOfConnectivity, int versionYear){
        this -> deviceName = deviceName;
        this -> typeOfConnectivity = typeOfConnectivity;
        this -> versionYear = versionYear;
        this -> isOn = false;
    }
    // Function to switch the device on or off.
    void switchOnOff(bool turnOn) {
        //the data type of turnOn can be either true or false and the isOn is default set to false.
        if(isOn != turnOn){
            isOn = turnOn;
        }
    }
    // Virtual function for derived classes
    virtual void showDetails(){
        cout << "Device Name: " << deviceName <<endl;
        cout << "Type of Connectivity: " << typeOfConnectivity<<endl;
        cout << "Version Year: " << versionYear<<endl;
        cout << "Status: " << (isOn ? "On" : "Off")<<endl;
    }
};

class SmartBulb: public Device{
private:
    string colour;
    int brightness;
public:
    //Constructor. 
    SmartBulb(string deviceName, string typeOfConnectivity, int versionYear): Device(deviceName, typeOfConnectivity, versionYear){
        this -> deviceName = deviceName;
        this -> typeOfConnectivity = typeOfConnectivity;
        this -> versionYear = versionYear;
        this -> isOn = false;
        this -> brightness = 5;
        this -> colour = "white";
    }

    //set colour function.
    void setColour(string colour){
        if(isOn){
           this -> colour = colour;
        cout<<"The colour of this device is set to "<<colour<<endl; 
        } else{
            string error = "turn this device on before making modifications";
            cout<<error<<endl;
        }
        
    }

    //set brightness function.
    void setBrightness(int b){
        if(isOn){
            if(1 > b || b > 10){
                cout<<"Give a valid input between 1 to 10"<<endl;
            } else{
                if(b > brightness){
                cout<<"The brightness has been increased to "<<b<<endl;
                brightness = b;

                } else if( b == brightness) {
                cout<<"The brightness remains same"<<endl;
                } else {
                cout<<"The brightness has been lowered to "<<b<<endl;
                brightness = b;
                }
            }
        } else{
            string error = "turn this device on before making modifications";
            cout<<error<<endl;
        }
    }

    //Show details that was inherited from the Device class
    void showDetails() override {
        Device::showDetails();
        cout<<"Colour: " <<colour<<endl;
        cout<<"Brightness: "<<brightness<<endl;
    }

};

class Thermostat : public Device {
private:
    float temperature;
public:
    // Constructor
    Thermostat(string deviceName, string typeOfConnectivity, int versionYear) : Device(deviceName, typeOfConnectivity, versionYear) {
        this->temperature = 22.0; // Default temperature in Celsius
    }

    // Set temperature function
    void setTemperature(float temp) {
        if (isOn) {
            temperature = temp;
            cout << "Temperature is set to " << temperature << "°C" << endl;
        } else {
            cout << "Turn this device on before making modifications" << endl;
        }
    }

    // Show details inherited from Device class
    void showDetails() override {
        Device::showDetails();
        cout << "Temperature: " << temperature << "°C" << endl;
    }
};


int main() {
    string deviceType, name_of_device, company, colour;
    bool turn_on;
    int brightness, version_year;
    float temperature;
    string confirmation;

    cout << "Do you want to connect a device? y(yes) or n(no)" << endl;
    cin >> confirmation;

    if (confirmation == "y") {
        cout << "Which device do you want to connect? (SmartBulb/Thermostat)" << endl;
        cin >> deviceType;

        cout << "Enter the device name, company, and version year:" << endl;
        cin >> name_of_device >> company >> version_year;

        if (deviceType == "SmartBulb") {
            SmartBulb mybulb(name_of_device, company, version_year);

            cout << "Do you want to turn on the device? y(yes) or n(no)" << endl;
            string confirmation_turnon;
            cin >> confirmation_turnon;
            if (confirmation_turnon == "y") {
                mybulb.switchOnOff(true);
                cout << "Set colour and brightness (1 - 10):" << endl;
                cin >> colour >> brightness;
                mybulb.setColour(colour);
                mybulb.setBrightness(brightness);
            } else {
                cout << "Turn on the device to continue." << endl;
            }

            mybulb.showDetails();

        } else if (deviceType == "Thermostat") {
            Thermostat mythermostat(name_of_device, company, version_year);

            cout << "Do you want to turn on the device? y(yes) or n(no)" << endl;
            string confirmation_turnon;
            cin >> confirmation_turnon;
            if (confirmation_turnon == "y") {
                mythermostat.switchOnOff(true);
                cout << "Set temperature (°C):" << endl;
                cin >> temperature;
                mythermostat.setTemperature(temperature);
            } else {
                cout << "Turn on the device to continue." << endl;
            }

            mythermostat.showDetails();

        } else {
            cout << "Invalid device type." << endl;
        }

    } else {
        cout << "See you next time :)" << endl;
    }

    return 0;
}
