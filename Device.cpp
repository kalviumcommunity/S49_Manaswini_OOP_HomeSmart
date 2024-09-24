#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

class Device {
protected:
    string deviceName;
    string typeOfConnectivity;
    int versionYear;
    bool isOn;
public:
    Device(string deviceName, string typeOfConnectivity, int versionYear) {
        this->deviceName = deviceName;
        this->typeOfConnectivity = typeOfConnectivity;
        this->versionYear = versionYear;
        this->isOn = false;
    }
    virtual ~Device() {} // Virtual destructor for proper cleanup
    void switchOnOff(bool turnOn) {
        if (isOn != turnOn) {
            isOn = turnOn;
        }
    }
    virtual void showDetails() {
        cout << "Device Name: " << deviceName << endl;
        cout << "Type of Connectivity: " << typeOfConnectivity << endl;
        cout << "Version Year: " << versionYear << endl;
        cout << "Status: " << (isOn ? "On" : "Off") << endl;
    }
};

class SmartBulb : public Device {
private:
    string colour;
    int brightness;
public:
    SmartBulb(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear) {
        this->brightness = 5;
        this->colour = "white";
    }
    void setColour(string colour) {
        if (isOn) {
            this->colour = colour;
            cout << "The colour of this device is set to " << colour << endl;
        } else {
            cout << "Turn this device on before making modifications" << endl;
        }
    }
    void setBrightness(int b) {
        if (isOn) {
            if (1 > b || b > 10) {
                cout << "Give a valid input between 1 to 10" << endl;
            } else {
                brightness = b;
                cout << "The brightness has been set to " << b << endl;
            }
        } else {
            cout << "Turn this device on before making modifications" << endl;
        }
    }
    void showDetails() override {
        Device::showDetails();
        cout << "Colour: " << colour << endl;
        cout << "Brightness: " << brightness << endl;
    }
};

class Thermostat : public Device {
private:
    float temperature;
public:
    Thermostat(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear) {
        this->temperature = 22.0;
    }
    void setTemperature(float temp) {
        if (isOn) {
            temperature = temp;
            cout << "Temperature is set to " << temperature << "°C" << endl;
        } else {
            cout << "Turn this device on before making modifications" << endl;
        }
    }
    void showDetails() override {
        Device::showDetails();
        cout << "Temperature: " << temperature << "°C" << endl;
    }
};

class User {
private:
    string nameOfDeviceOwned;
    string companyofTheDevice;
public:
    User() {}
    User(string nameOfDeviceOwned, string companyofTheDevice) {
        this->nameOfDeviceOwned = nameOfDeviceOwned;
        this->companyofTheDevice = companyofTheDevice;
    }
    void display() {
        cout << "Name of the device: " << nameOfDeviceOwned << endl;
        cout << "Company of that device: " << companyofTheDevice << endl;
    }
};

int main() {
    string deviceType, name_of_device, company, colour;
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

        Device* device = nullptr;  // Using dynamic allocation

        if (deviceType == "SmartBulb") {
            device = new SmartBulb(name_of_device, company, version_year);
            SmartBulb* smartBulb = dynamic_cast<SmartBulb*>(device);

            cout << "Do you want to turn on the device? y(yes) or n(no)" << endl;
            string confirmation_turnon;
            cin >> confirmation_turnon;
            if (confirmation_turnon == "y") {
                smartBulb->switchOnOff(true);
                cout << "Set colour and brightness (1 - 10):" << endl;
                cin >> colour >> brightness;
                smartBulb->setColour(colour);
                smartBulb->setBrightness(brightness);
            } else {
                cout << "Turn on the device to continue." << endl;
            }

            smartBulb->showDetails();

        } else if (deviceType == "Thermostat") {
            device = new Thermostat(name_of_device, company, version_year);
            Thermostat* thermostat = dynamic_cast<Thermostat*>(device);

            cout << "Do you want to turn on the device? y(yes) or n(no)" << endl;
            string confirmation_turnon;
            cin >> confirmation_turnon;
            if (confirmation_turnon == "y") {
                thermostat->switchOnOff(true);
                cout << "Set temperature (°C):" << endl;
                cin >> temperature;
                thermostat->setTemperature(temperature);
            } else {
                cout << "Turn on the device to continue." << endl;
            }

            thermostat->showDetails();

        } else {
            cout << "Invalid device type." << endl;
        }

        delete device;  // Freeing the allocated memory

    } else {
        string keepTrack;
        cout << "Do you want to keep a track of all the devices? y(yes) or n(no) " << endl;
        cin >> keepTrack;
        if (keepTrack == "y") {
            User* devices = new User[5];  // Using dynamic allocation for array

            for (int i = 0; i < 5; i++) {
                string name_of_device;
                string company_of_device;
                cout << "Enter the details (order: first the device name and then the company) " << i + 1 << endl;
                cin >> name_of_device >> company_of_device;
                devices[i] = User(name_of_device, company_of_device);
            }
            for (int i = 0; i < 5; i++) {
                devices[i].display();
            }

            delete[] devices;  // Freeing the allocated memory
        } else {
            cout << "See you next time :)" << endl;
        }
    }

    return 0;
}