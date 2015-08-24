#ifndef __NIMH_H__
#define __NIMH_H__


#define u8	unsigned char
#define u16	unsigned int
#define u32	unsigned long

#define	LED1	PA0
#define	LED2	PA1
#define	LED3	PC1
#define	LED4	PC0


#define PWM_ON	1
#define PWM_OFF	 0

#define SYS_CHARGING_STATE	0x00
#define SYS_DISCHARGE_STATE	0x10

#define	BAT_MAX_LABEL 		4

#define	BAT_ADD			0
#define	BAT_REMOVE		1


#define HAS_BATTERY		0x01   

#define CHARGE_STATE_ALL		0x3C

#define BAT_TYPE_ERROR						(1<<7)
#define CHARGE_STATE_ERROR				(1<<6)
#define CHARGE_STATE_PRE					(1<<5)
#define CHARGE_STATE_FAST					(1<<4)
#define CHARGE_STATE_TRICK					(1<<3)
#define CHARGE_STATE_FULL					(1<<2)
#define BAT_DETECT_BIT						(1<<1)   //电池测试
#define BAT_CHECK_BIT						(1<<0)   //有无电池

#if 1
#define BAT_MIN_VOLT_33_OPEN	472		//(0.3/2.6)*4096
#define BAT_MIN_VOLT_OPEN	372 			//(0.3/3.3)*4096
#define BAT_MAX_VOLT_OPEN	2110		//(1.7/3.3)*4096

#define BAT_MIN_VOLT_OPEN_SPE	372 			//(0.3/3.3)*4096

#define BAT_MAX_VOLT_CLOSE 2358		//(1.9/3.3*4096)        (1.8/3.3)*4096	


#define BAT_LEVEL_LOW_TO_MIDD		1737			// 1.4     (1.4/3.3)*4096
#define BAT_LEVEL_MIDD_TO_HIGH		1750				//  1.41	(1.41/3.3)*4096

#define CHARGING_PRE_END_VOLT		1117			//(0.9/3.3)*4096
#define CHARGING_FAST_END_VOLT	1799			//(1.45/3.3)*4096
#define CHARGING_FAST_MAX_VOLT	1986			//(1.6/3.3)*4096

#define CHARGING_FAST_TEMP_END_VOLT	1799			// (1.45/3.3)*4096
#else
#define BAT_MIN_VOLT_33_OPEN	472		//(0.3/2.6)*4096
#define BAT_MIN_VOLT_OPEN	186 			//(0.3/3.3)*4096
#define BAT_MAX_VOLT_OPEN	1055		//(1.7/3.3)*4096


#define BAT_MAX_VOLT_CLOSE 1117		//(1.8/3.3)*4096	


#define BAT_LEVEL_LOW_TO_MIDD		868			// 1.4     (1.4/3.3)*4096
#define BAT_LEVEL_MIDD_TO_HIGH		875				//  1.41	(1.41/3.3)*4096

#define CHARGING_PRE_END_VOLT		558			//(0.9/3.3)*4096
#define CHARGING_FAST_END_VOLT	900			//(1.45/3.3)*4096
#define CHARGING_FAST_MAX_VOLT	993			//(1.6/3.3)*4096

#define CHARGING_FAST_TEMP_END_VOLT	900			// (1.45/3.3)*4096
#endif

#define BAT_LEVEL_LOW	1
#define BAT_LEVEL_MIDD	2
#define BAT_LEVEL_HIGH	3




#define BAT_CHARGING_PULSE_TIME	61   //2000ms  2000/16.384
#define BAT_CHARGING_PULSE_DELAY_TIME	67//1100ms
#define BAT_CHARGING_DETECT_TIME	122
#define BAT_CHARGING_PWMOFF_DETECT_TIME	90		// 1.5S	

#define BAT_CHARGING_TEST_TIME	20	
#define BAT_CHARGING_TRICK_TIME	12

#define BAT_CHARGING_PRE_MAX_TIME	73242	//20min   (20*60*1000)/16.384
#define BAT_CHARGING_FAST_MAX_TIME	 1098632             //  5hour  (5*60*60*1000)/16.384
#define BAT_START_DV_CHECK			18310			   // 5min  (5*60*1000)/16.384

#define BAT_DV_CHECK_INTERVAL			305			//5s  5*1000/16.384
#define ADC_DV_VOLT						6			//5mv   0.005/3.3*4096


#define FAST_SKIP_COUNT	0
#define SUP_SKIP_COUNT		0
#define PRE_SKIP_COUNT		0
#define TRI_SKIP_COUNT		10
#define DUMMY_SKIP_COPUNT	0xFF

#define DisWatchdog()	RCEN=0
#define EnWatchdog()		RCEN=1

#define t8n_start()	T8NEN=1
#define t8n_stop()	T8NEN=0

#define t8p1_start()	T8P1E=1
#define t8p1_stop()	T8P1E=0


#define CHANNEL_VBAT_1	8
#define CHANNEL_VBAT_2 4
#define CHANNEL_VBAT_3	12
#define CHANNEL_VBAT_4	2


#define CHANNEL_TEMP_1		3
#define CHANNEL_TEMP_2		3

#define CHANNEL_20_RES	9

#define 	ADC_TEMP_MAX	1069    //55
#define	ADC_TEMP_MIN	3007	//0

#define BAT_VALID_VALUE	787

#define SHOW_CHARGING_TICK	0x40

#define LED_DISPLAY_INTERVAL	122		// 2s 2*1000/16.384


//output
#define OUTPUT_STATUS_WAIT	0
#define OUTPUT_STATUS_NORMAL	1
#define OUTPUT_STATUS_STOP	2
#define MIN_VBAT_CHANNEL_1_IDLE	 2916  //(4.7/2=2.4V   2.4/3.3*4096)
#define MIN_VBAT_OUPUT				620	//(1/2=0.5	0.5/3.3*4096)
#define OUTPUT_CHECK_INTERVAL		31	//(500/16.384	31)

#define ENABLE_BOOST()	PB7=1
#define DISABLE_BOOST()	PB7=0

u32 getSysTick();
u32 getDiffTickFromNow(u32 ttick);
void ledHandler(void);
void delay_us(u16);
u32 getBatTick();
	
u16 getVbatAdc(u8 channel);
u16 getAverage(u8 channel);
u16 getBatTemp(u8 batNum);

void send(u16 sData);
void sendStr(char str[]);
void sendF(u32 sData);

void LED_OFF(u8 led);
void LED_ON(u8 led);

void delay_ms(u16 nus);
#endif
