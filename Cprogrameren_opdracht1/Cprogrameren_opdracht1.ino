
static byte DS    = 10;  
static byte SHCP  = 11; 
static byte STCP  = 12;  



unsigned long previous = 0;
unsigned long interval = 1000;
void (*execute)();

String letter = "p";


struct pBlok
{
byte x,y;
}
pBlok[31] = 
{
  {-1,-1},{2,1},{2,2},{2,3},{2,4},
  {2,5},{2,6},{2,7},{2,8},{3,1},
  {3,2},{3,3},{3,4},{3,5},{3,6},
  {3,7},{3,8},{4,1},{4,2},{4,4},
  {4,5},{5,1},{5,2},{5,3},{5,4},
  {5,5},{6,1},{6,2},{6,3},{6,4},
  {6,5}
  
};


struct xBlok
{
byte x,y;
}
xBlok[29] = 
{
  {-1,-1},{1,1},{1,2},{2,2},{2,3},
  {3,3},{3,4},{4,4},{4,5},{4,6},
  {3,6},{3,7},{2,7},{2,8},{1,8},
  {5,4},{5,5},{5,6},{6,3},{6,4},
  {6,6},{6,7},{7,2},{7,3},{7,7},
  {7,8},{8,7},{8,2},{8,8}
};

struct lBlok
{
byte x,y;
}
lBlok[23] =
{
  {-1,-1},{2,1},{2,2},{2,3},{2,4},
  {2,5},{2,6},{2,7},{2,8},{3,1},{3,2},
  {3,3},{3,4},{3,5},{3,6},{3,7},{3,8},
  {4,7},{5,7},{6,7},{4,8},{5,8},{6,8}
};






void setup()
{

  pinMode(DS,    OUTPUT);
  pinMode(SHCP,  OUTPUT);
  pinMode(STCP,  OUTPUT);



};

void loop()
{ 
 
Timecheck(final);
if(letter == "p") 
  {
    for(byte i =0; i < 31; i++){
      showLed(pBlok[i].x,pBlok[i].y);
      }
    }
    else if(letter == "x") 
  {
    for(byte i =0; i < 29; i++){
      showLed(xBlok[i].x,xBlok[i].y);
      }
    }
   else if( letter == "l") 
  {
    for(byte i =0; i < 23; i++){
      showLed(lBlok[i].x,lBlok[i].y);
      }
    }
}



void final()
{
  if(letter == "p") 
  {
   letter = "x";
  }
  else if(letter == "x") 
  {
   letter = "l";
  }
  else if(letter == "l") 
  {
   letter = "p";
  }
  
  
}




void showLed(char x, char y) //1,1 - 8,8
{
     //{K2,r7,r6,k1,r4,k3,k6,k4,k8,r5,r3,k5,r8,k7,r2,r1   }
    char matrix[16] = {0,1,1,0,1,0,0,0,0,1,1,0,1,0,1,1}; // zet matrix uit
    if (x == 1)
    {
          matrix[15] = 0; 
    }
    else if (x == 2)
    {
          matrix[14] = 0; 
    }
    else if (x == 3)
    {
          matrix[10] = 0; 
    }
    else if (x == 4)
    {
          matrix[4] = 0; 
    }
    else if (x == 5)
    {
          matrix[9] = 0; 
    }
    else if (x == 6)
    {
          matrix[2] = 0; 
    }
    else if (x == 7)
    {
          matrix[1] = 0; 
    }
    else if (x == 8)
    {
          matrix[12] = 0; 
    }

     //{K2,r7,r6,k1,r4,k3,k6,k4,k8,r5,r3,k5,r8,k7,r2,r1}
    if (y == 1)
    {
          matrix[3] = 1; 
    }
    else if (y == 2)
    {
          matrix[0] = 1; 
    }
    else if (y == 3)
    {
          matrix[5] = 1; 
    }
    else if (y == 4)
    {
          matrix[7] = 1; 
    }
    else if (y == 5)
    {
          matrix[11] = 1; 
    }
    else if (y == 6)
    {
          matrix[6] = 1; 
    }
    else if (y == 7)
    {
          matrix[13] = 1; 
    }
    else if (y == 8)
    {
          matrix[8] = 1; 
    }
 Shift_output(matrix);   
 
}

void Shift_output(char array[]) 
{
   static int i;
   digitalWrite(SHCP, LOW);
   digitalWrite(STCP, LOW);
  
   for(i=0;i<16;i++)
   {
       if( array[i] )
        digitalWrite(DS, HIGH);
       else
        digitalWrite(DS, LOW);

      digitalWrite(SHCP, HIGH);
      digitalWrite(SHCP, LOW);
   }
   digitalWrite(STCP, HIGH);
 }  

   
void Timecheck(void (*function)){
  execute = function;
  if ( millis()-previous >= interval) {
    previous = millis();
    execute();
  }
}
   
   
   
   
