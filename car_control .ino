const int ledPin = 12;

String str,strtmp; 
String strcheck;
String stringflush;
String stringtrans;
int stringflag;
int posx,posy;
int index1,index2;



void setup() { 
  Serial.begin (9600);
  pinMode(12, OUTPUT);
} 

void loop(){

    while(!Serial.available()) {}
    while (Serial.available()) {
      
        if (Serial.available() >0) {
            char c = Serial.read();
            str += c;
        }
    }

    int a = str.indexOf(',');
    if(a<=0)
    {
      strtmp = str;
      stringflag = 1;
    }
    else
    {
      stringflag = 0;
    }

    if (str.length() >0 && stringflag == 0) {
        stringflush = "True";
        strcheck = strtmp;
        Serial.println(strcheck);
        index1 = strcheck.indexOf('.');
        stringtrans = strcheck.substring(0,index1);
        posx = stringtrans.toInt();
        
        index2 = strcheck.indexOf(',');
        stringtrans = strcheck.substring(index1+1,index2);
        posy = stringtrans.toInt();
        
        str="";
        
        if(posx<=100)
          digitalWrite(12,HIGH);
        else if(posx>=100)
          digitalWrite(12,LOW);
        delay(50);
        pwm_control();     /*  design your control law here  */
		
    }
    Serial.flush();
    
}




