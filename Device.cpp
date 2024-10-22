#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

class Device
{

protected:
    string deviceName;
    string typeOfConnectivity;
    int versionYear;
    bool isOn;
    // Static variable to keep track of total devices
    static int totalDevices;

protected:
    void incrementTotalDevices()
    {
        totalDevices++;
    }

public:
    // constructor -1
    Device(string deviceName, string typeOfConnectivity, int versionYear)
    {
        this->deviceName = deviceName;
        this->typeOfConnectivity = typeOfConnectivity;
        this->versionYear = versionYear;
        this->isOn = false;
        incrementTotalDevices();
    }

    // Destructor 1
    virtual ~Device() {}

    // Pure virtual functions
    virtual void switchOnOff(bool turnOn) = 0;
    virtual void showDetails() const = 0;
    virtual void configure() = 0;

    // Common functionality
    static int getTotalDevices()
    {
        return totalDevices;
    }
};

int Device::totalDevices = 0; // Initialize static member

// Derived class SmartBulb
class SmartBulb : public Device
{
private:
    string colour;
    int brightness;
    static int totalSmartBulbs; // Static variable for SmartBulb count
public:
    // Constructor 2
    SmartBulb(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear)
    {
        this->brightness = 5;
        this->colour = "white";
        totalSmartBulbs++; // Increment SmartBulb count
    }

    // Accessors
    string getColour() const
    {
        return colour;
    }
    int getBrightness() const
    {
        return brightness;
    }
    // Destructor 2
    ~SmartBulb()
    {
        totalSmartBulbs--; // Decrement SmartBulb count
    }

    void switchOnOff(bool turnOn) override
    {
        isOn = turnOn;
        cout << deviceName << " is now " << (isOn ? "on" : "off") << endl;
    }

    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: SmartBulb" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (isOn ? "On" : "Off") << endl
             << "Colour: " << colour << endl
             << "Brightness: " << brightness << endl;
    }

    void configure() override
    {
        if (isOn)
        {
            cout << "Set colour: ";
            cin >> colour;
            cout << "Set brightness (1-10): ";
            cin >> brightness;
            if (1 <= brightness && brightness <= 10)
            {
                cout << "Colour set to " << colour << " and brightness set to " << brightness << endl;
            }
            else
            {
                cout << "Invalid brightness. Setting to default (5)." << endl;
                brightness = 5;
            }
        }
        else
        {
            cout << "Turn on the device before configuring." << endl;
        }
    }

    static int getTotalSmartBulbs()
    { // Static member function for SmartBulb count
        return totalSmartBulbs;
    }
};

int SmartBulb::totalSmartBulbs = 0; // Initialize static member

// Derived class Thermostat
class Thermostat : public Device
{
private:
    float temperature;

public:
    // Constructor 3
    Thermostat(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear)
    {
        this->temperature = 22.0;
    }

    // Destructor 3
    ~Thermostat() {}

    void switchOnOff(bool turnOn) override
    {
        isOn = turnOn;
        cout << deviceName << " is now " << (isOn ? "on" : "off") << endl;
    }

    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: Thermostat" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (isOn ? "On" : "Off") << endl
             << "Temperature: " << temperature << "°C" << endl;
    }

    void configure() override
    {
        if (isOn)
        {
            cout << "Set temperature (°C): ";
            cin >> temperature;
            cout << "Temperature set to " << temperature << "°C" << endl;
        }
        else
        {
            cout << "Turn on the device before configuring." << endl;
        }
    }
};

int main()
{
    string deviceType, name_of_device, company;
    int version_year;
    string confirmation;

    cout << "Do you want to connect a device? y(yes) or n(no)" << endl;
    cin >> confirmation;

    if (confirmation == "y")
    {
        cout << "Which device do you want to connect? (SmartBulb->(s)/Thermostat->(t))" << endl;
        cin >> deviceType;

        cout << "Enter the device name, company, and version year:" << endl;
        cin >> name_of_device >> company >> version_year;

        Device *device = nullptr; // Using dynamic allocation

        if (deviceType == "s")
        {
            device = new SmartBulb(name_of_device, company, version_year);
        }

        else if (deviceType == "t")
        {
            device = new Thermostat(name_of_device, company, version_year);
        }
        else
        {
            cout << "Invalid device type." << endl;
            return 1;
        }
        cout << "Do you want to turn on the device? y(yes) or n(no)" << endl;
        cin >> confirmation;
        if (confirmation == "y")
        {
            device->switchOnOff(true);
            device->configure();
        }
        else
        {
            cout << "Device remains off." << endl;
        }

        device->showDetails();

        delete device; // Freeing the allocated memory
    }
    cout << "Total devices created: " << Device::getTotalDevices() << endl;
    cout << "Total smart bulbs created: " << SmartBulb::getTotalSmartBulbs() << endl;

    return 0;
}
