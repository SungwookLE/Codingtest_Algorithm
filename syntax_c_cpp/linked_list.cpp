#include <iostream>
// 열혈 p109, 연결리스트
// 왜 std::vector, queue 같이 어레이 타입을 구조체 타입의 연결리스트 보다 많이 쓸까에 대한 탐구
// 이 블로그가 정리를 잘해놓았네, https://dc7303.github.io/essay/2020/02/23/whyUseArrayInsteadOfList/

template<typename T>
struct node{
    T data;
    struct node* next;
}; // 데이터가 저장되는 곳
 
template<typename T>
struct list{
    node<T> *head;
    node<T> *tail;
    node<T> *cur;
}; // 노드를 가리키는 화살표들

// typedef list List;

template<typename T>
class linked_list{
    public:
    linked_list(){
        List = new list<int>;
        List->cur = NULL;
        List->tail = NULL;
        List->head = NULL;
    }

    void push_data(T data){
        newNode = new node<int>;
        newNode->data = data;
        newNode->next = NULL;

        if (List->head == NULL)
            List->head = newNode; // 현재의 머리부분에 newNode를 대치하고,
        else
            List->tail->next = newNode; //  현재의 꼬리에 뒤에를 newNode로 대치하고,
        
        List->tail = newNode; // tail을 연결리스트의 끝에다 가져다 놓는다.
    }

    void print_data(){
        if (List->head == NULL)
            std::cout << " 저장된것 없음\n";
        else{
            List->cur = List->head;

            std::cout << List->cur->data << std::endl;
            while ( List->cur->next != NULL){
                List->cur = List->cur->next;
                std::cout << List->cur->data <<std::endl;
            }
        }
    }

    ~linked_list(){
        if (List->head == NULL){
            std::cout << "is empty\n";
        }
        else{
            node<T> * delNode = List->head;
            node<T> * delNextNode = List->head->next;

            std::cout << List->head << " is deleted\n";
            delete delNode;
            while(delNextNode != NULL){
                delNode = delNextNode;
                delNextNode = delNextNode->next;

                std::cout << delNode << " is deleted\n";
                delete delNode;
            }
        }
    }

    private:
    list<T> *List;
    node<T> *newNode;
};


int main(){

    linked_list<int> linked;

    linked.push_data(3);
    linked.push_data(5);
    linked.push_data(7);
    linked.push_data(9);
    linked.push_data(11);
    linked.push_data(13);
    linked.push_data(15);

    linked.print_data();

    return 0;
}

