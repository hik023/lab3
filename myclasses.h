//
// Created by Александр Балаев on 16.12.16.
//
#include "iostream"
using namespace std;

class CPoint
{
private:
    int x,y;
public:
    CPoint(): x(0),y(0)
    {}
    CPoint(int x0, int y0): x(x0),y(y0)
    {}
    void set(int x0, int y0)
    {
        x = x0;
        y = y0;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
};

class CColor
{
private:
    int red,green,blue;
public:
    CColor():red(0),green(0),blue(0)
    {}
    CColor(int r, int g, int b): red(r),green(g),blue(b)
    {}
    void setColor(int r, int g, int b){
        red = r;
        green = g;
        blue = b;
    }
    int get_red(){
        return red;
    }
    int get_green(){
        return green;
    }
    int get_blue(){
        return blue;
    }
};

class CColoredPoint : public CPoint, public CColor
{
public:
    CColoredPoint():CPoint(),CColor()
    {}
    CColoredPoint(int x0,int y0, int r, int g, int b): CPoint(x0,y0),CColor(r,g,b)
    {}
};

class CLine
{
private:
    CPoint f;
    CPoint l;
public:
    CLine(){}
    CLine(int x0, int y0, int x1, int y1)
    {
        f.set(x0,y0);
        l.set(x1,y1);
    }
    void set(int x0, int y0, int x1, int y1)
    {
        f.set(x0,y0);
        l.set(x1,y1);
    }
    int get_first_x()
    {
        return f.get_x();
    }
    int get_first_y()
    {
        return f.get_y();
    }
    int get_last_x()
    {
        return l.get_x();
    }
    int get_last_y()
    {
        return l.get_y();
    }
};

class CColoredLine: public CLine, public CColor
{
public:
    CColoredLine():CLine(),CColor()
    {};
    CColoredLine(int x0, int y0, int x1, int y1, int r, int g, int b): CLine(x0,y0,x1,y1), CColor(r,g,b)
    {};
};

class CPolyLine
{
private:
    int n;
    struct vertex
    {
        CPoint data;
        vertex *prev, *next;
    };
    vertex *head = new vertex;

public:
    CPolyLine(int n): n(n)
    {
        int x;
        int y;
        cout << "input point: ";
        cin >> x >> y;
        head->data.set(x,y);
        vertex *point = new vertex;
        int xp;
        int yp;
        cout << "input point: ";
        cin >> xp >> yp;
        point->data.set(xp,yp);
        point->prev = head;
        head->next = point;
        for(int i=2;i<n;i++)
        {
            vertex *point2 = new vertex;
            int xp1;
            int yp1;
            cout << "input point: ";
            cin >> xp1>> yp1;
            point2->data.set(xp1,yp1);
            point2->prev = point;
            point->next = point2;
            point = point2;
        }
        point->next = head;
        head->prev = point;
    }

    void refill()
    {
        vertex *v = head;
        for(int i = 0;i<n-1;i++)
        {
            v = v->next;
            delete(v->prev);
        }
        delete(v);

    }
    void show(vertex *&point, vertex *&head)
    {
        cout << "(" << point->data.get_x()<< ";" << point->data.get_y() << "),";
        if (point->next!=head) show(point->next,head);

    }
    vertex *& getHead()
    {
        return head;
    }
};