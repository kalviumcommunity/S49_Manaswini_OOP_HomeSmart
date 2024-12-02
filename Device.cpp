#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;
// Abstract class
class Device
{

protected:
    string deviceName;
    string typeOfConnectivity;
    int versionYear;
    bool deviceStatus;
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
        : deviceName(deviceName),
          typeOfConnectivity(typeOfConnectivity),
          versionYear(versionYear)
    {
        incrementTotalDevices();
    }

    // Destructor 1
    virtual ~Device() = default;

    // Pure virtual functions to be overridden by derived classes
    virtual bool isDeviceOn() const = 0;
    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
    virtual void showDetails() const = 0;
    virtual void configure() = 0;

    // Common functionality
    static int getTotalDevices()
    {
        return totalDevices;
    }

    // Getter methods for base class properties
    string getDeviceName() const { return deviceName; }
    string getConnectivityType() const { return typeOfConnectivity; }
    int getVersionYear() const { return versionYear; }
};

int Device::totalDevices = 0; // Initialize static member

// Derived class SmartWatch
class SmartWatch : public Device
{
private:
    int batteryLife;
    bool deviceStatus;

public:
    // Constructor for SmartWatch
    SmartWatch(string name, string connectivity, int year, int battery)
        : Device(name, connectivity, year), batteryLife(battery), deviceStatus(false) {}

    // Function to show specific details

    bool isDeviceOn() const override
    {
        return deviceStatus;
    }

    void switchOn() override
    {
        deviceStatus = true;
        cout << deviceName << " is now on" << endl;
    }

    void switchOff() override
    {
        deviceStatus = false;
        cout << deviceName << " is now off" << endl;
    }

    // Function overriding the pure virtual function
    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: SmartWatch" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (deviceStatus ? "On" : "Off") << endl
             << "Battery Life: " << batteryLife << " hours" << endl;
    }

    // Function overriding the pure virtual function
    void configure() override
    {
        if (deviceStatus)
        {
            cout << "Set battery life (hours): ";
            cin >> batteryLife;
            cout << "Battery life set to " << batteryLife << " hours" << endl;
        }
        else
        {
            cout << "Turn on the device before configuring." << endl;
        }
    }
};

// Derived class SmartSpeaker
class SmartSpeaker : public Device
{
private:
    int volumeLevel;
    bool deviceStatus;

public:
    // Constructor for SmartSpeaker
    SmartSpeaker(string name, string connectivity, int year, int volume)
        : Device(name, connectivity, year), volumeLevel(volume), deviceStatus(false) {}

    // Function to show specific details
    bool isDeviceOn() const override
    {
        return deviceStatus;
    }

    void switchOn() override
    {
        deviceStatus = true;
        cout << deviceName << " is now on" << endl;
    }

    void switchOff() override
    {
        deviceStatus = false;
        cout << deviceName << " is now off" << endl;
    }

    // Function overriding the pure virtual function
    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: SmartSpeaker" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (deviceStatus ? "On" : "Off") << endl
             << "Volume Level: " << volumeLevel << endl;
    }

    // Function overriding the pure virtual function
    void configure() override
    {
        if (deviceStatus)
        {
            cout << "Set volume level (1-10): ";
            cin >> volumeLevel;
            if (1 <= volumeLevel && volumeLevel <= 10)
            {
                cout << "Volume level set to " << volumeLevel << endl;
            }
            else
            {
                cout << "Invalid volume level. Setting to default (5)." << endl;
                volumeLevel = 5;
            }
        }
        else
        {
            cout << "Turn on the device before configuring." << endl;
        }
    }
};

// Derived class SmartBulb
class SmartBulb : public Device
{
private:
    string colour;
    int brightness;
    bool deviceStatus;

public:
    // Constructor 2
    SmartBulb(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear), brightness(5), colour("white"), deviceStatus(false)
    {
    }

    // Accessors
    bool isDeviceOn() const override
    {
        return deviceStatus;
    }

    void switchOn() override
    {
        deviceStatus = true;
        cout << deviceName << " is now on" << endl;
    }

    void switchOff() override
    {
        deviceStatus = false;
        cout << deviceName << " is now off" << endl;
    }

    // Function overriding the pure virtual function
    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: SmartBulb" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (deviceStatus ? "On" : "Off") << endl
             << "Colour: " << colour << endl
             << "Brightness: " << brightness << endl;
    }

    // Function overriding the pure virtual function
    void configure() override
    {
        if (deviceStatus)
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
};

// Derived class Thermostat
class Thermostat : public Device
{
private:
    float temperature;
    bool deviceStatus;

public:
    // Constructor 3
    Thermostat(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear), temperature(22.0), deviceStatus(false) {}

    // Destructor 3
    ~Thermostat() {}

    // Function overriding the pure virtual function
    bool isDeviceOn() const override
    {
        return deviceStatus;
    }

    void switchOn() override
    {
        deviceStatus = true;
        cout << deviceName << " is now on" << endl;
    }

    void switchOff() override
    {
        deviceStatus = false;
        cout << deviceName << " is now off" << endl;
    }

    // Function overriding the pure virtual function
    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: Thermostat" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (deviceStatus ? "On" : "Off") << endl
             << "Temperature: " << temperature << "°C" << endl;
    }

    // Function overriding the pure virtual function
    void configure() override
    {
        if (deviceStatus)
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
    string name_of_device, connectivity;
    int deviceType, version_year;
    string confirmation;

    cout << "Do you want to connect a device? y(yes) or n(no)" << endl;
    cin >> confirmation;

    if (confirmation == "y")
    {
        cout << "Which device do you want to connect? (SmartWatch(1)/SmartSpeker(2)/SmartBulb->(3)/Thermostat->(4))" << endl;
        cin >> deviceType;

        cout << "Enter the device name" << endl;
        cin >> name_of_device;
        cout << "Enter the type of connectivity" << endl;
        cin >> connectivity;
        cout << "Enter the version year" << endl;
        cin >> version_year;

        // Create a device object based on the user input [Runtime Polymorphism]
        Device *device = nullptr;
        if (deviceType == 1)
        {
            device = new SmartWatch(name_of_device, connectivity, version_year, 24);
        }
        else if (deviceType == 2)
        {
            device = new SmartSpeaker(name_of_device, connectivity, version_year, 5);
        }
        else if (deviceType == 3)
        {
            device = new SmartBulb(name_of_device, connectivity, version_year);
        }

        else if (deviceType == 4)
        {
            device = new Thermostat(name_of_device, connectivity, version_year);
        }
        else
        {
            cout << "Invalid device type." << endl;
            delete device;
            return 1;
        }
        cout << "Do you want to turn on the device? y(yes) or n(no)" << endl;
        cin >> confirmation;
        if (confirmation == "y")
        {
            device->switchOn(); // New method instead of switchOnOff
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

    return 0;
}
