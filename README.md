# printf

-------------
## 가변인자
### 함수형태 - `자료형` `함수이름` `(고정인자, ...)`
	ex) void	ft_printf(int args, ...)

### 활용방법
	void	ft_pritnf(int args, ...)
	{
		va_list ap;			//가변인자들의 목록 포인터 생성
		
		va_start(ap, args);		//가변인자 목록 포인터가 첫번째 인자를 가르키도록 설정
		
		**함수공간**
		va_arg(ap, int)			//ap 포인터가 현재 가르키고 있는 인자를 반환하고
						//포인터를 int만큼 이동
		va_end(ap)			//목록 포인터를 초기화함
	}
------------
## pirntf 함수
### 레퍼런스
[c 언어 레퍼런스 - printf 함수](https://modoocode.com/35)   
[ft_printf 레퍼런스](https://velog.io/@hidaehyunlee/%ED%98%95%EC%8B%9D%ED%83%9C%EA%B7%B8%EC%99%80-%EC%84%9C%EC%8B%9D%EC%A7%80%EC%A0%95%EC%9E%90-printf-%ED%95%A8%EC%88%98%EC%9D%98-%EC%98%B5%EC%85%98-%EC%95%8C%EC%95%84%EB%B3%B4%EA%B8%B0)
### 형식태그
	%[flag][width][.precision][length] 서식지정자_)
