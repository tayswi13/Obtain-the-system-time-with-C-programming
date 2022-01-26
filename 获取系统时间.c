#include <stdio.h>
#include <time.h>
#include <string.h> 
#include <stdlib.h>

typedef struct Date
{
    int da_year;  
    int da_mon;  
    int da_day;  
}DATE;
typedef struct Time
{
    int ti_hour;   
    int ti_min;   
    int ti_sec;    
}TIME;

void getTime(DATE *pdate,TIME *ptime)
{
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime ( &rawtime );
    char mytime[80];
    strcpy(mytime,asctime(timeinfo));
    char year[4],mouth[3],day[2],hour[2],min[2],sec[2];
    int i,j;
    for(i=20,j=0;j<4;i++,j++) year[j]=mytime[i];
    for(i=4,j=0;j<3;i++,j++) mouth[j]=mytime[i];
    for(i=8,j=0;j<2;i++,j++) day[j]=mytime[i];
    for(i=11,j=0;j<2;i++,j++) hour[j]=mytime[i];
    for(i=14,j=0;j<2;i++,j++) min[j]=mytime[i];
    for(i=17,j=0;j<2;i++,j++) sec[j]=mytime[i];
    pdate->da_year=atoi(year);
    pdate->da_day=atoi(day);
    ptime->ti_hour=atoi(hour);
    ptime->ti_min=atoi(min);
    ptime->ti_sec=atoi(sec);
    if(*mouth=='J') pdate->da_mon=1;
    else if(*mouth=='F') pdate->da_mon=2;
    else if(*mouth=='M'){
    	if(*(mouth+2)=='r') pdate->da_mon=3;
    	else pdate->da_mon=5;
	}
	else if(*mouth=='A'){
		if(*(mouth+1)=='p') pdate->da_mon=4;
		else pdate->da_mon=8;
	}
	else if(*mouth=='J'){
		if(*(mouth+2)=='n') pdate->da_mon=6;
		else pdate->da_mon=7;
	}
	else if(*mouth=='S') pdate->da_mon=9;
	else if(*mouth=='O') pdate->da_mon=10;
	else if(*mouth=='N') pdate->da_mon=11;
	else if(*mouth=='D') pdate->da_mon=12;
    printf ( "The current date/time is: %s", mytime );
}

int  main ()
{
    DATE date;
    TIME time;
    getTime(&date,&time);
    printf("year:%d,month:%d,day:%d\nhour:%d,min:%d,sec:%d\n",date.da_year,date.da_mon,date.da_day,time.ti_hour,time.ti_min,time.ti_sec);
    return 0;
}
