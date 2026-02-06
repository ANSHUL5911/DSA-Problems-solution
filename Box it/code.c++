#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
private:
    int length;
    int breadth;
    int height;

public:
    // Default constructor
    Box() {
        length = 0;
        breadth = 0;
        height = 0;
    }

    // Parameterized constructor
    Box(int l, int b, int h) {
        length = l;
        breadth = b;
        height = h;
    }

    // Copy constructor
    Box(const Box& b) {
        length = b.length;
        breadth = b.breadth;
        height = b.height;
    }

    // Getter functions
    int getLength() {
        return length;
    }

    int getBreadth() {
        return breadth;
    }

    int getHeight() {
        return height;
    }

    // Calculate volume
    long long CalculateVolume() {
        return (long long)length * breadth * height;
    }
    
    
};

bool operator<(Box& b1, Box& b2) {
    if (b1.getLength() < b2.getLength()) return true;
    if (b1.getLength() > b2.getLength()) return false;

    if (b1.getBreadth() < b2.getBreadth()) return true;
    if (b1.getBreadth() > b2.getBreadth()) return false;

    if (b1.getHeight() < b2.getHeight()) return true;

    return false;
}



// Operator overloading for <<
    ostream& operator<<(ostream& out, Box& b) {
    out << b.getLength() << " "
        << b.getBreadth() << " "
        << b.getHeight();
    return out;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}