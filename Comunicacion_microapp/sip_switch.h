/*
 * sip_switch.h
 *
 * Created: 2/02/2022 8:08:13 p. m.
 *  Author: lucho
 */ 


#ifndef SIP_SWITCH_H_
#define SIP_SWITCH_H_

int dp_init(int);
char* dp_read(int,int,int,int);

int dp_init(int bit){
	if(PIND & (1<<bit)){
		return 0;
	}
	else 
	return 1;
}
char* dp_read(int s1,int s2,int s3,int s4){
char* sensor="luis";

	if((s1==0) & (s2==0) & (s3==0) & (s4==0)){
		sensor="0";//M0
	}
	else if ((s1==0) & (s2==0) & (s3==0) & (s4==1)){
		sensor="1";//M1
	}
	else if ((s1==0) & (s2==0) & (s3==1) & (s4==0)){
		sensor="1";//M2
	}
	else if ((s1==0) & (s2==0) & (s3==1) & (s4==1)){
		sensor="2";//M3
	}
	else if ((s1==0) & (s2==1) & (s3==0) & (s4==0)){
		sensor="1";//M4
	}
	else if ((s1==0) & (s2==1) & (s3==0) & (s4==1)){
		sensor="2";//M5
	}
	else if ((s1==0) & (s2==1) & (s3==1) & (s4==0)){
		sensor="2";//M6
	}
	else if ((s1==0) & (s2==1) & (s3==1) & (s4==1)){
		sensor="3";//M7
	}
	else if ((s1==1) & (s2==0) & (s3==0) & (s4==0)){
		sensor="1";//M8
	}
	else if ((s1==1) & (s2==0) & (s3==0) & (s4==1)){
		sensor="2";//M9
	}
	else if ((s1==1) & (s2==0) & (s3==1) & (s4==0)){
		sensor="2";//M10
	}
	else if ((s1==1) & (s2==0) & (s3==1) & (s4==1)){
		sensor="3";//M11
	}
	else if ((s1==1) & (s2==1) & (s3==0) & (s4==0)){
		sensor="2";//M12
	}
	else if ((s1==1) & (s2==1) & (s3==0) & (s4==1)){
		sensor="3";//M13
	}
	else if ((s1==1) & (s2==1) & (s3==1) & (s4==0)){
		sensor="3";//M14
	}
	else if ((s1==1) & (s2==1) & (s3==1) & (s4==1)){
		sensor="4";//M15
	}
	return sensor;
}




#endif /* SIP_SWITCH_H_ */