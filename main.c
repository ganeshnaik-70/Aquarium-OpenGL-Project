#include<stdio.h>
#include<stdlib.h>
#include<freeglut.h>
#include<math.h>
float  s=400,ss=140, a=0,b=0,aa=-70,bb=0,flag=0,flag3=0, flag4=0;
float x=100,y=0,r=0.5,y11=0,y21=0,y31=0,y41=0,y51=0,y61=0,y71=0,y81=0,y91=0,y10=0,y12=0,y13=0,y14=0,x0=0,xo=0, angle=0.0, pi=3.142;
int moving = 0;
int temp =0;
void create_menu(void);
void menu(int);
void mov(void);

void drawstring(float x,float y,float z,char *string, int f)
{
    char *c;
    glRasterPos3f(x,y,z);
    for(c=string;*c!='\0';c++){
        if(f==0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
        else
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
    }
}

void init()
{
	glClearColor(0.0,0.6,0.9,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}
void screen()
{
    glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
	drawstring(210,425,0.0,"SRINIVAS INSTITUTE OF TEVHNOLOGY MANGALURU VALACHILL",1);
		glColor3f(0.0,0.0,0.0);
	drawstring(245,385,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",1);
		glColor3f(0.6,1.0,0.0);
	drawstring(210,350,0.0,"A MINI PROJECT ON COMPUTER GRAPHICS AND VISUALIZATION",1);
		glColor3f(1.0,1.0,0.0);
	drawstring(440,300,0.0,"AQUARIUM",1);
	 	glColor3f(1.0,0.0,0.0);
	  drawstring(135,205,0.0," STUDENT NAME",0);
	  	glColor3f(0.0,0.0,0.0);
	drawstring(140,170,0.0,"Ganesh Naik",0);
	drawstring(140,135,0.0,"Gajanan Bhat",0);
		glColor3f(1.0,0.0,0.0);
	drawstring(710,205,0.0,"Under the Guidance of",0);
		glColor3f(0.0,0.0,0.0);
	drawstring(720,170,0.0,"Prof Sowmay K",0);
		glColor3f(1.0,1.0,0.0);
	drawstring(406,95,0.0,"Academic Year 2020-21",0);
	drawstring(400,65,0.0,"Press 'P' to start the game",0);

glFlush();
 glutSwapBuffers();
}
void reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h>w)
		gluOrtho2D(0, 500, ((float)h/(float)w)*(0), ((float)h/(float)w)*500);
	else
        gluOrtho2D(((float)w/(float)h)*(0), ((float)w/(float)h)*(520), 0, 500);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void fish1()
{


glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
   glVertex2f(270+a,350+aa);

   glVertex2f(300+a,325+aa);

   glVertex2f(370+a,350+aa);
   glVertex2f(300+a,375+aa);
  glEnd();

glBegin(GL_POLYGON);

    glVertex2f(360+a,350+aa);
    glColor3ub( rand()%1, rand()%1000, rand()%1000 );
   glVertex2f(405+a,370+aa);
   glVertex2f(395+a,350+aa);
   glVertex2f(405+a,327+aa);
  glEnd();

  glBegin(GL_TRIANGLES);

  glColor3ub( rand()%1, rand()%1000, rand()%1000 );
    glVertex2f(302+a,373+aa);
   glColor3f(1.0,0.0,0.0);
	glVertex2f(340+a,409+aa);
	glVertex2f(320+a,360+aa);
  glEnd();

glBegin(GL_TRIANGLES);

glColor3ub( rand()%1, rand()%1000, 0 );
    glVertex2f(302+a,328+aa);
glColor3f(1.0,0.0,0.0);
	glVertex2f(340+a,300+aa);
	glVertex2f(320+a,340+aa);
  glEnd();


 glColor3f(0.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_POINTS);
  glVertex2f(280+a,355+aa);
  glEnd();
}

void fish2()
{
	 glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
     glVertex2f(70+b,145+bb);
  glColor3ub(rand()%500, rand()%500,0);
   glVertex2f(20+b,120+bb);
    glVertex2f(30+b,145+bb);
   glVertex2f(20+b,170+bb);


  glEnd();
  glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
   glVertex2f(65+b,145+bb);

   glVertex2f(125+b,170+bb);

   glVertex2f(165+b,145+bb);
   glVertex2f(125+b,120+bb);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3ub(rand()%500, rand()%500,0);
    glVertex2f(126+b,168+bb);
   glColor3f(1.0,0.0,0.0);
   glVertex2f(110+b,155+bb);
    glVertex2f(85+b,195+bb);
 glEnd();
 glBegin(GL_TRIANGLES);
  glColor3ub(rand()%500, rand()%500,0);
    glVertex2f(126+b,122+bb);
   glColor3f(1.0,0.0,0.0);
	glVertex2f(110+b,136+bb);
	glVertex2f(85+b,95+bb);
  glEnd();




 glColor3f(0.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_POINTS);
  glVertex2f(150+b,149+bb);
  glEnd();

}
void pbSmall(){

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(46,47,47);
        y =(sin(angle*pi/180)*30);
        x =(cos(angle*pi/180)*50);
        glVertex2f(x+150,y-5);
    }
    glEnd();
}

void pb(){

    pbSmall();
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub( 142,20,30);
        y =(sin(angle*pi/180)*45);
        x =(cos(angle*pi/180)*75);
        glVertex2f(x+250,y-10);
    }
    glEnd();
}

 void pb1(){

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub( 20,20,20);
        y =(sin(angle*pi/180)*35);
        x =(cos(angle*pi/180)*65);
        glVertex2f(x+370,y-5);
    }
    glEnd();
}
 void pb2(){

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(36, 60, 2);
        y =(sin(angle*pi/180)*40);
        x =(cos(angle*pi/180)*75);
        glVertex2f(x+610,y+10);
    }
    glEnd();
}

void circleFunc(float yc,int d,int x1,int y1){
    for(angle=0; angle<360.0; angle+=.1)
	{
        y =yc+(sin(angle*pi/180)*d);
        x =(cos(angle*pi/180)*d);
        glVertex2f(x+x1,y-y1);
	}
}
float checkBubPos(float y,float c){
    if(y<500){
        return y+c;
    }
    else{
        return 0;
    }
}
void circle(int x){

    //to draw circles
    glBegin(GL_POINTS);
    circleFunc(y21,15,x+10,30);
    circleFunc(y31,5,x,60);
    circleFunc(y41,7,x+10,90);
    circleFunc(y51,12,x,120);
    circleFunc(y61,15,x+10,150);
    circleFunc(y71,5,x,180);
    circleFunc(y81,3,x+10,210);
    circleFunc(y81,15,x,240);
    circleFunc(y91,12,x+10,270);
    circleFunc(y10,10,x,300);
    circleFunc(y12,16,x+10,330);
    circleFunc(y13,15,x,360);
    circleFunc(y14,10,x+10,400);
	glEnd();

	y11 = checkBubPos(y11,2.0);
	y21 = checkBubPos(y21,3.0);
	y31 = checkBubPos(y31,4.5);
	y41 = checkBubPos(y41,7.0);
	y51 = checkBubPos(y51,6.5);
	y61 = checkBubPos(y61,18.0);
	y71 = checkBubPos(y71,17.5);
	y81 = checkBubPos(y81,8.0);
	y91 = checkBubPos(y91,7.5);
	y10 = checkBubPos(y10,10.0);
	y12 = checkBubPos(y12,11.0);
	y14 = checkBubPos(y14,8.0);
	y12 = checkBubPos(y12,9.0);
	y13 = checkBubPos(y13,1.0);
	glutPostRedisplay();

}

void plant3L(int x1, int x2, int m){
    int dis = x2-x1;
    dis = dis/3;
    glColor3ub( 40,170,5);
    glBegin(GL_POLYGON);
    glVertex2f(x1,0);
    glVertex2f(x1-10,m-10);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(x1+dis,15);
    glVertex2f(x1+((x2-x1)/2),m);
    glVertex2f(x2-dis,15);
    glVertex2f(x2+12,m+10);
    glVertex2f(x2,0);
    glEnd();
}

void plant2L(int x1, int x2, int h1, int h2){

    glColor3ub( 60,170,15);
    glBegin(GL_POLYGON);
    glVertex2f(x1,0);
    glVertex2f(x1-20,h1);
    glColor3f(0.0,0.3,0.0);
    glVertex2f(x2,0);
    glVertex2f(x1+15,h2);
    glEnd();
}
void plant()
{
    plant2L(50,40,40,60);
    plant2L(95,85,50,60);
    plant2L(120,110,45,65);
    plant2L(70,60,60,40);
    plant2L(140,130,43,60);
    plant2L(950,940,40,50);
    plant2L(870,860,50,60);
    plant2L(470,460,40,50);
    plant2L(490,480,55,65);
    plant2L(520,510,40,50);
    plant2L(540,530,50,60);
    plant2L(700,690,40,50);
    plant2L(730,720,55,65);
    plant2L(795,785,40,50);

    plant3L(10,20,60);
    plant3L(160,170,50);
    plant3L(310,320,70);
    plant3L(435,445,60);
    plant3L(750,760, 55);
    plant3L(820,830,80);
    plant3L(900,910, 55);
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);
    if(moving==1){
        mov();
    }
    pb1();
    pb2();
    pb();
    plant();
    fish1();
    drawSineWave();
    fish2();
    Shark();
    drawFrog();

    glColor3f(1.0,1.0,1.0);
    glPointSize(2.0);
    circle(30);
    circle(930);


    if(flag3==0){
        screen();
    }

    glFlush();
    glutSwapBuffers();
}

void mov(void){
    if(a>=-500)
        a=a-7;
    else
        a=700;

    if(a<-500){
        aa=aa-100;
    }

    if(aa<-251){
        aa=100;
    }

    if(b<=1000)
        b=b+8.0;
    else
        b=-500;

    if(b>1000){
        bb=bb+150;
    }
    if(bb>251){
        bb=50;
    }

    if(s>=-700)
        s=s-9;
    else
        s=700;

    if(s<-700){
        ss=ss-250;
    }

    if(ss<-251){
        ss=80;
    }
}

void create_menu(void){

     glutCreateMenu(menu);
     glutAttachMenu(GLUT_LEFT_BUTTON);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
     glutAddMenuEntry("move", 1);
     glutAddMenuEntry("stop", 2);
     glutAddMenuEntry("back", 3);
     glutAddMenuEntry("quit", 4);

}

void menu(int val){
    switch (val) {
        case 1:
            if(flag4==1 && moving ==0)
                moving = 1;
            break;
        case 2:
            glutIdleFunc(NULL);
            glutDisplayFunc(display);
            moving = 0;
            break;
        case 3:
            moving = 0;
            flag3=0;
            flag4=0;
            screen();
            break;
        case 4: exit(0);
            break;

    }
}

void speed()
{
	a=a-9.0;
	s=s-10;
	b=b+10;
}

void slow()
{
	a=a-0.0001;
}

void key(unsigned char k,int x,int y)
{
	if(k=='i')
        glutIdleFunc(speed);

	if(k=='d'){
        glutIdleFunc(slow);
	}

	if(k=='p'){
        flag3=1;
        flag4=1;
	}

}
void drawFrog(){

    glPushMatrix();
    glTranslatef(600,55,0);
    glRotatef(50, 0, 0, 1);
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(46,127,7);
        y =(sin(angle*pi/180)*15);
        x =(cos(angle*pi/180)*7);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(630,55,0);
    glRotatef(-50, 0, 0, 1);
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(46,127,7);
        y =(sin(angle*pi/180)*15);
        x =(cos(angle*pi/180)*7);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(46,150,7);
        y =(sin(angle*pi/180)*21);
        x =(cos(angle*pi/180)*13);
        glVertex2f(x+615,y+65);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(46,130,7);
        y =(sin(angle*pi/180)*10);
        x =(cos(angle*pi/180)*17);
        glVertex2f(x+615,y+85);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(255,255,255);
        y =(sin(angle*pi/180)*7);
        x =(cos(angle*pi/180)*5);
        glVertex2f(x+605,y+92);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(255,255,255);
        y =(sin(angle*pi/180)*7);
        x =(cos(angle*pi/180)*5);
        glVertex2f(x+625,y+92);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    for(angle=180; angle<360.0; angle+=.1){
        glColor3ub(255,255,255);
        y =(sin(angle*pi/180)*7);
        x =(cos(angle*pi/180)*7);
        glVertex2f(x+615,y+82);
    }
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(6.0);
    glBegin(GL_POINTS);
    glVertex2f(605,92);
    glVertex2f(625,92);
    glEnd();

    glColor3ub(46,115,7);
    glBegin(GL_POLYGON);
    glVertex2f(605,70);
    glVertex2f(600,42);
    glVertex2f(604,42);
    glVertex2f(611,70);
    glEnd();

    glColor3ub(46,115,7);
    glBegin(GL_POLYGON);
    glVertex2f(620,70);
    glVertex2f(627,42);
    glVertex2f(631,42);
    glVertex2f(626,70);
    glEnd();


}
void drawSineWave(){
    glPointSize(8.0);
    glBegin(GL_POINTS);
    for(angle=0; angle<500.0; angle=angle+0.9){
        glColor3ub(46,110,7);
        x =(sin(angle*pi/90)*15);
        y = angle;
        glVertex2f(x+960,y);
    }
    glEnd();
    drawLeafLeft(960,80);
    drawLeafLeft(969,210);
    drawLeafLeft(945,330);
    drawLeafLeft(957,460);
    drawLeafRight(945,140);
    drawLeafRight(957,280);
    drawLeafRight(971,410);
}
void drawLeafLeft(int x, int y){

    glLineWidth(5);
    glColor3ub( 60,120,15);
    glBegin(GL_LINES);
    glVertex2f(x,y);
    glVertex2f(x-10,y);
    glEnd();

    glColor3ub( 60,170,15);
    glBegin(GL_POLYGON);
    glVertex2f(x-10,y);
    glVertex2f(x-17,y+18);
    glVertex2f(x-50,y+13);
    glColor3f(0.1,0.5,0.0);
    glVertex2f(x-70,y);
    glVertex2f(x-50,y-13);
    glVertex2f(x-17,y-18);
    glEnd();

}
void drawLeafRight(int x, int y){

    glLineWidth(5);
    glColor3ub( 60,120,15);
    glBegin(GL_LINES);
    glVertex2f(x,y);
    glVertex2f(x+10,y);
    glEnd();

    glColor3ub( 60,170,15);
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y);
    glVertex2f(x+17,y+18);
    glVertex2f(x+50,y+13);
    glColor3f(0.1,0.5,0.0);
    glVertex2f(x+70,y);
    glVertex2f(x+50,y-13);
    glVertex2f(x+17,y-18);
    glEnd();

}
void Shark(){

    //For Shark Body
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<320; angle+=2){
        glColor3ub(115,116,117);
        y =(sin(angle*pi/319)*30);
        x =angle;
        glVertex2f(x+280+s,y+285+ss);
    }
    glColor3ub(200,200,200);
    glVertex2f(x+280+s,y+265+ss);
    for(angle=298; angle>35; angle-=2){
        x =angle;
        y = -(sin(angle*pi/319)*20);
        glVertex2f(x+280+s,y+265+ss);
    }

    glVertex2f(300+s,265+ss);
    glEnd();
    glColor3ub(138,3,3);
    glBegin(GL_POLYGON);
    glVertex2f(302+s,263+ss);
    glVertex2f(330+s,276+ss);
    glVertex2f(297+s,268+ss);
    glEnd();

    //For Shark Tail
    glColor3ub(115,116,117);
    glBegin(GL_POLYGON);
    glVertex2f(598+s,285.6+ss);
    glVertex2f(640+s,330+ss);
    glColor3ub(rand()%40+190,rand()%40+190,rand()%40+190);
    glVertex2f(628+s,275+ss);
    glVertex2f(640+s,220+ss);
    glVertex2f(598+s,265+ss);
    glEnd();

    glColor3ub(100,106,107);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(410+s,313+ss);
    glColor3ub(150,150,150);
    glVertex2f(460+s,360+ss);
    glVertex2f(475+s,313+ss);
    glEnd();

    glColor3ub(115,116,117);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(420+s,260+ss);
    glVertex2f(450+s,210+ss);
    glColor3ub(rand()%40+190,rand()%40+190,rand()%40+190);
    glVertex2f(460+s,260+ss);
    glEnd();

    glColor3ub(115,116,117);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(555+s,297+ss);
    glVertex2f(580+s,305+ss);
    glVertex2f(580+s,290+ss);
    glEnd();

    glColor3ub(115,116,117);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(555+s,257+ss);
    glVertex2f(580+s,247+ss);
    glColor3ub(rand()%40+190,rand()%40+190,rand()%40+190);
    glVertex2f(580+s,261+ss);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(0,0,0);
        y =(sin(angle*pi/180)*5);
        x =(cos(angle*pi/180)*5);
        glVertex2f(x+332+s,y+287+ss);
    }
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(331.8+s,287+ss);
    glEnd();

}

void helloF(){
    glClear(GL_COLOR_BUFFER_BIT);
    pb1();
    pb2();
    pb();
    plant();
    Shark();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1200,600);
    glutCreateWindow("AQUERIUM");
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    //glutDisplayFunc(helloF);
    glutDisplayFunc(display);
    create_menu();
    glutMainLoop();
}



