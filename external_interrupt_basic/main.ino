void setup() {
  init_port();
  init_timer();
}

void init_port(){
  char *ddr = (char*)0x30;
  *ddr = 0x01;
}

void init_timer(){
  volatile char *EICR_A = (char*)0x69;
  volatile char *EI_MSK = (char*)0x3D;

  *EICR_A = 0x03;
  *EI_MSK = 0x01;
}

ISR (INT0_vect){
    volatile char *out = (char*)0x31;
    *out^= 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:

}
