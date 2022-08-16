# printf

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
