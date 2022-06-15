void setup() {
  init_port();
  init_timer();
}

void init_port(){
  char *ddr = (char*)0x30;
  *ddr = 0x01;
}

void init_timer(){
  volatile char *PCIC_R = (char*)0x68;
  volatile char *PCMSK_0 = (char*)0x6B;

  *PCIC_R = 0x01;
  *PCMSK_0 = 0x01;
}

ISR (PCINT0_vect){
   volatile char *out = (char*)0x31;
   *out^= 0x01;
}

void loop() {

}
