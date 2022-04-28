https://www.youtube.com/watch?v=umwh5IO5bC8&list=PLDV-cCQnUlIbMTKI-Tc3RV6i3yn0IWeLT

부동소수점 floating, pair, tuple, enum class, union type. enum classs, 등


```

부동소수점. 영상처리 분야나 이런곳에선 부동소수점 많이ㅡ씀

unsinged integer 한마디로 우리가 4byte크기의 int는 1 1 1 1 이거나 0 0 0 0 은 0 ~ 15까지 숫자를 표현가능

signed integer 1's compliment , 2's compliment -8~ -7까지 표현.  32비트는 0~2^32 - 1, 64비트는 2^64 - 1
    
    singed integer 은 -2^31 ~ 2^31 -` 표현 이렇게
    
    한계점 0.5, 0.15 , 370.25, 이런 숫자는 불가능.  floating number 사용
    
    만오천 . - 38만, 0.00000123 만오천은 1.5 x 10^4 이런식
    
    -3.8 x 10^5
    
    페어 튜플..
    
    std::pair<int,std::string> numStr{1,"nocope"};

    std::cout << numStr.first << std::endl;
    std::cout << numStr.second << std::endl;

struct NewType
    
std::pair<int, int> divide(int a , int b)
{
    if(b==0)
    {
        return std::make_pair<int, int>(0,-1);
    }
    return std::make_pair<int, int>(a/b,0);
    
}

튜플? pair의 generalization 타입임.
    
 std::tuple<double, char, std::String> get_student()
{
    return std::make_tupe(3.8, 'A', 'Lisa simpson');
}

int main() {
    auto student0 = get_student();
    
    std:cout << "ID: 0,"
             << "GPA: " << std::get<0>(student0) << ", ";
             << "grade: " << std::get<1>(student0) << ", ";
             << "name: " << std::get<2>(student0) << '\n';

    auto [gpa2, grade2, name2] = get_student();
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 <<< ", "
              << "grade: " << grade2 <<< ", "
              << "name: " << name2 <<< ", "

        
}
```
