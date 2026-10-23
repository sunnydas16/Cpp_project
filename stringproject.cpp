#include <iostream>
using namespace std;

class String
{
    char *str;
    public:

    //  Default Constructor
    String()
    {
        str = new char[1];
        str[0] = '\0';
    }

    //  Parameterized Constructor
    String(const char *s)
    {
        int len = 0;

        while (s[len] != '\0')
        {
            len++;
        }

        str = new char[len + 1];

        for (int i = 0; i <= len; i++)
        {
            str[i] = s[i];
        }
    }

    //  ----Copy Constructor
    String(const String &obj)
    {
        int len=0;

        while (obj.str[len] != '\0')
        {
            len++;
        }

        str = new char[len + 1];

        for (int i = 0; i <= len; i++)
        {
            str[i] = obj.str[i];
        }
    }

    //  Assignment Operator
    String& operator=(const String &obj)
    {
        if (this != &obj)
        {
            delete[] str;

            int len = 0;

            while (obj.str[len] != '\0')
            {
                len++;
            }

            str = new char[len + 1];

            for (int i = 0; i <= len; i++)
            {
                str[i] = obj.str[i];
            }
        }

        return *this;
    }

    //  Addition Operator +
    String operator+(const String &obj)
    {
        String temp;

        int len1 = 0;
        int len2 = 0;

        while (str[len1] != '\0')
        {
            len1++;
        }

        while (obj.str[len2] != '\0')
        {
            len2++;
        }

        delete[] temp.str;

        temp.str = new char[len1 + len2 + 1];

        int i;

        for (i = 0; i < len1; i++)
        {
            temp.str[i] = str[i];
        }

        for (int j = 0; j < len2; j++)
        {
            temp.str[i + j] = obj.str[j];
        }

        temp.str[len1 + len2] = '\0';

        return temp;
    }

    //  Subscript Operator []
    char& operator[](int index)
    {
        return str[index];
    }

    //  Stream Insertion <<
    friend ostream& operator<<(ostream &out, const String &obj);

    //  Stream Extraction >>
    friend istream& operator>>(istream &in, String &obj);

    //  Comparison Operators

    friend bool operator>(const String &s1, const String &s2);
    friend bool operator<(const String &s1, const String &s2);
    friend bool operator>=(const String &s1, const String &s2);
    friend bool operator<=(const String &s1, const String &s2);
    friend bool operator==(const String &s1, const String &s2);
    friend bool operator!=(const String &s1, const String &s2);

    // Friend String Functions

    friend String& strcpy(String &s2, const String &s1);
    friend String& strncpy(String &s2, const String &s1, int n);

    friend int strcmp(const String &s2, const String &s1);
    friend int strncmp(const String &s2, const String &s1, int n);

    friend String& strcat(String &s2, const String &s1);
    friend String& strncat(String &s2, const String &s1, int n);

    friend String& strrev(String &s1);
    friend String& strupr(String &s1);
    friend String& strlwr(String &s1);

    friend char* strchr(String &s1, char ch);
    friend char* strrchr(String &s1, char ch);

    friend char* strstr(String &s1, char *s);

    friend int strlen(const String &s1);

    // Destructor
    ~String()
    {
        delete[] str;
    }
};


// STREAM OPERATORS
// <<
ostream& operator<<(ostream &out, const String &obj)
{
    out << obj.str;

    return out;
}


// >>
istream& operator>>(istream &in, String &obj)
{
    char ch;
        int len=0;
        while(in.get(ch))
        {
                if(ch==' '||ch=='\n'||ch=='\t')
                        break;
                len++;
        }
        in.clear();
        delete[] obj.str;
        obj.str = new char[len+1];
        int i=0;
        while(in.get(ch))
        {
                if(ch==' '||ch=='\n'||ch=='\t')
                        break;
                obj.str[i] = ch;
                i++;
        }
        obj.str[i]='\0';
    return in;
}


// COMPARISON OPERATORS
// >
bool operator>(const String &s1, const String &s2)
{
    int i = 0;

    while (s1.str[i] != '\0' &&
           s2.str[i] != '\0' &&
           s1.str[i] == s2.str[i])
    {
        i++;
    }

    return s1.str[i] > s2.str[i];
}


// <
bool operator<(const String &s1, const String &s2)
{
    int i = 0;

    while (s1.str[i] != '\0' &&
           s2.str[i] != '\0' &&
           s1.str[i] == s2.str[i])
    {
        i++;
    }

    return s1.str[i] < s2.str[i];
}


// >=
bool operator>=(const String &s1, const String &s2)
{
    return !(s1 < s2);
}


// <=
bool operator<=(const String &s1, const String &s2)
{
    return !(s1 > s2);
}


// ==
bool operator==(const String &s1, const String &s2)
{
    int i = 0;

    while (s1.str[i] != '\0' &&
           s2.str[i] != '\0')
    {
        if (s1.str[i] != s2.str[i])
        {
            return false;
        }

        i++;
    }

    return s1.str[i] == s2.str[i];
}


// !=
bool operator!=(const String &s1, const String &s2)
{
    return !(s1 == s2);
}

// strcpy

String& strcpy(String &s2, const String &s1)
{
    int len = 0;

    while (s1.str[len] != '\0')
    {
        len++;
    }

    delete[] s2.str;

    s2.str = new char[len + 1];

    for (int i = 0; i <= len; i++)
    {
        s2.str[i] = s1.str[i];
    }

    return s2;
}



// strncpy

String& strncpy(String &s2, const String &s1, int n)
{
    delete[] s2.str;

    s2.str = new char[n + 1];

    int i = 0;

    while (i < n && s1.str[i] != '\0')
    {
        s2.str[i] = s1.str[i];
        i++;
    }

    s2.str[i] = '\0';

    return s2;
}


// strcmp

int strcmp(const String &s2, const String &s1)
{
    int i = 0;

    while (s2.str[i] != '\0' &&
           s1.str[i] != '\0' &&
           s2.str[i] == s1.str[i])
    {
        i++;
    }

    return s2.str[i] - s1.str[i];
}


// strncmp

int strncmp(const String &s2, const String &s1, int n)
{
    int i = 0;

    while (i < n &&
           s2.str[i] != '\0' &&
           s1.str[i] != '\0' &&
           s2.str[i] == s1.str[i])
    {
        i++;
    }

    if (i == n)
        return 0;

    return s2.str[i] - s1.str[i];
}


// strcat

String& strcat(String &s2, const String &s1)
{
    int len1 = 0;
    int len2 = 0;

    while (s2.str[len1] != '\0')
    {
        len1++;
    }

    while (s1.str[len2] != '\0')
    {
        len2++;
    }

    char *temp = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++)
    {
        temp[i] = s2.str[i];
    }

    for (int i = 0; i < len2; i++)
    {
        temp[len1 + i] = s1.str[i];
    }

    temp[len1 + len2] = '\0';

    delete[] s2.str;

    s2.str = temp;

    return s2;
}


// strncat

String& strncat(String &s2, const String &s1, int n)
{
    int len1 = 0;
    int len2 = 0;

    while (s2.str[len1] != '\0')
    {
        len1++;
    }

    while (s1.str[len2] != '\0')
    {
        len2++;
    }

    if (len2 > n)
        len2 = n;

    char *temp = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++)
    {
        temp[i] = s2.str[i];
    }

    for (int i = 0; i < len2; i++)
    {
        temp[len1 + i] = s1.str[i];
    }

    temp[len1 + len2] = '\0';

    delete[] s2.str;

    s2.str = temp;

    return s2;
}


// strrev

String& strrev(String &s1)
{
    int len = 0;

    while (s1.str[len] != '\0')
    {
        len++;
    }

    int i = 0;
    int j = len - 1;

    while (i < j)
    {
        char temp = s1.str[i];

        s1.str[i] = s1.str[j];
        s1.str[j] = temp;

        i++;
        j--;
    }

    return s1;
}


// strupr

String& strupr(String &s1)
{
    int i = 0;

    while (s1.str[i] != '\0')
    {
        if (s1.str[i] >= 'a' && s1.str[i] <= 'z')
        {
            s1.str[i] = s1.str[i] - 32;
        }

        i++;
    }

    return s1;
}


// strlwr

String& strlwr(String &s1)
{
    int i = 0;

    while (s1.str[i] != '\0')
    {
        if (s1.str[i] >= 'A' && s1.str[i] <= 'Z')
        {
            s1.str[i] = s1.str[i] + 32;
        }

        i++;
    }

    return s1;
}



// strchr

char* strchr(String &s1, char ch)
{
    int i = 0;

    while (s1.str[i] != '\0')
    {
        if (s1.str[i] == ch)
        {
            return &s1.str[i];
        }

        i++;
    }

    if (ch == '\0')
        return &s1.str[i];

    return NULL;
}


// strrchr


char* strrchr(String &s1, char ch)
{
    char *result = NULL;

    int i = 0;

    while (s1.str[i] != '\0')
    {
        if (s1.str[i] == ch)
        {
            result = &s1.str[i];
        }

        i++;
    }

    if (ch == '\0')
        return &s1.str[i];

    return result;
}


// strstr

char* strstr(String &s1, char *s)
{
    int i, j;

    for (i = 0; s1.str[i] != '\0'; i++)
    {
        j = 0;

        while (s[j] != '\0' &&
               s1.str[i + j] == s[j])
        {
            j++;
        }

        if (s[j] == '\0')
        {
            return &s1.str[i];
        }
    }

    return NULL;
}



// strlen

int strlen(const String &s1)
{
    int len = 0;

    while (s1.str[len] != '\0')
    {
        len++;
    }

    return len;
}


int main()
{
    
    // 1. Default Constructor
    String s1;

    cout << "Default Constructor:" << endl;
    cout << "s1 = [" << s1 << "]" << endl;

    // 2. Parameterized Constructor
    String s2("Hello");
    cout << "\nParameterized Constructor:" << endl;
    cout << "s2 = " << s2 << endl;

    // 3. Copy Constructor
    String s3 = s2;
    cout << "\nCopy Constructor:" << endl;
    cout << "s3 = " << s3 << endl;

    // 4. Assignment Operator
    s1 = s2;
    cout << "\nAssignment Operator:" << endl;
    cout << "s1 = " << s1 << endl;

    // 5. Addition Operator
    String s4(" World");

    String s5 = s2 + s4;
    cout << "\nAddition Operator:" << endl;
    cout << "s5 = " << s5 << endl;

    // 6. Subscript Operator
    cout << "\nSubscript Operator:" << endl;
    cout << "s2[0] = " << s2[0] << endl;
    cout << "s2[1] = " << s2[1] << endl;
   
    // 7. Stream Extraction
    String s6;
    cout << "\nEnter a string: ";
    cin >> s6;

    cout << "You entered: " << s6 << endl;


    // 8. Comparison Operators
    
    String a("Apple");
    String b("Banana");

    cout << "\nComparison Operators:" << endl;

    cout << "a > b  = " << (a > b) << endl;
    cout << "a < b  = " << (a < b) << endl;
    cout << "a >= b = " << (a >= b) << endl;
    cout << "a <= b = " << (a <= b) << endl;
    cout << "a == b = " << (a == b) << endl;
    cout << "a != b = " << (a != b) << endl;

    // 9. strcpy
    String x("One");
    String y("Two");

    strcpy(y, x);
    cout << "\nstrcpy:" << endl;
    cout << "y = " << y << endl;

    // 10. strncpy
    String z;
    strncpy(z, s5, 5);
    cout << "\nstrncpy:" << endl;
    cout << "z = " << z << endl;

    // 11. strcmp
    cout << "\nstrcmp:" << endl;
    cout << "strcmp(a,b) = " << strcmp(a, b) << endl;

    // 12. strncmp    
    cout << "\nstrncmp:" << endl;
    cout << "strncmp(a,b,2) = " << strncmp(a, b, 2) << endl;

    // 13. strcat
    String c("Hello ");
    String d("World");

    strcat(c, d);

    cout << "\nstrcat:" << endl;
    cout << "c = " << c << endl;

    // 14. strncat    
    String e("Good ");
    String f("Morning");

    strncat(e, f, 3);

    cout << "\nstrncat:" << endl;
    cout << "e = " << e << endl;

    // 15. strrev
    String rev("Hello");

    strrev(rev);

    cout << "\nstrrev:" << endl;
    cout << "rev = " << rev << endl;

    // 16. strupr
    String upper("hello");

    strupr(upper);

    cout << "\nstrupr:" << endl;
    cout << "upper = " << upper << endl;
   
    // 17. strlwr

    String lower("HELLO");

    strlwr(lower);

    cout << "\nstrlwr:" << endl;
    cout << "lower = " << lower << endl;


    // 18. strchr
    
    String find1("Hello");

    char *p1 = strchr(find1, 'l');

    cout << "\nstrchr:" << endl;

    if (p1 != NULL)
        cout << "Character found: " << p1 << endl;
    else
        cout << "Character not found" << endl;


    // 19. strrchr
    char *p2 = strrchr(find1, 'l');

    cout << "\nstrrchr:" << endl;

    if (p2 != NULL)
        cout << "Last occurrence: " << p2 << endl;
    else
        cout << "Character not found" << endl;


   
    // 20. strstr
    
    String find2("Hello World");

    char word[] = "World";

    char *p3 = strstr(find2, word);

    cout << "\nstrstr:" << endl;

    if (p3 != NULL)
        cout << "Substring found: " << p3 << endl;
    else
        cout << "Substring not found" << endl;


    
    // 21. strlen
   
    cout << "\nstrlen:" << endl;
    cout << "Length of s5 = " << strlen(s5) << endl;


    return 0;
}