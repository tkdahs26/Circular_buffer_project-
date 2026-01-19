# Circular_buffer_project-



Language: C++


Tool: Visual Studio 2022


효율적인 메모리 관리가 가능한 순환 버퍼를 구현하고, STL 함수에 필요한 반복자Iterator를 사용한 프로젝트입니다.


주요 기능
템플릿클래스활용한 다양한 데이터 타입
head와 tail 인덱스에 %연산을 적용하여 다시 처음으로 돌아가는 원형 구조로 설계했습니다.
버퍼가 가득 찼을 때 새 데이터가 들어오면 head를 이동시켜 가장 오래된 데이터를 삭제합니다.
STL 함수를 사용할 수 있도록 itorator 내부 클래스와 operator * ++ != [] 등 오버로딩 설계했습니다.
itorator 를 활용해 뒤섞인 버퍼를 오래된순부터 최신순까지 나열합니다



<img width="910" height="309" alt="buffer1" src="https://github.com/user-attachments/assets/49eb6928-a7c6-4ce2-b865-4a669d704204" />  버퍼의 최대 크기를 지정합니다

<img width="1122" height="206" alt="image" src="https://github.com/user-attachments/assets/cac633ef-ed63-492a-ae2b-e89324427fd7" /> 
현재 버퍼 순서: 배열에 넣고 나머지는 오류같지만 주소값이고 <br>
begin()호출시 순서: stl의 begin함수를 호출시 itorator클래스가 순서를 오래된순부터 최신순까지 나열합니다.<br>


평균값 accumulate() 최대값 max_element() 최소값 min_element() 상위, 하위 3개 partial_sort_copy() 의 매개변수에 begin() end() 함수를 넣고 각 함수들의 값을 구했습니다.


<img width="1910" height="749" alt="buffer31" src="https://github.com/user-attachments/assets/cfa361f3-2ab9-4c3b-aa99-fd7ea4608595" />
최대 크기를 5로 설정해서 6번째 23.1 입력했을때 %연산에 의해 처음입력한 24.5는 삭제되고 그 자리에 23.1이 들어갔습니다<br>
순서를 나열한 begin() 실행시 오래된 순으로 나열되기 때문에 두번째입력한 25.2가 제일 오래되서 첫번째 인덱스로 이동했습니다 









