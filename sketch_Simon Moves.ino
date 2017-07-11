#include <Wire.h>
#include <SPI.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <SSD1331.h>
#include <S65L2F50.h>
#include <S65LPH88.h>
#include <S65LS020.h>
#include <MI0283QT2.h>
#include <MI0283QT9.h>
#include <DisplaySPI.h>
#include <DisplayI2C.h>
#include <PS2Mouse.h>
#define MOUSE_DATA 5
#define MOUSE_CLOCK 6

MI0283QT2 lcd;
PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);
void right(int);
void left(int);
void forward(int);
void backward(int);
float mousex();
float mousey();
float average (int * array, int );  


void setup() 
{
  //uint8_t clear_bg=0x00;
  Serial.begin(38400);
  mouse.initialize();
  
    //init display
  lcd.begin();
  lcd.fillScreen(RGB(255,255,255));
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(80, 10);
  lcd.println("Welcome to \n");
   lcd.setCursor(40, 30);
  lcd.println("Simon Moves Game \n");
  delay(2000);
  lcd.setCursor(70, 60);
  lcd.println("Game Rule 1. \n");
  delay(2000);
  lcd.setCursor(30, 100);
  lcd.println("Follow the Arrow\n");
  lcd.setCursor(20, 120);
  lcd.println("Pattern with mouse \n");
  delay(5000);
  lcd.fillScreen(RGB(255,255,255));
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(100, 100);
  lcd.println("Enjoy ! \n");
  delay(2000);
  level1();
}

void loop()
{ 
 
}

///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  Level 1   //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void level1()
{
  int counter = 0;
/////////////////////// Screen Data ////////////////////
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(100, 100);
  lcd.println("Level 1\n");
  delay(2000);
  lcd.setCursor(110, 130);
  lcd.println("start\n");
  delay(2000);
  lcd.fillScreen(RGB(255,255,255));//delay(500);
  
/////////////////////// Designed Pattern //////////////   
  right(10);
  forward(10);

/////////////////////// Input from Mouse//////////////
  lcd.setTextSize(1);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(10,10);
  lcd.println("your input should start in 1 seconds\n");
  //lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  delay (1500);
  lcd.setCursor(130, 100);
  lcd.println("GO");
  delay(500);
  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 10);


  float x1=0;
  float y1=0;
////// Reading X - Y coordinates /////////

  x1= mousex();
  y1= mousey();  
   
/////// Showing Entered Pattern /////

  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 10);
  lcd.println("input is \n");
  delay(2000);
  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(1);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));

  if(x1 > 0)
    right(10);  
    else 
    { 
      lcd.setCursor(200,100);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    
    delay(1000);
  if(y1 > 0)
    forward(10);  
    else 
    {
      lcd.setCursor(100,50);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    delay(1000);

    
//////////// Result ///////////////// 
  lcd.fillScreen(RGB(255,255,255));// delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 100);
  
  if (counter == 0)
  {
    lcd.println("You Won \n");
    lcd.setCursor(30, 120);
    lcd.println("Going to Level 2");
    delay(4000);
    lcd.fillScreen(RGB(255,255,255));
    
    level2();
  }
    else 
    {
    lcd.println("You Loose \n"); 
    lcd.fillScreen(RGB(255,255,255));
    lcd.setCursor(90, 100);
    lcd.println("Game Over\n"); 
    delay(5000);
    lcd.fillScreen(RGB(255,255,255));
 
  } 
}

///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  Level 2   //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void level2()
{
  int counter = 0;
/////////////////////// Screen Data ////////////////////
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(100, 100);
  lcd.println("Level 2\n");
  delay(2000);
  lcd.setCursor(110, 130);
  lcd.println("start\n");
  delay(2000);
  lcd.fillScreen(RGB(255,255,255));//delay(500);

/////////////////////// Designed Pattern //////////////   
  
  right(10);
  forward(10);
  left(10);
  backward(10);
  delay(2000);

/////////////////////// Input from Mouse//////////////
  lcd.setTextSize(1);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(10,10);
  lcd.println("your input should start in 1 seconds\n");
  //lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  delay (1500);
  lcd.setCursor(130, 100);
  lcd.println("GO");
  delay(500);
  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 10);

 
  float x2[2]={0};
  float y2[2]={0};
////// Reading X - Y coordinates /////////
  for (int i= 0;i<2;i++)
  {
  x2[i]= mousex();
 
  y2[i]= mousey();  

  }

/////// Showing Entered Pattern /////
  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 10);
  lcd.println("input is \n");

  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(1);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  
  if(x2[0] > 0)
    right(10);  
    else 
    { 
      lcd.setCursor(200,100);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    
    delay(2000);
  if(y2[0] > 0)
    forward(10);  
    else 
    {
      lcd.setCursor(100,50);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    delay(2000);
  if(x2[1] < 0)
    (left(10));
    else 
    {
      lcd.setCursor(20, 100);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    delay(2000);
  if(y2[1] < 0)
    backward(10);  
    else 
    {
      lcd.setCursor(100, 150);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
   
//////////// Result ///////////////// 
  lcd.fillScreen(RGB(255,255,255));// delay(500);
  delay(2000);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 100);
  if (counter == 0)
  {
    lcd.println("You Won \n");
    lcd.setCursor(30, 120);
    lcd.println("Going to Level 3");
    delay(4000);
    lcd.fillScreen(RGB(255,255,255));
    level3();
    
  }
    else 
    {
    lcd.println("You Loose \n"); 
    lcd.fillScreen(RGB(255,255,255));
    lcd.setCursor(100, 50);
    lcd.println("Game Over\n"); 
    delay(5000);
    lcd.fillScreen(RGB(255,255,255));
  }
    

}

///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  Level 3   //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void level3()
{
  int counter = 0;
/////////////////////// Screen Data ////////////////////
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(100, 100);
  lcd.println("Level 3\n");
  delay(2000);
  lcd.setCursor(110, 130);
  lcd.println("start\n");
  delay(2000);
  lcd.fillScreen(RGB(255,255,255));//delay(500);
  
/////////////////////// Designed Pattern //////////////  
  right(10);
  forward(10);
  backward(10);
  left(10);
  
  delay(2000);

/////////////////////// Input from Mouse//////////////
  lcd.setTextSize(1);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(10,10);
  lcd.println("your input should start in 1 seconds\n");
  //lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  delay (1500);
  lcd.setCursor(130, 100);
  lcd.println("GO");
  
  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 10);

  float x3[2]={0};
  float y3[2]={0};
////// Reading X - Y coordinates /////////
  for (int i= 0;i<2;i++)
  {
  x3[i]= mousex();
  y3[i]= mousey();  
  }

/////// Showing Entered Pattern /////

  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 10);
  lcd.println("input is \n");

  lcd.fillScreen(RGB(255,255,255));//delay(500);
  lcd.setTextSize(1);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
 
  if(x3[0] > 0)
    right(10);  
    else 
    { 
      lcd.setCursor(200,100);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    
    delay(2000);
  if(y3[0] > 0)
    forward(10);  
    else 
    {
      lcd.setCursor(100,50);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    delay(2000);
  if(x3[1] < 0)
    backward(10);
    else 
    {
      lcd.setCursor(100, 150);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
    delay(2000);
   
  if(y3[1] < 0)
    left(10);  
    else 
    {
      lcd.setCursor(20, 100);
      lcd.println("Wrong Choice\n");
      counter = 1;
    }
     lcd.fillScreen(RGB(255,255,255));
  
    
//////////// Result ///////////////// 
  lcd.fillScreen(RGB(255,255,255));// delay(500);
  delay(2000);
  lcd.setTextSize(2);
  lcd.setTextColor(RGB(200,0,0), RGB(255,255,255));
  lcd.setCursor(90, 100);
   
  if (counter == 0)
  {
    lcd.println("You Won \n");
    lcd.setCursor(70, 120);
    lcd.println("Congratulation");
    lcd.setCursor(40, 140);
    lcd.println("  You have finished the game");
    delay(4000);
  }
    else 
    {
    lcd.println("You Loose \n"); 
    lcd.fillScreen(RGB(255,255,255));
    lcd.setCursor(100, 50);
    lcd.println("Game Over\n"); 
    delay(5000);
    lcd.fillScreen(RGB(255,255,255));
  }
}




void forward(int del)
{
  delay(20);
  lcd.fillTriangle(130,70,180,70,155,5,RGB(  0,0 ,200));
  lcd.drawTriangle(130,70,180,70,155,5,RGB(  0,  0,  0));
  delay(abs(del)*15);
  lcd.fillScreen(RGB(255,255,255));// delay(500);
}

void left(int del)
{ 
  delay(20);
  lcd.fillTriangle(15,110,90,85,90,135,RGB(  0,200,0));
  lcd.drawTriangle(15,110,90,85,90,135,RGB(  0,  0,  0));
  delay(abs(del)*15);
  lcd.fillScreen(RGB(255,255,255));// delay(500);
}

void right(int del)
{ 
  delay(20);
  lcd.fillTriangle(220,85,220,135,295,110,RGB(  0,200,200));
  lcd.drawTriangle(220,85,220,135,295,110,RGB(  0,  0,  0));
  delay(abs(del)*15);
  lcd.fillScreen(RGB(255,255,255));// delay(500);
  
}

void backward(int del)
{ 
  //delay(20);
  lcd.fillTriangle(130,160,180,160,155,225,RGB(  200,0 ,0));
  lcd.drawTriangle(130,160,180,160,155,225,RGB(  0,  0,  0));
  delay(abs(del)*15);
  lcd.fillScreen(RGB(255,255,255));// delay(500);
}



float average (int * array, int len)  // assuming array is int.
{
  long sum = 0L ;  // sum will be larger than an item, long for safety.
  for (int i = 0 ; i < len ; i++)
    sum += array [i] ;
  return  ((float) sum) / len ;  // average will be fractional, so float may be appropriate.
}

float mousex()
{
  int mx[50]={0};
  int data[2];
  lcd.print("next step \n");
  for (int j=0;j<50;j++)
  {
  mouse.report(data);
  mx[j] = data[1];
  }
  
  return average(mx,50);  
  
}

float mousey()
{
  int my[50]={0};
  int data[2];
  lcd.print("next step \n");
  for (int k=0;k<50;k++)
  {
  mouse.report(data);
  my[k] = data[2];
    }
 
  return average(my,50);  
   
} 
