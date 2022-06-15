void setup() {
 init_port();
 init_timer();

 volatile short *OCR1_A = (short*)0x88;
 while(1){
  for(int i=1;i<256;i++){
    *OCR1_A  = i;
    delay1();
  }

  for(int j=254;j>0;j--){
    *OCR1_A  = j;
    delay1();
  }
 }
}

void init_port(){
  volatile char *ddr = (char*)0x24;
  *ddr = 0x20;
}

void init_timer(){
  volatile char *TCCR1_A = (char*)0x80;
  volatile char *TCCR1_B = (char*)0x81;
  volatile short *TCNT_1 = (short*)0x84;
  *TCCR1_A = 0xA1;
  *TCCR1_B = 0x09;
  *TCNT_1  = 0;
  // *TIMSK_1 = 0x01;
}

void delay1(){
  volatile long i;
  for(i=0;i<5000;i++);
}


void loop() {
  
}
