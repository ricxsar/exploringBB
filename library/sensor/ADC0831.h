
#ifndef ADC0831_H_
#define ADC0831_H_
//#include"../bus/I2CDevice.h"
#include "../bus/SPIDevice.h"

namespace exploringBB {

/**
 * @class ADC0831
 * @brief Specific class for the ADC0831 Accelerometer
 */
class ADC0831{

private:
	SPIDevice *device;
	int combineValues(unsigned char upper, unsigned char lower);

public:
	ADC0831(SPIDevice *busDevice);
	virtual int getData();

	virtual ~ADC0831();
};

} /* namespace exploringBB */

#endif /* ADC0831_H_ */
