#include<stdio.h>

#include<stdlib.h>

#include <string.h>

#include<GL/glut.h>

#include<math.h>

#include<time.h>



#define PI 3.14

float angleMoon=0.0, angleEarth=0.0,angleAstroid=0.0,angleMars=0.0,angleMercury=0.0,angleVenus=0.0,angleJupiter=0.0, angleSaturn=0.0,angleUranus=30.0,angleNeptune=60.0;

void drawstring(float x,float y,float z,char *string)



{
 char *c;
 glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
 {
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
 }
}

GLfloat sx=0.2,sy=0.2,sz=0.2;
int planet=0;

int planet1;

GLfloat black[]={0.0f,0.0f,0.0f,1.0f};

GLfloat white[]={1.0f,1.0f,1.0f,1.0f};

GLfloat blue[]={0.0f,0.0f,0.9f,1.0f};

GLfloat er[]={0.0f,5.0f,0.9f,1.0f};

GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};

GLfloat qAmb[]={0.1,0.1,0.1,1.0};

GLfloat qDif[]={1.0,1.0,1.0,1.0};

GLfloat qSpec[]={.50,.50,.50,.10};

GLfloat qPos[]={0,0,0,0.1};

GLfloat sc[8]={0.295 , 0.40,0.50, 0.60,0.80,1.0,1.05,1.13};

double ang=2*PI/300;

double angular=2*PI/50;





void initLighting()

{

    //glMaterialfv(GL_FRONT,GL_AMBIENT,yellow);

    //glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);

    glShadeModel(GL_FLAT);

    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT7);

    glLightfv(GL_LIGHT7,GL_AMBIENT,qAmb);

    glLightfv(GL_LIGHT7,GL_DIFFUSE,qDif);

    glLightfv(GL_LIGHT7,GL_SPECULAR,qSpec);

    //glMaterialfv(GL_FRONT,GL_DIFFUSE,yellow);

}

void myinit()

{

   glClearColor(0.0,0.0,0.0,0.0); //backgroundcolor is green

   //gluOrtho2D(0,699,0,699);

   glPointSize(1.0);

   glLineWidth(2.0);



}



void background()

{

    glBegin(GL_QUADS);

      glColor3f(0.0,0.00,0.00);

      glVertex3f(-01.00,01.00,1);

      glColor3f(.20,0.0,0.70);

      glVertex3f(01.00,1.00,1);

      glColor3f(0,0.0,0.0);

      glVertex3f(1.00,-1.00,1);

      glColor3f(.70,.10,.20);

      glVertex3f(-1.00,-1.00,1);

    glEnd();

}



void orbit()

{

glColor3f(0.5,0.5,0.5);





int i=0;

for(i=0;i<8;i++){

glPushMatrix();

glRotatef(63,1.0,0.0,0.0);

glScalef(sc[i],sc[i],sc[i]);

glBegin(GL_POINTS);

double ang1=0.0;

  int i=0;

  for(i=0;i<300;i++)

  {glVertex2d(cos(ang1),sin(ang1));

   ang1+=ang;  }

glEnd();

glPopMatrix();

}

}



void draw(void)

{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);

    background();

    orbit();

    glLoadIdentity();

    glPushMatrix();

    glEnable(GL_DEPTH_TEST);

   glEnable(GL_COLOR_MATERIAL);

       glPushMatrix();

       glColor3f(0.7,0.5,0.0);

       glScalef(sx,sy,sz);

        glLightfv(GL_LIGHT7,GL_POSITION,qPos);

       glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);

       glutSolidSphere(1,50,50);

       glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

       glPopMatrix();



       glScalef(0.2,0.2,0.2);

      if(planet==1||planet==0){

       glPushMatrix();

         glRotatef(angleMercury,0.0,1.0,-0.5);

         glTranslatef(1.5,0.0,0.0);

         glColor3f(1.0,0.9,0.0);

         glScalef(0.08,0.08,0.08);

         glutSolidSphere(1,50,50);

       glPopMatrix();

	}



       if(planet==2||planet==0){

       glPushMatrix();

         glRotatef(angleVenus,0.0,1.0,-0.5);

         glTranslatef(2.0,0.0,0.0);

         glColor3f(0.9,0.1,0.0);

         glScalef(0.1,0.1,0.1);

         glutSolidSphere(1,50,50);

       glPopMatrix();

	}



       if(planet==3||planet==0){

       glPushMatrix();

         glRotatef(angleEarth,0.0,1.0,-0.5);

         glTranslatef(2.5,0.0,0.0);

         glColor3f(0.0,0.1,0.7);

         glScalef(0.23,0.23,0.23);

         glutSolidSphere(1,50,50);

            glPushMatrix();

             glRotatef(angleMoon,0.0,0.1,0.05);

             glTranslatef(1.3,0.0,0.0);

             glColor3f(1.0,1.0,1.0);

             glScalef(0.5,0.5,0.5);

             glutSolidSphere(0.5,50,50);

           glPopMatrix();//moon made

       glPopMatrix();//earth made

	}



       if(planet==4||planet==0){

       glPushMatrix();

         glRotatef(angleMars,0.0,1.0,-0.5);

         glTranslatef(-3.0,0.0,0.0);

         glColor3f(0.05,0.05,0.01);

         glScalef(0.17,0.17,0.17);

         glutSolidSphere(1,50,50);

       glPopMatrix();

	}





        glPushMatrix();

             glColor3f(3.30,3.30,3.30);

             glRotatef(63,1.0,0.0,0.0);

             int j=0,i=0,div=90;float siz=2;

             float scl[4]={3.3,3.4,3.35,3.2};

             for(j=0;j<4;j++)

             {glPushMatrix();siz-=0.3;

             glPointSize(siz);

             glScalef(scl[j],scl[j],scl[j]);

             glBegin(GL_POINTS);

                double ang1=0.0 -angleAstroid,a=(2*PI)/div;

                for(i=0;i<div;i++)

                  {glVertex2d(cos(ang1),sin(ang1));

                   ang1+=a;  }

                   div+=10;

            glEnd();

            glPopMatrix();

             }

           glPopMatrix();//astroid made





      if(planet==5||planet==0){

       glPushMatrix();

         glRotatef(angleJupiter,0.0,1.0,-0.5);

         glTranslatef(-4.0,0.0,0.0);

         glColor3f(0.4,0.2,0.0);

         glScalef(0.5,0.5,0.5);

         glutSolidSphere(1,50,50);

         glPopMatrix();

	}



       if(planet==6||planet==0){

       glPushMatrix();

         glRotatef(angleSaturn,0.0,1.0,-1.0);

         glTranslatef(-5.0,0.0,0.0);

         glColor3f(0.9,0.0,0.0);

         glScalef(0.4,0.4,0.4);

         glutSolidSphere(1,50,50);

         glPushMatrix();

             glRotatef(63,1.0,0.0,0.0);

             glPointSize(3);

             glColor3f(5.0,3.0,1.0);

             glScalef(1.2,1.2,1.2);

             glBegin(GL_POINTS);

                double ang1=0.0;

                i=0;

                for(i=0;i<50;i++)

                  {glVertex2d(cos(ang1),sin(ang1));

                   ang1+=angular;  }

            glEnd();



            glPointSize(2);

           glPopMatrix();//ring made

       glPopMatrix();

	}



      if(planet==7||planet==0){

      glPushMatrix();

         glRotatef(angleUranus,0.0,1.0,-0.5);

         glTranslatef(5.2,0.0,0.0);

         glColor3f(0.0,0.5,0.9);

         glScalef(0.23,0.23,0.23);

         glutSolidSphere(1,50,50);

       glPopMatrix();

	}



      if(planet==8||planet==0){

       glPushMatrix();

         glRotatef(angleNeptune,0.0,1.0,-0.5);

         glTranslatef(-5.7,0.0,0.0);

         glColor3f(0.0,0.0,0.9);

         glScalef(0.2,0.2,0.2);

         glutSolidSphere(1,50,50);

       glPopMatrix();

	}



glPopMatrix();

     glFlush();

}





void update(int value){



if((angleMoon>=0 && angleMoon<180) )

{sx-=0.0003;sy-=0.0003;sz-=0.0003;}

else{sx+=0.0003;sy+=0.0003;sz+=0.0003;}





angleMoon+=2;

if(angleMoon>360){

    angleMoon-=360;}

angleEarth+=0.7;

if(angleEarth>360){

    angleEarth-=360;}

angleMercury+=2;

if(angleMercury>360){

    angleMercury-=360;}

angleVenus+=0.9;

if(angleVenus>360){

    angleVenus-=360;}

angleMars+=0.5;

if(angleMars>360){

    angleMars-=360;}

angleJupiter+=0.2;

if(angleJupiter>360){

    angleJupiter-=360;}

angleSaturn+=0.1;

if(angleSaturn>360){

    angleSaturn-=360;}





angleUranus+=0.05;

if(angleUranus>360){

    angleUranus-=360;}





angleNeptune+=0.02;

if(angleNeptune>360){

    angleNeptune-=360;}





angleAstroid+=0.002;

if(angleAstroid>360){

    angleAstroid-=360;}





glutPostRedisplay();

glutTimerFunc(20,update,0);

}



void mykey(unsigned char k,int x,int y)



{



if (k=='q')



        planet=0;



if (k=='m')



        planet =1;



if (k=='v')



        planet =2;

if (k=='g')



        planet =3;

if (k=='w')



        planet =4;

if (k=='j')



        planet=5;



if (k=='t')



        planet =6;



if (k=='u')



        planet =7;

if (k=='n')



        planet =8;

if (k=='e')



        exit(0);

}



int main(int argc, char **argv)

{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowPosition(0,0);

    glutInitWindowSize(1200,1200);

    glutCreateWindow("Solar System");

    initLighting();

    myinit();

    glutDisplayFunc(draw);

    glutKeyboardFunc(mykey);

    glutTimerFunc(25,update,0);

    glutMainLoop();

    return 0;

}
