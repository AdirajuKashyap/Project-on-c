
#include<stdio.h>
float consumption_perDay(float x,float y,float h)

{
    float z;
    z=x*y*h;
    return z;
}
float consumption_perMonth(float power_consumption,int s,float m)

{

    float days;
    if(m==1||m==12||m==3||m==5||m==7||m==8||m==10)
    {
        days=31;
    }
    else if(m==4||m==6||m==11||m==9)
    {
        days=30;
    }
    else if(s==0 && m==2)
    {
        days=29;
    }
    else if(s>0 && m==2)
    {
        days=28;
    }
    return power_consumption*days;
}
float billCalculator(float units)
{
    float bill = 0;
    if (units <= 30)
    {
        bill = units * 1.9;
    }
    else if (units <= 75)
    {
        bill = (30 * 1.9) + ((units-30) * 3);
    }
    else if (units <= 125)
    {
        bill = (30 * 1.9) + (45 * 3) + ((units-75) * 4.5);
    }
    else if (units <= 225)
    {
        bill = (30 * 1.9) + (45 * 3) + (100 * 4.5) + ((units-125) * 6);
    }
    else if (units <= 400)
    {
        bill = (30 * 1.9) + (45 * 3) + (100 * 4.5) + (175 * 6) + ((units-225) * 8.75);
    }
    else
    {
        bill = (100 * 0.5) + (100 * 0.75) + (100 * 1.00) + ((units-400) * 9.75);
    }
    return bill;
}
float check_fine(float unpaid_bill)
{
    int fine;
    if(unpaid_bill > 0)
    {
        fine = 50;
    }
    else
    {
        fine = 0;
    }
    return fine;
}
int main()
{
    float total_Lights,total_Fans,total_TVs,total_Heaters,total_Fridges,total_ACs;
    float Light_usage,Fan_usage,TV_usage,Heater_usage,Fridge_usage,AC_usage;
    float Light_power,Fan_power,TV_power,Heater_power,AC_power,Fridge_power;
    float dailyUsage_Light,dailyUsage_Fan,dailyUsage_TV,dailyUsage_Heater,dailyUsage_AC,dailyUsage_Fridge;
    float monthlyUsage_Light,monthlyUsage_Fan,monthlyUsage_TV,monthlyUsage_Heater,monthlyUsage_AC,monthlyUsage_Fridge;
    float dailyUsage,monthlyUsage,Units,cost_per_Unit,total_bill,unpaid_bill,fine;

    float month;
    int year;
    int s;
   
    printf("\nEnter the year : ");
    scanf("%d",&year);
    printf("\nEnter the month's number : ");
    scanf("%f",&month);
    printf("\nEnter the no of Lights used : ");
    scanf("%f",&total_Lights);
    printf("\nEnter the no of Hours the Lights are used : ");
    scanf("%f",&Light_usage);
    printf("\nEnter the no of Fans used : ");
    scanf("%f",&total_Fans);
    printf("\nEnter the no of Hours the Fans are used : ");
    scanf("%f",&Fan_usage);
    printf("\nEnter the no of TVs used : ");
    scanf("%f",&total_TVs);
    printf("\nEnter the no of Hours the TVs are used : ");
    scanf("%f",&TV_usage);
    printf("\nEnter the no of Heaters used : ");
    scanf("%f",&total_Heaters);
    printf("\nEnter the no of Hours the Heaters are used : ");
    scanf("%f",&Heater_usage);
    printf("\nEnter the no of ACs used : ");
    scanf("%f",&total_ACs);
    printf("\nEnter the no of Hours the ACs are used : ");
    scanf("%f",&AC_usage);
    printf("\nEnter the no of Fridges used : ");
    scanf("%f",&total_Fridges);
    printf("\nEnter the no of Hours the Fridges are used : ");
    scanf("%f",&Fridge_usage);
    printf("\nEnter the Power Consumption of a Light (ref:10w) : ");
    scanf("%f",&Light_power);
    printf("\nEnter the Power Consumption of a Fan (ref:75w) : ");
    scanf("%f",&Fan_power);
    printf("\nEnter the Power Consumption of a TV (ref:100w) : ");
    scanf("%f",&TV_power);
    printf("\nEnter the Power Consumption of a Heater (ref:1000w) : ");
    scanf("%f",&Heater_power);
    printf("\nEnter the Power Consumption of an AC (ref:1200w) : ");
    scanf("%f",&AC_power);
    printf("\nEnter the Power Consumption of a Fridge (ref:150w) : ");
    scanf("%f",&Fridge_power);
    printf("\nEnter the unpaid bill amount : ");
    scanf("%f",&unpaid_bill);
   
    if(year%4==0 && year%100 !=0)
    s=0;
    else if(year%100==0 && year%400==0)
    s=0;
    else
    s=1;
    fine=check_fine(unpaid_bill);
    dailyUsage_Light=consumption_perDay(total_Lights,Light_usage,Light_power);
    dailyUsage_Fan=consumption_perDay(total_Fans,Fan_usage,Fan_power);
    dailyUsage_TV=consumption_perDay(total_TVs,TV_usage,TV_power);
    dailyUsage_Heater=consumption_perDay(total_Heaters,Heater_usage,Heater_power);
    dailyUsage_AC=consumption_perDay(total_ACs,AC_usage,AC_power);
    dailyUsage_Fridge=consumption_perDay(total_Fridges,Fridge_usage,Fridge_power);
    printf("\n-------------Power consumption Per Day--------------\n");
    printf("\n\nPower used by the Lights in a day : %.1f W\n",dailyUsage_Light);
    printf("Power used by the Fans in a day : %.1f W\n",dailyUsage_Fan);
    printf("Power used by the TVs in a day : %.1f W\n",dailyUsage_TV);
    printf("Power used by the Heaters in a day : %.1f W\n",dailyUsage_Heater);
    printf("Power used by the ACs in a day : %.1f W\n",dailyUsage_AC);
    printf("Power used by the Fridges in a day : %.1f W\n",dailyUsage_Fridge);
    monthlyUsage_Light=consumption_perMonth(dailyUsage_Light,s,month);
    monthlyUsage_Fan=consumption_perMonth(dailyUsage_Fan,s,month);
    monthlyUsage_TV=consumption_perMonth(dailyUsage_TV,s,month);
    monthlyUsage_Heater=consumption_perMonth(dailyUsage_Heater,s,month);
    monthlyUsage_AC=consumption_perMonth(dailyUsage_AC,s,month);
    monthlyUsage_Fridge=consumption_perMonth(dailyUsage_Fridge,s,month);
    printf("\n------------Power consumption Per Month-------------\n");
    printf("\nPower used by Lights in a month : %.1f W\n",monthlyUsage_Light);
    printf("Power used by Fans in a month : %.1f W\n",monthlyUsage_Fan);
    printf("Power used by TVs in a month : %.1f W\n",monthlyUsage_TV);
    printf("Power used by Heaters in a month : %.1f W\n",monthlyUsage_Heater);
    printf("Power used by ACs in a month : %.1f W\n",monthlyUsage_AC);
    printf("Power used by Fridges in a month : %.1f W\n",monthlyUsage_Fridge);
    dailyUsage=dailyUsage_Light+dailyUsage_Fan+dailyUsage_TV+dailyUsage_Heater+dailyUsage_AC+dailyUsage_Fridge;
    monthlyUsage=monthlyUsage_Light+monthlyUsage_Fan+monthlyUsage_TV+monthlyUsage_Heater+monthlyUsage_AC+monthlyUsage_Fridge;
    Units=monthlyUsage/1000;
    printf("\n---------------Summary----------------\n");
    printf("\nTotal Power load in a day : %.1f W\nTotal Power load in a month : %.1f W\nTotal Units consumed in a month : %.1f \n",dailyUsage,monthlyUsage,Units);
    printf("fine/reconnection charges : %.1f/-",fine);
    total_bill=billCalculator(Units) + unpaid_bill + fine;
    printf("\nElectricity Bill is %.1f/-",total_bill);

return 0;
}



