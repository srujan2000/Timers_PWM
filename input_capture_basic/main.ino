volatile short *ICR_1 = (short*)0x86;
volatile char *TIFR_1 = (char*)0x36;

unsigned int capture;
void setup() {
  // init_port();
  init_timer();
  Serial.begin(9600);
}

void init_timer(){
  volatile char *TCCR1_A = (char*)0x80;
  volatile char *TCCR1_B = (char*)0x81;
  volatile short *TCNT_1 = (short*)0x84;
//  volatile short *OCR1_A = (short*)0x88;
   volatile char *TIMSK_1 = (char*)0x6F;


  *TCCR1_A = 0;
  *TCCR1_B = 0x41;
  *TCNT_1 = 0;
   *TIMSK_1 = 0x20;
}

ISR (TIMER1_CAPT_vect){
  capture = *ICR_1;
  Serial.println(capture,DEC);
}



void loop() {
  // put your main code here, to run repeatedly:

}
