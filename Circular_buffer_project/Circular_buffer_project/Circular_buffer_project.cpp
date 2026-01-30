#include <iostream>   
#include <numeric>    
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>

class CircularBuffer {
public:
    T* buffer;
    size_t head; // 가장 오래된 데이터 인덱스
    size_t tail;
    size_t _size;
    size_t _capacity;

public:
    // 생성자,초기화리스트
    CircularBuffer(size_t capacity) : _capacity(capacity), head(0), tail(0), _size(0) {
        buffer = new T[_capacity];  //capacity개수의 배열
    }

    ~CircularBuffer() { delete[] buffer; }



   
    // ------------------------ 반복자(Iterator) 구현 ------------------------------------

  
  class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
    private:
        T* buffer_Iter;        // 버퍼 주소 복사
        size_t index_Iter;    
        size_t head_Iter;      // 시작 위치 복사
        size_t capacity_Iter;  // 버퍼 크기 복사

    public:
        // 생성자 
        Iterator(T* buffer, size_t index, size_t head, size_t capacity)
            : buffer_Iter(buffer), index_Iter(index), head_Iter(head), capacity_Iter(capacity) {}

        // 현재 인덱스의 실제 데이터
        T& operator*() {
     
            
            return buffer_Iter[(head_Iter + index_Iter) % capacity_Iter];
        }

   
        Iterator& operator++() {
            index_Iter++;
            return *this;
        }

       
        bool operator!=(const Iterator& other) const {
            return index_Iter != other.index_Iter;
        }
    };



  T& operator[](size_t index) { //논리적 인덱스 접근

      return buffer[(head + index) % _capacity];

  }


  const T& operator[](size_t index) const {
      return buffer[(head + index) % _capacity];
  }
    // ------------------------------------------------------------------------
   





    void push_back(const T& value) {    //버퍼에 데이터를 쌓음
        buffer[tail] = value;             // 1. tail에 데이터 저장
        tail = (tail + 1) % _capacity;    // 2. 다음 칸으로 이동

        if (_size < _capacity) {
            _size++;                      //  빈칸이 있다면 사이즈 증가
        }
        else {
            head = (head + 1) % _capacity; //head 값 이동
        }
    }


    size_t capacity() const { 
        return _capacity;
    }


    size_t size() const {
        return _size;
    }

    // 비어있는지 확인
    bool empty() const {
        return _size == 0;
    }
     

    void pop_front() {
        if (!empty()) {
            head = (head + 1) % _capacity;
            _size--;
        }
    }

    // literator생성자 호출
    Iterator begin() {
        return Iterator(buffer, 0, head, _capacity);
    }//CircularBuffer필드를 Iterator 생성자 매개변수로 사용

  
    Iterator end() {
        return Iterator(buffer, _size, head, _capacity);
    }



}
;
int main() {
    size_t capacity;
    cout << "데이터 개수 제한 버퍼 크기를 설정하세요: ";
    cin >> capacity;

    CircularBuffer<double> temp_buffer(capacity);
    double temp;

    cout << "온도를 입력하세요 (종료하려면 99 입력):" << endl;

    while (true) {
        cout << "현재 온도 입력: ";
        cin >> temp;
        if (temp == 99) break;

        temp_buffer.push_back(temp);


        cout << "현재 버퍼 순서: [";
        for (size_t i = 0; i < temp_buffer.capacity(); ++i) {
            cout << temp_buffer.buffer[i] << (i == temp_buffer.capacity() - 1 ? "" : ", ");
        }
        cout << "]" << endl;


        cout << "begin()호출시 순서: [";
        for (auto it = temp_buffer.begin(); it != temp_buffer.end(); ++it) {  
            cout << *it;
            auto next_it = it;
            if (++next_it != temp_buffer.end()) cout << ", ";
        }
        cout << "]" << endl;


        // STL사용한 상위 하위 추출
        std::vector<double> top_3(3);    // 가장 작은 값 3개
        std::vector<double> bottom_3(3); // 가장 큰 값 3개

        // 하위 3개  추출
        std::partial_sort_copy(temp_buffer.begin(), temp_buffer.end(),
            top_3.begin(), top_3.end());

        // 상위 3개 추출  마지막에 std::greater 추가
        std::partial_sort_copy(temp_buffer.begin(), temp_buffer.end(),
            bottom_3.begin(), bottom_3.end(), std::greater<double>());
         


                // STL사용한 실시간 출력
            double max_temp = *std::max_element(temp_buffer.begin(), temp_buffer.end());//begin end 반복 operator*을 반환함
            double min_temp = *std::min_element(temp_buffer.begin(), temp_buffer.end());
            double sum_temp = std::accumulate(temp_buffer.begin(), temp_buffer.end(), 0.0);

            cout << "   데이터 개수: " << temp_buffer.size()
                << " | 평균: " << sum_temp / temp_buffer.size()
                << " | 최대: " << max_temp 
                << " | 최소: " << min_temp
                << " | 가장높은온도 3개: " << bottom_3[0] << ", " << bottom_3[1] << ", " << bottom_3[2] 
                <<" | 가장낮은온도  3개: " << top_3[0] << ", " << top_3[1] << ", " << top_3[2] << endl;
            
    }
    return 0;
}









