/* A LCD Character Display applications
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include <iostream>
#include <sstream>
#include <bus/SPIDevice.h>
#include <sensor/ADC0831.h>
using namespace std;
using namespace exploringBB;

int main(){
   cout << "Starting EBB ADXL345 SPI Test" << endl;
   SPIDevice *busDevice = new SPIDevice(1,0); // Using second SPI bus (both loaded)
   busDevice->setSpeed(500000);
   ADC0831 acc(busDevice);
   cout << "DATA: " << acc.getData() << endl;
   cout << "End of EBB ADXL345 SPI Test" << endl;
}
