// GSM related functions

void initGPRS()
{
  Serial1.println("AT+CSQ");//signal quality report
  delay(100);
  showGsmData();
  Serial1.println("AT+CGATT?");//attach to gprs service. returns 1 if attached, 0 otherwise
  delay(100);
  showGsmData();
  Serial1.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR, the connection type is using gprs
  delay(1000);
  showGsmData();
  Serial1.println("AT+SAPBR=3,1,\"APN\",\"isp.vodafone.ie\"");//setting the APN to local apn server
  delay(4000);
  showGsmData();
  Serial1.println("AT+SAPBR=3,1,\"USER\",\"vodafone\"");//setting the apn user
  delay(1000);
  showGsmData();
  Serial1.println("AT+SAPBR=3,1,\"PWD\",\"vodafone\"");//setting the apn password
  delay(4000);
  showGsmData();
  Serial1.println("AT+SAPBR=1,1");//setting the SAPBR, for detail you can refer to the AT command mamual
  delay(3000);
  showGsmData();
}

void submitHttpRequest(String url)
{
 Serial1.println("AT+HTTPINIT"); //init the HTTP request
 delay(2000); 
 showGsmData();
 String httpParam = "AT+HTTPPARA=\"URL\",\"" ;
 httpParam += url ;
 httpParam += "\"";
 Serial1.println(httpParam);// setting the httppara, the second parameter is the website you want to access
 delay(1000);
 showGsmData();
 Serial1.println("AT+HTTPACTION=0");//submit the request 
 delay(20000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
 showGsmData();
 Serial1.println("AT+HTTPREAD");// read the data from the website you access
 delay(300);
}

// forward any serial data from GSM to serial monitor
void showGsmData()
{
 while(Serial1.available()!=0) //serial 1 is connected to GSM module
   Serial.write(Serial1.read());
}


