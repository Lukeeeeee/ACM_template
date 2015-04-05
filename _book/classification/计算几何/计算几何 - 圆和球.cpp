#include <iostream>
#include <cmath>
using namespace std;
#define eps 1e-10
/********** ����� **********/
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
};
/********** ������ά�� ***********/
struct Point3{
    double x,y,z;
    Point3(double x=0,double y=0,double z=0):x(x),y(y),z(z) {}
};
/********** ����Բ **********/
struct Circle{
    Point c;
    double r;
    Circle(Point c,double r):c(c),r(r){}
    Point point(double a){
        return Point(c.x + cos(a)*r,c.y + sin(a)*r);
    }
};
/*********** ��ά����� **********/
double dis3(Point3 A,Point3 B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
}
/*********** ���� ***********/
/*********** �Ƕ�ת���ɻ��� ***********/
double torad(double deg)
{
    return deg/180 * acos(-1);    //acos(-1)����PI
}
/*********** ��γ�ȣ��Ƕȣ�ת��Ϊ�ռ����� **********/
void get_coord(double R,double lat,double lng,double &x ,double &y,double &z)
{
    lat = torad(lat);    //γ��
    lng = torad(lng);    //����
    x = R*cos(lat)*cos(lng);
    y = R*cos(lat)*sin(lng);
    z = R*sin(lat);
}
/*********** ������������ ***********/
double disA2B(double R,Point3 A,Point3 B)
{
    //��������뿴�����A��B�Ͱ뾶R���ɵ����εĻ���
    double d = dis3(A,B);    //�ҳ�
    double a = 2*asin(d/2/R);    //Բ�Ľ�
    double l = a*R;        //����
    return l;
}
