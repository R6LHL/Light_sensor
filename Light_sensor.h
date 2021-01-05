#ifndef _LIGHT_SENSOR_H
#define _LIGHT_SENSOR_H

#include <Arduino.h>

typedef unsigned char pin_num;

enum state
			{
				smoke_is_present = true,
				smoke_is_absent = false,
			};

template <unsigned const int T_ADC> // bit depth of ADC
class Light_sensor //: public Potentiometer
{
	public:
		
		Light_sensor(pin_num analog, pin_num digital){ //: Potentiometer<T_ADC>(analog){
			pinMode(digital, INPUT_PULLUP);
			pinMode(analog, INPUT);
			analog_pin = analog;
			digital_pin = digital;
		}
		
		Light_sensor(pin_num digital){
			pinMode(digital, INPUT_PULLUP);
			digital_pin = digital;
		}
		
		unsigned const char getState(void) {return digitalRead(digital_pin);}
		float getValueAsCoeff(void) {
			int adc = analogRead(analog_pin);
			int adc_bit_depth = (T_ADC - 1);
			return ((float)adc/(float)adc_bit_depth);
			}
		unsigned int getValue(void) {return analogRead(analog_pin);}
		
	private:
		
		pin_num digital_pin;
		pin_num analog_pin;
		
		/*
		typedef Potentiometer<T_ADC> Potentiometer_new;
		Potentiometer_new photosensor(analog_pin);
		*/
		
	
};

#endif //_LIGHT_SENSOR_H
