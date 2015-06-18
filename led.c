#include "nimh.h"
#include <hic.h>

extern u8 gBatStateBuf[5];
extern u8 gBatLeveL[4] ;
void LED_ON(u8 led)
{
	switch(led)
	{
		case 1:
			PA0=0;break;
		case 2:
			PA1=0;break;
		case 3:
			PC1=0;break;
		case 4:
			PC0=0;break;
	}
}

void LED_OFF(u8 led)
{
	switch(led)
	{
		case 1:
			PA0=1;break;
		case 2:
			PA1=1;break;
		case 3:
			PC1=1;break;
		case 4:
			PC0=1;break;
	}	
}



void ledHandler(void)
{
	u8 i;
	static u8 count= 0,ledOnFlag=0;

	static u32 ledDispalyTick = 0;
	/*
	//charging state
	if(getSysTick() & SHOW_CHARGING_TICK)
	{
		for(i=1;i<5;i++)
		{	
			if(gBatStateBuf[i] & 0x38)
				LED_ON(i);
		}
	}
	else
	{
		for(i=1;i<5;i++)
		{
			if((gBatStateBuf[i] & 0x38) && (gBatStateBuf[i] & CHARGE_STATE_FULL)==0)
				LED_OFF(i);
		}
	}
	*/
	
	if(getDiffTickFromNow(ledDispalyTick) > LED_DISPLAY_INTERVAL)
	{
		if(getSysTick() & 0x10)
		{
			ledOnFlag = 1;
			if(count !=0)   //first skip
			{
				for(i=1;i<5;i++)
				{
					if(gBatLeveL[i-1] >=count && (gBatStateBuf[i]&(CHARGE_STATE_ERROR | BAT_TYPE_ERROR)) ==0)
						LED_ON(i);
				}
			}
		}
		else
		{
			if(ledOnFlag == 1)
			{
				count++;
				ledOnFlag = 0;				
			}

			for(i=1;i<5;i++)
			{
				if((gBatStateBuf[i] & (CHARGE_STATE_FULL | CHARGE_STATE_ERROR | BAT_TYPE_ERROR)) == 0)
					LED_OFF(i);		
			}
			
			if(count >4)
			{
				count =0;
				ledDispalyTick = getSysTick();
			}
		}
		
	}

	//error state

	if(getSysTick() & 0x08)
	{
		for(i=1;i<5;i++)
		{
			if(gBatStateBuf[i] & ((CHARGE_STATE_ERROR)|(BAT_TYPE_ERROR) ))
				LED_ON(i);	
		}
	}
	else
	{
		for(i=1;i<5;i++)
		{
			if(gBatStateBuf[i] & ((CHARGE_STATE_ERROR)|(BAT_TYPE_ERROR) ))
				LED_OFF(i);		
		}
	}

	
	
}

