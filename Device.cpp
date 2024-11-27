#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

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
    {
        this->deviceName = deviceName;
        this->typeOfConnectivity = typeOfConnectivity;
        this->versionYear = versionYear;
        this->isOn = false;
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
        cout << deviceName << " is now " << (isOn ? "on" : "off") << endl;
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
    ~SmartBulb() {}

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

    // Destructor 3
    ~Thermostat() {}

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

    return 0;
}
