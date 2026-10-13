# MESS RCOS

The MESS (Mesh Environment Sensor System) goal is to connect multiple ESP-32 CDevKits with various sensors through network programming with the intent to 
read environmental data of chosen location. The environmental data is going to be used to scientifically compare one system to another analytical tools 
made in R so we can see statistics like thermal lag, HVAC performance, statistical differences compared to an ideal environment, air-quality, etc...

The goal in comparing environments is to detect abnormalities of buildings compared to an ideal building, which is why we will compare data of old and new 
buildings at Rensselaer Polytechnic Institute.  

## Description

MESS stands for Mesh Environment Sensor System which is a wireless network system consisting of individual nodes, in this case ESP-32 CDevKits,
which communicate with each other and relay data across multiple paths to a central gateway. 

This project works by programming multiple (4) ESP-32 CDevKits with >1 sensors which are connected using network programming, the data collected will be 
stored in an SQL environment, and the data will be analyzed and projected using SI units with graphs and plots. All of the data and analysis will be made 
available using a local hosted website. 


## Getting Started

### Dependencies

This project relies on the following core tools and frameworks:
* C (GCC compiler)
* C-Make
* ESP-IDF SDK

Uncertain tools and frameworks 
* Postgresql ( will require an SQL server to store data later on + database management )
* HTML/CSS/Javascript ( Will require for a website UI )
* R ( Will most likely be used for analytical analysis )

### Installing

* **[C-MAKE] (https://cmake.org/download/)** 
* **[C / GCC compiler] (https://installc.org/)**
* **[ESP-IDF SDK] (https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html)** 

NOTE:
This project was developed on an ARCH-linux OS and as such some packages were installed using pacman and the AUR instead of installing
the provided binaries.

### Executing program
The program must be executed inside MESS-RCOS folder and after running build, it will create a /build/ folder and sdkconfig file 
must not be deleted and is required to flash and monitor the program.

```
idf.py set-target esp32 // to initialize the project.
idf.py build //to compile and build the project

// PORT is the ESP32’s serial connection

idf.py -p PORT flash //Flashes program onto ESP32
idf.py -p PORT monitor //Shows output of ESP32 program while running
```

## Help

Troubleshooting tips:
* finding PORT when needing it to run something like "idf.py -p PORT flash" 
```
ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null //POSIX shell syntax
```
* How do I stop monitoring the program OR reset the program?
```
/*
1. To reset the program to line 01, press EN / RESET while plugged in.
2. To stop monitoring the output press "CTRL + C" or "CTRL + ]". NOTE: this will not stop the program
*/
```

## Authors

Contributors names and contact info:

* Alfredo Martinez-Melchor

## Version History

* 0.1.0
    * Initial Release: This tag defines the end of exploration into hardware programming and shifting into my teams assigned roles as software/datasci developers.
    This tag was meant to allow individuals the opportunity to learn about hardware/firmware while using embedded programming using ESP-IDF, however after this tag
    I will follow the parent repository listed in acknowledgements where someone will do the hardware will me and my team does the software/datasci roles.  

## License

This project is licensed under the MIT License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [C-MAKE ESP-IDF Documentation](https://docs.espressif.com/projects/esp-idf/en/v3.3/api-guides/build-system-cmake.html?highlight=cmakelists%20txt)
* [Inter-Integrated Circuit (I2C) documentation](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/i2c.html#_CPPv423i2c_master_bus_config_t)
* [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html)
* [esp-dev-kits Repo](https://github.com/espressif/esp-dev-kits/tree/master/docs/en/esp32-devkitc)
* [ESP-IDF repo](https://github.com/espressif/esp-idf/tree/v6.1)