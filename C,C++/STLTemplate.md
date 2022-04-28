https://pretending.tistory.com/entry/C-Template-Type-Deduction-%ED%85%9C%ED%94%8C%EB%A6%BF-%ED%83%80%EC%9E%85-%EC%B6%94%EB%A1%A0-stdforward?category=878025


템플릿 타입 추론.


```

/*
데이터타입에 상관없게 프로그래밍 짤수있게 만듬.
    instanciation 언제 이루어지는지? c++는 더 빠른 코드를 위해 LR VALUE PERFECT FROWARDING?
    
template<typename T>
    -function, calss, alias, variable template존재.
    
   변수의 타입을 정해주지않고 컴파일시간에 정한다. int나 float type이 정해지지않음.
   최대값 max function도 템플릿으로 만듬.    
T testFunc(T a)
{
    return a;
}
*/

#include <algorithm>


int main() 
{
    
    std::vector<int> ints;
        std::vector<double> doubles;
        std::vector<Cat> Cats;


    
    int maxI = std::max<int>(1,5);
    float maxf = std::max<float>(1.2f,2.5f);

    double maxd = std::max<double>(1.4,3.4);
    
    std:cout << maxI << std::endl;
    
    return 0;
}
/*
arguemnt type떄문에 function overloading  

int add(int a, int b)
{
    return a+b;
} ;

double add(double a, double b)
{
    return a+b;
};
이렇게 매번쓰기 힘드니까.
*/

template<typename T>
T add(T a, T b)
{
    return a+b;
};

int main()
{
    int a = add(1,1);
    double b = add(2.5, 5.1); //double은없으니까 function 오버로딩
     
    auto c = add("Abc","dasdsaasd"); //이거는 컴파일이 당연히 안됌.
    
    return 0;
    }

```


```
//instantiation 
//explicit template function instantiation

//template tye deduction. 템플릿 타입 추론. argument type 명시 안해줘도 컴파일러가 argument로 보고 deduction(추론) 하여 해당 타입 함수 만들어주기. 예를들어

template<typenameT>
void printVar(T a)
{
    std::cout <<typeid(a).name <<std::endl;
}

int main()
{
    printVar<int>(a); //type 명시
    
    printVar(a); //type 미명시
    
    return 0; 
}

하면 

//출력 콘솔에서 확인을 하게 되면 두 호출 모두 int 타입의 함수가 만들어지고 Argument로 넘어간 값도 출력이 잘 되었다. 
이와 같이 Template 함수는 Argument를 보고 Type을 Deduction (추론)을 하게 된다. 일만 integer나 string클래스에 대해서는
다 문제없이 잘 작동하는데 Parameter를 Reference로 받거나 R-Value로 받을 경우는 어떻게 되나 궁금할 수 있다. 

```
