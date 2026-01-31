# Circular Buffer Project (C++)

프로젝트 개요 <br>

본 프로젝트는 면접 과제를 업그레이드한 C++ 순환 버퍼 구현 프로젝트입니다. <br>
고정 크기 버퍼에서 오래된 데이터를 자동으로 제거하는 구조를 구현했으며, <br>
원형 구조에서도 입력 시간 순서로 데이터를 처리할 수 있도록 Iterator를 직접 구현했습니다. <br>


핵심 구현 내용 <br>

템플릿 기반 CircularBuffer<T> 구현 <br>

고정 크기 배열을 사용하는 원형 구조 <br>

버퍼가 가득 차면 가장 오래된 데이터가 자동으로 제거되는 방식 <br>

내부 Iterator 클래스를 구현해 <br>

begin() / end() 제공 <br>

입력 시간 순서 기준 인덱스 순서 변경 <br>

STL 알고리즘 적용 가능 <br>

 <br> <br> <br> <br>

배운 점 <br>

STL 알고리즘은 iterator 규칙에 의해 동작한다는 점 <br>

원형 구조에서도 시간 순서로 순회하기 위해 Iterator 설계가 필요하다는 점 <br>

 % 연산을 활용해 head / tail 기반의 원형 구조를 구현할 수 있다는 점 <br>
  

 <br> <br>
 추가로 학습한 C++ 문법 <br>

const 메소드를 통해 읽기 전용 인터페이스를 명확히 구분 <br>
T& 반환을 사용해 불필요한 객체 복사를 방지 <br>


 <br> <br>
개발 환경
 <br>
Language: C++ <br>

IDE: Visual Studio 2022






 

 <br> <br> <br> <br>

<img width="910" height="309" alt="buffer1" src="https://github.com/user-attachments/assets/49eb6928-a7c6-4ce2-b865-4a669d704204" />  버퍼의 최대 크기를 지정합니다

<img width="1122" height="206" alt="image" src="https://github.com/user-attachments/assets/cac633ef-ed63-492a-ae2b-e89324427fd7" /> 
온도를 입력하면 버퍼에 저장되며,  
버퍼가 가득 찬 이후에는 가장 오래된 데이터부터 자동으로 제거됩니다.


24.5입력 <br>
begin()  end()를 통해 시간 순서 기준으로 데이터를 순회하며,  
STL 알고리즘을 사용해 평균, 최대, 최소 , 최대값 3개 최소값 3개를 계산합니다.


<img width="1910" height="749" alt="buffer31" src="https://github.com/user-attachments/assets/cfa361f3-2ab9-4c3b-aa99-fd7ea4608595" />
버퍼 최대 크기를 5로 설정한 상태에서 6번째 온도 값"23.1" 을 입력한 상황입니다.

이 경우 버퍼가 가득 차 있으므로 가장 오래된 데이터"24.5"가 자동으로 제거되고  
새로 입력한 "23.1"이 해당 위치에 저장됩니다.

Iterator begin을 통해 버퍼를 순회하면 메모리 인덱스 순서와 관계없이 입력 시간 순서 기준으로 데이터가 출력됩니다.








