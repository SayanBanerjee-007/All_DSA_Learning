#include <iostream>

using namespace std;
class MyArray
{
private:
    int total_size;
    int used_size;
    int *ptr;
public:
    MyArray(void){}
    MyArray(MyArray* ,int ,int );
    void set_value(MyArray* a);
    void display_value(MyArray* a);
};
MyArray::MyArray(MyArray* a,int Usize,int Tsize)
{
    a->total_size=Tsize;
    a->used_size=Usize;
    a->ptr=new int(Tsize);
}    
void MyArray::set_value(MyArray* a)
{
    for(int i=0;i<(a->used_size);i++)
    {
        cout<<"Enter element No."<<i+1<<" ->";
        scanf("%d",&(*a).ptr[i]);
    }
}
void MyArray::display_value(MyArray* a)
{
    for(int i=0;i<(a->used_size);i++)
    {
        printf("Element No.%d is: %d\n",i+1,(a->ptr)[i]);
    }
    delete[] a->ptr;
}

int main()
{
    MyArray marks(&marks,2,10);
    marks.set_value(&marks);
    marks.display_value(&marks);
    cout << endl;
    return 0;
}