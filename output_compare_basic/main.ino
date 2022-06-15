void init_port();
void init_timer();

void setup() {
  init_port();
  init_timer();
}


void init_port(){
  volatile char *ddr =(char*)0x30;
  *ddr = 0x01;
}


void init_timer(){
  volatile char *TCCR1_A = 0x80;
  volatile char *TCCR1_B = 0x81;
  volatile short *TCNT_1 = 0x84;
  volatile short *OCR1_A = 0x88;
  volatile char *TIMSK_1 = 0x6F;

  *TCCR1_A = 0;
  *TCCR1_B = 0x0C;
  *TCNT_1  = 0;
   
   *OCR1_A  = 62500;
   *TIMSK_1 = 0x03;
}

ISR (TIMER1_COMPA_vect){
  volatile char *out = (volatile char*)0x31;
  *out ^= 0x01;
}

void loop() {
}
