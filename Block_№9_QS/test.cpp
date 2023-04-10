#include "pch.h"
#include "quick_sort.hpp"
#include "Exception.hpp"

bool myfunction(int i, int j) { return (i < j); }

struct myclass
{
    bool operator() (int i, int j) { return (i < j); };
};

class Unit
{
public:
    Unit(int arg) : size(arg) {}
    int GetSize(void) { return size; }
    bool operator==(const Unit& that) const { return this->size == that.size; }
private:
    int size;
};

//
//int main() {
//    myclass myobject;
//
//    int myints[] = { 32,71,12,45,26,80,53,33 };
//    std::vector<int> myvector(myints, myints + 8);               // 32 71 12 45 26 80 53 33
//
//    // using default comparison (operator <):
//    std::sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33
//
//    // using function as comp
//    std::sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
//
//    // using object as comp
//    std::sort(myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
//
//    // print out content:
//    std::cout << "myvector contains:";
//    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';
//
//
//    std::vector<int> vector_stdsort = { 32,71,12,45,26,80,53,33 };
//    std::vector<int> vector_mysort(vector_stdsort);
//
//    quick_sort(vector_mysort.begin(), vector_mysort.end());
//
//    std::sort(vector_stdsort.begin(), vector_stdsort.end());
//
//   return 0;
//}      


TEST(TestCase_SortNoCompArr, Test_SortNoCompArr)
{
    int arr_mysort[] = { 32,71,12,45,26,80,53,33 };
    int arr_stdsort[] = { 32,71,12,45,26,80,53,33 };

    //first 5 sort
    quick_sort(arr_mysort, arr_mysort + 5);

    std::sort(arr_stdsort, arr_stdsort + 5);

    for (int i = 0; i < 8; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }

    //full sort
    quick_sort(arr_mysort, arr_mysort + 8);

    std::sort(arr_stdsort, arr_stdsort + 8);

    for (int i = 0; i < 8; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }
}

TEST(TestCase_SortArrComp, Test_SortArrComp_Lambda)
{
    int arr_mysort[] = { 11,71,20,121,45,26,80,13,33,20 };
    int arr_stdsort[] = { 11,71,20,121,45,26,80,13,33,20 };

    //first 5 sort
    quick_sort(arr_mysort, arr_mysort + 6, [](int a, int b) { return a > b; });

    std::sort(arr_stdsort, arr_stdsort + 6, [](int a, int b) { return a > b; });

    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }

    //full sort
    quick_sort(arr_mysort, arr_mysort + 10, [](int a, int b) { return a > b; });

    std::sort(arr_stdsort, arr_stdsort + 10, [](int a, int b) { return a > b; });

    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }
}

TEST(TestCase_SortArrComp, Test_SortArrComp_myfunction)
{
    int arr_mysort[] = { 24,80,3,33,20,51,41,20,121,25 };
    int arr_stdsort[] = { 24,80,3,33,20,51,41,20,121,25 };

    quick_sort(arr_mysort, arr_mysort + 10, myfunction);

    std::sort(arr_stdsort, arr_stdsort + 10, myfunction);

    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }
}

TEST(TestCase_SortArrComp, Test_SortArrComp_struct)
{
    myclass myobject;

    int arr_mysort[] = { 24,80,3,33,20,51,41,20,121,25 };
    int arr_stdsort[] = { 24,80,3,33,20,51,41,20,121,25 };

    quick_sort(arr_mysort, arr_mysort + 10, myobject);

    std::sort(arr_stdsort, arr_stdsort + 10, myobject);

    for (int i = 0; i < 10; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }
}


TEST(TestCase_RangeArr, Test_RangeArr1)
{
    int arr_mysort[] = { 5 };
    int arr_stdsort[] = { 5 };

    quick_sort(arr_mysort, arr_mysort + 1);

    for (int i = 0; i < 1; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }
}


TEST(TestCase_SortArrEqual, Test_SortArrEqual1)
{
    int arr_mysort[] = { 5,5,5,5,9,5 };
    int arr_stdsort[] = { 5,5,5,5,9,5 };

    quick_sort(arr_mysort, arr_mysort + 6);

    std::sort(arr_stdsort, arr_stdsort + 6);

    for (int i = 0; i < 6; i++)
    {
        EXPECT_TRUE(arr_mysort[i] == arr_stdsort[i]);
    }
}


TEST(TestCase_SortNoComp, Test_SortNoComp)
{
    std::vector<int> vector_stdsort = { 32,71,12,45,26,80,53,33 };
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end());

    std::sort(vector_stdsort.begin(), vector_stdsort.end());

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}



TEST(TestCase_SortNoComp, Test_SortOtherTyps1)
{
    std::vector<double> vector_stdsort = { 25.5, 5.1 , 98 };
    std::vector<double> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end());

    std::sort(vector_stdsort.begin(), vector_stdsort.end());

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_SortNoComp, Test_SortOtherTyps2)
{
    std::vector<size_t> vector_stdsort = { 27 , 1, 98, 19 };
    std::vector<size_t> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end());

    std::sort(vector_stdsort.begin(), vector_stdsort.end());

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_SortComp, Test_SortComp_Lambda)
{
    std::vector<int> vector_stdsort = { 12, 55, 2, 78, 4, 8, 102, 41, 1, 96, 77, 66, 11 };
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end(), [](int a, int b) { return a > b; });

    std::sort(vector_stdsort.begin(), vector_stdsort.end(), [](int a, int b) { return a > b; });

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_SortComp, Test_SortComp_myfunction)
{
    std::vector<int> vector_stdsort = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end(), myfunction);

    std::sort(vector_stdsort.begin(), vector_stdsort.end(), myfunction);

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_SortComp, Test_SortComp_struct)
{
    myclass myobject;

    std::vector<int> vector_stdsort = { 7, 88, 2, 35, 78, 41, 16, 9, 32, 22, 91 };
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end(), myobject);

    std::sort(vector_stdsort.begin(), vector_stdsort.end(), myobject);

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_SortComp, Test_SortComp)
{
    std::vector<int> myvector = { 32,71,12,45,26,80,53,33 };
    std::vector<Unit> vector_stdsort;

    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        vector_stdsort.push_back(Unit(*it));

    std::vector<Unit> vector_mysort = vector_stdsort;

    quick_sort(vector_mysort.begin(), vector_mysort.end(), [](Unit a, Unit b) { return a.GetSize() > b.GetSize(); });

    std::sort(vector_stdsort.begin(), vector_stdsort.end(), [](Unit a, Unit b) { return a.GetSize() > b.GetSize(); });


    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_Range, Test_Range1)
{
    std::vector<int> vector_stdsort = { 7, 88, 2, 35, 78, 41, 16, 9, 32, 22, 91 };
    std::vector<int> vector_mysort(vector_stdsort);

    EXPECT_THROW({ quick_sort(vector_mysort.end(), vector_mysort.begin()); }, Invalid_value_exception);
}

TEST(TestCase_Range, Test_Range2)
{
    std::vector<int> vector_stdsort = { 7 };
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end());

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_Range, Test_Range3)
{
    std::vector<int> vector_stdsort;
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end());

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_SortEqual, Test_SortEqual1)
{
    std::vector<int> vector_stdsort = { 1, 1, 1, 1, 1, 1 };
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end());

    std::sort(vector_stdsort.begin(), vector_stdsort.end());

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}

TEST(TestCase_SortEqual, Test_SortEqual2)
{
    std::vector<int> vector_stdsort = { 12, 1, 1, 1, 1, 6 };
    std::vector<int> vector_mysort(vector_stdsort);

    quick_sort(vector_mysort.begin(), vector_mysort.end());

    std::sort(vector_stdsort.begin(), vector_stdsort.end());

    //EXPECT_EQ(vector_mysort, vector_stdsort);
    EXPECT_TRUE(vector_mysort == vector_stdsort);
}