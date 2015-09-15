
#include "ADC0831.h"
#include <iostream>
#include "ADC0831.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>

using namespace std;

namespace exploringBB {

/**
 * The constructor for the ADC0831 accelerometer object. It passes the bus number and the
 * device address (with is 0x53 by default) to the constructor of I2CDevice. All of the states
 * are initialized and the registers are updated.
 * @param I2CBus The bus number that the ADC0831 device is on - typically 0 or 1
 * @param I2CAddress The address of the ADLX345 device (default 0x53, but can be altered)
 */

ADC0831::ADC0831(SPIDevice *busDevice){
	//this->I2CAddress = I2CAddress;
	//this->I2CBus = I2CBus;
	this->device = busDevice;
}

int ADC0831::combineValues(unsigned char upper, unsigned char lower){
   return (((int)upper<<2)&0b11111100)|((int)lower>>6)&0b00000011;
}

/**
 * Read the sensor state. This method checks that the device is being correctly
 * read by using the device ID of the ADC0831 sensor. It will read in the accelerometer registers
 * and pass them to the combineRegisters() method to be processed.
 * @return 0 if the registers are successfully read and -1 if the device ID is incorrect.
 */
int ADC0831::getData(){
	unsigned char tx[] = {0x00, 0x00};
	unsigned char rx[sizeof(tx)];

	this->device->transfer(tx, rx, sizeof(tx));
	return this->combineValues(rx[0], rx[1]);
}

ADC0831::~ADC0831() {}

} /* namespace exploringBB */
