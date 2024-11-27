#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <map>
#include <functional>

using namespace std;

// Configuration Helper Class for SmartWatch
class SmartWatchConfigHelper
{
public:
    static void configureBattery(int &batteryLife)
    {
        cout << "Set battery life (hours): ";
        cin >> batteryLife;
        cout << "Battery life set to " << batteryLife << " hours" << endl;
    }
};

// Configuration Helper Class for SmartSpeaker
class SmartSpeakerConfigHelper
{
public:
    static void configureVolume(int &volumeLevel)
    {
        cout << "Set volume level (1-10): ";
        cin >> volumeLevel;
        if (volumeLevel < 1 || volumeLevel > 10)
        {
            cout << "Invalid volume. Setting to default (5)." << endl;
            volumeLevel = 5;
        }
    }
};

// Configuration Helper Class for SmartBulb
class SmartBulbConfigHelper
{
public:
    static void configureSettings(string &colour, int &brightness)
    {
        cout << "Set colour: ";
        cin >> colour;
        cout << "Set brightness (1-10): ";
        cin >> brightness;
        if (brightness < 1 || brightness > 10)
        {
            cout << "Invalid brightness. Setting to default (5)." << endl;
            brightness = 5;
        }
    }
};

// Configuration Helper Class for Thermostat
class ThermostatConfigHelper
{
public:
    static void configureTemperature(float &temperature)
    {
        cout << "Set temperature (°C): ";
        cin >> temperature;
        cout << "Temperature set to " << temperature << "°C" << endl;
    }
};

// Logging Helper Class
class DeviceLogger
{
public:
    static void logDeviceCreation(const string &deviceName)
    {
        cout << "Device created: " << deviceName << endl;
    }

    static void logDeviceStatus(const string &deviceName, bool isOn)
    {
        cout << deviceName << " is now " << (isOn ? "on" : "off") << endl;
    }
};

// Abstract class
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
        DeviceLogger::logDeviceCreation(deviceName);
    }

public:
    // constructor -1
    Device(string deviceName, string typeOfConnectivity, int versionYear)
        : deviceName(deviceName), typeOfConnectivity(typeOfConnectivity), versionYear(versionYear), isOn(false)
    {
        incrementTotalDevices();
    }

    // Destructor 1
    virtual ~Device() {}

    // Pure virtual functions to be overridden by derived classes
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

// Derived class SmartWatch
class SmartWatch : public Device
{
private:
    int batteryLife;

public:
    // Constructor for SmartWatch
    SmartWatch(string name, string connectivity, int year, int battery)
        : Device(name, connectivity, year), batteryLife(battery) {}

    // Function overriding the pure virtual function
    void switchOnOff(bool turnOn) override
    {
        isOn = turnOn;
        DeviceLogger::logDeviceStatus(deviceName, isOn);
    }

    // Function overriding the pure virtual function
    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: SmartWatch" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (isOn ? "On" : "Off") << endl
             << "Battery Life: " << batteryLife << " hours" << endl;
    }

    // Function overriding the pure virtual function
    void configure() override
    {
        if (isOn)
        {
            SmartWatchConfigHelper::configureBattery(batteryLife);
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

public:
    // Constructor for SmartSpeaker
    SmartSpeaker(string name, string connectivity, int year, int volume)
        : Device(name, connectivity, year), volumeLevel(volume) {}

    // Function overriding the pure virtual function
    void switchOnOff(bool turnOn) override
    {
        isOn = turnOn;
        DeviceLogger::logDeviceStatus(deviceName, isOn);
    }

    // Function overriding the pure virtual function
    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: SmartSpeaker" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (isOn ? "On" : "Off") << endl
             << "Volume Level: " << volumeLevel << endl;
    }

    // Function overriding the pure virtual function
    void configure() override
    {
        if (isOn)
        {
            SmartSpeakerConfigHelper::configureVolume(volumeLevel);
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

public:
    // Constructor 2
    SmartBulb(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear), brightness(5), colour("white")
    {
    }

    // Function overriding the pure virtual function
    void switchOnOff(bool turnOn) override
    {
        isOn = turnOn;
        DeviceLogger::logDeviceStatus(deviceName, isOn);
    }

    // Function overriding the pure virtual function
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

    // Function overriding the pure virtual function
    void configure() override
    {
        if (isOn)
        {
            SmartBulbConfigHelper::configureSettings(colour, brightness);
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

public:
    // Constructor 3
    Thermostat(string deviceName, string typeOfConnectivity, int versionYear)
        : Device(deviceName, typeOfConnectivity, versionYear), temperature(22.0) {}

    // Function overriding the pure virtual function
    void switchOnOff(bool turnOn) override
    {
        isOn = turnOn;
        DeviceLogger::logDeviceStatus(deviceName, isOn);
    }

    // Function overriding the pure virtual function
    void showDetails() const override
    {
        cout << "Device Name: " << deviceName << endl
             << "Type: Thermostat" << endl
             << "Type of Connectivity: " << typeOfConnectivity << endl
             << "Version Year: " << versionYear << endl
             << "Status: " << (isOn ? "On" : "Off") << endl
             << "Temperature: " << temperature << "°C" << endl;
    }

    // Function overriding the pure virtual function
    void configure() override
    {
        if (isOn)
        {
            ThermostatConfigHelper::configureTemperature(temperature);
        }
        else
        {
            cout << "Turn on the device before configuring." << endl;
        }
    }
};

// Factory class for creating devices
class DeviceFactory
{
private:
    map<int, function<Device *(const string &, const string &, int)>> deviceCreators;

public:
    DeviceFactory()
    {
        // Register existing device types
        deviceCreators[1] = [](const string &name, const string &connectivity, int year)
        {
            return new SmartWatch(name, connectivity, year, 24);
        };
        deviceCreators[2] = [](const string &name, const string &connectivity, int year)
        {
            return new SmartSpeaker(name, connectivity, year, 5);
        };
        deviceCreators[3] = [](const string &name, const string &connectivity, int year)
        {
            return new SmartBulb(name, connectivity, year);
        };
        deviceCreators[4] = [](const string &name, const string &connectivity, int year)
        {
            return new Thermostat(name, connectivity, year);
        };
    }

    Device *createDevice(int deviceType, const string &name, const string &connectivity, int year)
    {
        if (deviceCreators.find(deviceType) != deviceCreators.end())
        {
            return deviceCreators[deviceType](name, connectivity, year);
        }
        cout << "Invalid device type." << endl;
        return nullptr;
    }
};

int main()
{
    DeviceFactory factory;
    map<int, Device *> devices;
    int choice;
    int deviceCount = 0;

    do
    {
        cout << "\n==== Smart Device Hub ====\n";
        cout << "1. Add Device\n";
        cout << "2. Switch Device On/Off\n";
        cout << "3. Configure Device\n";
        cout << "4. Show Device Details\n";
        cout << "5. Show Total Devices\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\nSelect Device Type:\n";
            cout << "1. SmartWatch\n";
            cout << "2. SmartSpeaker\n";
            cout << "3. SmartBulb\n";
            cout << "4. Thermostat\n";
            cout << "Enter your choice: ";
            int deviceType;
            cin >> deviceType;

            string name, connectivity;
            int year;

            cout << "Enter device name: ";
            cin >> name;
            cout << "Enter connectivity type (e.g., WiFi, Bluetooth): ";
            cin >> connectivity;
            cout << "Enter version year: ";
            cin >> year;

            Device *device = factory.createDevice(deviceType, name, connectivity, year);
            if (device)
            {
                devices[++deviceCount] = device;
                cout << "Device added with ID: " << deviceCount << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Enter device ID to switch on/off: ";
            int deviceID;
            cin >> deviceID;

            if (devices.find(deviceID) != devices.end())
            {
                cout << "Enter 1 to switch on, 0 to switch off: ";
                bool turnOn;
                cin >> turnOn;
                devices[deviceID]->switchOnOff(turnOn);
            }
            else
            {
                cout << "Invalid device ID.\n";
            }
            break;
        }
        case 3:
        {
            cout << "Enter device ID to configure: ";
            int deviceID;
            cin >> deviceID;

            if (devices.find(deviceID) != devices.end())
            {
                devices[deviceID]->configure();
            }
            else
            {
                cout << "Invalid device ID.\n";
            }
            break;
        }
        case 4:
        {
            cout << "Enter device ID to show details: ";
            int deviceID;
            cin >> deviceID;

            if (devices.find(deviceID) != devices.end())
            {
                devices[deviceID]->showDetails();
            }
            else
            {
                cout << "Invalid device ID.\n";
            }
            break;
        }
        case 5:
        {
            cout << "Total devices created: " << Device::getTotalDevices() << endl;
            break;
        }
        case 6:
        {
            cout << "Exiting...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    // Cleanup: Delete all dynamically allocated devices
    for (auto &pair : devices)
    {
        delete pair.second;
    }

    return 0;
}
