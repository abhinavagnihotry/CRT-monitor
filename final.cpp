
#include <stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<time.h>
#pragma warning (disable : 4305)
#pragma warning (disable : 4244)

void cyc_draw();

#define TEXTID 3
int flag;                   //to initialize the window
float  col=0.0f,ang=0.0f,an=0.0f;
float f=0.0f,t=0.0f,l=0.0f,t1=0.0f,t2=0.0f;
int n=0,nn=0 ,w;
int m=0,s=4,cc=0,state1=0;
float va=0.02;
float z=0,x=0,y=0;
float yy,xx,zz,y2,yyy;
float incy=8,decy=-8;
float incy1=-8,incyy1;
float incyy,decyy;
int state5=0, state2=0,state3=0,state4=0,state6=0,state7=0,state8=0,state9=0,state10=0,state11=0,state12=0,state13=0;
float x1,y1,z1;
float c1=1,c2=0,c3=0;
float c4=1,c5=1,c6=1;

static GLfloat theta[] = {0.0f,0.0f,0.0f};
static GLint axis = 2;
static GLdouble viewer[]= {0.0, 0.0, 7.0}; /* initial viewer location */
char text[]={"CATHODE RAY TUBE"};
char text1[]={"Cathode"};
char text2[]={"Anode"};
char text3[]={"Phosphorescent Screen"};
char text4[]={"APPLYING A MAGNETIC FIELD"};
char text5[]={"Vertical Deflecting Plates"};
char text6[]={"Horizontal Deflecting Plates"};
char text7[]={"Electron Gun "};
char text8[]={"Power Supply "};

char optiontext1[]={"Options"};
char optiontext2[]={" e:APPLY A ELECTRIC FIELD "};
char optiontext3[]={" E:REMOVE A ELECTRIC FIELD "};
char optiontext4[]={" m:APPLY A MAGNETIC FIELD "};
char optiontext5[]={" M:REMOVE A MAGNETIC FIELD "};
char optiontext6[]={" z:ZOOM IN "};
char optiontext7[]={" Z:ZOOM OUT "};
char optiontext8[]={" Esc:EXIT "};
char elee[]={"APPLYING A ELECTRIC FIELD"};

GLfloat circles[][2]={{-1.0,4.0},{.9,3.9}};

GLfloat vertices[][3]={{0,0.7,1.2},{0,1.2,1.2},{0,1.2,0.7},{0,0.7,0.7},/*CRT 4*/{2.15,2.3,-0.7},{2.15,-0.7,-0.7},{2.15,-0.7,2.3},{2.15,2.3,2.3},
{-2.5,0.7,1.2},{-2.5,1.2,1.2},{-2.5,1.2,0.7},{-2.5,0.7,0.7},{-1,0,0}};
GLfloat electrodep[][3]={{-0.5,1.8,1.4},{-0.5,1.65,1.4},{0.5,1.65,1.4},{0.5,1.8,1.4},{-0.5,1.8,0},{-0.5,1.65,0},{0.5,1.65,0},{0.5,1.8,0}};

//vertex for Electrodes
GLfloat electroden[][3]={{-0.5,0.1,1.4},{-0.5,0.25,1.4},{0.5,0.25,1.4},{0.5,0.1,1.4},{-0.5,0.1,0},{-0.5,0.25,0},{0.5,0.25,0},{0.5,0.1,0}};
GLfloat electrodeup[][3]={{-0.10,1.8,0.6},{-0.10,1.8,0.8},{0.10,1.8,0.8},{0.10,1.8,0.6},{-0.10,3.5,0.6},{-0.10,3.5,0.8},{0.10,3.5,0.8},{0.10,3.5,0.6}} ;
GLfloat electrodedn[][3]={{-0.10,0.25,0.6},{-0.10,0.25,0.8},{0.10,0.25,0.8},{0.10,0.25,0.6},{-0.10,-1.45,0.6},{-0.10,-1.45,0.8},{0.10,-1.45,0.8},{0.10,-1.45,0.6}} ;                         //upper part of plate
//matrix for colour

GLfloat colors[][3] = {{0.4,0.4,0.4},{0.4,0.4,0.4},{0.6,0.6,0.6},{0.6,0.6,0.6},{0.6,0.6,0.6},{0.6,0.6,0.6},
{0.4,0.4,0.4},{0.4,0.4,0.4},{0.4,0.4,0.4},{0.4,0.4,0.4},{0.6,0.6,0.6},{0.6,0.6,0.6}};

//Border points
GLfloat border[][2] = {{-3.8,5.1},{3.8,5.1},{3.8,-2.5},{-3.8,-2.5},{-3.6,5.1},{3.6,5.1},{3.8,4.8},{3.8,-2.2},{3.6,-2.5},{-3.6,-2.5},{-3.8,-2.2},{-3.8,4.8}};

GLfloat screenborder[][3] = {{2.16,0.0,0.0},/*1*/{2.16,-0.76,-0.72},{2.16,-0.76,-0.68},{2.16,2.35,-0.68},{2.16,2.35,-0.72},/*5*/{2.16,2.27,-0.72},
{2.16,2.27,2.32},{2.16,2.35,2.32},{2.16,2.35,2.28},/*9*/{2.16,-0.76,2.28},{2.16,-0.76,2.32},{2.16,-0.68,2.32},{2.16,-0.68,-0.72}};

//power suply cube
GLfloat powsup[][3]={{-2,1.2,1.2},{-2,1.2,2.2},{-3,1.2,2.2},{-3,1.2,1.2},{-2,2.2,1.2},{-2,2.2,2.2},{-3,2.2,2.2},{-3,2.2,1.2}};
GLfloat mag[][3]={{0,0.5,0.7},{0,0.5,1.2},{-0.5,0.5,1.2},{-0.5,0.5,0.7},{0,-0.5,0.7},{0,-0.5,1.2},{-0.5,-0.5,1.2},{-0.5,-0.5,0.7},{0,-1.5,0.7},{0,-1.5,1.2},{-0.5,-1.5,1.2},{-0.5,-1.5,0.7}};
void keyboard(GLubyte,GLint, GLint );

void polygon(int a, int b, int c , int d)
{
    glLineWidth(2);
    if(a==6 && b==7 && c==4 && d==5)  //display black colour
    {

        glBegin(GL_POLYGON);
        //$$$$
        glColor3f(0,0,0);
        glVertex3fv(vertices[a]);

        glColor3f(0,0,0);
        glVertex3fv(vertices[b]);

        glColor3f(0,0,0);
        glVertex3fv(vertices[c]);

        glColor3f(0,0,0);
        glVertex3fv(vertices[d]);

        glEnd();
        glBegin(GL_LINE_LOOP);
        glColor3f(1,1,1);

        glVertex3fv(vertices[a]);
        glColor3f(1,1,1);

        glVertex3fv(vertices[b]);
        glColor3f(1,1,1);

        glVertex3fv(vertices[c]);
        glColor3f(1,1,1);
        glVertex3fv(vertices[d]);
        glEnd();
    }
    else
    {

        glBegin(GL_POLYGON);
        glColor3fv(colors[a]);
        glVertex3fv(vertices[a]);
        glColor3fv(colors[b]);
        glVertex3fv(vertices[b]);
        glColor3fv(colors[c]);
        glVertex3fv(vertices[c]);
        glColor3fv(colors[d]);
        glVertex3fv(vertices[d]);
        glEnd();
    }
}

void colorcube()//crt
{
    polygon(3,2,4,5);
    polygon(6,7,4,5);
    polygon(0,1,2,3);
    polygon(1,7,4,2);
    polygon(0,6,5,3);
    polygon(3,11,10,2);
    polygon(8,9,10,11);
    polygon(9,1,2,10);
    polygon(0,8,11,3);
}

void eledraw(int a,int b,int c,int d) //Draw the two Electrodes
{
    glBegin(GL_POLYGON);
    xx=electrodep[a][0];
    yy=electrodep[a][1];
    zz=electrodep[a][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+incy,zz);
    xx=electrodep[b][0];
    yy=electrodep[b][1];
    zz=electrodep[b][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+incy,zz);
    xx=electrodep[c][0];
    yy=electrodep[c][1];
    zz=electrodep[c][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+incy,zz);
    xx=electrodep[d][0];
    yy=electrodep[d][1];
    zz=electrodep[d][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+incy,zz);
    glEnd();

    glBegin(GL_POLYGON);
    xx=electroden[a][0];
    yy=electroden[a][1];
    zz=electroden[a][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+decy,zz);
    xx=electroden[b][0];
    yy=electroden[b][1];
    zz=electroden[b][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+decy,zz);
    xx=electroden[c][0];
    yy=electroden[c][1];
    zz=electroden[c][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+decy,zz);
    xx=electroden[d][0];
    yy=electroden[d][1];
    zz=electroden[d][2];
    glColor3f(0.5,0,0.5);
    glVertex3f(xx,yy+decy,zz);
    glEnd();

    glBegin(GL_POLYGON);
    xx=electrodeup[a][0];
    yy=electrodeup[a][1];
    zz=electrodeup[a][2];
    glColor3f(0.5,0,1);
    glVertex3f(xx,yy+incy,zz);
    xx=electrodeup[b][0];
    yy=electrodeup[b][1];
    zz=electrodeup[b][2];
    glColor3f(0.5,0,0);
    glVertex3f(xx,yy+incy,zz);
    xx=electrodeup[c][0];
    yy=electrodeup[c][1];
    zz=electrodeup[c][2];
    glColor3f(0.5,0,0);
    glVertex3f(xx,yy+incy,zz);
    xx=electrodeup[d][0];
    yy=electrodeup[d][1];
    zz=electrodeup[d][2];
    glColor3f(0.5,0,0);
    glVertex3f(xx,yy+incy,zz);
    glEnd();

    glBegin(GL_POLYGON);
    xx=electrodedn[a][0];
    yy=electrodedn[a][1];
    zz=electrodedn[a][2];
    glColor3f(0.5,0,1);
    glVertex3f(xx,yy+decy,zz);
    xx=electrodedn[b][0];
    yy=electrodedn[b][1];
    zz=electrodedn[b][2];
    glColor3f(0.5,0,0);
    glVertex3f(xx,yy+decy,zz);
    xx=electrodedn[c][0];
    yy=electrodedn[c][1];
    zz=electrodedn[c][2];
    glColor3f(0.5,0,0);
    glVertex3f(xx,yy+decy,zz);
    xx=electrodedn[d][0];
    yy=electrodedn[d][1];
    zz=electrodedn[d][2];
    glColor3f(0.5,0,0);
    glVertex3f(xx,yy+decy,zz);
    glEnd();

    glBegin(GL_LINE_LOOP);//+
    glColor3f(1,0,0);
    glVertex3f(0.3,-0.7+decy,1);
    glColor3f(1,0,0);
    glVertex3f(0.5,-0.7+decy,1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glColor3f(1,0,0);
    glVertex3f(0.4,-0.6+decy,1);
    glColor3f(1,0,0);
    glVertex3f(0.4,-0.8+decy,1);
    glEnd();
    glBegin(GL_LINE_LOOP);//-
    glColor3f(1,0,0);
    glVertex3f(0.3,2.4+incy,1);
    glColor3f(1,0,0);
    glVertex3f(0.5,2.4+incy,1);
    glEnd();

}


void powerd(int a,int b,int c,int d)  //Draw the Power supply Cube
{

    glBegin(GL_POLYGON);//power supply
    glColor3f(0,0.5,0.5);
    glVertex3fv(powsup[a]);
    glColor3f(1,0.5,0.25);
    glVertex3fv(powsup[b]);
     glColor3f(0,0.5,0.5);
    glVertex3fv(powsup[c]);
    glColor3f(1,0.5,0.25);
    glVertex3fv(powsup[d]);
    glEnd();

    {
        glBegin(GL_LINE_LOOP);//cover line for cube
        glColor3f(1,0.5,0);
        glVertex3fv(powsup[a]);
        glColor3f(1,0.5,0);
        glVertex3fv(powsup[b]);
        glColor3f(1,0.5,0);
        glVertex3fv(powsup[c]);
        glColor3f(1,0.5,0);
        glVertex3fv(powsup[d]);
        glEnd();
    }

    {
        glBegin(GL_LINE_STRIP);
        glLineWidth(5);
        glColor3f(col,col,col);
        glVertex3f(-2.5,1,1);
        glVertex3f(-2.7,1,1);
        glVertex3f(-2.7,1,1.7);
        glVertex3f(-2.7,1.2,1.7);
        glEnd();
    }
    {
        glBegin(GL_LINE_STRIP);//wire to anode from power
        glLineWidth(5);
        glColor3f(col,col,col);
        glVertex3f(-1.7,1,1.0);
        glVertex3f(-1.7,1,1.0);
        glVertex3f(-2.4,1,1.7);
        glVertex3f(-2.4,1.2,1.7);
        glEnd();
    }

}

void magnetup(int a,int b,int c,int d)  //Draw the magnet
{

    glBegin(GL_POLYGON);
    x1=mag[a][0];
    y1=mag[a][1];
    z1=mag[a][2];
    glColor3f(c1,c2,c3);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[b][0];
    y1=mag[b][1];
    z1=mag[b][2];
    glColor3f(c1,c2,c3);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[c][0];
    y1=mag[c][1];
    z1=mag[c][2];
    glColor3f(c1,c2,c3);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[d][0];
    y1=mag[d][1];
    z1=mag[d][2];
    glColor3f(c1,c2,c3);
    glVertex3f(x1,y1+incy1,z1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    x1=mag[a][0];
    y1=mag[a][1];
    z1=mag[a][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[b][0];
    y1=mag[b][1];
    z1=mag[b][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[c][0];
    y1=mag[c][1];
    z1=mag[c][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[d][0];
    y1=mag[d][1];
    z1=mag[d][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    glEnd();
}


void magnetdn(int a,int b,int c,int d) //Draw the magnet
{
    glBegin(GL_POLYGON);
    x1=mag[a][0];
    y1=mag[a][1];
    z1=mag[a][2];
    glColor3f(c4,c5,c6);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[b][0];
    y1=mag[b][1];
    z1=mag[b][2];
    glColor3f(c4,c5,c6);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[c][0];
    y1=mag[c][1];
    z1=mag[c][2];
    glColor3f(c4,c5,c6);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[d][0];
    y1=mag[d][1];
    z1=mag[d][2];
    glColor3f(c4,c5,c6);
    glVertex3f(x1,y1+incy1,z1);
    glEnd();


    glBegin(GL_LINE_LOOP);
    x1=mag[a][0];
    y1=mag[a][1];
    z1=mag[a][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[b][0];
    y1=mag[b][1];
    z1=mag[b][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[c][0];
    y1=mag[c][1];
    z1=mag[c][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    x1=mag[d][0];
    y1=mag[d][1];
    z1=mag[d][2];
    glColor3f(1,0,0);
    glVertex3f(x1,y1+incy1,z1);
    glEnd();

}

void electrod()//crt
{
    eledraw(0,1,2,3);
    eledraw(4,5,6,7);
    eledraw(0,1,5,4);
    eledraw(2,3,7,6);
    eledraw(0,3,7,4);
    eledraw(1,2,6,5);
}


void power()//crt
{
    //draaw power supply cube
    powerd(0,1,2,3);
    powerd(1,2,6,5);
    powerd(4,5,6,7);
    powerd(4,0,3,7);
    powerd(0,1,5,4);
    powerd(3,2,6,7);
}

void magnd()
{
    magnetdn(4,5,6,7);
    magnetdn(5,9,10,6);
    magnetdn(8,9,10,11);
    magnetdn(4,8,11,7);
    magnetdn(4,5,9,8);
    magnetdn(6,7,11,10);
}

void magnu()//crt_
{
    magnetup(0,1,2,3);
    magnetup(1,5,6,2);
    magnetup(0,1,2,3);
    magnetup(0,4,7,3);
    magnetup(3,7,6,2);
    magnetup(0,4,5,1);
}

void menu(int s)  //design menu
{
    if(s==0)
    {
    for(w=0;w<=(int)strlen(elee);w++)
    {
    glRasterPos3f(-2,2,0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,elee[w]);
    }

    incyy=-0.05;
    n=0;
    incy=8;
    decyy=0.05;
    decy=-8;
    state2=1;
    state3=1;
    state6=0;
    incy1=-8;
    }

    if(s==1)
    {
    incyy1=-0.2;
    state6=1;
    state2=0;
    incy=8;
    decy=-8;
    state7=0;
    state13=1;
    c1=1;c2=0;c3=0;
    c4=1;c5=1;c6=1;
    t1=0;
    t2=0;
    state10=0;
    state9=0;
    }

    if(s==2)
    {
    incy=8;
    decy=-8;
    state2=0;
    state1=1;
    state4=0;
    incy=8;
    decy=-8;
    state6=0;
    state9=0;
    state7=0;
    state10=0;
    state11=0;
    state12=0;
    state13=0;
    }

    if(s==3)
    {
    incy1=-8;
    state6=0;
    state2=0;
    t1=0;
    state1=0;
    state7=0;
    state12=0;
    }


    if(s==4)
    {
    exit(0);
    }
}


void electrmotion()                //Apply the motion effect for electron
{
    t=0;
    l=0;
    col=0;

    if(m%2==0)                    //colour changing operation after each two points
    {
    t=1;
    col=1;
    }

    m=m+1;
    va=va-0.007;

    if(yy==1)
    {
    va=0.02;
    }

    if(va<0)//after ele effect to get same transper of electron
    {
    va=0.02;
    }

    if(decy<=decyy && state2==1)
    {
    decy=decy+0.045;	//0.02;	
    }

    if(incy>=incyy && state2==1)
    {
    incy=incy-0.045;	//0.02;
    }

    if(decy>=decyy && state2==1)
    {
    state11=1;
    }

    if(incy<=incyy && state2==1)
    {
    state12=1;
    }

    if(incy>incyy)
    {
    state4=1;
    }

    if(incy1<=incyy1 && state6==1)//for magnet slow motion
    {
    incy1=incy1+0.15; //0.017;
    }

    else if(incy1>=incyy1 && state6==1)
    {
    state9=1;
    }

    if(incy1>=incyy1 && state7==1)
    {
    state10=1;
    }

    if(incy1>=incyy1 && state6==1 && state8==0)//invert the magnet
    {
        if(t1<=300)
        {
        t1++;
        }

        else
        {
            state9=0;
            state7=1;
            state6=0;

            if(t2==0)
            {
                incy1=-8;
                t2=1;
                incyy1=-0.2;
            }

            state6=1;
            state2=0;
            incy=8;
            decy=-8;
            state7=1;
            //state8=1;
            c1=1;c2=1;c3=1;
            c4=1;c5=0;c6=0;
        }
    }
    glutPostRedisplay();

}




void DrawTextXY(double x,double y,double z,double scale,char *s)
{
    int i;

    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(scale,scale,scale);
    for (i=0;i < (int)strlen(s);i++)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,s[i]);
    glPopMatrix();
}

void keys(unsigned char key, int x, int y)
{
if(key == 'e')
{
    for(w=0;w<=(int)strlen(elee);w++)
    {
    glRasterPos3f(-2,2,0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,elee[w]);
    }

    incyy=-0.05;
    n=0;
    incy=8;
    decyy=0.05;
    decy=-8;
    state2=1;
    state3=1;
    state6=0;
    incy1=-8;
    state6=0;
    state9=0;
    state7=0;
    state10=0;
}

if(key == 'E')
{
    incy=8;
    decy=-8;
    state2=0;
    state1=1;
    state4=0;
    incy=8;
    decy=-8;
    state6=0;
    state9=0;
    state7=0;
    state10=0;
    state11=0;
    state12=0;
}

if(key == 'm')
{
    incyy1=-0.2;
    state6=1;
    state2=0;
    incy=8;
    decy=-8;
    state7=0;
    c1=1;c2=0;c3=0;
    c4=1;c5=1;c6=1;
    t1=0;
    t2=0;
    state10=0;
    state9=0;
}

if(key == 'M')
{
    incy1=-8;
    state6=0;
    state2=0;
    t1=0;
    state1=0;
    state7=0;
    state12=0;
}

	if(key == 'x') viewer[0]-= 1.0;
    if(key == 'X') viewer[0]+= 1.0;
	if(key == 'y') viewer[1]-= 1.0;
    if(key == 'Y') viewer[1]+= 1.0;


    if(key == 'z') viewer[2]-= 1.0;
    if(key == 'Z') viewer[2]+= 1.0;
    if(key==27)     exit(0);
}

void myinit()
{
    glShadeModel (GL_SMOOTH);
    glClearColor(0,0.5,1,1);
    glPointSize(8);
    gluOrtho2D(0,2000,0,1000);
    glEnable(GL_DEPTH_TEST);
}


 




void screenborderfunc(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);

    glColor3f(0.35f, 0.35f, 0.35f);
    glVertex3fv(screenborder[a]);
    glVertex3fv(screenborder[b]);
    glVertex3fv(screenborder[c]);
    glVertex3fv(screenborder[d]);

    glEnd();
}



  void drawCube(float x, float y, float z) 
    {
        glPushMatrix();
		glTranslatef(x, y, z);
		glScalef(0.2,0.1,0.06);
        
        glBegin(GL_QUADS); 
        glVertex3f(-1.0f,-1.0f ,-1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);

        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        glVertex3f(-1.0f,-1.0f ,1.0f );
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glEnd();

        glPopMatrix();
    }



void display()  // crt_display the all the objects
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.6,0.839,1,1);

    if(state3==1)
    {
        glClearColor(0,0.5,1,1);
        glColor3f(0.6,0.6,0);
        glRasterPos3f(1.5,0,0);
        for(w=0;w<=(int)strlen(elee);w++)
        {
            glColor3f(1,0,1);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,elee[w]);
        }

        if(n==100)
        {
            state3=0;
            state13=0;
            n=0;
        }

        n++;
        glFlush();
        glutSwapBuffers();
    }



    if(state13==1)
    {
        glClearColor(0,0.5,1,1);
        glColor3f(1,1,0);
        glRasterPos3f(1.5,0,0);
        for(w=0;w<=(int)strlen(text4);w++)
        {
            glColor3f(1,0,1);
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text4[w]);
        }

        if(n==100)
        {
        state13=0;
        state3=0;
        n=0;
        }

        n++;
        glFlush();
        glutSwapBuffers();
    }


    if(state3==0 && state13==0)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Update  position in modelview matrix                      

        glLoadIdentity();
	
        gluLookAt(viewer[0],viewer[1],viewer[2], 0.0, 0.0, 0.0, 0.0, 100.0, 0.0);

        /* rotate cube */
       
        glRotatef(35, 0.0, 1.0, 0.0);
        glRotatef(180, 0.0, 0.0, 1.0);


		glColor3f(1,0,0);		
        glRasterPos3f(1,-3.3,0);
        for(w=0;w<=(int)strlen(text);w++)
        {
			
             								//color of all the labels
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[w]);
        }

		
		//options

        glRasterPos3f(-5,-5.3,0);
        for(w=0;w<=(int)strlen(optiontext1);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext1[w]);
        }
//options2
         glRasterPos3f(-5,-5.0,0);
        for(w=0;w<=(int)strlen(optiontext2);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext2[w]);
        }
//options3
 glRasterPos3f(-5,-4.7,0);
        for(w=0;w<=(int)strlen(optiontext3);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext3[w]);
        }

//options4

 glRasterPos3f(-5,-4.4,0);
        for(w=0;w<=(int)strlen(optiontext4);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext4[w]);
        }


//options5
 glRasterPos3f(-5,-4.1,0);
        for(w=0;w<=(int)strlen(optiontext5);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext5[w]);
        }



//options6

 glRasterPos3f(-5,-3.8,0);
        for(w=0;w<=(int)strlen(optiontext6);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext6[w]);
        }



//options7
 glRasterPos3f(-5,-3.5,0);
        for(w=0;w<=(int)strlen(optiontext7);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext7[w]);
        }

		
//options8
 glRasterPos3f(-5,-3.2,0);
        for(w=0;w<=(int)strlen(optiontext8);w++)
        {
			
             glColor3f(0.6,0,0);										//color of all the labels
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,optiontext8[w]);
        }

glRotatef(theta[0], 0.0, 1.0, 0.0);
        colorcube();
        electrod();
        power();
        magnu();
        magnd();


	glColor3f(0.6,0,0);	


        glRasterPos3f(-4,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-4.2,0.2,0);
        glVertex3f(-2.5,1,1);
        glEnd();
        for(w=0;w<=(int)strlen(text1);w++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text1[w]);
        }
        glRasterPos3f(-2.6,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-2.7,0.2,0);
        glVertex3f(-1.75,0.7,1.1);
        glEnd();
        for(w=0;w<=(int)strlen(text2);w++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text2[w]);
        }



        glRasterPos3f(2.8,-1.4,0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(2.6,-1.2,0);
        glVertex3f(2.2,-0.4,1); 
        glEnd();
        for(w=0;w<=(int)strlen(text3);w++)
        {
           glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text3[w]);
        }

        glRasterPos3f(-1.15,-0.3,0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-1.5,-0.0,0);
        glVertex3f(-0.9,0.8,1);
        glEnd();

        for(w=0;w<=(int)strlen(text5);w++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text5[w]);
        }


		
										//Horizontal deflecting plates	
        glRasterPos3f(0.1,-0.9,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-0.1,-0.6,1);
		glVertex3f(-0.25,1.0,0.8);
        glEnd();

        for(w=0;w<=(int)strlen(text6);w++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text6[w]);
        }


				// electron gun 

		 glRasterPos3f(-3.7,-0.9,-0.2);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-3.9,-0.65,-0.2);
        glVertex3f(-2.1,0.98,0.98);
        glEnd();

        for(w=0;w<=(int)strlen(text7);w++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text7[w]);
        }


		//power supply

		 glRasterPos3f(-5.5,-0.6,-0.2);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-5.7,-0.35,-0.2);
        glVertex3f(-2.5,1.7,1.7);
        glEnd();

        for(w=0;w<=(int)strlen(text7);w++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text8[w]);
        }



        y=l/50;
        z=0;

        glPointSize(6);
        glBegin(GL_POINTS);
        for(f=0;f<=4.25;f=f+0.08,z=z+y)            //display electron as points
        {
            glColor3f(0,t,0);
            glVertex3f(-2.1+f,1,1);
        }
        glEnd();
        glPointSize(6);


        if(state1==0)
        {
            cc=1;
        }

        else
        {
            cc=2;
        }

        if(state2==1 && state11==1 && state12==1)
        {
            cc=3;
        }

        if(state6==1 && state9==1)
        {
            cc=3;
        }

        if(state7==1 && state10==1)
        {
           cc=4;
        }


        switch(cc)
        {
        case 1:yy=1;

            for(f=0;f<=4.30;f=f+0.08)          //display electron as points in slant up
            {
                glPointSize(6);
                glBegin(GL_POINTS);
                if((-2.1+f)>-0.0)
                {
                    glColor3f(0,1.0,0);
                    glVertex3f(-2.1+f,yy,1);    
                    yy=yy+va;    //0.02

					glVertex3f(-2.1+f,yy,1);        
                    yy=yy+va+0.003;

                }
                else
                {
                    glColor3f(0,1.0,0);
                    glVertex3f(-2.1+f,1,1);   
                }
            }
            state1=1;
            glEnd();




            break;


        case 2:
            yy=1;
            for(f=0;f<=4.3;f=f+0.08)            //display electron as points in slant down
            {
                glPointSize(6);
                glBegin(GL_POINTS);
                if((-2.1+f)>0.0)                
                {
                    glColor3f(0,1,0);
                    glVertex3f(-2.1+f,yy,1);      
                    yy=yy-va;    //0.02


					
					glVertex3f(-2.1+f,yy,1);        
                    yy=yy-va-0.003;					
                }
                else
                {
                    glColor3f(0,1.0,0);
                    glVertex3f(-2.1+f,1,1);
                }
            }
            state1=0;
            glEnd();
            break;


        case 3:
            yyy=1;
            for(f=0;f<=4.3;f=f+0.08)            //display electron as points in slant down
            {
                glPointSize(6);
                glBegin(GL_POINTS);
                if((-2.1+f)>0.0)
                {
                    glColor3f(0,1.0,0);
                    glVertex3f(-2.1+f,yyy,1);
                    yyy=yyy-0.03;    //0.02

					
					glVertex3f(-2.1+f,yyy,1);        
                    yyy=yyy-0.03-0.003;				


                }
                else
                {
                    glColor3f(0,1.0,0);
                    glVertex3f(-2.1+f,1,1);
                }
            }
            state1=0;
            glEnd();
            break;

        case 4:
            y2=1;
            for(f=0;f<=4.3;f=f+0.08)            //display electron as points in slant down
            {
                glPointSize(6);
                glBegin(GL_POINTS);
                if((-2.1+f)>0.0)
                {
                    glColor3f(0,1.0,0);
                    glVertex3f(-2.1+f,y2,1);
                    y2 = y2+0.02;    //0.02

					
					glVertex3f(-2.1+f,y2,1);        
                    y2=y2+0.023;

                }
                else
                {
                    glColor3f(0,1.0,0);
                    glVertex3f(-2.1+f,1,1);
                }
            }
            state1=0;
            glEnd();
            break;
        }



/* ########## FUNCTION TO DISPLAY THE MOVING PIXELS ON THE SCREEN ######### */	

glPointSize(10);
	glBegin(GL_POINTS);
	float j,i=0.0,m=0.0,colb=0.0;
	for (i=-0.5;i<=2.3;i=i+0.2)
	{		colb = rand() % 2;
		for(m=-0.5;m<=2.3;m=m+0.2)
		{	
			
				glPointSize(10);
				glColor3f(0.0,0.0,colb);
				glVertex3f(2.2,i,m);
				for ( j=0.0;j<=30000; j=j+1){}
				for ( j=0.0;j<=30000; j=j+1){}
				for ( j=0.0;j<=30000; j=j+1){}
		}
	}
	glEnd();


		screenborderfunc(1,2,3,4);
		screenborderfunc(4,5,6,7);
		screenborderfunc(7,8,9,10);
		screenborderfunc(10,11,12,1);


        glBegin(GL_POLYGON);				//anode
        glLineWidth(10);
        glColor3f(1,0,0.5);
        glVertex3f(-1.75,0.7,1.1);

        glColor3f(0.7,0,0.5);
        glVertex3f(-1.75,0.7,0.8);

        glColor3f(0.8,0,0.5);
        glVertex3f(-1.75,1.2,0.8);

        glColor3f(0.9,0,0.5);
        glVertex3f(-1.75,1.2,1.1);
        glEnd();



        glBegin(GL_POLYGON);				//cathode
        glColor3f(1,0,0.6);
        glVertex3f(-2.49,0.7,1.1);

        glColor3f(1,0,0.6);
        glVertex3f(-2.49,0.7,0.8);

        glColor3f(1,0,0.6);
        glVertex3f(-2.49,1.2,0.8);

        glColor3f(1,0,0.6);
        glVertex3f(-2.49,1.2,1.1);
        glEnd();


		//different color at the point where electrons start spliting
		glBegin(GL_POLYGON);
        glLineWidth(10);
        glColor3f(0.2,0.2,0.2);
        glVertex3f(0.005,0.7,1.2);

        glColor3f(0.2,0.2,0.2);
        glVertex3f(0.005,1.2,1.2);

        glColor3f(0.2,0.2,0.2);
        glVertex3f(0.005,1.2,0.7);

        glColor3f(0.2,0.2,0.2);
        glVertex3f(0.005,0.7,0.7);
        glEnd();


		
		//different color at the back panel
		glBegin(GL_POLYGON);
        glLineWidth(10);
        glColor3f(0.3,0.3,0.3);
        glVertex3f(2.15,-0.7,-0.695);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(2.15,2.3,-0.695);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,1.2,0.705);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,0.7,0.705);
        glEnd();



		
		//different color at the back panel from outside
		glBegin(GL_POLYGON);
        glLineWidth(10);
        glColor3f(0.3,0.3,0.3);
        glVertex3f(2.15,-0.7,-0.705);

        glColor3f(0.3,0.3,0.3);
        glVertex3f(2.15,2.3,-0.705);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,1.2,0.695);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,0.7,0.695);
        glEnd();


			
		//different color at the back panel of tube from outside
		glBegin(GL_POLYGON);
        glLineWidth(10);
        glColor3f(0.3,0.3,0.3);
        glVertex3f(-2.5,0.7,0.695);

        glColor3f(0.3,0.3,0.3);
        glVertex3f(-2.5,1.2,0.695);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,1.2,0.695);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,0.7,0.695);
        glEnd();



	
		//different color at the back panel of tube from inside
		glBegin(GL_POLYGON);
        glLineWidth(10);
        glColor3f(0.3,0.3,0.3);
        glVertex3f(-2.5,0.7,0.705);

        glColor3f(0.3,0.3,0.3);
        glVertex3f(-2.5,1.2,0.705);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,1.2,0.705);

         glColor3f(0.3,0.3,0.3);
        glVertex3f(0.005,0.7,0.705);
        glEnd();





        if(state12!=1)
        {


            glBegin(GL_POLYGON);//vertical deflecting plates // down
            glLineWidth(10);
            glColor3f(0.67,0.52549,0);
            glVertex3f(-1.5,1.1,0.8);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-1.5,1.1,1.1);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.95,1.1,1.1);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.95,1.1,0.8);
            glEnd();


            glBegin(GL_POLYGON);//upper plates
            glLineWidth(10);
            glColor3f(0.67,0.52549,0);
            glVertex3f(-1.5,0.8,0.8);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-1.5,0.8,1.1);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.95,0.8,1.1);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.95,0.8,0.8);
            glEnd();

			 glBegin(GL_POLYGON);//back horizontal plates
            glLineWidth(10);
            glColor3f(0.5,0.25,0);
            glVertex3f(-0.1,0.75,0.8);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.75,0.75,0.8);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.75,1.15,0.8);

           // glColor3f(0.5,0,0.5);
            glVertex3f(-0.1,1.15,0.8);
            glEnd();


			glBegin(GL_POLYGON);//front horizontal plates
            glLineWidth(10);
            glColor3f(0.67,0.349,0);
            glVertex3f(-0.1,0.75,1.1);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.75,0.75,1.1);

            //glColor3f(0.5,0,0.5);
            glVertex3f(-0.75,1.15,1.1);

           // glColor3f(0.5,0,0.5);
            glVertex3f(-0.1,1.15,1.1);
            glEnd();

        }

						
		    glColor3f(0.9,0.9,0);
			drawCube(-2.1,0.98,0.98);


            glFlush();
            glutSwapBuffers();
        }
}





void mouse(int btn, int state, int x, int y)//crt_mouse
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;   //  viewer[2]=-7;       //$$$$$$
    if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;


    theta[axis] += 10.0;
    ang=theta[axis];

    if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
      display();
}





void myReshape(int w, int h)//crt_first
{
    glViewport(0, 0, w, h);

    /* Use a perspective view */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h) glFrustum(-3.0, 3.0, -3.0 * (GLfloat) h/ (GLfloat) w,
    2.0* (GLfloat) h / (GLfloat) w, 3.0, 80.0);
    else glFrustum(-3.0, 3.0, -3.0 * (GLfloat) w/ (GLfloat) h,
    2.0* (GLfloat) w / (GLfloat) h, 3.0, 80.0);

    /* Or we can use gluPerspective */

    gluPerspective(45.0, w/h, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(0.0,1000.0,0.0,100.0);
	 glShadeModel(GL_FLAT); 
}


void OnSize(int x,int y)//screen resolution
{
    glViewport(0,0,x,y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,1,1,100);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    //  glDrawBufffer(GL_BACK);
}

void CRT(GLfloat a,GLfloat b)
{
    glBegin(GL_POLYGON);
    glVertex3f(a-0.008,b-0.008,0);
    glVertex3f(a+0.008,b-0.008,0);
    glVertex3f(a+0.008,b+0.008,0);
    glVertex3f(a-0.008,b+0.008,0);
    glEnd();
}


/*
void c_letter()
{
    GLfloat q,w;

    for(q=-1.0;q>=-2.0;q+=-0.03)
    {
    for(w=4.0;w>3.8;w-=0.03)
    {
    CRT(q,w);
    }

    }//<- C

    for(q=-1.83;q>=-2.0;q+=-0.03)
    {
    for(w=3.8;w>2.8;w-=0.03)
    {
    CRT(q,w);
    }

    }//

    for(q=-2.0;q<=-1.0;q-=-0.03)
    {
    for(w=2.8;w>2.6;w-=0.03)
    {
    CRT(q,w);
    }

    }//-> C
}

void r_letter()
{
    GLfloat e,r;

    for(e=-0.4;e>-0.6;e+=-0.03)
    {
    for(r=4.0;r>2.6;r-=0.03)
    {
    CRT(e,r);
    }

    }//

    for(e=-0.4;e<0.4;e+=0.03)
    {
    for(r=3.8;r<4.0;r+=0.03)
    {
    CRT(e,r);
    }

    }//-> R

    for(e=0.2;e<0.4;e+=0.03)
    {
    for(r=3.8;r>3.5;r-=0.03)
    {
    CRT(e,r);
    }

    }//

    for(e=0.3;e>=-0.4;e+=-0.03)
    {
    for(r=3.5;r>3.25;r-=0.03)
    {
    CRT(e,r);
    }

    }//->

    for(e=0.2;e<0.4;e+=0.03)
    {
    for(r=3.25;r>2.6;r-=0.03)
    {
    CRT(e,r);
    }
}//
    //glColor3f(0.0,0.0,0.0);
    ////CRT(0.39,3.3);
    ////CRT(0.4,2.6);
    //glBegin(GL_POLYGON);
    //glVertex3f(0.3,3.2,0);
    //glVertex3f(0.3,3.6,0);
    //glVertex3f(0.5,3.6,0);
    //glVertex3f(0.5,3.2,0);
    //glEnd();
    }

void t_letter()
{
    GLfloat t,u;
    for(t=1.8;t>=0.8;t-=0.03)
    {
    for(u=3.8;u<4.0;u+=0.03)
    {
    CRT(t,u);
    }

    }//-> T

    for(t=1.2;t<=1.4;t+=0.03)
    {
    for(u=3.8;u>2.6;u-=0.03)
    {
    CRT(t,u);
    }
    }//
}

*/





        /*{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glutFullScreen();
        DrawTextXY(-2.0,1.5,0.0,0.0022,"Graphical Implementation Of");
        DrawTextXY(-2.7,1.0,0.0,0.0022," ''CATHODE RAY TUBE''");
        DrawTextXY(1.4,-1.6,0.0,0.0007,"Press C to continue  ");
        DrawTextXY(-1.0,0.10,0.0,0.0015,"  Submitted By:    ");
        glColor3f(0.0,1.0,0.0);
        DrawTextXY(-2.5,-0.3,0.0,0.001,"PRATHIMA.G (1ST12CS076)              VIDHYASHRE.R(1ST13CS145) ");
        glColor3f(1.0,0.0,0.0);
        DrawTextXY(-1.0,-0.7,0.0,0.0015,"Under the guidance of:");
        glColor3f(0.9,0.2,0.6);
        DrawTextXY(-1.0,-1.0,0.0,0.001,"    Mr.SRINATH.K.S B.E.,M.Tech.    ");
        DrawTextXY(-1.0,-1.3,0.0,0.001,"    Lecturer,Dept. Of CS&E");

        DrawTextXY(-1.0,-1.6,0.0,0.001,"    SaIT");
        //geppetto edit begins
        glColor3f(0.0,0.5,0.5);
        DrawTextXY(-1.0,-1.8,0.0,0.0013,"Sambhram Institute Of Technology,M.S.Palya,B'lore");
        //geppetto edit ends
        glFlush();
        glutSwapBuffers();

        }
        */


void borderfunc(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);

    glColor3f(0.18f, 0.7215f, 0.7215f);
    glVertex2fv(border[a]);

     glColor3f(0.18f, 0.7215f, 0.7215f);
    glVertex2fv(border[b]);

     glColor3f(0.18f, 0.7215f, 0.7215f);
    glVertex2fv(border[c]);

     glColor3f(0.18f, 0.7215f, 0.7215f);
    glVertex2fv(border[d]);

    glEnd();
}




//MODIFIED
void cover()//Main screen content
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(0.149, 0.149, 0.149, 0.0);

    glTranslatef(0.0,0.0,-6.0);
    glTranslatef(0.0,-1.3,0.0);

    //glColor3f(1.00,0.20,0.10);
    glLoadName(TEXTID);
	 glColor3f(1.0,0.0,0.0);
    DrawTextXY(-2.0,4.0,0.1,0.0014," Graphical Implementation Of");
    glColor3f(0.0,1.0,0.0);
    DrawTextXY(-3.2,2.5,0.0,0.0039,"CATHODE RAY TUBE");
    glColor3f(1.0,0.0,0.0);
    DrawTextXY(-1.0,1.5,0.0,0.0013,"Submitted By:    ");
    glColor3f(0.0,1.0,0.0);
    DrawTextXY(-3.6,1.0,0.0,0.0011," Pallavi Purohit(1ST14CS738)     Abhinav Agnihotry(1ST14CS700) ");
    glColor3f(1.0,0.0,0.0);
    DrawTextXY(-2.5,0.5,0.0,0.0013,"      Under the guidance of:");
    glColor3f(0.9,0.2,0.6);
    DrawTextXY(-2.4,0.0,0.0,0.0015,"  Mr.SRINATH K.S. B.E.,M.Tech.    ");
    DrawTextXY(-1.2,-0.4,0.0,0.001,"Lecturer,Dept. Of CS&E");
    DrawTextXY(-1.0,-0.7,0.0,0.001,"   SaIT");

    DrawTextXY(1.3,-1.75,0.0,0.0008," Press any key to continue  ");
	DrawTextXY(-3.4,-1.75,0.0,0.0008,"Press Esc to Exit  ");
    //geppetto edit begins
    glColor3f(0.0,0.5,0.5);
    DrawTextXY(-3.5,-1.2,0.0,0.0013," Sambhram Institute Of Technology,M.S.Palya,B'lore");


    borderfunc(4,0,3,9);
    borderfunc(10,3,2,7);
    borderfunc(8,2,1,5);
    borderfunc(6,1,0,11);

    glFlush();          //Finish rendering
    glutSwapBuffers();

}



        /*
        void cover()//Main screen content
        {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glClearColor(1.0, 0.0, 0.0, 0.0);

        glTranslatef(0.0,0.0,-6.0);
        glTranslatef(0.0,-1.3,0.0);

        //glColor3f(1.00,0.20,0.10);
        glLoadName(TEXTID);

        DrawTextXY(-2.5,4.5,0.1,0.0014,"   GRAPHICAL IMPLEMENTATION OF  ");


        //$$$$$$


        //$$$$$
        glColor3f(1.0,0.4,0.3);
        DrawTextXY(-3.8,2.6,0.1,0.0015,"   WORKING ");
        DrawTextXY(1,2.6,0.1,0.0015,"    Monitor ");

        glColor3f(0.7,0.6,0.1);
        DrawTextXY(-1.0,1.8,0.1,0.0007,"     Submitted by ");

        //OnSize(x,y);
        glColor3f(0.0,0.0,0.0);
        DrawTextXY(-3.6,1.3,0.0,0.0016," PALLAVI PUROHIT ");
        DrawTextXY(-0.12,1.3,0.0,0.0016," ABHINAV AGNIHOTRY ");
        glColor3f(0.0,0.0,0.0);
        DrawTextXY(-3.2,1.12,0.0,0.001,"    (1ST14CS738) ");
        DrawTextXY(1.0,1.12,0.0,0.001,"     (1ST14CS700) ");

        glColor3f(0.7,0.6,0.1);
        DrawTextXY(-2.3,0.4,0.0,0.0014,"     Under the Guidance of:  ");
        glColor3f(1.0,0.0,0.0);
        DrawTextXY(-1.4,0.0,0.0,0.0017,"        Mr. Srinath K.S.");
        DrawTextXY(-1.2,-0.2,0.0,0.001,"        Asst. Prof.,CSE., SaIT");

        glColor3f(0,1,0);
        DrawTextXY(-0.5,-1.0,0.0,0.0019,"SaIT");
        DrawTextXY(-0.7,-1.2,0.0,0.0013,"BANGALORE");
        glColor3f(0.3,0.3,0.3);
        DrawTextXY(0.5,-2.2,0.0,0.0008,"     Press any key to continue... ");

        glColor3f(1.0,0.0,0.0);     //$$$$$$$$$$$$$$$$$$$$

        c_letter();

        glColor3f(1.0,0.0,0.0);     //$$$$$$$$$$$$$$$$$$
        r_letter();

        glColor3f(1.0,0.0,0.0);
        t_letter();


        glFlush();          //Finish rendering
        glutSwapBuffers();
        */


        /*
        glBegin(GL_LINE_LOOP);
        glVertex2f(-3.5,-3.5);
        glVertex2f(-3.5,3.0);

        glVertex2f(-3.5,3.0);
        glVertex2f(3.0,3.0);

        glVertex2f(3.0,3.0);
        glVertex2f(3.0,-3.5);

        glVertex2f(-3.5,-3.5);
        glVertex2f(3.0,-3.5);
        glEnd();
        */






void Display2(void)//home screen content
{
   glClearColor(0.149, 0.149, 0.149, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0,0.0,-6.0);
    glTranslatef(0.0,-1.3,0.0);
	glColor3f(1.0,1.0,0.0);
    DrawTextXY(-1.0,1.5,0.1,0.003,"OPTIONS");
    glColor3f(1.0,0.0,0.0);
    DrawTextXY(0.0,0.80,0.0,0.0015,"PRESS C : EXECUTION");
    DrawTextXY(1.97,0.70,0.0,0.001," -");
    glColor3f(1.0,0.0,0.0);
    DrawTextXY(0.0,0.0,0.0,0.0015,"PRESS R : INTRODUCTION");
    DrawTextXY(1.92,-0.1,0.0,0.0013," -");
    DrawTextXY(0.0,-0.80,0.0,0.0015,"PRESS T : EXIT");
    DrawTextXY(1.969,-0.90,0.0,0.001," -");
    DrawTextXY(0.0,-1.60,0.0,0.0015,"PRESS M : MAIN PAGE");
    DrawTextXY(1.42,-1.71,0.0,0.0015," -");
    glutSwapBuffers();
    glFlush();
}

void Display3(void)//Help screen content
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(1.0f, 0.7f, 0.4f, 0.0f);

    glTranslatef(0.0,0.0,-6.0);
    glTranslatef(0.0f,-1.3f,0.0f);
    //DrawTextXY(-0.5,1.5,0.0,0.0022,"HELP");
	glColor3f(1.0f,0.0f,0.6f);
    DrawTextXY(-1.9,4.32,0.0,0.002," Cathod Ray Tube(CRT)");
glColor3f(1.0f,1.0f,1.0f);
    DrawTextXY(-3.7,3.8,0.0,0.00088,"* It is the most common output device used by most of the graphics system.");
    DrawTextXY(-3.7,3.4,0.0,0.00088,"* Digital o/p produced by the processor is given to digital to anolog converter.");
    DrawTextXY(-3.7,3.0,0.0,0.00088,"* Anlog voltages hences produced are applied across the x and y deflection plates.");
    DrawTextXY(-3.7,2.6,0.0,0.00088,"* The direction of the beam can be controlled by these 2 deflection plates.");
    DrawTextXY(-3.7,2.2,0.0,0.00088,"* When the electrons strik the phosphor coating on the tube light is emitted.");
    DrawTextXY(-3.7,1.8,0.0,0.0009,"* Colored CRT's have 3 different colored phosphors.");
    DrawTextXY(-3.7,1.4,0.0,0.0009,"* That are.. ");
    DrawTextXY(-3.7,0.6,0.0,0.0009,"* There are mainly 2 types of CRT's namely...");
    DrawTextXY(-2.7,0.1,0.0,0.0013," 1.Random-scan CRT(calligrahic/vector CRT)");
    DrawTextXY(-2.7,-0.3,0.0,0.0013," 2.Raster system CRT");
    DrawTextXY(-3.7,-1.0,0.0,0.0009," Options(press in working screen)");

    glColor3f(1.0f,0.0f,0.0f);
    DrawTextXY(-3.0,1.0,0.0,0.0019," RED");
    glColor3f(0.0f,1.0f,0.0f);
    DrawTextXY(-1.0,1.0,0.0,0.0019," GREEN");
    glColor3f(0.0f,0.0f,1.0f);
    DrawTextXY(1.5,1.0,0.0,0.0019," BLUE");
    glColor3f(0.0f,0.3f,0.0f);
    DrawTextXY(-3.2,-1.2,0.0,0.0008," e:APPLY A ELECTRIC FIELD ");
    DrawTextXY(-3.2,-1.4,0.0,0.0008," E:REMOVE A ELECTRIC FIELD ");
    DrawTextXY(-3.2,-1.6,0.0,0.0008," m:APPLY A MAGNETIC FIELD ");
    DrawTextXY(-3.2,-1.8,0.0,0.0008," M:REMOVE A MAGNETIC FIELD ");
    DrawTextXY(-3.2,-2.0,0.0,0.0008," z:ZOOM IN ");
    DrawTextXY(-3.2,-2.2,0.0,0.0008," Z:ZOOM OUT ");

    glColor3f(0.3f,0.3f,0.3f);
    DrawTextXY(0.5,-1.0,0.0,0.0008,"     Press any c/C to continue... ");
    DrawTextXY(0.5,-1.4,0.0,0.0008,"     Press any r/R to return... ");
    DrawTextXY(0.5,-1.8,0.0,0.0008,"     Press any t/T to exit... ");

    glutSwapBuffers();
    glFlush();
}



void keyboard1(unsigned char key,int x,int y)//home screen keyboard
{

    if(key=='c'||key=='C')
    {
        glutReshapeFunc(myReshape);
        glutDisplayFunc(display);
        glutMouseFunc(mouse);
        myinit();
        glutKeyboardFunc(keys);
        glutIdleFunc(electrmotion);         //$$$$$$$$$
        glEnable(GL_DEPTH_TEST);
        glutMainLoop();
    }

    if(key=='r'||key=='R' )
    {
        if(flag==0)
        {
            glutCreateWindow("help");
            glutKeyboardFunc(keyboard1);
            glutDisplayFunc(Display3);
            glutReshapeFunc(OnSize);
            glutFullScreen();
            flag=1;
        }
        else
        {
            glutCreateWindow("home");
            glutDisplayFunc(Display2);
            glutReshapeFunc(OnSize);
            glutKeyboardFunc(keyboard1);
            glutFullScreen();
            flag=0;
        }
    }

    if(key=='m' || key=='M')
    {
        glutCreateWindow("Main");
        glutKeyboardFunc(keyboard);
        glutDisplayFunc(cover);
        glutReshapeFunc(OnSize);
        glutFullScreen();
        glutMainLoop();
    }

    if(key=='t'||key=='T')
        exit(0);
	//glutSwapBuffers();
}

void keyboard(GLubyte key, GLint x, GLint y) //main screen keyboard
{
    if(key==27)     exit(0);

    else
    {
        glutCreateWindow("home");
        glutDisplayFunc(Display2);  
        glutReshapeFunc(OnSize);
        glutKeyboardFunc(keyboard1);
        glutFullScreen();
        glutMainLoop();
    }
}


int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
    glutCreateWindow("Main");
    glClearColor(0.0,0.0,0.0,0.0);
    glutFullScreen();
    init();
    glutDisplayFunc(cover);		// calling the display func showing the cover page of project
    glutReshapeFunc(OnSize);
    glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}


/*

    cover() = cover page uses keyboard ()
    display2() = option page uses keyboard1()
	display() = execution screen uses keys()
	display3() = info page uses keyborad1()
*/