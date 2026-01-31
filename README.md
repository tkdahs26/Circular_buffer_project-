# Circular Buffer Project (C++)

프로젝트 개요

본 프로젝트는 면접 과제를 업그레이드한 C++ 순환 버퍼 구현 프로젝트입니다.
고정 크기 버퍼에서 오래된 데이터를 자동으로 제거하는 구조를 구현했으며,
원형 구조에서도 입력 시간 순서로 데이터를 처리할 수 있도록 Iterator를 직접 구현했습니다.


핵심 구현 내용

템플릿 기반 CircularBuffer<T> 구현

고정 크기 배열을 사용하는 원형 구조

버퍼가 가득 차면 가장 오래된 데이터가 자동으로 제거되는 방식

내부 Iterator 클래스를 구현해

begin() / end() 제공

입력 시간 순서 기준 인덱스 순서 변경

STL 알고리즘 적용 가능


배운 점

STL 알고리즘은 iterator 규칙에 의해 동작한다는 점

원형 구조에서도 시간 순서로 순회하기 위해 Iterator 설계가 필요하다는 점

 % 연산을 활용해 head / tail 기반의 원형 구조를 구현할 수 있다는 점
  


 추가로 학습한 C++ 문법

const 메소드를 통해 읽기 전용 인터페이스를 명확히 구분
T& 반환을 사용해 불필요한 객체 복사를 방지



개발 환경

Language: C++

IDE: Visual Studio 2022






 

 <br> <br> <br> <br>

<img width="910" height="309" alt="buffer1" src="https://github.com/user-attachments/assets/49eb6928-a7c6-4ce2-b865-4a669d704204" />  버퍼의 최대 크기를 지정합니다

<img width="1122" height="206" alt="image" src="https://github.com/user-attachments/assets/cac633ef-ed63-492a-ae2b-e89324427fd7" /> 
24.5입력 <br>
현재 버퍼 순서: 배열에 넣고 나머지는 설정안해서 생긴 임의의 데이터 값입니다 <br>
begin()호출시 순서: stl의 begin함수를 호출시 itorator클래스가 순서를 오래된순부터 최신순까지 나열합니다.<br>


평균값 accumulate() 최대값 max_element() 최소값 min_element() 상위, 하위 3개 partial_sort_copy()은 stl함수이기 때문에 별도의 계산 없이 매개변수에 begin() end() 함수를 넣고 각 함수들의 값을 구했습니다.


<img width="1910" height="749" alt="buffer31" src="https://github.com/user-attachments/assets/cfa361f3-2ab9-4c3b-aa99-fd7ea4608595" />
현재 버퍼 순서:      최대 크기를 5로 설정해서 6번째 23.1 입력했을때 %연산에 의해 처음입력한 24.5는 삭제되고 그 자리에 23.1이 들어갔습니다<br>
begin() 호출시 순서: 배열 순서와 상관없이 오래 입력 순으로 나열되기 때문에 가장 오래된 24.5가 삭제되고 두번째입력한 25.2가 첫번째 인덱스로 이동했습니다 









