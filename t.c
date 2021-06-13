//Timer1 100 Hz  Control Duty Cycle
  void DELAYL();
  void DELAYH();
  unsigned char i;
  unsigned char j[]={0x00};    //DELAYH     TMR1H
  unsigned char k[]={0x00};    //DELAYH     TMR1L
  unsigned char m[]={0x00};    //DELAYL     TMR1H
  unsigned char n[]={0x00};    //DELAYL     TMR1L
  void main ()
 {
  ADCON1= 0x07;
  TRISA = 0b00110000;
  TRISC = 0x00;
  i = 0;
  while(1)
    {
      if(PORTA.F5==0)
       {
        while(PORTA.F5==0);
        if(i==3)
          {
          }
        else
          i++;
       }
      else
       {
         PORTC.F2=0;
         DELAYL();
         PORTC.F2=1;
         DELAYH();
       }
    }
 }
  void DELAYL()
{  T1CON  = 0X0C;
   TMR1H=m[i];
   TMR1L=n[i];
   T1CON.F0 = 1;
   while(PIR1.F0==0);
   PIR1.F0=0;
}
void DELAYH()
{  T1CON  = 0X0C;
   TMR1H=j[i];
   TMR1L=k[i];
   T1CON.F0 = 1;
   while(PIR1.F0==0);
   PIR1.F0=0;
}

