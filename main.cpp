#include<bits/stdc++.h>
#include<string.h>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<mmsystem.h>
using namespace std;


bool rightface=1,upface=0,downface=0,leftface=0;
bool point1 = true, repoint=false;
//face angle
int uer = 40;
int usr = 140;

int ueu = 360;
int usu = 0;

int uel = 225;
int usl = -45;

int ued = 135;
int usd = -135;
//pack start point
int x = 40, px = 1, py = 1;
int y = 40;
//food start point
int x2 = 80;
int y2 = 100;

//flag vc push
int score = 0, flag = 1;
vector<int> vx;
vector<int> vy;


int Map[24][24] =
{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void myInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 500, 0, 500, -10.0, 10.0);
    glClearColor(0,0,0,0);

}

void circle(float x, float y)
{
    float x1, y1, x2, y2;
    float radius = 17;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 0, 0);
    glVertex2f(x1, y1);
    float angle;
    for (angle=usr; angle<=360; angle+=0.5)
    {
        x2 = x1+sin((angle*3.1416)/180)*radius;
        y2 = y1+cos((angle*3.1416)/180)*radius;
        glVertex2f(x2,y2);
    }
    for (angle=0; angle<=uer; angle+=0.5)
    {
        x2 = x1+sin((angle*3.1416)/180)*radius;
        y2 = y1+cos((angle*3.1416)/180)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
}

void circleup(float x, float y)
{
    float x1, y1, x2, y2;
    float radius = 17;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 0, 0);
    glVertex2f(x1, y1);
    float angle;
    for (angle=usu; angle<=ueu; angle+=0.5)
    {
        x2 = x1+sin((angle*3.1416)/180)*radius;
        y2 = y1+cos((angle*3.1416)/180)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
}

void circleleft(float x, float y)
{
    float x1, y1, x2, y2;
    float radius = 17;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 0, 0);
    glVertex2f(x1, y1);
    float angle;
    for (angle=usl; angle<=uel; angle+=0.5)
    {
        x2 = x1+sin((angle*3.1416)/180)*radius;
        y2 = y1+cos((angle*3.1416)/180)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
}

void circledown(float x, float y)
{
    float x1, y1, x2, y2;
    float radius = 17;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 0, 0);
    glVertex2f(x1, y1);
    float angle;
    for (angle=usd; angle<=ued; angle+=0.5)
    {
        x2 = x1+sin((angle*3.1416)/180)*radius;
        y2 = y1+cos((angle*3.1416)/180)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
}

void circle2(float x, float y)
{
    float x1, y1, x2, y2;
    float radius = 12;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(rand()%256, rand()%256, rand()%256);
    glVertex2f(x1, y1);
    float angle;
    for (angle = 0; angle <= 360; angle += 0.5)
    {
        x2 = x1 + sin((angle * 3.1416) / 180) * radius;
        y2 = y1 + cos((angle * 3.1416) / 180) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void circle3(float x, float y)
{
    float x1, y1, x2, y2;
    float radius = 2;
    x1 = x;
    y1 = y;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0);
    glVertex2f(x1, y1);
    float angle;
    for (angle = 0; angle <= 360; angle += 0.5)
    {
        x2 = x1 + sin((angle * 3.1416) / 180) * radius;
        y2 = y1 + cos((angle * 3.1416) / 180) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}

float dis(float x, float y, float x2, float y2)
{
    float res = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
    return res;
}

void keyboardFunc(unsigned char key, int a, int b)
{

    if ( Map[px+1][py] and key == 'd' || key == 'D')
        x += 20, px++, rightface = 1, leftface = 0, upface = 0, downface = 0;
    else if (Map[px-1][py] and key == 'a' || key == 'A')
        x -= 20, px--, rightface = 0, leftface = 1, upface = 0, downface = 0;
    else if (Map[px][py+1] and key == 'w' || key == 'W')
        y += 20, py++, rightface = 0, leftface = 0, upface = 1, downface = 0;
    else if (Map[px][py-1] and key == 's' || key == 'S')
        y -= 20, py--, rightface = 0, leftface = 0, upface = 0, downface = 1;
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(rightface)
    {
        uer++;
        if(uer==90)uer=40;
        usr--;
        if(usr==90)usr=140;
        circle(x, y);
    }
    if(leftface)
    {
        uel++;
        if(uel==270)uel=225;
        usl--;
        if(usl==-90)usl=-45;
        circleleft(x, y);
    }
    if(upface)
    {
        ueu--;
        usu++;
        if(ueu==360-45)ueu=360;
        if(usu==45)usu=0;
        circleup(x, y);
    }


    if(downface)
    {
        ued++;
        if(ued==180)ued=135;
        usd--;
        if(usd==-180)usd=-135;
        circledown(x, y);
    }



    if(flag)
    {
        for(int i = 0; i < 24; i++)
        {
            for(int j = 0; j < 24; j++)
            {
                if(!Map[i][j])
                {
                    vx.push_back((i+1)*20);
                    vy.push_back((j+1)*20);
                }

            }
            flag = 0;
        }
    }

    for(int i = 0; i < vx.size(); i++)
    {
        circle3(vx[i], vy[i]);
    }


    if (point1)
        circle2(x2, y2);


    if (dis(x, y, x2, y2) <= 25 && point1)
    {
        point1 = false;
        repoint=true;
        score += 1;
    }
    if(repoint)
    {
        point1=true;
        x2 = rand()%460;
        y2 = rand()%460;
        if(x2 <= 40)x2 += 40;
        if(y2 <= 40)y2 += 40;
        circle2(x2, y2);
        repoint=false;
    }


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    glRasterPos2f(210, 480); // Set position for the score text
    string sc = "";
    int tmp1 = score;
    while(tmp1)
    {
        int tmp = tmp1%10;
        tmp1 /= 10;
        char ch = tmp+'0';
        sc = sc+ch;
    }
    reverse(sc.begin(), sc.end());
    string scoreText = "Score: "+sc ;//+ to_string(score);

    for (int i = 0; i < scoreText.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[i]); // Render each character of the score text
    }

    glFlush();
}

void update(int val)
{
    glutPostRedisplay();
    glutTimerFunc(2, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(480, 480 );
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Team Pseudo");
    myInit();
    sndPlaySound("sound.wav",SND_ASYNC);
    glutKeyboardFunc(keyboardFunc);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);


    update(0);
    glutMainLoop();
}
