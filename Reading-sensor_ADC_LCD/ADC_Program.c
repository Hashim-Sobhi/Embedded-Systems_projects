/************************************************************/
/** author  :Hashim Sobhy                                   **/
/** Date    :2021/5/7                                       **/
/** Version :1.0                                            **/
/** Title   :ADC Driver                                     **/
/** Subtitle:ADC Program                                    **/
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "ADC_Register.h"
void ADC_ViodInit(void)
{
	//select Vref = Avcc =5v
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	
	// ADC Data Right Adjustment
	CLR_BIT(ADMUX,ADLAR);
	
	//Enable ADC
	SET_BIT(ADCSRA,ADEN);
	
	//Single conversion
	SET_BIT(ADCSRA,ADATE);
	
	//Disable ADC enable
	CLR_BIT(ADCSRA,ADIE);
	
	//Prescaller 64
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
}
u16 ADC_U16ReadValue(u8 channel)
{
	// ADC Channel Selection
	ADMUX &= 0xE0;
	ADMUX |=channel;
	
	// Start Single Convertion
	SET_BIT(ADCSRA,ADSC);
	
	//wait for the conversion
	while (GET_BIT(ADCSRA,ADIF)==0)
	{
		
	}
	
	// clear flag
	CLR_BIT(ADCSRA,ADIF);
	return ADC_D;
}