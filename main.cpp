#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
class BigDecimalInt {
private:
    string s1;
public:
    BigDecimalInt(string decStr)
    {
        s1 = decStr;
    }

    BigDecimalInt (int decint)
    {
        if (decint < 0)
        {
            decint*=-1;

            while ( decint!=0)
            {
                s1+=(decint%10)+'0';
                decint-= decint%10;
                decint/=10;

            }
            s1+='-';
        }

        else   if (decint == 0)
        {
            s1="0";
        }

        else if (decint >0 ){
            while ( decint!=0)
            {

                s1+=(decint%10)+'0';
                decint-= decint%10;
                decint/=10;

            }
        }
        int n = s1.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s1[i], s1[n - i - 1]);
        }

    }

    bool checksign(string s2)
    {
        string s="";
        if (s2[0]=='-')
        {
            for (int i=1; i<s2.length(); i++)
            {
                s+=s2[i];
            }
            s2=s;
            return false;
        }

        else
        {
            return true;
        }
    }

    string check(string s5)
    {
        string s="";
        if (s5[0]=='-')
        {
            for (int i=1; i<s5.length(); i++)
            {
                s+=s5[i];
            }
            s5=s;
            return s5;
        }

        else
        {
            return  s5;
        }
    }

    bool isSmaller(string str1, string str2)
    {

        int n1 = str1.length(), n2 = str2.length();
        if (n1 < n2)
        {
            return true;
        }
        if (n2 < n1)
        {
            return false;
        }

        for (int i = 0; i < n1; i++)
        {
            if (str1[i] < str2[i])
            {
                return true;
            }
            else if (str1[i] > str2[i])
            {
                return false;
            }
        }

        return false;
    }

    string summation(string a, string b)
    {
        if (a.length() > b.length())
            swap(a, b);

        string string = "";

        int len1 = a.length(), len2 = b.length();
        int diff = len2 - len1;
        int carry = 0;
        for (int i = len1 - 1; i >= 0; i--)
        {
            int sum= ((a[i] - '0')+ (b[i + diff] - '0') + carry);

            string+=sum % 10 + '0';
            carry = sum / 10;
        }
        for (int i = len2 - len1 - 1; i >= 0; i--)
        {
            int sum = ((b[i] - '0') + carry);
            string+=sum % 10 + '0';
            carry = sum / 10;
        }
        if (carry!=0)
        {
            string+=carry + '0';
        }
        reverse(string.begin(), string.end());
        return string;
    }

    string comp(string v)
    {
        string compliment = "";


        for (int i = 0; i < v.size(); i++)
        {

            compliment += '9' - v[i] + '0';
        }
        compliment = summation(compliment, "1");
        return compliment;
    }

    BigDecimalInt operator+(BigDecimalInt anotherDec) {
        bool b1,b2;
        b1=checksign(s1);
        b2=checksign(anotherDec.s1);
        s1=check(s1);
        anotherDec.s1=check(anotherDec.s1);
        int index=0;
        if(isSmaller(s1,anotherDec.s1))
        {
            index=1;
        }
        else
        {
            index=0;
        }

        if (isSmaller(s1,anotherDec.s1))
        {
            swap(s1, anotherDec.s1);
        }
        BigDecimalInt b(s1);

        if(b1== true && b2== true || b1==false && b2== false)
        {
            if(b1==false && b2== false)
            {
                cout<<"-";
            }

            int j = s1.size() - 1;
            for (int i = anotherDec.s1.size() - 1; i >= 0; i--, j--)
                s1[j] += (anotherDec.s1[i] - '0');

            for (int i = s1.size() - 1; i > 0; i--) {
                if (s1[i] > '9') {
                    int d = s1[i] - '0';
                    s1[i - 1] = ((s1[i - 1] - '0') + d / 10) + '0';
                    s1[i] = (d % 10) + '0';
                }
            }
            if (s1[0] > '9') {
                string k;
                k += s1[0];
                s1[0] = ((s1[0] - '0') % 10) + '0';
                k[0] = ((k[0] - '0') / 10) + '0';
                s1 = k + s1;
            }

            BigDecimalInt b(s1);
            return b;
        }
        else if( b1==true && b2== false)
        {

            if(index==1){
                cout<<"-";
            }
               return (*this) - anotherDec;

        }
        else if(b1==false && b2==true )
        {
            if(index==0){
                cout<<"-";
            }
            return (*this) - anotherDec;

        }

    }

    BigDecimalInt operator-(BigDecimalInt anotherDec)
    {

        bool b1,b2;
        b1=checksign(s1);
        b2=checksign(anotherDec.s1);
        s1=check(s1);
        anotherDec.s1=check(anotherDec.s1);
        int index=0;
        if(isSmaller(s1,anotherDec.s1))
        {
            index=1;
        }
        else
        {
            index=0;
        }
        int diffLen=0;
        if(s1.length()>anotherDec.s1.length()) {
            int len1 = s1.length(), len2 = anotherDec.s1.length();
             diffLen = len1 - len2;
            for (int i = 0; i < diffLen; i++) //to make len1=len2
            {
                anotherDec.s1 = "0" + anotherDec.s1;
            }
        }
        else
        {
            int len1 = s1.length(), len2 = anotherDec.s1.length();
             diffLen = len2 - len1;
            for (int i = 0; i < diffLen; i++) //to make len1=len2
            {
                s1 = "0" + s1;
            }
        }

        if(b1== true && b2== true || b1== false && b2== false)
        {
            if(b1==false && b2== false)
            {
                if(index==0) {
                    cout << "-";
                }
            }
            string c = summation(s1, comp(anotherDec.s1));


            if (c.length() > s1.length() || c.length() > anotherDec.s1.length() ) {
                string::iterator it;
                it = c.begin();
                c.erase(it);
                it = c.begin();
                BigDecimalInt b(c);
                return b;

            }

            else {
                c = comp(c);
                string::iterator it;
                it = c.begin();
                BigDecimalInt b(c);
                return b;
            }
        }
        else if( b1==true && b2== false)
        {
            return (*this) + anotherDec;
        }
        else if(b1==false && b2==true )
        {
            cout<<"-";
            return (*this) + anotherDec;

        }
    }
    BigDecimalInt operator= (BigDecimalInt anotherDec)
    {
        BigDecimalInt bd(s1);
    }

    int size()
    {
        return s1.length();
    }
    friend  ostream& operator<< (ostream& output, BigDecimalInt a)
    {
        string::iterator it;
        it = a.s1.begin();
        while (*it == '0')
        {
            a.s1.erase(it);
        }
        cout<<a.s1;
    }
};
int main()
{

    cout<<"choose one of these options:"<<endl;
    cout<<"1)show test cases"<<endl<<"2)Enter test cases"<<endl<<"3)Exit"<<endl;
    int choice;
    cin>>choice;
    if(choice==1) {
        //test case 1
        cout<<"test case 1"<<endl;
        BigDecimalInt num1("-10000");
        BigDecimalInt num2("-5300");
        cout<<"num1<<"<<num1<<endl;
        cout<<"num2<<"<<num2<<endl;
        cout << "num1+num2= ";
        BigDecimalInt num3 = num1 + num2;
        cout<<num3<<endl;
        cout << "num1-num2= ";
        BigDecimalInt num4 = num1 - num2;
        cout<<num4<<endl;

        //test case 2
        cout<<"test case 2"<<endl;
        BigDecimalInt num5("12000");
        BigDecimalInt num6("-5350");
        cout<<"num3<<"<<num5<<endl;
        cout<<"num4<<"<<num6<<endl;
        cout << "num3+num4= ";
        BigDecimalInt num7 = num5 + num6;
        cout<<num7<<endl;
        cout << "num3-num4= ";
        BigDecimalInt num8 = num5 - num6;
        cout<<num8<<endl;
        //test case 3
        cout<<"test case 3"<<endl;
        BigDecimalInt num9("-9800");
        BigDecimalInt num10("400");
        cout<<"num5<<"<<num9<<endl;
        cout<<"num6<<"<<num10<<endl;
        cout << "num5+num6= ";
        BigDecimalInt num11 = num9 + num10;
        cout<<num11<<endl;
        cout << "num5-num6= ";
        BigDecimalInt num12 = num9 - num10;
        cout<<num12<<endl;
        //test case 4
        cout<<"test case 4"<<endl;
        BigDecimalInt num13("123456789012345678901234567890");
        BigDecimalInt num14("113456789011345678901134567890");

        cout<<"num7<<"<<num13<<endl;
        cout<<"num8<<"<<num14<<endl;
        cout<<"num7+num8= ";
        BigDecimalInt num15=num13+num14;
        cout<<num15<<endl;
        //test case 5
        cout<<"test case 5"<<endl;
        BigDecimalInt num16("1230000000000000001");
        BigDecimalInt num17("30000000000000001");
        cout<<"num9<<"<<num16<<endl;
        cout<<"num10<<"<<num17<<endl;
        cout<<"num9-num10= ";
        BigDecimalInt num18=num16-num17;
        cout<<num18<<endl;
        //test case 6
        cout<<"test case 6"<<endl;
        BigDecimalInt num19(2500);
        BigDecimalInt num20(2000);
        cout<<"num11<<"<<num19<<endl;
        cout<<"num12<<"<<num20<<endl;
        cout <<"num11+num12= "<< num19 + num20 << endl;
        cout <<"num11-num12= "<< num19 - num20 << endl;
    }
    else if(choice==2)
    {
        cout<<"1)Integers"<<endl<<"2)Decimal integers"<<endl;
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int a,b;
            cout<<"Enter number1"<<endl;
            cin>>a;
            cout<<"Enter number2"<<endl;
            cin>>b;
            BigDecimalInt nu3(a);
            BigDecimalInt nu4(b);
            cout<<"choose the operation:"<<endl<<"1)Summation"<<endl<<"2)Subtraction"<<endl;
            int ch2;
            cin>>ch2;
            if(ch2==1) {
                BigDecimalInt nu5 = nu3 + nu4;
                cout << nu5 << endl;
            }
            else if(ch2==2){
                BigDecimalInt nu6=nu3-nu4;
                cout << nu6 << endl;
            }
        }
        else if(ch==2){

                string a, b;
                cout << "Enter number1" << endl;
                cin >> a;
                cout << "Enter number2" << endl;
                cin >> b;
                BigDecimalInt nu3(a);
                BigDecimalInt nu4(b);
                cout << "choose the operation:" << endl << "1)Summation" << endl << "2)Subtraction" << endl;
                int ch2;
                cin >> ch2;
                if (ch2 == 1) {
                    BigDecimalInt nu5 = nu3 + nu4;
                    cout << nu5 << endl;
                } else if (ch2 == 2) {
                    BigDecimalInt nu6 = nu3 - nu4;
                    cout << nu6 << endl;
                }
        }
    }
    else
    {
        return 0;
    }
    return 0;
}
